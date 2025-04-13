# Compilator și flag-uri
CC = g++
CFLAGS = -Wall -Werror -Wextra -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Surse și directoare
SRC_DIRS = src gui
SRC_FILES = main.cpp $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Executabil
TARGET = main

# Regula implicită
all: $(TARGET)

# Linkarea obiectelor într-un executabil
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Regula pentru a compila fișiere .cpp în .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Curățare fișiere temporare
clean:
	rm -f $(OBJ_FILES) $(TARGET)

# Rulare (opțional)
run: all
	./$(TARGET)
rebuild: clean all