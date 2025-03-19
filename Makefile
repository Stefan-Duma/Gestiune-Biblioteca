CC = g++
CFLAGS = -Wall -Werror -Wextra -L./lib
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-widgets -lGL

all:
	$(CC) $(CFLAGS) main.cpp src/*.cpp -o main
	./main

ui:
	$(CC) $(CFLAGS) gui/*.cpp -o ui $(SFML_FLAGS)
	./ui