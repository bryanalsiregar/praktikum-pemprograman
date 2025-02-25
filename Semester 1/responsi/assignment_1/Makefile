CXX = g++
CXXFLAGS = -Wall 
TARGET =  hitung-bilangan-ganjil-dan-genap 
SRC =  hitung-bilangan-ganjil-dan-genap.cpp 

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