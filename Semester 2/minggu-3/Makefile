# Variables
CXX = g++
CXXFLAGS = -Wall 
TARGET_BST = bst 
SRC_BST = bst.cpp 
TARGET_STACK = stack 
SRC_STACK = stack.cpp 
TARGET_QUEUE = queue 
SRC_QUEUE = queue.cpp

# Default target: compile the program
all: $(TARGET_BST)
	$(TARGET_STACK)
	$(TARGET_QUEUE)

# Compile the fibonacci.cpp
$(TARGET_BST): $(SRC_BST)
	$(CXX) $(CXXFLAGS) -o $(TARGET_BST) $(SRC_BST)
$(TARGET_STACK): $(SRC_STACK)
	$(CXX) $(CXXFLAGS) -o $(TARGET_STACK) $(SRC_STACK)
$(TARGET_QUEUE): $(SRC_QUEUE)
	$(CXX) $(CXXFLAGS) -o $(TARGET_QUEUE) $(SRC_QUEUE)

# Run script
run_stack: $(TARGET_STACK)
			./$(TARGET_STACK)
run_queue: $(TARGET_QUEUE)
			./$(TARGET_QUEUE)
run_bst: $(TARGET_BST)
			./$(TARGET_BST)

# Clean up the compiled files
clean_stack:
	rm -f $(TARGET_STACK)
clean_bst:
	rm -f $(TARGET_BST)
clean_queue:
	rm -f $(TARGET_QUEUE)

# Phony targets to avoid conflicts
.PHONY: all clean test