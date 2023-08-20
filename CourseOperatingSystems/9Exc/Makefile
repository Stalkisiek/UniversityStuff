CC = gcc
CFLAGS = -Wall -Wextra -pthread

TARGET = mutual_exclusion

all: $(TARGET)

$(TARGET): mutual_exclusion.o
	$(CC) $(CFLAGS) $^ -o $@

mutual_exclusion.o: mutual_exclusion.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o

run:
	./$(TARGET) $(ARGS)

.PHONY: run
