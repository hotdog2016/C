objs =  queue.o tree.o stack.o
vpath  %.c ../tree
vpath  %.c ../stack
main:$(objs)
	gcc -o $@ $^
	rm $(objs)
%.o:%.c
	gcc -o $@ -c $<
.PHONY : clean
clean:
	rm $(objs)
