# This is a simple Makefile for compiling code.cpp

# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Name of the output executable
TARGET = code

# Source files
SRCS = code.cpp

# Object files (corresponding to source files)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)
