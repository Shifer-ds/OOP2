#ifndef MANOLIBAS_H_INCLUDED
#define MANOLIBAS_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

using std::sort;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::ifstream;
using std::setprecision;
using namespace std;
struct studentas
{
    string vardas = "", pav = "";
    float paz[100], vid, med, egz, gal;
};

void spausdinimas(studentas stud);
int int_imimas();
int ndskaiciaus_imimas();
int menu_pasirinkimas();
float pazymiu_imimas();
string vardo_imimas();
void spausdintiviska(studentas* grupe, int n);
studentas sukurimas();
#endif // MANOLIBAS_H_INCLUDED
