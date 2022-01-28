CC=gcc
CFLAGS=-Wall
LDFLAGS=-lc
LDLIBS=
OBJS=book4.o main.o
TARGET= main

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^

.c.o:
	$(CC) -c -o $@ $<

clean:
	rm -f *.o
	rm -f $(TARGET)
