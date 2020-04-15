objs = tree.o  test_28_1.o

vpath  %.c ../list
vpath  %.c ../tree

main:$(objs)
	gcc -o $@ $^
	rm $(objs)

%.o:%.c
	gcc -o $@ -c $<
.PHONY : clean
clean:
	rm $(objs)
