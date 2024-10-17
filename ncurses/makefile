CC = gcc                                            #Our compiler
CFLAGS = -I../stopwatch                             #includes the stopwatch path
LDFLAGS = -L../stopwatch -lstopwatch -lncurses      #Library search path
TARGET = bounce                                     #Output file
SRCS = main.c                                       #Source file
all: $(TARGET)                                      #default call when using 'make' command


#Assembles our compilation command- Pulls from the target ($(VARIABLE)) to generate the terminal command.
#In our case, typing 'make' calls the 'all' execution which outputs this command:
# gcc -I../stopwatch main.c -o bounce -L../stopwatch -lstopwatch -lncurses
$(TARGET):
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

#This removes the compiled objects.
clean:
	rm -f $(OBJS) $(TARGET)