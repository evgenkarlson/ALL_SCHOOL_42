> Este bine sa înțelegem ca atunci când efectuam operații asupra unui descriptor de fișier si acesta nu a fost inchis,exista un fel de indicator de citire care pointeaza la octetul curent. 

> Vom numi offset diferența dintre octetul curent si octetul zero (deci primul). 

> lata un exemplu in care am descris cateva operații efectuate asupra unui descriptor de fișier 

> si consecințele asupra offset-ului. 

> Avem un fișier "README" ce conține 42 de octeti 

> pe care il deschidem fara vreun flag specific. 

> Descriptorul de fișier este 42, iar offsetul este la 0. 

> Vom citi din acest fișier 12 octeti, asta face ca offsetul sa devină 12. 

> Vom citi apoi 30 de octeti si ajungem la un offset egal cu 42. 

> Offset-ul este 42, dimensiunea fișierului este 42, am ajuns la finalul fișierului. 

> Vom citi 1 octet si se va returna valoarea 0 pentru ca nu mai putem avansa. 

> Cum facem daca dorim sa deplasam indicatorul de citire in alt loc din fișier? 

> Ultima funcție de sistem pe care o sa v-o arat răspunde acestei probleme. 

> Funcția se numește "Iseek" si primește 3 parametri: 

> primul parametru este descriptorul de fișier, 

> al doilea parametru este offset-ul de rezultat sau de calcul, 

> al treilea parametru este modul de calcul. 

> Va las sa va uitati in "man", sunt explicați acolo. 

> Funcția "Iseek" ne returneaza noul offset sau -1 in caz de eroare. 

> Va voi arata exemplu anterior actualizat pentru a demonstra folosirea funcției "Iseek". 

> Avem offset-ul la valoarea 42, 

> efectuam o deplasare de -40 cu funcția "Iseek" in modul "SEEK_END", 

> care presupune o deplasare plecând de la sfârșitul fișierului.

> Deci, 42-40, funcția "Iseek" va returna offset-ul 2. 

> Suntem la al doilea octet din fișier. 

> Sa vedem cum arata acestea in cod. 

> Avem programul dezvoltat anterior pentru deschiderea si citirea fișierului (cu "O_RDONLY"). 

> Voi adauga un apel "Iseek" pentru o deplasare înapoi de 10 octeti. 

> Rezultatul acestei modificări nu va fi unul foarte util pentru ca vom avea o bucla infinita, 

> dar va arata foarte bine ceea ce se intampla. 

> Compilez. 

> Avem o bucla infinita, ceea ce era de așteptat. 

> Funcția "Iseek" ar putea sa vi se para utila pentru a se poziționa la finalul fișierului, 

> insa este mai simplu de folosit funcția "open" cu flagul "O_APPEND 

> In plus, a citi date pe care le-am citit deja nu este foarte util, chiar daca asta am făcut. 

> Concluzionam aici cu noțiunile de care aveți nevoie pentru ziua de azi. 

> Va invit sa cititi in "man" despre funcțiile de sistem analizate 

> si va recomand sa verificați valorile returnate 
> in special de funcțiile sistem "open” si "read".