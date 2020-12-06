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

vector<Studentoclase> nuskaitymasClase(int kiekis){

    ifstream duomenys;

    vector<Studentoclase> studentai;

    try
    {
        duomenys.open("example" + std::to_string(kiekis) + ".txt");
        string dummyLine;
        string temp;
        cout << dummyLine;
        while (!duomenys.eof())
        {
            getline(duomenys, dummyLine);
            string vardas;
            string pavarde;
            float egz;
            vector<float> pazymiai;
            duomenys >> vardas >> pavarde;
            for (int i = 0; i < 5; i++)
            {
                duomenys >> temp;
                if ((cin.good() == false) or !(stoi(temp) <= 10 && 1 <= stoi(temp)))
                {
                    throw 1;
                }
                pazymiai.push_back(stoi(temp));
            }
            duomenys >> temp;
            if ((cin.good() == false) or !(stoi(temp) <= 10 && 1 <= stoi(temp)))
            {
                throw 1;
            }
            egz = stoi(temp);
            Studentoclase st (vardas, pavarde, pazymiai, egz);
            studentai.push_back(st);
        }
        duomenys.close();
    }
    catch (...)
    {
        cout << "Netinkamas failas" << endl;
        exit(1);
    }
    return studentai;
};

vector<studentas> nuskaitymasStrukt(int kiekis){

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
    return studentai;
};

vector<Studentoclase> surusiavimasClase(vector<Studentoclase> studentaiC){
    vector<Studentoclase> nelaimeliaiC2;
        for(Studentoclase stud: studentaiC)
        {
            if(stud.getGal() < 5)
            {
                nelaimeliaiC2.push_back(stud);
            }

        }
        studentaiC.erase(std::remove_if(studentaiC.begin(), studentaiC.end(), [](Studentoclase stud)
        {
            return stud.getGal() < 5;
        }), studentaiC.end());
        return studentaiC;
};
vector<studentas> surusiavimasStruk(vector<studentas> studentai){
    vector<studentas> nelaimeliaiV2;
        for(studentas stud: studentai)
        {
            if(stud.gal < 5)
            {
                nelaimeliaiV2.push_back(stud);
            }

        }
        studentai.erase(std::remove_if(studentai.begin(), studentai.end(), [](studentas stud)
        {
            return stud.gal < 5;
        }), studentai.end());
    return nelaimeliaiV2;
};

void generavimas(int kiekis){
    auto visas = std::chrono::high_resolution_clock::now();

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

    auto t12vector = std::chrono::high_resolution_clock::now();
    vector<studentas> studentaiS;
    studentaiS = nuskaitymasStrukt(kiekis);
    auto t22vector = std::chrono::high_resolution_clock::now();

    auto t12list = std::chrono::high_resolution_clock::now();
    vector<Studentoclase> studentaiC;
    studentaiC = nuskaitymasClase(kiekis);
    auto t22list = std::chrono::high_resolution_clock::now();


    std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis nuskaitymas su STRUCT  truko: "
                << std::chrono::duration_cast<std::chrono::milliseconds>(t22vector-t12vector).count()
                << " Milisekundes\n";
    std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis nuskaitymas su CLASS   truko: "
                << std::chrono::duration_cast<std::chrono::milliseconds>(t22list-t12list).count()
                << " Milisekundes\n";

    auto t13List = std::chrono::high_resolution_clock::now();//nuo cia

    vector<Studentoclase> kietekai;
    kietekai = surusiavimasClase(studentaiC);

    auto t23List = std::chrono::high_resolution_clock::now();

    auto t13Vector = std::chrono::high_resolution_clock::now();

    vector<studentas> nelaimeliai;
    nelaimeliai = surusiavimasStruk(studentaiS);

    auto t23Vector = std::chrono::high_resolution_clock::now();


    std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis isskaidymas su STRUCT grupes truko: "
                << std::chrono::duration_cast<std::chrono::milliseconds>(t23Vector-t13Vector).count()
                << " Milisekundes\n";//iki cia
    std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis isskaidymas su Class  grupes truko: "
                    << std::chrono::duration_cast<std::chrono::milliseconds>(t23List-t13List).count()
                    << " Milisekundes\n";//iki cia


    auto t14 = std::chrono::high_resolution_clock::now();//nuo cia
    ofstream myfile1;
    myfile1.open ("kietekai" + std::to_string(kiekis) + ".txt");
    myfile1 << "kietiVardas       Pavarde        ND1      ND2      ND3      ND4      ND5      EGZ      GAL \n";
    for (Studentoclase i : kietekai){
        myfile1 << std::setw(12) << i.getVardas();
        myfile1 << std::setw(16) << i.getPavarde();
        for (int ia=0; ia<5; ia++){ myfile1<< std::setw(9) << std::fixed << setprecision(2) <<  i.getPaz(ia);};
         myfile1<< std::setw(9) << std::fixed << setprecision(2) << i.getGal();
        myfile1<< std::setw(9) << std::fixed << setprecision(2) << i.getGal();
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
                << " Milisekundes\n"<<"\n";//iki cia

    auto visas2 = std::chrono::high_resolution_clock::now();

    std::cout << "Failo su "+ std::to_string(kiekis)+ " pilnas apdorojimas su STRUCT truko: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(visas2-visas-(t23List-t13List)-(t22list-t12list)).count()
            << " Milisekundes\n";

    std::cout << "Failo su "+ std::to_string(kiekis)+ " pilnas apdorojimas su CLASS  truko: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(visas2-visas-(t23Vector-t13Vector)-(t22vector-t12vector)).count()
              << " Milisekundes\n"<<"\n";

}

void gentyrimas(){
    vector<int> tyrimumatmenys = {100000, 1000000};
    for (int i : tyrimumatmenys){

    generavimas(i);


};
}

/*
void optimizavimoTyrimas(){
    vector<int> tyrimumatmenys = {1000, 10000, 100000, 1000000, 10000000};
    for (int kiekis : tyrimumatmenys){

        //duomenu sugeneravims
        vector<studentas> studentaiV;
        list<studentas> studentaiL;
        vector<studentas> studentaiV2;
        list<studentas> studentaiL2;
        int nd = 10;
        for (int k = 0; k < kiekis; k++ ){
            studentas zmogus;
            for (int i = 0; i < nd; i++){
                zmogus.paz[i] = rand() % 10 + 1;
                zmogus.vid += zmogus.paz[i];
            }
            zmogus.vid = zmogus.vid / nd;
            zmogus.egz = rand() % 10 + 1;
            zmogus.gal = 0.4 * zmogus.vid + 0.6 * zmogus.egz;
            studentaiV.push_back(zmogus);
            studentaiL.push_back(zmogus);
            studentaiV2.push_back(zmogus);
            studentaiL2.push_back(zmogus);
        }



        cout << "Duomenys sugeneruoti. Atliekama 1 strategijos analize su "+std::to_string(kiekis)+" vnt.: \n \n";

        auto t13List = std::chrono::high_resolution_clock::now();//nuo cia
        list<studentas> nelaimeliaiL;
        list<studentas> kietekaiL;
        for(int i = 0 ; i < kiekis; i++)
        {
            studentas stud = studentaiL.back();
            studentaiL.pop_back();
            if(stud.egz < 5)
            {
                nelaimeliaiL.push_back(stud);
            }
            else
            {
                kietekaiL.push_back(stud);
            }
        }
        auto t23List = std::chrono::high_resolution_clock::now();

        auto t13Vector = std::chrono::high_resolution_clock::now();

        vector<studentas> kietekaiV;
        vector<studentas> nelaimeliaiV;

        for(studentas i : studentaiV){
            if((i.gal) >= 5){
                kietekaiV.push_back(i);
            }
            else{
                nelaimeliaiV.push_back(i);
            }
        }

        auto t23Vector = std::chrono::high_resolution_clock::now();


        std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis isskaidymas i VECTOR grupes truko: "
                    << std::chrono::duration_cast<std::chrono::milliseconds>(t23Vector-t13Vector).count()
                    << " Milisekundes\n";
        std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis isskaidymas i LIST   grupes truko: "
                        << std::chrono::duration_cast<std::chrono::milliseconds>(t23List-t13List).count()
                        << " Milisekundes\n \n";//iki cia

        cout << "                      Atliekama 2 strategijos analize su "+std::to_string(kiekis)+" vnt.: \n \n";


        auto t14Vector = std::chrono::high_resolution_clock::now();

        vector<studentas> nelaimeliaiV2;
        for(studentas stud: studentaiV2)
        {
            if(stud.egz < 5)
            {
                nelaimeliaiV2.push_back(stud);
            }

        }
        studentaiV2.erase(std::remove_if(studentaiV2.begin(), studentaiV2.end(), [](studentas stud)
        {
            return stud.egz < 5;
        }), studentaiV2.end());

        auto t24Vector = std::chrono::high_resolution_clock::now();


        std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis isskaidymas i VECTOR grupes truko: "
                    << std::chrono::duration_cast<std::chrono::milliseconds>(t24Vector-t14Vector).count()
                    << " Milisekundes\n";
        std::cout << "Failo su "+ std::to_string(kiekis) +" duomenimis isskaidymas i LIST   grupes truko: "
                        << std::chrono::duration_cast<std::chrono::milliseconds>(t24List-t14List).count()
                        << " Milisekundes\n \n";//iki cia

    }
*/



