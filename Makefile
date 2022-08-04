CC ?= gcc
CFLAGS ?= 

default: simple

src/%.o: src/%.c
	$(CC) -Isrc -c -Wall -fstack-protector-strong -D_FORTIFY_SOURCE=2 \
		$(CFLAGS) $(EXTRA_CFLAGS) $^ -o $@

.PHONY:
simple: src/main.o
	$(CC) -Isrc -Wall $(CFLAGS) $^ -lz -o $@

.PHONY:
clean:
	rm simple src/*.o
