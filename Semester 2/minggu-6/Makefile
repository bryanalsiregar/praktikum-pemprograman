# Variables
CXX = g++
CXXFLAGS = -Wall
TARGET_DSF_BSF = dsf_bsf
SRC_DSF_BSF = dsf_bsf.cpp
TARGET_SHORTEST_PATH = mst_shortest_path
SRC_SHORTEST_PATH = mst_shortest_path.cpp

# Default target: compile the program
all: $(TARGET_DSF_BSF)
	 $(TARGET_SHORTEST_PATH)
	
$(TARGET_DSF_BSF): $(SRC_DSF_BSF)
	$(CXX) $(CXXFLAGS) -o $(TARGET_DSF_BSF) $(SRC_DSF_BSF)
$(TARGET_SHORTEST_PATH): $(SRC_SHORTEST_PATH)
	$(CXX) $(CXXFLAGS) -o $(TARGET_SHORTEST_PATH) $(SRC_SHORTEST_PATH)



run_dsf_bsf: $(TARGET_DSF_BSF)
	  ./$(TARGET_DSF_BSF)

run_mst_shortest_path: $(TARGET_SHORTEST_PATH)
			./$(TARGET_SHORTEST_PATH)

# Clean up the compiled files
clean_dsf_bsf:
	rm -f $(TARGET_DSF_BSF)
clean_mst_shortest_path:
	rm -f $(TARGET_SHORTEST_PATH)

clean_all:
	rm -f $(TARGET_DSF_BSF)
	rm -f $(TARGET_SHORTEST_PATH)

# Phony targets to avoid conflicts
.PHONY: all clean test