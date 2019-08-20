
CFLAGS=-lm -lGL -lGLU -lglut

all:
	gcc double.c -o double $(CFLAGS)
