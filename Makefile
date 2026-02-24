CC = gcc
CFLAGS = -Wall -Wextra
OBJS = main.o grid.o generation.o

main : $(OBJS)

clean : 
	$(RM) *.o main
