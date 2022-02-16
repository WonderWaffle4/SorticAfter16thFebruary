#include "sortic.h"

bool checkFileName(string name){
    int length = itc_len(name);
    if(length > 32)
        return false;
    string forbiddenChars = "\\/?:*\"><|";
    for(long long i = 0; i < length; i++){
        for(int j = 0; j < 10; j++){
            if(forbiddenChars[j] == name[i]){
                cout << forbiddenChars << " <---- these symbols are forbidden!" << endl;
                return false;
            }
        }
    }
    return true;
}

string outputFileName(){
    string line;
    cout << "Input file name to output to(max 32 characters): ";
    cin >> line;
    while(!checkFileName(line)){
        cout << "Input file name to output to(max 32 characters): ";
        cin >> line;
    }
    return line;
}

void readFromFile(ifstream &inputFromFile, vector<int> &a){
    string stringOfNumbers = "";
    string bufferStringForReading;
    for(inputFromFile >> bufferStringForReading; !inputFromFile.eof(); inputFromFile >> bufferStringForReading)
        stringOfNumbers += bufferStringForReading + " ";
    bufferStringForReading = "";
    for(long long i = 0; i < itc_len(stringOfNumbers); i++){
        if(!(stringOfNumbers[i] >= '0' && stringOfNumbers[i] <= '9')){
            if(itc_len(bufferStringForReading) != 0)
                a.push_back(itc_toInt(bufferStringForReading));
            bufferStringForReading = "";
        }
        else
            bufferStringForReading += stringOfNumbers[i];
    }
    inputFromFile.close();
}

string filePath(string line){
    string path = "";
    path += line;
    path += ".txt";
    return path;
}
