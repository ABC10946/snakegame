CC = gcc
CFLAGS = -Wall -std=c11
PROGRAM = snakegame
SRCS = main.c
LIBS = -lglut -lGLU -lGL

all: $(PROGRAM)

$(PROGRAM): $(SRCS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(SRCS) $(LIBS)

clean:
	rm -f $(PROGRAM)
