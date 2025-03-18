# Variables
CXX = g++
CXXFLAGS = -Wall 
TARGET = avl
SRC = avl.cpp
TARGET_TUGAS = avl_tugas
SRC_TUGAS = avl_tugas.cpp

# Default target: compile the program
all: $(TARGET)
	 $(TARGET_TUGAS)
	
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)
$(TARGET_TUGAS): $(SRC_TUGAS)
	$(CXX) $(CXXFLAGS) -o $(TARGET_TUGAS) $(SRC_TUGAS)



run: $(TARGET)
	  ./$(TARGET)

run_tugas: $(TARGET_TUGAS)
			./$(TARGET_TUGAS)

# Clean up the compiled files
clean:
	rm -f $(TARGET)
clean_tugas:
	rm -f $(TARGET_TUGAS)

clean_all:
	rm -f $(TARGET)
	rm -f $(TARGET_TUGAS)

# Phony targets to avoid conflicts
.PHONY: all clean test