objs = list.o stack.o queue.o tree.o test_35_1.o

vpath  %.c ../queue
vpath  %.c ../tree
vpath  %.c ../stack
vpath  %.c ../list


main:$(objs)
	gcc -o $@ $^
	rm $(objs)
%.o:%.c
	gcc -o $@ -c $<
.PHONY : clean
clean:
	rm $(objs)
