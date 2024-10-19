CC = gcc
CFLAGS = -Wall -g #-Wall shows all warnings, -g includes debugging info.
LDFLAGS = -lncurses
TARGET = venus.exe
SRCS = venus.c

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

#both:
#	rm -f $(TARGET) && $(TARGET)

clean:
	rm -f $(TARGET)
