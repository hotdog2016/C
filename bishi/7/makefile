objects := $(patsubst %.c,%.o,$(wildcard *.c))
main:$(objects)
	gcc -o $@ $(objects)
%.o: %.c
	gcc -c $< -o $@ 
