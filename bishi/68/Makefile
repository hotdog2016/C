objs = 68_1.o list.o tree.o
CC=g++

vpath %.c ../list
vpath %.c ../tree

main:$(objs)
	$(CC) -o  $@ -g $^ 
	rm $(objs)
%.o:%.cc
	$(CC) -o  $@ -c -g $<
%.o:%.c
	gcc -o  $@ -c -g $<
.PHONY : clean
clean:
	rm $(objs)
