#include "apa.h"
#include <chrono>
#include <math.h>

using namespace chrono;

double valoreMedio(vector<int> values) {
    
    long int sum = 0;
    
    for(int i = 0; i < MAX_REPETITIONS; i++)
        sum += values[i];
    
    return sum / MAX_REPETITIONS;
}

double standardEmpiricalDeviation(vector<int> values, double mediumValue) {
    
    long int sum = 0;
    
    for(int i = 0; i < MAX_REPETITIONS; i++)
        sum += pow(values[i]-mediumValue, 2);
    return sum / (MAX_REPETITIONS-1);

}

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
    auto start = high_resolution_clock::now();
    
    if(!fileExists(argv[1]))
        createFile(argv[1]);
    
    vector<int> rep = APA(argv[1]);

    createFileFromVec("results.txt", rep);

    double Vmedio = valoreMedio(rep);
    cout << "Valore medio -> " << Vmedio << endl;
    cout << "Deviazione standard empirica" << standardEmpiricalDeviation(rep, Vmedio) << endl;

    auto duration = duration_cast<seconds>(high_resolution_clock::now() - start);
    cout << duration.count()/60 << endl;
    return 0;

}