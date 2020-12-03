## Paleidimas
Paskutinės versijos paleidimas:
1. Parsisiųsti naujausios versijos failus
2. Sukompiliuoti pasinaudojus CMakeLists.txt
3. Paleisti programą
## Instrukcijos
- Paleidžiama programa
- Norint paleisti vector ir list testavimą "1" enter. [v0.5]
- Norint paleisti strategijų analizę "0" enter tada "1" enter. [v1.0]
- Norint paleisti ankstesnių versijų operacijas "0" enter tada "0" enter: 
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
<br />
Failo su 1000 duomenimis sukurimas truko: 15 Milisekundes<br />
Failo su 1000 duomenimis nuskaitymas i VECTOR truko: 15 Milisekundes<br />
Failo su 1000 duomenimis nuskaitymas i LIST   truko: 0 Milisekundes<br />
Failo su 1000 duomenimis isskaidymas i VECTOR grupes truko: 0 Milisekundes<br />
Failo su 1000 duomenimis isskaidymas i LIST   grupes truko: 0 Milisekundes<br />
Failo su 1000 duomenimis grupiu perasymas truko: 15 Milisekundes<br />
<br />
Failo su 1000 pilnas apdorojimas su VECTOR truko: 62 Milisekundes<br />
Failo su 1000 pilnas apdorojimas su LIST   truko: 46 Milisekundes<br />
<br />
Failo su 10000 duomenimis sukurimas truko: 15 Milisekundes<br />
Failo su 10000 duomenimis nuskaitymas i VECTOR truko: 49 Milisekundes<br />
Failo su 10000 duomenimis nuskaitymas i LIST   truko: 31 Milisekundes<br />
Failo su 10000 duomenimis isskaidymas i VECTOR grupes truko: 0 Milisekundes<br />
Failo su 10000 duomenimis isskaidymas i LIST   grupes truko: 15 Milisekundes<br />
Failo su 10000 duomenimis grupiu perasymas truko: 78 Milisekundes<br />
<br />
Failo su 10000 pilnas apdorojimas su VECTOR truko: 142 Milisekundes<br />
Failo su 10000 pilnas apdorojimas su LIST   truko: 140 Milisekundes<br />
<br />
Failo su 100000 duomenimis sukurimas truko: 211 Milisekundes<br />
Failo su 100000 duomenimis nuskaitymas i VECTOR truko: 361 Milisekundes<br />
Failo su 100000 duomenimis nuskaitymas i LIST   truko: 358 Milisekundes<br />
Failo su 100000 duomenimis isskaidymas i VECTOR grupes truko: 124 Milisekundes<br />
Failo su 100000 duomenimis isskaidymas i LIST   grupes truko: 111 Milisekundes<br />
Failo su 100000 duomenimis grupiu perasymas truko: 739 Milisekundes<br />
<br />
Failo su 100000 pilnas apdorojimas su VECTOR truko: 1438 Milisekundes<br />
Failo su 100000 pilnas apdorojimas su LIST   truko: 1422 Milisekundes<br />
<br />
Failo su 1000000 duomenimis sukurimas truko: 2376 Milisekundes<br />
Failo su 1000000 duomenimis nuskaitymas i VECTOR truko: 4214 Milisekundes<br />
Failo su 1000000 duomenimis nuskaitymas i LIST   truko: 3830 Milisekundes<br />
Failo su 1000000 duomenimis isskaidymas i VECTOR grupes truko: 1310 Milisekundes<br />
Failo su 1000000 duomenimis isskaidymas i LIST   grupes truko: 1116 Milisekundes<br />
Failo su 1000000 duomenimis grupiu perasymas truko: 6445 Milisekundes<br />
<br />
Failo su 1000000 pilnas apdorojimas su VECTOR truko: 14347 Milisekundes<br />
Failo su 1000000 pilnas apdorojimas su LIST   truko: 13768 Milisekundes<br />
<br />
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
<br />
Duomenys sugeneruoti. Atliekama 1 strategijos analize su 1000 vnt.:<br />
<br />
Failo su 1000 duomenimis isskaidymas i VECTOR grupes truko: 0 Milisekundes<br />
Failo su 1000 duomenimis isskaidymas i LIST   grupes truko: 0 Milisekundes<br />
<br />
                      Atliekama 2 strategijos analize su 1000 vnt.:<br />
<br />
Failo su 1000 duomenimis isskaidymas i VECTOR grupes truko: 1 Milisekundes<br />
Failo su 1000 duomenimis isskaidymas i LIST   grupes truko: 0 Milisekundes<br />
<br />
Duomenys sugeneruoti. Atliekama 1 strategijos analize su 10000 vnt.:<br />
<br />
Failo su 10000 duomenimis isskaidymas i VECTOR grupes truko: 1 Milisekundes<br />
Failo su 10000 duomenimis isskaidymas i LIST   grupes truko: 3 Milisekundes<br />
<br />
                      Atliekama 2 strategijos analize su 10000 vnt.:<br />
<br />
Failo su 10000 duomenimis isskaidymas i VECTOR grupes truko: 1 Milisekundes<br />
Failo su 10000 duomenimis isskaidymas i LIST   grupes truko: 2 Milisekundes<br />
<br />
Duomenys sugeneruoti. Atliekama 1 strategijos analize su 100000 vnt.:<br />
<br />
Failo su 100000 duomenimis isskaidymas i VECTOR grupes truko: 31 Milisekundes<br />
Failo su 100000 duomenimis isskaidymas i LIST   grupes truko: 27 Milisekundes<br />
<br />
                      Atliekama 2 strategijos analize su 100000 vnt.:<br />
<br />
Failo su 100000 duomenimis isskaidymas i VECTOR grupes truko: 29 Milisekundes<br />
Failo su 100000 duomenimis isskaidymas i LIST   grupes truko: 33 Milisekundes<br />
<br />
Duomenys sugeneruoti. Atliekama 1 strategijos analize su 1000000 vnt.:<br />
<br />
Failo su 1000000 duomenimis isskaidymas i VECTOR grupes truko: 296 Milisekundes<br />
Failo su 1000000 duomenimis isskaidymas i LIST   grupes truko: 334 Milisekundes<br />
<br />
                      Atliekama 2 strategijos analize su 1000000 vnt.:<br />
<br />
Failo su 1000000 duomenimis isskaidymas i VECTOR grupes truko: 227 Milisekundes<br />
Failo su 1000000 duomenimis isskaidymas i LIST   grupes truko: 340 Milisekundes<br />
<br />
Duomenys sugeneruoti. Atliekama 1 strategijos analize su 10000000 vnt.:<br />
<br />
Failo su 10000000 duomenimis isskaidymas i VECTOR grupes truko: 10713 Milisekundes<br />
Failo su 10000000 duomenimis isskaidymas i LIST   grupes truko: 11260 Milisekundes<br />
<br />
                      Atliekama 2 strategijos analize su 10000000 vnt.:<br />
<br />
Failo su 10000000 duomenimis isskaidymas i VECTOR grupes truko: 10012 Milisekundes<br />
Failo su 10000000 duomenimis isskaidymas i LIST   grupes truko: 19718 Milisekundes<br />
<br />
