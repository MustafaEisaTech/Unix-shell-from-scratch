CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = src/main.c src/shell.c src/input.c src/parser.c src/launch.c
OBJ = $(SRC:.c=.o)
TARGET = my_shell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)