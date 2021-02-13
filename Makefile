CXXFLAGS := -m64 -DUNIX -std=c++11 -g -fno-omit-frame-pointer -O3

convert: criteo-to-bin.cpp
	g++ $(CXXFLAGS) -o convert criteo-to-bin.cpp
