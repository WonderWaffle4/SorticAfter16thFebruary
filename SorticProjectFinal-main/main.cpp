#include "sortic.h"

void printArray(const vector<int> arr, ofstream &inputToFile){
    for(long long i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
        inputToFile << arr[i] << " ";
    }
    inputToFile << endl;
    cout << endl;
}

void printStep(const vector<int> &a, const vector<int> &b, HANDLE Console, string functionName, ofstream &outputToFile){
    SetConsoleTextAttribute(Console, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout << functionName << endl;
    outputToFile << functionName << endl;
    SetConsoleTextAttribute(Console, 15);
    cout << "Vector a: ";
    outputToFile << "Vector a: ";
    printArray(a, outputToFile);
    cout << "Vector b: ";
    outputToFile << "Vector b: ";
    printArray(b, outputToFile);
    outputToFile << endl;
    cout << endl;
}

void optionYes(bool &WantToRead, vector<int> &a, HANDLE &Console){
    string line;
    WantToRead = true;
    cout << "Enter name of the file to read from: ";
    cin >> line;
    ifstream inputFromFile;
    line = filePath(line);
    inputFromFile.open(line);
    while(!inputFromFile){
        cout << "There is no such file!" << endl << "Try again: " << endl;
        cin >> line;
        inputFromFile.open(filePath(line));
    }
    readFromFile(inputFromFile, a);
    SetConsoleTextAttribute(Console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "File found!" << endl;
}

void optionNo(ofstream &outputToFile, vector<int> &a){
    string line;
    cin >> line;
    outputToFile << line << endl;
    while(line != "!"){
        a.push_back(itc_toInt(line));
        cin >> line;
        outputToFile << line << endl;
    }
}
//SWAP
//sa(sb) swap first 2 of a(b)
//ss

//PUT TO A, PUT TO B
//pa(a, b) delete first of b and put it to a
//pb(b, a)

//ra(a), rb(b) shift elements of a vector to the one right
//rr
//rra(a), rrb(b) shift element of a vector to the one left
//rrr
int main(){
    int numberOfIterations = 0;
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Console, 15 | FOREGROUND_INTENSITY);
    bool WantToRead = false;
    string line;
    vector<int> a, b;
    cout << "Do you want to read from file? Type \"yes\" if you do and something else if you don't: ";
    cin >> line;
    if(line == "yes")
        optionYes(WantToRead, a, Console);
    else{
        SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "You've chosen not to read from file" << endl << endl;
    }
    SetConsoleTextAttribute(Console, 15);
    line = outputFileName();
    ofstream outputToFile(filePath(line));
    if(!WantToRead)
        optionNo(outputToFile, a);
    cout << "Start: ";
    outputToFile << "Start: ";
    printArray(a, outputToFile);
    outputToFile << endl;
    cout << endl;
    sorter(a, b, Console, outputToFile, numberOfIterations);
}
