#jfr
CC = gcc
CFLAGS = -Wall -g
SRCS = mercury.c commands.c
TARGET = merc.exe
all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -rf $(OBJS) $(TARGET)
