#include "check_sortic.h"

long long itc_str_to_int(string str)
{
    long long number = 0, i = 0;
    int ch = 0;
    while(str[i] != '\0')
    {
        ch = str[i] - 48;
        number = number * 10 + ch;
        i++;
    }
    return number;
}

void pause(string str, vector <int> &a, vector <int> &b, HANDLE &Console)
{
    int i = 0;
    int j = 0;
    string ch = "";
    string ewq = "";
    while(str[i] != '!')
    {
        while (str[j] != ' '){
            ch += str[j];
            j++;
        }
        j++;
        a.push_back(itc_str_to_int(ch));
        ch = "";
        i = j;
    }
    i += 2;
    j += 2;
    while(str[i] != '*')
    {
        while (str[j] != ' ' && str[j] != '*')
        {
            ewq += str[j];
            j++;
        }
    i = j;
    j++;
    runner(ewq, a, b, Console);
    ewq = "";
    }
}

string Issortic(vector <int> &a)
{
    string message = "OK";
    for(int i = 1; i < a.size(); i++)
    {
        if(a[i] < a[i - 1])
            message = "KO";
    }
    return message;
}

void print_mass(vector <int> &mass)
{
    for (int i = 0; i < mass.size(); i++)
        cout << mass[i] << " ";
    cout << endl;
}

void runner(string str, vector <int> &a, vector <int> &b, HANDLE &Console)
{
    if (str == "sa")
        sa(a);
    else if (str == "sb")
        sb(b);
    else if (str == "pa")
        pa(a, b);
    else if (str == "pb")
        pb(b, a);
    else if (str == "ra")
        ra(a);
    else if (str == "rb")
        rb(b);
    else if (str == "rr")
        rr(a, b);
    else if (str == "rra")
        rra(a);
    else if (str == "rrb")
        rrb(b);
    else if (str == "rrr")
        rrr(a, b);
    SetConsoleTextAttribute(Console, FOREGROUND_GREEN); // green
    cout << str << endl;
    SetConsoleTextAttribute(Console, 15); // green
    cout << "Vector a: ";
    print_mass(a);
    cout << "Vector b: ";
    print_mass(b);
}
