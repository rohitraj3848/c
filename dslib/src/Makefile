all: main

CFLAGS += -Wall -Werror -I../h

OBJS = 	main.o \
		graph.o \
		linkedlist.o \
	

main: $(OBJS)
	gcc $(CFLAGS)  $(OBJS) -o main 

main.o: main.c
	gcc -c $(CFLAGS) main.c


graph.o: graph.c
	gcc -c $(CFLAGS)  graph.c

linkedlist.o: graph.c
	gcc -c $(CFLAGS)  linkedlist.c


clean:
	\rm *.o main
	
