CC=gcc

main:
	$(CC) -o main main.c
	./main
	rm -f main
	rm -f *.o