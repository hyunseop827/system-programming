# Makefile is script for build tool (make) to understand build rules.
# 
# which source code to complie with which options.
# which order to link.
# 
# it's like a recipe for make build tool.

# Makefile

CC=gcc
CFLAGS=
OBJS=ch01-03-main.o ch01-03-addnum.o
LIBS=
all : add.out

add.out : $(OBJS)
	$(CC) $(CFLAGS) -o add.out $(OBJS) $(LIBS)

ch01-3-main.o : ch01-03-main.c
	$(CC) $(CFLAGS) -c ch01-03-main.c
ch01-3-addnum.o : ch01-03-addnum.c
	$(CC) $(CFLAGS) -c ch01-03-addnum.c

clean:
	rm -f $(OBJS) add.out *.o core
