# Makefile

CC=gcc
CFLAGS=
OBJS=prac13-subnum.o prac13-main.o
LIBS=
all : add.out

add.out : $(OBJS)
	$(CC) $(CFLAGS) -o add.out $(OBJS) $(LIBS)

prac13-main.o : prac13-main.c
	$(CC) $(CFLAGS) -c prac13-main.c 
prac13-subnum.o : prac13-subnum.c
	$(CC) $(CFLAGS) -c prac13-subnum.c 

clean:
	rm -f $(OBJS) sub.out *.o core
