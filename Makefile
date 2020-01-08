# simple Makefile
# Nooreldean Koteb

CC= gcc
CFLAGS=-g -Wall
TARGET= encrypt_decrypt

all:$(TARGET)
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
clean:
	rm $(TARGET)
