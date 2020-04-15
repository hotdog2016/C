objs = stack.o queue.o tree.o test_33_1.o

vpath  %.c ../queue
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
