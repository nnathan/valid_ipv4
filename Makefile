main: main.c check_ip.o
	gcc -Wall -Werror -O3 -o main main.c check_ip.o

check_ip.o: check_ip.c
	gcc -Wall -Werror -O3 -c check_ip.c

.PHONY: clean
clean:
	rm -f check_ip.o main
