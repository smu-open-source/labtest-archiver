CC = gcc
CFLAGS = -fsanitize=address -I../include -Wall -Wextra

TARGET = out
SRC = ../src/config.c config_testcases.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)