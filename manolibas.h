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
    float paz[11], vid, med, egz, gal;
};

float vidurkis(vector<float> paz);
float median(vector<float> paz);

class Studentoclase
        {
            //Galutinis pagal vidurki
            private:
            string vardas;
            string pav;
            vector<float> paz;
            float egz;
            float vid;
            float med;
            float gal;
            public:
        Studentoclase(string vardas, string pav, vector<float> paz, float egz)
        {
            this->vardas = vardas;
            this->pav = pav;
            this->paz = paz;
            this->egz = egz;
            this->vid = vidurkis(paz);
            this->med = median(paz);
            this->gal = vid*0.4 + 0.6*egz;
        }
        string getVardas()
        {
            return vardas;
        }
        string getPavarde()
        {
            return pav;
        }

        float getGal()
        {
            return gal;
        }
        float getPaz(int i)
        {
            return paz[i];
        }

        void spausdinimas(studentas stud)
        {
        cout << vardas
            << std::setw(20) << pav;
        cout << std::setw(20) << std::fixed <<
            setprecision(2) << getGal() << endl;
        }
        bool getPalyginimas(Studentoclase stud2)
        {
            return vardas < stud2.getVardas();
        }

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
