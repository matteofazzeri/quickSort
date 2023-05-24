#include "apa.h"
#include <unistd.h>

void printVec(vector<int> v) {
   vector<int>::iterator iter = v.begin();

   for(iter; iter < v.end(); iter++)
      cout << *iter << endl;

}

bool fileExists(const char *fileName) {
   std::ifstream infile(fileName);
   return infile.good();
}