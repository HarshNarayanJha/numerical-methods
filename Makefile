CC = gcc
CFLAGS = -Wall -Wextra -Werror -lm

bin:
	mkdir -p ./bin

%: src/%.c bin
	$(CC) $(CFLAGS) src/$*.c -o bin/$*
	bin/$*

clean:
	rm -r ./bin
