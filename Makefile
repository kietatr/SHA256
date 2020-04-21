all: main run

main: main.c helpers.c
	gcc -o main main.c helpers.c

run:
	./main

clean:
	rm main