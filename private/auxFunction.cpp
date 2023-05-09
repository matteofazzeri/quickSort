#include "apa.h"
#include <unistd.h>


void swap(int& a, int& b) {
    int temp = a;
    a=b;
    b=temp;
}

void printVec(vector<int> v) {
   vector<int>::iterator iter = v.begin();

   for(iter; iter < v.end(); iter++)
      cout << *iter << endl;

}

//function to shuffle the array elements into random positions
void random_shuffle(vector<int>& v) {
   int size = v.size()-1;
   //function to shuffle the array elements into random positions
   srand(time(NULL));
   for (int i = size; i >= 0; i--) {
      int j = rand()%(size);
      int temp = v[i];
      v[i] = v[j];
      v[j] = temp;
   }
}


bool fileExists(const char *fileName) {
   std::ifstream infile(fileName);
   return infile.good();
}