#include "apa.h"
#include <chrono>
#include <math.h>

using namespace chrono;

double valoreMedio(const std::vector<int>& values) {
    long int sum = 0;

    for(int i = 0; i < values.size(); i++)
        sum += values[i];
    
    return static_cast<double>(sum) / values.size();  // Cast a double per precisione
}

double deviazioneStandardEmpirica(const std::vector<int>& values, double valoreMedio) {
    long long int sum = 0;
    
    for(int i = 0; i < values.size(); i++)
        sum += pow(values[i] - valoreMedio, 2);
        
    double varianza = static_cast<double>(sum) / (values.size() - 1);
    
    return sqrt(varianza);  // Radice quadrata della varianza per ottenere la deviazione standard
}


vector<int> APA() {
    
    vector<int> nComp;
    vector<int> vec;
    //readFile(vec, fileName);

    for(int i=0; i<ARRAY_SIZE; i++)
        vec.push_back(i);

    for(int  i = 0; i < MAX_REPETITIONS; i++) {
        random_shuffle(vec.begin(), vec.end());    // shuffle the vector in a random way
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

    //run python script to create a png with a graph of the results
    system("python3 Exported/plot.py");

    auto duration = duration_cast<seconds>(high_resolution_clock::now() - start);
    cout << (double)duration.count()/60 << endl;
    return 0;

}
