#include "apa.h"

// aux function to read from single stream
void readFromStream(vector<int>& v, istream& str) {
    string line;

    getline(str, line);
    istringstream instream;            // uso una variabile di tipo istringstream per poter scandire i pezzi di ogni riga usando >>
    instream.clear();
    instream.str(line);
    
    string first;
    instream >> first;   
    v.push_back(stoi(first));
    
    getline(str, line);                // poi si iniziano a scansionare le righe seguenti
    instream.clear();
    instream.str(line);

    while (!str.eof())  
    {        
        instream >> first;
        v.push_back(stoi(first));
    
        /*while (!instream.eof())
        {
            instream >> childLabel;
            instream >> conditionChild;
            if(limbExists(childLabel, t))
            {
                adjust_label(childLabel);
                //adjust_label(conditionChild);
                cout << childLabel << " -> " << conditionChild << "\t\t"<<endl;
                e = tree::addElemInTree(fatherLabel, childLabel, conditionChild, t);
                if(e != tree::err0) return tree::createEmptyTree();
            }
            else    cout << "\n\n[--già presente--]\n\n";
        }*/
        
        getline(str, line); 
        instream.clear();
        instream.str(line);
    }
    str.clear();
}

// function called first time to read the file
void readFile(vector<int>& v, const string fileName) {
    ifstream ifs(fileName.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs)
    {
        cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n";
    }  
    readFromStream(v, ifs);
}

// function to create a file of 10^4 random values (one per line)
void createFile(const string fileName) {
    // Create and open a text file
    ofstream myFile(fileName);

    // Write to the file
    for(int i = 0; i <ARRAY_SIZE; i++) {
        myFile << rand()%ARRAY_SIZE+1;
        myFile << "\n";
    }

    // Close the file
    myFile.close();
}

// function to create a file of 10^4 given values (one per line)
void createFileFromVec(const string fileName, vector<int> nComp) {
    // Create and open a text file
    ofstream myFile(fileName);

    // Write to the file
    for(int i = 0; i <MAX_REPETITIONS; i++) {
        myFile << nComp[i];
        myFile << "\n";
    }
        

    // Close the file
    myFile.close();
}


// function to edit an existing file
void editFile(const string fileName);