> Buna ziua. 

> In acest video va voi vorbi de un nou cuvânt cheie, enumerările, "enum". 

> Enumerările sunt ceva destul de special; se folosesc pentru a pune cuvinte in loc de cifre. 

> Sunt ca si niște "int"-uri, si in general sunt folosite pentru a face liste, pentru a va putea repera in cod. 

> De exemplu daca aveți valori care au o semnificație, eroarea 1, 2, 3, una e "segmentation fault", etc., deci daca aveți nevoie sa numiți erorile. 

> In general veți utiliza o enumerare, pentru a evita sa faceți "defme"-uri unele sub altele, caz in care n-ati fi siguri ca nu aveți de doua ori același "define", cu aceeași cifra. 

> E ceva verificat in momentul compilării, si va permite chiar sa generați o serie de cifre.

> Cred ca un exemplu va valora cat o mie de explicații. 

> Sunt cam ca si structurile. 

> Pentru a declara "enum"-uri trebuie scris "enum" si după aceea numele enumerării, de exemplu "e_list". 

> Tot cu , la sfarsit, pentru ca e ceva care se întâmpla In timpul compilării, si trebuie sa definim sfârșitul instrucțiunii. 

> La fel ca si cu structurile putem scrie "enum e_list” ca sa spunem ca exista, dar nu e foarte interesant. 

> iata cum funcționează: 

> Vreau de exemplu sa definesc o valoare 1, o valoare 2 si o valoare 3, le voi numi "val" ("vaH", "val2", "val3"), cu virgula intre ele. 

> Si acum pot crea obiecte de tipul "e_list", ca si structurile. 

> Vedeți aici variabila "a" care e de tip "e_list 

> Si lui "a" ii voi putea da valoarea "val1". 

> Acesta e singurul lucru puțin urat pentru enumerări in C, si anume faptul ca dintr-o data "vall", care facea parte din enumerarea "e_list", dar acum a devenit un fel de cuvânt cheie, si "val1" are acum valoarea 0.

> "val2" are valoarea 1, si "val3" are valoarea 2. 

> In principiu valorile vor urca, plecând de la 0. 

> Ati putea de asemenea sa precizați ca "val1" are valoarea 4, aveți dreptul sa faceți asta, si apoi "val2" va avea valoarea 5, si "val3", 6. 

> Sau puteti sa precizați ca "val1" e 4, "val2" e 7, si "val3" va fi 8 in mod normal. 

> Sa verificam asta. 

> Daca aici pun val3 , si acum valoarea retumata de main (va voi arata un truc ca sa nu folosesc alta funcție) va fi "a". 

> Sa vedem daca compilează... Compilează. 

> Voi executa "a.out", si apoi voi face un "echo $?" pentru a vedea valoarea retumata de ultimul executabil, si vedem ca e 8. 

> Deci "val3” are valoarea 8. 

> Asta e cam tot ce trebuie sa stiti despre enumerări. 

> In mod normal nu puteti pune de doua ori aceeași valoare, deci daca pun "vaH = 7" si "va!2 = 7", riscati sa aveți o problema, dar nici nu sunt sigur...

> Compilatorul va lașa sa faceți asta, se pare. 

> Depinde de versiuni. Aici va lașa sa puneți ce valori vreți. 

> Avantajul e pur si simplu ca in momentul in care adaugati o variabila avanseaza cu 1 de fiecare data, acesta e adevăratul avantaj al enumerărilor. 

> Atentie, riscul enumerărilor e ca toate numele folosite aici au devenit nume utilizabile tara a avea nevoie sa puneți "e_list" inainte. 

> Deci e un risc, e un pericol, dar in unele cazuri chiar se folosesc. 

> In general când lumea folosește nume de genul asta pentru enumerări, pune inca o data numele enumerării la inceputul numelui variabilei, deci de exemplu am putea pune aici "e_list_val1". 

> Si mai departe "e_list_val2", etc. 

> Asta e tot despre enumerări. 

> Putem pune si "typedef' înainte daca vreți, dar nu are un prea mare interes, pentru ca daca ati observat, "e_list" l-am folosit o singura data pentru a defini "a", dar as fi putut pune un "int" si era același lucru.

> Atentie in schimb, daca aveți doua enumerări diferite, si incercati sa le asignati intre ele, unele opțiuni de compilare va vor da erori, ca sa indice ca sunt diferente intre cele doua enumerări. 