CC      := clang
CFLAGS  := -Wall -Wextra -g
TARGET  := db
SRCS    := $(wildcard *.c)
OBJS    := $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run