# Variables
CXX = g++
CXXFLAGS = -Wall
TARGET = string_matching
SRC = string_matching.cpp

# Default target: compile the program
all: $(TARGET)
	
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	  ./$(TARGET)

clean:
	rm -f $(TARGET)

# Phony targets to avoid conflicts
.PHONY: all clean test