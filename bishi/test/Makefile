objs =  main.o tree.o
vpath  %.c ../tree
main:main.o $(objs)
	gcc -o $@ $^
	rm $(objs)
%.o:%.c
	gcc -o $@ -c $<
.PHONY : clean
clean:
	rm $(objs)
