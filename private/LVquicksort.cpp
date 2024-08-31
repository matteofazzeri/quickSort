#include "apa.h"

void LVquicksort(vector<int>& v, int low, int high, int& nComp) {

    int pIndex=0;   //random pivot position
    if(v.size() <= 1)
        return;
    if(low < high) {
        pIndex = RandomPivotPartition(v, low, high, nComp);
        //cout<<pIndex<<endl;
        LVquicksort(v, low, pIndex-1, nComp);
        LVquicksort(v, pIndex+1, high, nComp);
    }
    
    //printVec(v);
}

int Partition(vector<int>& v, int start, int end, int& nComp) {
    int index=start;
    int pivot=end;

    for(int i=start; i<end; i++) {
        // finding index of pivot.
        nComp++;
        if(v[i] < v[pivot]) {
            swap(v[index], v[i]);    
            index++;
        }
    }

    swap(v[index], v[pivot]);
    return index;
}

// Function to generate a random pivot index
int RandomPivotPartition(vector<int>& v, int low, int high, int& nComp) {

    /*
      * Swap the random pivot <low + rand()%(high - low + 1)>
      * With the last one of the sub-vector
    */
    swap(v[low + rand()%(high - low + 1)], v[high]);

    return Partition(v, low, high, nComp);
}