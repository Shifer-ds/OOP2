#include "manolibas.h"

float vidurkis(vector<float> paz)
{
    /** Apskaiciuoja pazymiu vidurki
     *
     *
     */

    float vid = 0;
    float suma = 0;
    for(float i: paz){
        suma = suma + i;
    }
    vid = suma/paz.size();
    return vid;
}
float median(vector<float> paz)
{
    /** Apskaiciuoja pavymiu mediana
     */

    float mediana = 0;
    int nd = paz.size();
    sort(paz.begin(), paz.end());
    if (nd % 2 != 0)
    {
        mediana = (float)paz[nd / 2];
    }
    else
    {
        mediana = (float)((paz[(nd - 1) / 2] + paz[nd / 2])) / 2.0;
    };
    return mediana;
}

void spausdinimas(studentas stud)
{
    /** Studento duomenu spausdinimo funkcija
     */
    cout << stud.vardas
         << std::setw(20) << stud.pav;
    cout << std::setw(20) << std::fixed <<
         setprecision(2) << stud.gal << endl;
}



int int_imimas()
{
     /** int imimo funkcija, su patikrinimu
     */
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
    /** pazymiu skaiciaus imimo funkcija, su patikrinimu
     */
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
     /** int reiksmes 0 arba 1 imimo funkcija skirta meniu pasirinkimui, su patikrinimu
     */
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
    /** pazymiu imimo funkcija, su patikrinimu
     */
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
     /** string (vardo ir pavardes) imimo funkcija, su patikrinimu
     */
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
     /** visos grupes spausdinimo funkcija
     */
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


studentas sukurimas()
{
     /** studento sukurimo su vartotojo ivestimis funkcija
     */
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
