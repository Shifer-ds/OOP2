#include "manolibas.h"
#include "failufunkcijoslibas.h"

int main()
{
    int atlikti_testa = 0;

    cout << "ar atlikti testa? (ne - 0, taip - 1)";
    atlikti_testa = menu_pasirinkimas();
    if(atlikti_testa = 1){
            gentyrimas();
    }
    else{
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
    }
};
