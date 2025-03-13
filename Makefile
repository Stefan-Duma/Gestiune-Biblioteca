CC = g++
CFLAGS = -Wall -Werror -Wextra src/*.cpp
SFML_FLAGS = -Ilib/ -Llib/ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-widgets -lGL

all: app gui    

app: main.cpp
	$(CC) main.cpp $(CFLAGS) -o main
	./main

ui: ui.cpp
	$(CC) $(CFLAGS) ui.cpp -o ui $(SFML_FLAGS)
