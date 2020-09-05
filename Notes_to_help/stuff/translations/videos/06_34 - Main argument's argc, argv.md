> Ok, in partea a doua o sa vedem parametrii programului. 

> Stiti ca functia "Is" primeste ca parametru -"I" pentru a afisa detaliile unui director. 

> Pana acum stiti cum sa executati in mod simplu un program, dar puteti adauga parametrii in cadrul acestui apel fara sa schimbe nimic. 

> Refac rapid functia "main" din videoclipul anterior. 

> Reafisez "bonjour”. 
> Sunteti de acord ca apelurile urmatoare:
> ,/a.out
> ,/a.out toto
> ./a.out tot asdas.... 
> ..vor afisa acelasi lucru. 

> Pentru moment nu stiti cum sa cititi parametrii. 

> ’main" nu ia doar "void" sau nimic, poate sa preia doi parametri: 

> V-am prevenit ca "main" nu ia doar "void" sau nimic, poate sa preia doi parametri: 

> ca "mairT nu ia doar "voîcT sau nîmîc, poate sa preia doi parametri: int argc, char **argv. 

> Cu ajutorul lor se pot recupera parametrii transmisi programului. 

> Parametrul "argc" repezinta numarul de parametri transmisi programului. 

> Parametrul "argv" este un "char **", deci un tablou de siruri de caractere, deci va contine parametrii care urmeaza dupa numele fisierului binar in linia de comanda. 

> Daca vreau sa afisez primul parametru... 

> ft putstr(argv[O]);
> si un ’\n'. 

> Voi recompila. 

> Vad ca desi nu am dat niciun parametru imi afiseaza "a.out 

> Loading cc-tangs...done

> Explicatia este ca tabloul de siruri de caractere incepe la 0 si contine ca prim element numele fisierului binar. 

> Daca as lansa fisierul binar dintr-un alt director (de exemplu de aici), 

> voi vedea ca se afiseaza numele relativ la directorul din care execut
> /j06/a.out 

> Deci retineti ca primul parametru este numele fisierului binar, primul parametru efectiv din linia de comanda. 

> Daca vreau sa afisez primul parametru dat programului voi scrie: ft_putstr(argv[1]); 

> Doar ca daca n-am dat nici un parametru, voi avea "semgentation fault". Nu puteti citi acest element din tablou daca e vid. 

> Daca fac asta, functioneaza... La fel acum. 

> Daca fac asta, imi va afisa doar primul parametru. 

> Puteti folosi ghilimelele pentru a grupa cuvintele intr-un singur parametru. 

> Pentru a recapitula, vom spune ca valoarea implicita pentru "argc" este 1, 

> pentru ca argv[O] are tot timpul o valoare. 

> Apoi veti putea folosi "argv[1J" sa dati optiuni programului, cum face "ls" cu "-I", sau orice alt binar cu optiuni. 

> Veti putea fi mai performanti in scrierea programului pentru ca veti putea adauga conditii. 

> Veti putea spune de exemplu: daca "argc == 2" doar atunci voi afisa asta. 

> Voi putea evita ''segmentation fault" pentru ca voi putea testa daca am transmis un parametru la executie sau nu,  iar daca am pus unul, il voi putea afisa. 

> Asta e ceva util, nu veti avea nevoie sa testati existenta sirului de caractere, pentru ca cu "argc" puteti afla cati parametri aveti. 

> Puteti de asemenea afisa pe parcurs parametrii trimisi programului. 

> Parcurgand tabloul. 

> Veti putea sa spuneti:

> 'Am nevoie de un parametru"...

> ...daca nu il am, ii spun utilizatorului ca am nevoie de un numar de parametri. 

> Si ca de exemplu "a.out" ia parametrul "toto". 

> Astfel puteti informa utilizatorul cu privire la modul de utilizare a programului 

> Va permite sa faceti lucruri de genul asta. 

> Cred ca aceste doua exemple va vor ajuta sa va imaginati ansamblul de cazuri posibile, facand programul mai deschis utilizatorului, si putand sa-i indicati de ce parametri e nevoie. 

> Atentie, cum ati vazut adineauri, am avut "segmentation fault" cand nu am pus un parametru. 

> Deci apare o dificultate in plus, verificarea parametrilor pe care-i primiti de la utilizator. 

> Pana acum nu exista aceasta constrangere, voi lansati binarul pe care l-ati creat. 

> Acum ii permiteti utilizatorului sa interactioneze cu programul. 

> Si nu veti sti niciodata ce date poate sa introduca. 

> Atentie, cand vom corecta vom sti exact ce puteti face, si ce ati putea uita. 

> Va dau un sfat la final: fiti atenti si ganditi-va ca utilizatorul programului poate sa introduca date pe care nu vi le puteti imagina. 

> Testati corespunzator in cadrul programului valorile acestor parametri.