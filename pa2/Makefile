OBJS= sorted-list.o main.o

CC= gcc

CFLAGS= -Wall -g

sl: $(OBJS) libsl.a
	$(CC) -o sl $(OBJS) libsl.a

libsl.a: sorted-list.o
	ar -r libsl.a sorted-list.o

sorted-list.o: sorted-list.c sorted-list.h
	$(CC) -c $(CFLAGS) sorted-list.c

main.o: main.c
	$(CC) -c $(CFLAGS) main.c

clean:
	rm -f sl $(OBJS) libsl.a