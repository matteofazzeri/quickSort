#include "apa.h"
#include <chrono>

vector<int> APA(const string fileName) {
    vector<int> nComp;
    vector<int> vec;
    readFile(vec, fileName);

    random_shuffle(vec);    // shuffle the vector in a random way

    for(int  i = 0; i < MAX_REPETITIONS; i++) { 
        nComp.push_back(0);
        LVquicksort(vec, 0, vec.size() - 1, nComp[i]);
    }
    
    return nComp;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    createFile(argv[1]);
    
    createFileFromVec("results.txt", APA(argv[1]));
    return 0;
}