> Buna ziua.

> Astazi vom vorbi despre manipularea sirurilor de caractere. 

> Vom vedea care este scopul lor si cum se utilizeaza. 

> Ce este un sir de caractere? 

> Un sir de caractere este un tablou de valori de tip char. 

> Ati studiat in zilele precedente despre tablouri. Sunt pur si simplu tablouri de tip char. 

> Sa declaram tabloul nostru. 

> Scriem o functie "main". 

> Tipul este "char", apoi "str1[J", deci semantica unui tablou. 

> li asignam o valoare, "Hello". 

> In mod concret, in dreapta aveam o reprezentare completa a memoriei. 
  
> Cum e stocat in memoriei sirul de caractere? 

> Avem pe pozitia 00 caracterul "H", pe pozitia 01 caracterul "e" samd. 

> ne permite sa terminam un sir de caractere cu un caracter special "\0". 

> Veti vedea foarte curand utilitatea sa. 

> Gata cu teoria, sa trecem la partea practica. 

> ft_putstr" pe care trebuia sa o realizati pentru zilele precedente. Eu v-o ofer cadou. 

> sirul de caractere sî vo
> :char" pentru a aranja putin

> Sa incepem cu functia "ft_putchar" care ar trebui sa fie destul de simpla pentru voi. 

> Ar trebui sa puteti folosi functia "write" fara dificultate. 

> Nu vom intra in detalii. 

> Deci "write" de 1, cu adresa lui "c".... 

> Sa trecem la partea importanta, functia "ft_putstr". 

> Functia "ft_putstr" primeste ca parametru un sir de caractere pe care il vom manipula. 

> Ce face functia "ft_putstr"? 

> Functia itereaza dupa fiecare element din sir pentru a-l afisa. 

> Cum face sa il afiseze? Apeleaza functia "ft_putchar". 

> In mod concret, vom avea o bucla si o conditie de terminare. 

> La fiecare iteratie, apelam "ft_putchar"... 

> cu sirul nostru de caractere. 

> Daca avem o bucla avem si un index. 

> Vom initializa indexul cu valoarea 0. 

> Vom utiliza indexul pentru a parcurge sirul de caractere. 

> Incrementam indexul "i". 

> Ajunge la problema stabilirii conditiei de terminare. 

> Cum putem stii ca un sir de caractere se termina? 

> Aici, conventia ca "\0" are rol de terminator de sir de caractere ne salveaza viata. 

> Ne vom opri in momentul in care ajungem la primul caracter "\0". 

> Pur si simplu. 

> Sa vedem rezultatul... 

> gcc test.c. Apoi a.out. Si "Hello"! 

> Sirul de caractere este afisat, avem si returul la linie "\n". 

> Vom aborda problema manipularii sirurilor de caractere. 

> Am vazut cum parcurgem sirul de caractere, acum vom schimba o valoare din sirul de caractere. 

> Vom inlocui primul caracter cu "y". 

> Vom implmenta functia "replace_first_h_with_y". 

> Functia nu este foarte utila, dar veti realiza functii mult mai utile in cadrul exercitiilor de astazi. 

> Cum accesam prima pozitie din tablou? 

> str[O] = 'y'; 

> Sa analizam ce vom avea in memorie. Vom inlocui "H", prima casuta din tablou, cu "y". 

> Acesta e rezultatul pe care-l asteptam. 

> Sa apelam functia noastra "replace_first_h_with_y(str1)". 

> Vom adauga cateve apeluri cu scop de debug pentru a vedea ca inlocuirea se face corect. 

> "Hello"... "yello". Perfect! 

> Vom realiza o ultima functie care primeste ca parametri 2 siruri de caractere. 

> Primul va fi sursa, al doilea va fi destinatia. 

> Vom face o copie a primului caracter din sursa in destinatie. 

> Voi incepe prin a declara un al doilea sir de caractere "str2", cu valoarea "Yellow". 

> Elimin functia precedenta. 

> void replace_first_char(char *src, char *dest). 

> Concret... Readuc memoria la starea dinainte. 

> Avem un al doilea sir de caractere aici. 

> Si caracterul "\0". 

> Vom copia caracterul "H" (primul caracter din sir) in al doilea sir de caractere. 

> Cum accesam primul caracter? Cu "src[O]". 

> "dest", tot in primul caracter: dest[O] = src[O]. 

> Apelam functia scrisa: replace_firsț_char(str1, str2). 

> Afisam str1, apoi str2. 

> "Hello", "Hello", "Hello". 

> Adaugam elemente de debug pentru a vedea "str2" inainte de manipulare. 

> Deci am manipulat sirul de caractere. 

> Aceasta schimbare nu se face doar pe primele caracterele din siruri, bineinteles. 

> Putem sa o facem pe prima, iar aici pe a doua. 

> Depinde doar de ce vrem sa facem. 

> Sper ca acest curs de manipulare a sirurilor de caractere va va permite sa intelegeti mai clar, si sa realizati exercitiile de astazi care necesita, in mare, scrierea de bucle si conditii adecvate. 

> Sper ca sirurile de caractere sunt o notiune mai clara pentru voi. Multumesc.