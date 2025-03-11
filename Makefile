CC = g++
CFLAGS = -Wall -Werror -Wextra -L.
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-widgets

all:
	$(CC) $(CFLAGS) main.cpp client.cpp carte.cpp -o main
	./main

ui:
	$(CC) $(CFLAGS) gui.cpp -o gui $(SFML_FLAGS)