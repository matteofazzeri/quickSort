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

vector<int> APA() {
    
    vector<int> nComp;
    vector<int> vec;
    //readFile(vec, fileName);

    for(int i=0; i<ARRAY_SIZE; i++)
        vec.push_back(i);

    for(int  i = 0; i < MAX_REPETITIONS; i++) {
        random_shuffle(vec);    // shuffle the vector in a random way
        nComp.push_back(0);
        LVquicksort(vec, 0, vec.size() - 1, nComp[i]);
    }
    
    return nComp;

}

int main(int argc, char *argv[])
{
    
    if(fileExists(argv[1])) {
        cout << "The file " << argv[1] << " already exists.\n"
             << "Do you want to delete it and run again? [Y/N] ";
        char response=0;
        cin >> response;

        switch (response)
        {
        case 'Y': case 'y':
            system("make clean");
            system("clear");
            cout << "Ready for execute the program again.\n";
            cout << "Click any key to continue...\n";
            getchar();
            getchar();
            system("pause");
            system("make");
            return 0;
        break;
        case 'N': case 'n':
            return 0;
        break;
        default:
            break;
        }

    }

    srand(time(NULL));
    auto start = high_resolution_clock::now();

    vector<int> rep = APA();

    createFileFromVec(argv[1], rep);

    double Vmedio = valoreMedio(rep);
    cout << "Valore medio -> " << Vmedio << endl;
    cout << "Deviazione standard empirica -> " << standardEmpiricalDeviation(rep, Vmedio) << endl;

    system("python3 plot.py");

    auto duration = duration_cast<seconds>(high_resolution_clock::now() - start);
    cout << (double)duration.count()/60 << endl;
    return 0;

}