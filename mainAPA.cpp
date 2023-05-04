#include "apa.h"
#include <chrono>

using namespace chrono;

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
    auto start = high_resolution_clock::now();

    srand(time(NULL));
    createFile(argv[1]);
    createFileFromVec("results.txt", APA(argv[1]));
    
    auto duration = duration_cast<microseconds>(high_resolution_clock::now() - start);
    
    cout << duration.count() << endl;

    return 0;
}