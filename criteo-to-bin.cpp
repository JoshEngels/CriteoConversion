#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
  
  // Read in raw data
  ifstream input(argv[1], ios::binary | ios::ate);
  streamsize size = input.tellg();
  input.seekg(0, ios::beg);
  char *buffer = (char *)malloc(size);
  vector<uint32_t> data(0);
  if (input.read(buffer, size)) {

    // Do parsing
    size_t bytePosition = 0;
    size_t linesRead = 0;
    while (bytePosition < size) {

      data.push_back(buffer[bytePosition] == '1' ? 1 : 0);
      bytePosition += 1;

      size_t tabCount = 0;
      size_t lastTabPosition = bytePosition;
      while (tabCount < 39 && bytePosition + 1 < size) {
        bytePosition++;
        if (buffer[bytePosition] == '\t' || buffer[bytePosition] == '\n') {
          tabCount++;
          uint32_t toAdd = 0;
          for (size_t i = lastTabPosition + 1; i < bytePosition; i++) {
            toAdd *= tabCount < 14? 10 : 16;
            if (buffer[i] >= 'a') {
              toAdd += buffer[i] - 'a' + 10;
            } else {
              toAdd += buffer[i] - '0';
            }
          }
          data.push_back(toAdd);
          lastTabPosition = bytePosition;
        }
      }

      bytePosition++;
      linesRead++;
    }
  }

  // Write data to output file, append if already there
  ofstream output(argv[2], ios::out | ios::binary | ios::app);
  output.write((char*)&data[0], data.size() * sizeof(uint32_t));
  output.close();

  input.close();
  output.close();


}
