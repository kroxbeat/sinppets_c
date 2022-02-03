CC=gcc
CFLAGS=-Wall
LDFLAGS=-lc
LDLIBS=
OBJS=ribrary.o main.o
TARGET= main

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^

.c.o:
	$(CC) -c -o $@ $<

clean:
	rm -f *.o
	rm -f $(TARGET)
