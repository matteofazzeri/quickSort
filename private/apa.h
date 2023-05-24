#ifndef APA_HINCLUDED
#define APA_HINCLUDED


#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

/********* FromFile.cpp *********/
void readFile(vector<int>&, const string);
void createFile(const string);
void createFileFromVec(const string, vector<int>);

/********* auxFunction.cpp *********/
void printVec(vector<int>);
bool fileExists(const char*);

/********* auxFunction.cpp *********/
void LVquicksort(vector<int>&, int, int, int&);
int RandomPivotPartition(vector<int>&, int, int, int&);
int Partition(vector<int>&, int, int, int&);

/********* Global Constants *********/
const int MAX_REPETITIONS = 100000;
const int ARRAY_SIZE = 10000;


#endif