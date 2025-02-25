# Variables
CXX = g++
CXXFLAGS = -Wall 
TARGET = biggest_num # compile file name ex: file
SRC = biggest_num.cpp # source c++ code ex: file.cpp

# Default target: compile the program
all: $(TARGET)

# Compile the fibonacci.cpp
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)


run: $(TARGET)
	 ./$(TARGET)

# Clean up the compiled files
clean:
	rm -f $(TARGET)

# Phony targets to avoid conflicts
.PHONY: all clean test