objs = 53_2.o list.o
CC=g++

vpath %.c ../list

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
