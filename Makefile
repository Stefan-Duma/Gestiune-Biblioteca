CC = g++
CFLAGS = -Wall -Werror -Wextra
SDL_FLAGS = `sdl2-config --cflags --libs`
all:
	$(CC) $(CFLAGS) main.cpp src/*.cpp -o main
	./main

ui:
	$(CC) $(CFLAGS) $(SDL_FLAGS) 
