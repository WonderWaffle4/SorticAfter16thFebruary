#ifndef SORTIC_H_INCLUDED
#define SORTIC_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

void sa(vector<int> &a);
void sb(vector<int> &b);
void ss(vector<int> &a, vector<int> &b);

void pa(vector<int> &a, vector<int> &b);
void pb(vector<int> &b, vector<int> &a);

void ra(vector<int> &a);
void rb(vector<int> &b);
void rr(vector<int> &a, vector<int> &b);

void rra(vector<int> &a);
void rrb(vector<int> &b);
void rrr(vector<int> &a, vector<int> &b);

long long itc_str_to_int(string str);
void pause(string str, vector <int> &a, vector <int> &b, HANDLE &Console);
string Issortic(vector <int> &a);
void print(vector <int> &mass);
void runner(string str, vector <int> &a, vector <int> &b, HANDLE &Console);

#endif // SORTIC_H_INCLUDED
