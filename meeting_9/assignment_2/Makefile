# Variables
CXX = g++
CXXFLAGS = -Wall 
TARGET =  your_code_name # compile file name ex: file
SRC =  your_code_name.cpp # source c++ code ex: file.cpp

# Default target: compile the program
all: $(TARGET)

# Compile the fibonacci.cpp
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Run the program in test mode (using test.txt)
test: $(TARGET)
	./$(TARGET) test

run: $(TARGET)
	 ./$(TARGET)

# Clean up the compiled files
clean:
	rm -f $(TARGET)

# Phony targets to avoid conflicts
.PHONY: all clean test