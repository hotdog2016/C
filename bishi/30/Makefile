objs = stack.o  test_30_1.o

vpath  %.c ../list
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
