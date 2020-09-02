> In acest video va voi explica cum sa folosiți arborii binari in varianta lor cea mai simpla. 

> Ce e un arbore binar? 

> E pur si simplu o structura de date care permite stocarea si organizarea elementelor de orice tip, ca si o lista inlantuita. 

> Doar ca in lista inlantuita un element avea doar un element următor, aici va avea doua, dreapta (right) si stanga (left). 

> Va voi arata printr-o schema cum arata un arbore. 

> lata, asa arata un arbore, foarte frumos. 

> Vedeți ca e organizat destul de ciudat. 

> Cum e aranjat? 

> E ușor: pentru fiecare nod (de exemplu acesta), 

> veți avea in stanga toate elementele care sunt mai mici, 

> si la dreapta toate care sunt mai mari sau egale. 

> Daca iau O, e mai mic ca 2, si e in stanga. 

> Si daca iau acest 1, e mai mic decât 2-ul de-aici, dar mai mare sau egal cu 1 -ul de aici, deci e bine plasat. 

> Deci asa se aranjeaza. 

> La ce folosesc arborii binari fata de o lista, care e utilitatea lor? 

> Cautarea in arbori e mult mai rapida. 

> De exemplu daca refac aceeași lista, sortata sa zicem. 

> Deci am aceleași elemente, sortate. 

> Daca vreau sa fac o cautare înăuntru, sa zicem ca vreau sa caut 4 (cel mai rau caz). 

> Va trebui sa fac: 1,2, 3, 4, 5, 6 parcurgeri, deci 6 salturi pentru a ajunge pana la 4. 

> Pe când aici fac: 1,2, 3, deci de doua ori mai puțin. 

> Ne permite sa mergem mult mai repede, si va va fi util daca stocati un număr mare de date. 

> De exemplu e ceea ce fac bazele de date pentru a stoca multe elemente împreuna, 

> folosesc printre altele si arbori binari. 

> Al doilea caz de folosire al arborilor binari e in unii parseri, 

> veți vedea mai târziu ce inseamna asta, va las sa va informați singuri, nu e obiectivul acestui curs. 

> Ne permit de asemenea sa ordonam token-uri, sau alte lucruri. 

> Cum arata in C un arbore binar? 

> Arata asa. 

> Aici e forma ceva mai complicata a arborelui binar, știind ca avem si un părinte. 

> Avem pur si simplu o structura "s_btree", care e un nod din arbore, 

> cu un părinte (cam echivalentul precedentului dintr-o lista dublu inlantuita), 

> si după cum v-am spus mai devreme, doi fii, "right" si "left". 

> Si valoarea ("data"), pentru ca nu facem nimic daca nu avem si ceva date in structura de "date". 

> Cum parcurgem un arbore? Ati văzut ca e aranjat intr-un mod ciudat. 

> Exista o anumita tehnica, de fapt exista mai multe, in funcție de ceea ce vreți sa faceți. 

> Va mai arat o data schema. 

> Primul mod de parcurgere e in profunzime, 

> si vom scoate elemente sortate in primul caz, știind ca sunt diferite variante. 

> Cea mai clasica dintre parcurgeri e: parcurg ce e in dreapta, apoi pe mine, apoi ce e in stanga. 

> De fapt invers: stanga, eu, dreapta. 

> Daca iau acest arbore, încep aici la primul nod din arbore, 

> e in stanga, încă o data la stanga, aici nu am nici stanga nici dreapta, deci ma afișez pe mine

> însumi, 0. 

> Ma afiș: 1, merg in dreapta, 1, urc si ma afișez, 2, 

> merg in dreapta, 3 (pentru ca nu are un fiu in stanga), si ma reintorc la dreapta si citesc 4. 

> Vedem ca daca parcurgem arborele in modul asta (numit parcurs infix), il recuperam ordonat. 

> Mai exista si parcursul prefix, care e cam la fel, 

> doar ca afișam intai nodul curent: deci 2, 1,0, 1, 3, 4. 

> Si parcursul postfix, in care nodul se afiseaza după fii. Nu vi le arat pe toate. 

> Al doilea tip de parcurs, in lățime, 

> inseamna ca vom afișa nodul curent, apoi fii, apoi fii fiilor, pe nivel. 

> Deci: 2, apoi 1, 3, apoi 0, 1, 4. 

> E un parcurs puțin diferit, ceva mai complicat de implementat in C. 

> Deci in cazul parcursului in profunzime folosim un DFS (cautati sa vedeți ce inseamna), 

> iar in lățime, BFS (cautati si asta daca sunteti curioși). 

> Asa se parcurge un arbore. 

> Defectul arborilor binari fata de o lista e ca inserarea e ceva mai complicata. 

> Daca vreți sa adaugati un element, e ceva mai greu. 

> Vom folosi pentru asta dihotomia. 

> Veți testa o valoare, prima la care ajungeți in arbore. 

> Deci aici veți testa daca -1 e mai mic. Da. Deci mergeți aici. 

> Testati daca -1 e mai mic. Da, deci iar mergeți aici. 

> Si aici la fel, deci puneți -1 aici. 

> -1 va fi fiul stâng al lui 0. 

> Imaginati-va ca vreți sa puneți un 1. Sau un alt 0. 

> Veți testa daca O < 2, da, veți merge pe 1, veți testa daca O < 1, da, deci mergeți aici, 

> aici e mai mare sau egal, deci il veți pune in dreapta. 

> lata, ati făcut o inserare intr-un arbore. 

> Acest tip de arbore binar nu e neaparat foarte bun in toate cazurile. 

> Sa ne imaginam ca inserez elementele intr-o anumita ordine, 

> pot sa ajung la ceva de genul asta daca inserez 10, apoi 9, 8, 7, 6. 

> Deci 10 aici, si va avea un element in stanga, dar nu si in dreapta, la fel si următorul, etc., la infinit. 

> Acum nu mai arata a arbore, e deranjant, pentru ca pierdem faptul de a-l parcurge mai repede. 

> Si in plus de asta pierdem memorie petru ca alocam doi fii când ne folosim doar de unul. 

> Deci in videoul următor va voi arata cum rezolvam problema asta.