# Makefile for SDL project

CC = gcc
CFLAGS = -Wall -g $(shell sdl-config --cflags)
LIBS = $(shell sdl-config --libs) -lSDL_image -lSDL_mixer
SRCS = main.c
OBJS = $(SRCS:.c=.o)
EXEC = program

# Target to build the program
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LIBS)

# Compile .c files into .o files
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

# Clean up the build
clean:
	rm -f $(OBJS) $(EXEC)

# Run the program
run: $(EXEC)
	./$(EXEC)
