all: build

build:
	gcc -Wall tema4.c -o tema4

run: tema4
	./tema4

clean:
	rm -fr tema4
