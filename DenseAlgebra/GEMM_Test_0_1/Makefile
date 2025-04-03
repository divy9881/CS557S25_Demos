CXX = g++
CXXFLAGS = -DMKL_ILP64 -m64 -I"${MKLROOT}/include" -O3 -std=c++11 -fopenmp
LDFLAGS = -m64  -Wl,--start-group ${MKLROOT}/lib/libmkl_intel_ilp64.a ${MKLROOT}/lib/libmkl_gnu_thread.a ${MKLROOT}/lib/libmkl_core.a ${MKLROOT}/lib/libmkl_blacs_openmpi_ilp64.a -Wl,--end-group -lgomp -lpthread -lm -ldl
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
IMAGES = $(wildcard *.pgm)
EXECUTABLE = gemm_test_0_1

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(IMAGES)

clean-images:
	rm -f $(IMAGES)