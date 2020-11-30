#include "manolibas.cpp"
#include "failufunkcijoslibas.cpp"

int main()
{
    int atlikti_testa;

    cout << "ar atlikti testa? (ne - 0, taip - 1)";
    atlikti_testa = menu_pasirinkimas();
    if(atlikti_testa == 1){
        gentyrimas();
    }
    else{
    int optimizacijos = 0;
    cout << "atlikti optimizavimo strategiju tyrima? (ne - 0, taip - 1)";
    optimizacijos = menu_pasirinkimas();
    if(optimizacijos == 1){
        optimizavimoTyrimas();
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
        auto* grupe = new studentas[n];
        for (int i = 0; i < n; i++)
        {
            grupe[i] = sukurimas();
        };
        //spausdinimas
        spausdintiviska(grupe, n);
        delete[] grupe;
        }
    }
    }
};
