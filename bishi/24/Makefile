objs = list.o  test_24_1.o

vpath  %.c ../list

main:$(objs)
	gcc -o $@ $^
	rm $(objs)

%.o:%.c
	gcc -o $@ -c $<
.PHONY : clean
clean:
	rm $(objs)
