#include <fstream>
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int main(int argc, char **argv) {
  
  if (argc < 3) {
    clog << "Test the Criteo bin file by trying to read in some of the it." << endl;
    clog << "Usage:" << endl;
    clog << "test <file> <N>" << endl;
    clog <<"\t <file>: Location of binary file that contains criteo data (from running convert)." << endl;
    clog <<"\t <N>: Number of lines of Criteo to read in." << endl;
    return -1; 
  }

	auto start = clock();

  // Read in binary data
  ifstream input(argv[1], ios::binary | ios::ate);
  streamsize actual_size = input.tellg();
	size_t size = stol(argv[2]) * (size_t)160;
  cout << size << " " << actual_size << endl;
  input.seekg(0, ios::beg);
  char *buffer = (char *)malloc(size);
  if (input.read(buffer, size)) {
          uint32_t *data = (uint32_t *)buffer;   
  }

	auto duration = (clock() - start ) / (double) CLOCKS_PER_SEC;

  cout << "Total time: "<< duration << endl;

}