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

struct studentas
{
    string vardas = "", pav = "";
    float paz[100], vid, med, egz, gal;
};


void spausdinimas(studentas stud)
{
    cout << stud.vardas
         << std::setw(20) << stud.pav;
    cout << std::setw(20) << std::fixed <<
         setprecision(2) << stud.gal << endl;
}



int int_imimas()
{
    int pazymys;
    cin >> pazymys;

    //Error check
    while ((cin.good() == false) or !(0 <= pazymys))
    {
        cout << "neteisinga ivestis." << '\n';

        cin.clear();
        cin.ignore(999, '\n');

        //is naujo paparaso:
        cout << "Bandykite dar karta: ";
        cin >> pazymys;
    }
    return pazymys;
};

int ndskaiciaus_imimas()
{
    int nskaicius;
    cin >> nskaicius;

    //Error check
    while ((cin.good() == false) or !(nskaicius <= 10 && 0 <= nskaicius))
    {
        cout << "neteisinga ivestis." << '\n';

        cin.clear();
        cin.ignore(999, '\n');

        //is naujo paparaso:
        cout << "Bandykite dar karta: ";
        cin >> nskaicius;
    }
    return nskaicius;
};

int menu_pasirinkimas()
{
    int pasirink;
    cin >> pasirink;

    //Error check
    while ((cin.good() == false) or !(pasirink == 1 or pasirink == 0))
    {
        cout << "neteisinga ivestis." << '\n';

        cin.clear();
        cin.ignore(999, '\n');

        //is naujo paparaso:
        cout << "Bandykite dar karta: ";
        cin >> pasirink;
    }
    return pasirink;
};

float pazymiu_imimas()
{
    float pazymys;
    cin >> pazymys;

    //Error check
    while ((cin.good() == false) or !(pazymys<=10 && 1<=pazymys) )
    {
        cout << "neteisinga ivestis." << '\n';

        cin.clear();
        cin.ignore(999, '\n');

        //is naujo paparaso:
        cout << "Bandykite dar karta: ";
        cin >> pazymys;
    }
    return pazymys;
};

string vardo_imimas()
{
    string vard;
    cin >> vard;

    //Error check
    while (cin.good() == false)
    {
        cout << "neteisinga ivestis." << '\n';

        cin.clear();
        cin.ignore(999, '\n');

        //is naujo paparaso:
        cout << "Bandykite dar karta: ";
        cin >> vard;
    }
    return vard;
}

void spausdintiviska(studentas* grupe, int n)
{
    int pasirinkimas = 0;
    //sort(grupe, grupe + n);
    cout << "Spausdinti galutini pagal vidurki(0) ar mediana(1)";
    pasirinkimas = menu_pasirinkimas();
    if (pasirinkimas == 0)
    {
        for (int i = 0; i < n; i++)
        {
            grupe[i].gal = 0.4 * grupe[i].vid + 0.6 * grupe[i].egz;
        }
        cout << "vardas         Pavarde         galutinis(vid)" << "\n";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            grupe[i].gal = 0.4 * grupe[i].med + 0.6 * grupe[i].egz;
        }
        cout << "vardas         Pavarde         galutinis(med)" << "\n";
    }
    cout << "---------------------------------------------------------" << "\n";
    for (int i = 0; i < n; i++)
    {
        spausdinimas(grupe[i]);
    };
    cout << endl;
}
/*
bool palyginimas(studentas st1, studentas st2)
{
    if(st1.vardas < st2.vardas) {return true;}
    return false;
}

vector<studentas> rusiavimas(vector<studentas>  studentai)
{
     sort(studentai.begin(), studentai.end(), palyginimas);
     return studentai;
}
*/
bool palyginti_studentu_vardus(studentas stud1, studentas stud2)
{
    return stud1.vardas < stud2.vardas;
}

vector<studentas> isrikiuoti_vektoriu_pagal_vardus(vector<studentas>  studentai)
{
    sort(studentai.begin(), studentai.end(), palyginti_studentu_vardus);
    return studentai;
}

studentas sukurimas()
{
    studentas zmogus;
    cout << "iveskite varda:   ";
    zmogus.vardas = vardo_imimas();
    cout << "iveskite pavarde: ";
    zmogus.pav = vardo_imimas();
    //paprasome pazymiu(demonstracine funkcijos vieta):
    int arrandom = 0;
    int nd = 1;
    zmogus.vid = 0;
    cout << "ar generuoti atsitiktinai?(0-ne, 1-taip)";
    arrandom = menu_pasirinkimas();
    if (arrandom == 0)
    {
        cout << "kiek ND pazymiu?: ";
        nd = ndskaiciaus_imimas();

        vector < float > pazymiai(nd);
        zmogus.vid = 0;
        for (int i = 0; i < nd; i++)
        {
            cout << "Iveskite " << i + 1 << "-aji pazymi: ";
            pazymiai.push_back(pazymiu_imimas());

            zmogus.vid += pazymiai[i];

        };
        int pasirinkimas = 0;
        cout << "ar ivesite papildoma pazymi?(0-ne, 1- taip)";
        pasirinkimas = menu_pasirinkimas();

        while (pasirinkimas == 1)
        {
            nd++;

            cout << "Iveskite " << nd << "-aji pazymi: ";
            pazymiai[nd-1] = pazymiu_imimas();

            cout << "ar ivesite papildoma pazymi?(0-ne, 1- taip)";
            pasirinkimas = menu_pasirinkimas();
        }
        for (int i = 0; i < nd; i++)
        {
            zmogus.paz[i]=pazymiai[i];
        };
        // demonstracijos pabaiga.
        cout << "Iveskite egzamino rezultata: ";
        zmogus.egz = pazymiu_imimas();
        cout << endl;
    }
    else
    {
        int nd = rand() % 10 + 1;
        for (int i = 0; i < nd; i++)
        {
            zmogus.paz[i] = rand() % 10 + 1;
            //cout << zmogus.paz[i];
            zmogus.vid += zmogus.paz[i];
        }
        zmogus.egz = rand() % 10 + 1;
    };
    //cout << zmogus.vid;
    zmogus.vid = zmogus.vid / nd;
    sort(zmogus.paz, zmogus.paz + nd);
    if (nd % 2 != 0)
    {
        zmogus.med = (float)zmogus.paz[nd / 2];
    }
    else
    {
        zmogus.med = (float)((zmogus.paz[(nd - 1) / 2] + zmogus.paz[nd / 2])) / 2.0;
    };

    return zmogus;
};

void isfailo()
{
    std::ifstream duomenys;
    vector<studentas> studentai;
    int kiek = 0;
    try
    {
        duomenys.open("studentai10000.txt");
        string dummyLine;
        string temp;
        cout << dummyLine;
        while (!duomenys.eof())
        {
            getline(duomenys, dummyLine);
            studentas st;
            duomenys >> st.vardas >> st.pav;
            for (int i = 0; i < 5; i++)
            {
                duomenys >> temp;
                if ((cin.good() == false) or !(stoi(temp) <= 10 && 1 <= stoi(temp)))
                {
                    throw 1;
                }
                st.paz[(stoi(temp))];
            }
            duomenys >> temp;
            if ((cin.good() == false) or !(stoi(temp) <= 10 && 1 <= stoi(temp)))
            {
                throw 1;
            }
            st.egz = stoi(temp);
            studentai.push_back(st);
            kiek++;
        }
        duomenys.close();
    }
    catch (...)
    {
        cout << "Netinkamas failas" << endl;
        exit(1);
    }
    studentai = isrikiuoti_vektoriu_pagal_vardus(studentai);
    studentas* grupe = new studentas[kiek];
    for (int i = 0; i < kiek; i++)
    {
        grupe[i] = studentai[i];
    };
    spausdintiviska(grupe, kiek);
};




int main()
{
    int arfailas = 0;
    cout << "imti duomenis is failo? (ne - 0, taip - 1)";
    arfailas = menu_pasirinkimas();
    if (arfailas == 1)
    {
        isfailo() ;
    }
    else
    {
        int n = 0;
        cout << "kiek studentu bus?:  ";
        n = int_imimas();
        studentas* grupe = new studentas[n];
        for (int i = 0; i < n; i++)
        {
            grupe[i] = sukurimas();
        };
        //spausdinimas
        spausdintiviska(grupe, n);
        delete[] grupe;
    }
};
