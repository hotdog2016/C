objs = 60_1.o list.o tree.o
CC=g++

vpath %.c ../list
vpath %.c ../tree

main:$(objs)
	$(CC) -o $@ $^ 
	rm $(objs)
%.o:%.cc
	$(CC) -o $@ -c $<
%.o:%.c
	gcc -o $@ -c $<
.PHONY : clean
clean:
	rm $(objs)
