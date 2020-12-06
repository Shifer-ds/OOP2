## Paleidimas
Paskutinės versijos paleidimas:
1. Parsisiųsti naujausios versijos failus
2. Sukompiliuoti pasinaudojus CMakeLists.txt
3. Paleisti programą
## Instrukcijos
- Paleidžiama programa
- Norint paleisti STRUCT ir CLASS spartos testą "1" enter. [v1.1]
- Norint paleisti ankstesnių versijų operacijas "0" enter: 
- - Norint paleisti duomenų nuskaitymą iš failų reikia "studentai10000.txt", kuriame turi būti studentų duomenys(vardas, pavarde, pažymiai(5), egz. pažymys). [v0.2]
- - Norint suvesti duomenis ranka (taip pat išnaudoti atsitiktinių pažymių generavimą) "0" enter "0" enter "0" enter. Tada parašyti studentų skaičių ir kiekvienam sutekti vardą, pavardę ir pažymius. [v0.1]
## Versijų istorija

### [v0.1](https://github.com/Shifer-ds/University-work/releases/tag/0.1v) 
Užduotis sukurti programą, kuria galima suvesti studentų duomenis (vardas, pavarde, pažymiai, egz. pažymys) ir ji gražina galutinį įvertinimą kiekvienam studentui.
<br />
### [v0.2](https://github.com/Shifer-ds/University-work/releases/tag/v0.2)
Pridėta funkcija duomenų nuskaitymui.
<br />
### [v0.3](https://github.com/Shifer-ds/University-work/releases/tag/v0.3)
Užduotis patobulinti programą ją išskaidant į .cpp ir .h failus. Yra sukurti du header failai ir papildomi du .cpp failai kuriuose yra: failufunkcijoslibas.cpp - funkcijos skirtos dirbti su failais(ir susijusios funkcijos), manolibas.cpp - visos kitos funkcijos. Išimčių valdymas panaudotas faile "failufunkcijoslibas.cpp" funkcijoje "isfailo()" patikrinti ar tinkamas failas<br />
<br />
### [v0.4](https://github.com/Shifer-ds/University-work/releases/tag/v0.4) 
Užduotis sugeneruoti skirtingų duomenų dydžio failus. Juos nuskaityti. Išrušiuoti į du skirtingus failus (pagal galutinį pažymį <5 ir 5<). Be to išmatuoti šių veiksmų spartą.<br />
<br />
### [v0.5](https://github.com/Shifer-ds/University-work/releases/tag/v0.5)
Testas atliekamas su: Intel Core i5-8250U CPU @ 1.60GHz, 8GB RAM, SSD. <br />
Užduotis palyginti duomenų apdorojimo spartą, kai duomenys yra LIST ir VECTOR struktūrose:<br />

Failo su 10000000 duomenimis sukurimas truko: 21088 Milisekundes<br />
Failo su 10000000 duomenimis nuskaitymas i VECTOR truko: 58726 Milisekundes<br />
Failo su 10000000 duomenimis nuskaitymas i LIST   truko: 33773 Milisekundes<br />
Failo su 10000000 duomenimis isskaidymas i VECTOR grupes truko: 34590 Milisekundes<br />
Failo su 10000000 duomenimis isskaidymas i LIST   grupes truko: 24751 Milisekundes<br />
Failo su 10000000 duomenimis grupiu perasymas truko: 82562 Milisekundes<br />
<br />
Failo su 10000000 pilnas apdorojimas su VECTOR truko: 196966 Milisekundes<br />
Failo su 10000000 pilnas apdorojimas su LIST   truko: 162174 Milisekundes<br />
<br />
<br />
### [v1.0](https://github.com/Shifer-ds/University-work/releases/tag/v1.0) - 2 strategijų analizė.
1 strategija: sukuriami 2 masyvai(list arba vector tipo) ir į juos išskaidomi duomenys. <br />
2 strategija: sukuriamas 1 masyvas(list arba vector tipo) į kurį sudedama dalis duomenų, o pasikartojantys duomenys iš orginalaus duomenų masyvo ištrinami. <br />
Abiejų strategijų rezultas yra du masyvai su atitinkamais duomenimis.<br />
                      Atliekama 1 strategijos analize su 10000000 vnt.:<br />
<br />
Failo su 10000000 duomenimis isskaidymas i VECTOR grupes truko: 10713 Milisekundes<br />
Failo su 10000000 duomenimis isskaidymas i LIST   grupes truko: 11260 Milisekundes<br />
<br />
                      Atliekama 2 strategijos analize su 10000000 vnt.:<br />
<br />
Failo su 10000000 duomenimis isskaidymas i VECTOR grupes truko: 10012 Milisekundes<br />
Failo su 10000000 duomenimis isskaidymas i LIST   grupes truko: 19718 Milisekundes<br />
<br />
### [v1.1](https://github.com/Shifer-ds/OOP2/releases/tag/v1.1)
Užduoti palyginti Class ir Struct spartą programoje naudojant vector, kaip duomenų masyvo struktūrą ir 2 strategiją. Taip pat palyginti flag'us -01, -02, -03. <br />
nenaudojant "flag":<br />
Failo su 100000 duomenimis sukurimas truko: 202 Milisekundes<br />
Failo su 100000 duomenimis nuskaitymas su STRUCT  truko: 312 Milisekundes<br />
Failo su 100000 duomenimis nuskaitymas su CLASS   truko: 563 Milisekundes<br />
Failo su 100000 duomenimis isskaidymas su STRUCT grupes truko: 31 Milisekundes<br />
Failo su 100000 duomenimis isskaidymas su Class  grupes truko: 93 Milisekundes<br />
Failo su 100000 duomenimis grupiu perasymas truko: 672 Milisekundes<br /><br />

Failo su 100000 pilnas apdorojimas su STRUCT truko: 1219 Milisekundes<br />
Failo su 100000 pilnas apdorojimas su CLASS  truko: 1533 Milisekundes<br />
<br />
Failo su 1000000 duomenimis sukurimas truko: 2179 Milisekundes<br />
Failo su 1000000 duomenimis nuskaitymas su STRUCT  truko: 3225 Milisekundes<br />
Failo su 1000000 duomenimis nuskaitymas su CLASS   truko: 6106 Milisekundes<br />
Failo su 1000000 duomenimis isskaidymas su STRUCT grupes truko: 315 Milisekundes<br />
Failo su 1000000 duomenimis isskaidymas su Class  grupes truko: 971 Milisekundes<br />
Failo su 1000000 duomenimis grupiu perasymas truko: 6807 Milisekundes<br /><br />

Failo su 1000000 pilnas apdorojimas su STRUCT truko: 12542 Milisekundes<br />
Failo su 1000000 pilnas apdorojimas su CLASS  truko: 16079 Milisekundes<br />
<br />
F1<br />
Failo su 100000 pilnas apdorojimas su STRUCT truko: 1233 Milisekundes<br />
Failo su 100000 pilnas apdorojimas su CLASS  truko: 1556 Milisekundes<br />
<br />
Failo su 1000000 pilnas apdorojimas su STRUCT truko: 12610 Milisekundes<br />
Failo su 1000000 pilnas apdorojimas su CLASS  truko: 15966 Milisekundes<br />
<br />
F2<br />
Failo su 100000 pilnas apdorojimas su STRUCT truko: 1321 Milisekundes<br />
Failo su 100000 pilnas apdorojimas su CLASS  truko: 1644 Milisekundes<br />
<br />
Failo su 1000000 pilnas apdorojimas su STRUCT truko: 12634 Milisekundes<br />
Failo su 1000000 pilnas apdorojimas su CLASS  truko: 15980 Milisekundes<br />
<br />
F3<br />
Failo su 100000 pilnas apdorojimas su STRUCT truko: 1221 Milisekundes<br />
Failo su 100000 pilnas apdorojimas su CLASS  truko: 1532 Milisekundes<br />
<br />
Failo su 1000000 pilnas apdorojimas su STRUCT truko: 12419 Milisekundes<br />
Failo su 1000000 pilnas apdorojimas su CLASS  truko: 15917 Milisekundes<br />
<br />
Rezultate: F3 apdoroja greičiausiai. Struct struktūra greitesnė.

