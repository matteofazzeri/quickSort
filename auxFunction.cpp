#include "apa.h"

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
   //function to shuffle the array elements into random positions
   srand(time(NULL));
   for (int i = v.size() - 1; i > 0; i--) {
      int j = rand()%(i + 1);
      int temp = v[i];
      v[i] = v[j];
      v[j] = temp;
   }
}