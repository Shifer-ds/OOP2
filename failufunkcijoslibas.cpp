#include "failufunkcijoslibas.h"

bool palyginti_studentu_vardus(studentas stud1, studentas stud2)
{
    return stud1.vardas < stud2.vardas;
}

vector<studentas> isrikiuoti_vektoriu_pagal_vardus(vector<studentas>  studentai)
{
    sort(studentai.begin(), studentai.end(), palyginti_studentu_vardus);
    return studentai;
}

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

void generavimas(int kiekis){
    auto t1 = std::chrono::high_resolution_clock::now();
    ofstream myfile;
    int n = kiekis; // n turi buti kiekis
    myfile.open ("example" + std::to_string(kiekis) + ".txt");
    myfile << "     Vardas       Pavarde        ND1      ND2      ND3      ND4      ND5      EGZ \n";
    for (int i = 0; i < n; i++){
        myfile << std::setw(12) << "Vardas"+ std::to_string(i+1);
        myfile << std::setw(16) << "Pavarde"+ std::to_string(i+1);
        for (int i = 0; i < 6; i ++){ myfile<< std::setw(9) << rand() % 10 + 1;};
        myfile << "\n";
    }
    myfile.close();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis sukurimas truko: "
                << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
                << " Milisekundes\n";

    auto t12 = std::chrono::high_resolution_clock::now();//nuo cia
    ifstream duomenys;
    vector<studentas> studentai;
    try
    {
        duomenys.open("example" + std::to_string(kiekis) + ".txt");
        string dummyLine;
        string temp;
        cout << dummyLine;
        while (!duomenys.eof())
        {
            getline(duomenys, dummyLine);
            studentas st;
            duomenys >> st.vardas >> st.pav;
            st.vid = 0;
            for (int i = 0; i < 5; i++)
            {
                duomenys >> temp;
                if ((cin.good() == false) or !(stoi(temp) <= 10 && 1 <= stoi(temp)))
                {
                    throw 1;
                }
                st.paz[i]=stoi(temp);
                st.vid += st.paz[i];
            }
            st.vid = st.vid/5;
            duomenys >> temp;
            if ((cin.good() == false) or !(stoi(temp) <= 10 && 1 <= stoi(temp)))
            {
                throw 1;
            }
            st.egz = stoi(temp);
            st.gal = 0.4 * st.vid + 0.6 * st.egz;
            studentai.push_back(st);
        }
        duomenys.close();
    }
    catch (...)
    {
        cout << "Netinkamas failas" << endl;
        exit(1);
    }
    auto t22 = std::chrono::high_resolution_clock::now();
    std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis nuskaitymas truko: "
                << std::chrono::duration_cast<std::chrono::milliseconds>(t22-t12).count()
                << " Milisekundes\n";//iki cia

    auto t13 = std::chrono::high_resolution_clock::now();//nuo cia
    vector<studentas> kietekai;
    vector<studentas> nelaimeliai;
    float penki = 5;
    for(studentas i : studentai){
        if((i.gal) >= penki){
            kietekai.push_back(i);
        }
        else{
            nelaimeliai.push_back(i);
        }
        }
    auto t23 = std::chrono::high_resolution_clock::now();
    std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis isskaidymas i grupes truko: "
                << std::chrono::duration_cast<std::chrono::milliseconds>(t23-t13).count()
                << " Milisekundes\n";//iki cia

    auto t14 = std::chrono::high_resolution_clock::now();//nuo cia
    ofstream myfile1;
    myfile1.open ("kietekai" + std::to_string(kiekis) + ".txt");
    myfile1 << "kietiVardas       Pavarde        ND1      ND2      ND3      ND4      ND5      EGZ      GAL \n";
    for (studentas i : kietekai){
        myfile1 << std::setw(12) << i.vardas;
        myfile1 << std::setw(16) << i.pav;
        for (int ia=0; ia<5; ia++){ myfile1<< std::setw(9) << std::fixed << setprecision(2) <<  i.paz[ia];};
         myfile1<< std::setw(9) << std::fixed << setprecision(2) << i.egz;
        myfile1<< std::setw(9) << std::fixed << setprecision(2) << i.gal;
        myfile1 << "\n";
    }
    myfile1.close();

    ofstream myfile2;
    myfile2.open ("nelaimeliai" + std::to_string(kiekis) + ".txt");
    myfile2 << "nelaiVardas       Pavarde        ND1      ND2      ND3      ND4      ND5      EGZ      GAL \n";
    for (studentas i : nelaimeliai){
        myfile2 << std::setw(12) << i.vardas;
        myfile2 << std::setw(16) << i.pav;
        for (int ia=0; ia<5; ia++){ myfile2<< std::setw(9) << std::fixed << setprecision(2) <<  i.paz[ia];};
        myfile2<< std::setw(9) << std::fixed << setprecision(2) << i.egz;
        myfile2<< std::setw(9) << std::fixed << setprecision(2) << i.gal;
        myfile2 << "\n";
    }
    myfile2.close();
    auto t24 = std::chrono::high_resolution_clock::now();
    std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis grupiu perasymas truko: "
                << std::chrono::duration_cast<std::chrono::milliseconds>(t24-t14).count()
                << " Milisekundes\n";//iki cia

}

void gentyrimas(){
    vector<int> tyrimumatmenys = {1000, 10000, 100000, 1000000, 10000000};
    for (int i : tyrimumatmenys){
    auto t1 = std::chrono::high_resolution_clock::now();
    generavimas(i);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Failo su "+ std::to_string(i)+ " pilnas apdorojimas truko: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " Milisekundes\n"<<"\n";}
}


