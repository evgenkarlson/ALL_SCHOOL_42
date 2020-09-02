> Stiti sa declarați si sa utilizați un pointer la funcție intr-un program. 

> Dar poate va întrebați la ce ar putea folosi. 

> Pentru ca avand deja posibilitatea de a apela funcțiile intr-un mod standard, de ce ne-am complica sa folosim o o sintaxa dificila pentru a le putea apela folosind un pointer la funcție? 

> Este o întrebare buna, si o soluție pe care evident puteti sa o folosiți. 

> Trebuie retinutca exista cazuri particulare in care pointerii la funcții ajuta mult, si in plus cresc lizibilitatea si mentenabilitatea codului. 

> Va propun sa vedem impreuna un astfel de exemplu in care pointerii la funcții sunt o soluție buna. 

> Am ales sa va prezint acest exemplu in pseudocod si nu in C, pentru ca daca v-as fi aratat direct codul in C, ati fi avut o soluție pentru rezolvarea exercitiilor si nu acesta e scopul meu. 

> Ceea ce veți vedea este o sintaxa care nu exista, pe care am inventat-o pentru nevoile acestui exercițiu, doar pentru a va putea arata conceptele pointerilor la funcții. 

> Va trebui sa transcrieti singuri acest exemplu in C pentru a-l putea utiliza. 

> Exemplul pe care vi-l propun este sa va imaginați situația in care deținem trei funcții care ne permit sa scriem niște informații arbitrare, fie intr-un fișier cu funcția "put_file", fie in rețea cu funcția "put_network". 

> Presupunem ca avem aceste funcții implementate si ca funcționează corect. 

> Scopul nostru este sa scriem o funcție "put" care va avea doi parametri. 

> Primul parametru, numit "where", ne va permite sa știm la ce ieșire vom afișa ("stdout", fișier sau rețea). 

> Al doilea parametru, numit "what", reprezintă informația de afișat. 

> Nu e important sa știm tipul informațiilor, doar trebuie sa știm ca exista. 

> O strategie naiva ar fi sa scriem un cod ca cel de mai jos: daca "where == STDOUT" atunci apelez funcția "put_stdout" cu parametrul "what", altfel, daca "where == FILE" atunci scriu intr-un fișier, etc. 

> Problema este ca de fiecare data când voi dori sa adaug o destinație (de ex. vreau sa am o funcție "put_stderr" care sa scrie la ieșirea de eroare) va trebui sa scriu o instrucțiune "else if'. 

> ce numim in jargon "o pădure de instrucțiuni if' si este inacceptabil sa avem asa ceva in cod. 

> O soluție eficace va fi sa folosim un pointer la funcții pentru a apela funcția corecta. 

> Sa vedem ce avem: 
> Avem trei funcții ("put_stdout", ”put_file", "put_network") care au toate același prototip. 

> Nu returneaza nimic si preiau argumentul "what" pentru a-l afișa in locația specificata de parametrul "where 

> Este posibil de a regrupa pointerii spre aceste funcții intr-un tabel si de a asocia fiecărei intrări funcția pe care o vom utiliza. 

> Pseudocodul va arata in felul următor: 

> Sa ne imaginam tabelul de pointeri la funcții, care va fi compus dintr-o lista de perechi (sau ce vreți sa faceți
> in C, e treaba voastra), 

> in care vom avea ca prim element al perechii ieșirea la care sa scriem, iar ca al doilea parametru un pointer la funcția care trebuie utilizata. 

> Aceasta structura ne va permite sa avem un cod mai simplu in funcția "put". 

> Funcția "put" va avea parametrii "where" si "what", apoi vom face o bucla ("for", "while", recursivitate etc.),  unde pentru fiecare intrare din tabel voi avea o cuplu "where" de referința si funcția "put" asociata, si vom verifica daca valoarea parametrului "where" al funcției este egala cu valoarea "where_r" corespunzătoare perechii din tabel. 

> Daca exista egalitate, apelam funcția "put_" corespunzătoare, daca nu bucla continua pana când găsim funcția corecta, sau daca nu o găsim, va trebui sa tratam un caz de eroare, dar in afara scopului acestui exercițiu. 

> Aceasta este o forma standard de programare, va veți afla uneori in acest tip de situație si va fi util sa va amintiți de pointerii la funcții. 

> Ne revedem pentru concluziile acestui curs.