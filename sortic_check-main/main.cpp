#include"check_sortic.h"

int main()
{
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Console, FOREGROUND_INTENSITY);
    string str, mass;
    ifstream file("test.txt");
        vector <int> a;
        vector <int> b;
        getline(file, str);
        pause(str, a, b, Console);
        mass = Issortic(a);
        if(mass == "OK")
        {
             SetConsoleTextAttribute(Console, FOREGROUND_GREEN ); // green
             cout << mass << endl;
        }
        else if(mass == "KO")
        {
             SetConsoleTextAttribute(Console, FOREGROUND_RED ); // white
             cout << mass << endl;
        }
        SetConsoleTextAttribute(Console, 15 ); // white
    return 0;
}
