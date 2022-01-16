CC=gcc
CFLAGS=-Wall
LDFLAGS=-lc
LDLIBS=-lssl -lcrypto
OBJS=hello.o
TARGET= main

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^

.c.o:
	$(CC) -c -o $@ $<

clean:
	rm -f *.o
	rm -f $(TARGET)
