# basic GTK+ app makefile
SOURCES = myosc.c
OBJS    = ${SOURCES:.c=.o}
CFLAGS  = `pkg-config gtk+-3.0 --cflags`
LDADD   = `pkg-config gtk+-3.0 --libs` -lm
CC      = gcc -Wall
PACKAGE = myosc

all : ${OBJS}
	${CC} -o ${PACKAGE} ${OBJS} ${LDADD}

.c.o:
	${CC} ${CFLAGS} -c $<

# end of file
