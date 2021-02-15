CXXFLAGS := -m64 -DUNIX -std=c++11 -g -fno-omit-frame-pointer -O3

all: convert test

convert: criteo-to-bin.cpp
	g++ $(CXXFLAGS) -o convert criteo-to-bin.cpp

test: test-criteo.cpp
	g++ $(CXXFLAGS) -o test test-criteo.cpp
