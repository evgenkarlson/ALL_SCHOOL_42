> Vom vedea acum cum sa alocam memorie in mod dinamic. 

> Vom deschide un nou fișier ".c". 

> Ideea e ca vom defini un pointer, o variabila care nu are o mărime predefinita, care va conține doar adresa unei zone de memorie pe care o vom cere sistemului. 

> Deci vom declara un pointer "char *", o variabila "str" care e un pointer de tip "char *". 

> Deci definim un pointer si nu un sir de caractere de mărime fixa, si vom face sa varieze marimea șirului. 

> Pentru a o modifica vom utiliza un "#define LEN" de exemplu. 

> Si o vom face 42 de bytes deocamdată. 

> Pur si simplu vom utiliza comanda sistem "malloc" careia ii vom da marimea pe care dorim sa o alocam. 

> Apoi vom parcurge acest sir, si-l vom umple cu niște caractere. 

> Vom spune de exemplu "afiseaza caracterul 'O', adunand i mod 10". 

> Ceea ce ne va da 01234567890123... 

> Mai multe lucruri trebuie corectate aici... 

> In primul rând trebuie avut grija ce mărime trimitem la "malloc”. 

> Ideea e ca aici ii cerem un "malloc" de 42. 

> Șirul nostru vrem sa aiba 42 de caractere, deci trebuie sa ne gândim la zeroul terminal. 

> Deci adaugam +1 la marimea "malloc"-ului. 

> Apoi "malloc" asteapta o mărime in bytes. 

> Aici presupunem ca un caracter are 1 byte; pentru a fi siguri putem utiliza "sizeof'. 

> De exemplu putem face "sizeof(char)". 

> Si vom înmulți cu numărul de caractere de care avem nevoie. 

> "sizeof' ne va da marimea variabilei in bytes. 

> Daca de exemplu vreau in loc de un sir de caractere, sa am un tablou de numere întregi. 

> Putem face același lucru cu "int *str", dar inseamna ca acum trebuie sa schimbam aici punând "int". 

> Mai simplu, vom pune "*str", asa "sizeof' va lua direct tipul variabilei "str". 

> Asta ne permite doar sa schimbam tipul variabilei si sa evitam sa schimbam tipul peste tot in cod. 

> Ne vom uita acum la manualul "malloc”. 

> Pentru a evita alertele, erorile, problemele, vom include fișierul de definiții aici. 

> "stdlib.h" 

> Cum spune "man"-ul. 

> Veți observa ca prototipul "malloc” (in sinopsisul "malloc") returneaza un "void 

> ipat, deci vom face o conversie, pentru a tipa ce retumeaza "malloc" in "char 

> Avem un tip "char *" care corespunde la "str", malloc" de marimea unui caracter inmultita cu numărul de caractere,plus 1 pentru zeroul terminal pe care-l vom pune aici. 

> "i"-ul in aceste moment va avea valoarea "LEN". 

> Deci suntem la sfârșitul șirului, si-i alipim un zero terminal. 

> După ce am făcut toate astea, pur si simplu vom afișa șirul de caractere. 

> Șirul nostru de caractere se afiseaza, de la 0 la 41, pentru ca indexat de la 0, deci avem cei 42 de bytes.

> Vom adauga doar o revenire la linie pentru a face afisajul mai frumos. 

> Si de exemplu acum vom modifica marimea, punând 21 in loc de 42. 

> Recompilam, reexecutam, si șirul nostru are acum doar 21 de caractere, alocarea s-a făcut singura. 

> Nu a trebuit sa modificam nimic in cod. 

> uteam bineînțeles sa facem ceva de genul asta, dar asa alocam memoria intr-o maniera stabila si definitiva. 

> Cu metoda noastra putem utiliza memorie temporar, si apoi sa o eliberam. 

> Vom elimina afisajul, pentru ca daca nu vom avea probleme. 

> Si vom pune un sir mare de caractere, de 42 milioane de bytes. 

> Deci ne va lua 42MB in memorie. 

> Un pic mai puțin pentru ca 1M e 1024*1024. 

> Deci facem același lucru, alocam 42MB, ii umplem, doar ca nu-i afișam ca sa nu avem probleme. 

> Vom adauga doar ceva aici sa blocam programul, (ii vom da "kill" ca sa scăpăm de el)  ca sa putem verifica cu "top" memoria folosita de program. 

> Nu mai avem nevoie de "putstr". 

> Si vom lansa programul nostru in fundal, pentru a putea vedea in "top" memoria ocupata. 

> Deci e rulat in fundal, lucrează de zor in "while (1)". 

> II găsim aici in "top" si vedem ca ocupa 40MB de memorie. 

> vom lașa intenționat sa ruleze, si acum ne reintoarcem in manualul "malloc". 

> In manualul de "maîoc* gasîm un alt apel sistem, "free", care ne va permite sa eliberam memoria alocata in prealabil cu "malloc". 

> "free" ia "void *" care v-a fost transmis de către "malloc", si nu returneaza nimic. 

> Același "define". 

> Si pur si simplu inainte de "while" vom apela "free", si-i vom da "str" care e adresa returnata de "malloc" cu cateva linii înainte.

> Vom compila asta in "a.out2" si vom lansa acest "a.out2" tot in fundal. 

> Acum putem merge sa comparam in "top": primul "a.out" consuma inca cei 40MB de memorie, a.out2" a coborât la 132KB de memorie, am eliberat memoria folosita de "malloc". 

> Aceasta ne permite sa facem alocari de memorie punctuale, care vor fi de exemplu liste inlantuite, sau lucruri la care nu avem marimea la inceput deci carorar nu le putem fixa marimea direct in program, cum foarte des e cazul pentru șirurile de caractere, pentru tablouri, si pentru listele inlantuite. 

> Aceasta a fost explicația pentru "malloc".