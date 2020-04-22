objs = 51_1.o
CC=g++

main:$(objs)
	$(CC) -o $@ $^
	rm $(objs)
%.o:%.c
	$(CC) -o $@ -c $<
.PHONY : clean
clean:
	rm $(objs)
