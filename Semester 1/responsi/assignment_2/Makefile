CXX = g++
CXXFLAGS = -Wall 
TARGET =  temukan-bilangan-terbesar-kedua 
SRC =  temukan-bilangan-terbesar-kedua.cpp 

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

test: $(TARGET)
	./$(TARGET) test

run: $(TARGET)
	 ./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean test