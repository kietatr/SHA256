all: main run

main: main.c helpers.c sha256.c
	gcc -Wall -o main main.c helpers.c sha256.c

run:
	./main

clean:
	rm main