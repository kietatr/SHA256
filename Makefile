all: main run

main: main.c helpers.c sha256.c
	gcc -Wall -o main main.c helpers.c sha256.c

run:
	./main

clean:
	rm main

other-implementation: other-implementation.c
	gcc -o other-implementation other-implementation.c sha-2/sha-256.c

time-my-implementation: main
	./time-my-implementation.sh

time-other-implementation: other-implementation
	./time-other-implementation.sh