# Variables
CXX = g++
CXXFLAGS = -Wall 
TARGET_BST = bst 
SRC_BST = bst.cpp 
TARGET_STACK = stack 
SRC_STACK = stack.cpp 
TARGET_QUEUE = queue 
SRC_QUEUE = queue.cpp

TARGET_TUGAS_BST = tugas_bst 
SRC_TUGAS_BST = tugas_bst.cpp 
TARGET_TUGAS_STACK = tugas_stack 
SRC_TUGAS_STACK = tugas_stack.cpp 
TARGET_TUGAS_QUEUE = tugas_queue 
SRC_TUGAS_QUEUE = tugas_queue.cpp

# Default target: compile the program
all: $(TARGET_BST)
	$(TARGET_STACK)
	$(TARGET_QUEUE)
	$(TARGET_TUGAS_BST)
	$(TARGET_TUGAS_STACK)
	$(TARGET_TUGAS_QUEUE)
	

$(TARGET_BST): $(SRC_BST)
	$(CXX) $(CXXFLAGS) -o $(TARGET_BST) $(SRC_BST)
$(TARGET_STACK): $(SRC_STACK)
	$(CXX) $(CXXFLAGS) -o $(TARGET_STACK) $(SRC_STACK)
$(TARGET_QUEUE): $(SRC_QUEUE)
	$(CXX) $(CXXFLAGS) -o $(TARGET_QUEUE) $(SRC_QUEUE)

$(TARGET_TUGAS_BST): $(SRC_TUGAS_BST)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TUGAS_BST) $(SRC_TUGAS_BST)
$(TARGET_TUGAS_STACK): $(SRC_TUGAS_STACK)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TUGAS_STACK) $(SRC_TUGAS_STACK)
$(TARGET_TUGAS_QUEUE): $(SRC_TUGAS_QUEUE)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TUGAS_QUEUE) $(SRC_TUGAS_QUEUE)

run_stack: $(TARGET_STACK)
			./$(TARGET_STACK)
run_queue: $(TARGET_QUEUE)
			./$(TARGET_QUEUE)
run_bst: $(TARGET_BST)
			./$(TARGET_BST)

run_tugas_stack: $(TARGET_TUGAS_STACK)
			./$(TARGET_TUGAS_STACK)
run_tugas_queue: $(TARGET_TUGAS_QUEUE)
			./$(TARGET_TUGAS_QUEUE)
run_tugas_bst: $(TARGET_TUGAS_BST)
			./$(TARGET_TUGAS_BST)


# Clean up the compiled files
clean_stack:
	rm -f $(TARGET_STACK)
clean_bst:
	rm -f $(TARGET_BST)
clean_queue:
	rm -f $(TARGET_QUEUE)

clean_tugas_stack:
	rm -f $(TARGET_TUGAS_STACK)
clean_tugas_bst:
	rm -f $(TARGET_TUGAS_BST)
clean_tugas_queue:
	rm -f $(TARGET_TUGAS_QUEUE)


# Phony targets to avoid conflicts
.PHONY: all clean test