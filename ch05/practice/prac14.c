/*
 * Read /var/log/wtmp and print:
 *  - login name
 *  - terminal name
 *  - logout time
 *  - remote login host
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <utmp.h>

typedef struct {
    int  used;
    char line[UT_LINESIZE];
    char user[UT_NAMESIZE];
    char host[UT_HOSTSIZE];
} Session;

static void fmt_time(time_t t, char *buf, size_t n) {
    struct tm *lt = localtime(&t);
    if (!lt) {
        snprintf(buf, n, "unknown");
        return;
    }
    strftime(buf, n, "%Y-%m-%d %H:%M:%S", lt);
}

static Session *find_session(Session sessions[], int cap, const char *line) {
    // 1) existing session with same terminal line
    for (int i = 0; i < cap; i++) {
        if (sessions[i].used &&
            strncmp(sessions[i].line, line, UT_LINESIZE) == 0) {
            return &sessions[i];
        }
    }
    // 2) empty slot
    for (int i = 0; i < cap; i++) {
        if (!sessions[i].used) return &sessions[i];
    }
    return NULL;
}

int main(void) {
    if (utmpname("/var/log/wtmp") == -1) {
        perror("utmpname");
        return 1;
    }

    setutent();

    Session sessions[512];
    memset(sessions, 0, sizeof(sessions));

    struct utmp *u;
    while ((u = getutent()) != NULL) {
        if (u->ut_type == USER_PROCESS) {
            Session *s = find_session(sessions, 512, u->ut_line);
            if (!s) continue;

            memset(s, 0, sizeof(*s));
            s->used = 1;

            strncpy(s->line, u->ut_line, UT_LINESIZE - 1);
            strncpy(s->user, u->ut_user, UT_NAMESIZE - 1);
            strncpy(s->host, u->ut_host, UT_HOSTSIZE - 1);

        } else if (u->ut_type == DEAD_PROCESS) {
            Session *s = find_session(sessions, 512, u->ut_line);
            if (!s || !s->used) continue;

            time_t logout_t = (time_t)u->ut_tv.tv_sec;
            char tbuf[64];
            fmt_time(logout_t, tbuf, sizeof(tbuf));

            printf("login=%-8.8s tty=%-12.12s logout=%s remote=%s\n",
                   s->user[0] ? s->user : "-",
                   s->line[0] ? s->line : "-",
                   tbuf,
                   s->host[0] ? s->host : "-");

            s->used = 0;
        }
    }

    endutent();
    return 0;
}

