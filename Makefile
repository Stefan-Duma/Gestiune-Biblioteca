CC = g++
CFLAGS = -Wall -Werror -Wextra
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all:
	$(CC) $(CFLAGS) main.cpp src/*.cpp gui/*.cpp -o main $(SFML_FLAGS)
	./main

ui:
	$(CC) $(CFLAGS) gui/*.cpp -o gui/main $(SFML_FLAGS)
	./gui/main

demo:
	$(CC) $(CFLAGS) main.cpp src/*.cpp -o main
	./main