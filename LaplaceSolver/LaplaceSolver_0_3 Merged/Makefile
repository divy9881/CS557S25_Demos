CXX = g++
CXXFLAGS = -Wall -O3 -std=c++11 -fopenmp
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
IMAGES = $(wildcard *.pgm)
EXECUTABLE = laplace_solver

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(IMAGES)

clean-images:
	rm -f $(IMAGES)