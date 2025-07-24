CXX = g++
CXXFLAGS = -std=c++23 -pthread -Wall -Wextra
TARGET = bin/main
SRC = src/main.cpp src/threadspractice.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f bin/$(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
