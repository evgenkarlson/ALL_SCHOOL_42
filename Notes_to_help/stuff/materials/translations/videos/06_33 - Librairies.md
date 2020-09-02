> In aceasta prima parte vom discuta despre biblioteci. 

> Am pregatit doua fisiere: "ft_putchar.c" si "ft_putstr.c", pe care cred ca le cunoaste deja toata lumea. 

> Poate ca nu am rescris exact aceeasi sintaxa, insa cred ca veti intelege codul. Oricum nu asta e scopul. 

> Voi reveni la crearea unui program de baza. 

> Stificâaaca veăî^a afisez *bonjour les gens", voi scrie o functie "main" care apeleaza functia "ft_putstr" deja implementata. 
> Compilez... 

> Compilatorul returneaza eroare pentru ca nu gaseste functia "ft_putstr". Deci nu poate face ce-i cer. 

> Adaug in apelul de compilare fisierul "ft_putstr.c". 

> Compilatorul returneaza eroare pentru ca acum nu gaseste functia "ft_putchar", folosita in "ft_putstr". 

> Adaug in apelul de compilare fisierul "ft_putchar.c". Reusesc, in sfarsit, sa compilez si sa afisez mesajul pe ecran. 

> Pentru a crea biblioteci va trebui sa compilam functiile pe care le vom include. 

> Insa, daca vreau sa compilez doar "ft_putstr", imi va spune nu doar ca nu gaseste "ft_putchar", 

> dar si ca pentru a crea un executabil are nevoie de o functie "main", asa cum am vazut si in primele zile ale piscinei. 

> Totusi, am nevoie sa pun functia "ft_putstr" in biblioteca, dar fara a avea o functie "main". 

> Pentru asta "gcc" are optiunea "-c". 

> Folositi "man" pentru detalii, dar remarcati deja ca "gcc -c" a creat un fisier ".o", deci "ft_putstr.o". 

> Acesta este un obiect, un fisier in limbaj masina, de neinteles pentru noi, doar calculatorul stie sa-l citeasca 

> Si in plus pentru a face ceva cu el, trebuie si un "main". 

> Vom avea nevoie de acest fisier pentru a crea o librarie. 

> Va puteti imagina ca, daca un program este un perete, atunci fisierul ".o" este o caramida, o caramida gata facuta, putand fi folosita la zidirea mai multor pereti, cu sensul ca o data facuta caramida, nu trebuie sa o mai refaceti, puteti sa o folositi peste tot. 

> Compilatorul "gcc" stie exact cum sa faca asta, ar putea folosi fisierul ".o" asa. 

> Voi crea fisierele obiect "*.o" si voi crea fisierul binar executabil "a.out" pornind de la fisierele obiect. 

> Daca fac asta, functioneaza foarte bine, imi creaza un fisier binar care functioneaza. "gcc" stie sa faca totul. 

> Compilatorul stie sa asambleze caramizile ".o" si sa returneze fisierul executabil "a.out". 

> Nu vom avea nevoie de fisierul "main", ci doar de o biblioteca care contine "ft_putstr" si "ft_putchar". 

> Deci prima etapa: crearea de ".o". 

> O data ce avem fisierele ”.o", vom folosi un program numit "ar" cu optiunile (nu va voi spune ce face, veti cauta singuri folosind "man") 

> Primul argument dupa "rc" este numele bibliotecii voastre.

> Ex. libstr.a; numele incepe obligatoriu cu "lib...", 

> va voi spune mai tarziu de ce. 

> Apoi numele efectiv al bibliotecii ("str”), si ”.a" care semnifica faptul ca este o biblioteca statica. 

> Exista si biblioteci dinamice, dar nu intra in obiectivul cursului. 

> Deci "libstar.a", numele bibliotecii, apoi numele fisierelor care contin functiile pe care vreau sa le includ in biblioteca (deci cele doua ".o"). 

> Programul "ar" s-a executat si am obtinut fisierul "libstr.a" cu cele doua functii. 

> Cum il folosim in continuare? 

> Vom folosi programul "main.c" si ii voi spune compilatorului ca biblioteca pe care vreau sa o folosesc se gaseste in directorul curent. 

> Cu optiunea "-L." specific prin punct sa caute in directorul curent. 

> Numele bibliotecii este indicat de "-Istr" (amintiti-va de conventia de nume "lib..."). "-Istr" va indica "gcc"-ului ca am nevoie de "libstr.a". 

> Aceasta functioneaza in acelasi fel ca si cand as fi compilat fisierele ".c". 

> Avantajul este ca fisierul "libstr.a" poate fi stocat in oricare director al sistemului de fisiere. cu bibliotecile gata facute. 

> O biblioteca ne permite sa nu refacem de fiecare data functii pe care le-am implementat deja, ci sa plecam cu bibliotecile gata facute. 

> Acesta este un pas inainte, am vazut ca programul "ar" ne ajuta sa construim biblioteca. 

> De la un moment dat, veti crea un numar mare de functii pe care le veti include in biblioteca voastra. 

> Apelul utilizat anterior pentru compilare

> gcc main.c -L. -Istr 

> va functiona fara probleme, nu striga la voi deocamdata. 

> Dar daca, spre exemplu, veti avea 3000 de functii (sau chiar mult inainte), 

> si ati avea nevoie de "ft_putstr" care e pe la jumatatea bibliotecii, 

> sompilatorul va trebui sa parcurga jumatate de biblioteca pentru a gasi functia cautata si a crea fisierul binar. 

> Nu va folosi toata biblioteca pentru a se servi de "ft_putstr". 

> Aceasta operatiune este costisitoare, si cand veti avea programe complexe care utilizeaza biblioteci, 

> si compilatorul va trebui sa caute in toate bibliotecile unde sunt functiile voastre, "gcc" va lucra mult timp. 

> Exista un program numit "ranlib" care primeste ca parametru numele bibliotecii voastre si care construieste un index. 

> Acest index ii va permite compilatorului sa gaseasca mai rapid functia cautata. 

> De exemplu, acest index ar putea avea forma:
> pozitia 1: ft_putstr()
> pozitia 2: ft_putchar()
> s.a.m.d. 

> Indexarea permite optimizarea timpului de compilare si este foarte eficace atunci cand avem un numar mare 

> Invatati sa folositi de acum acest bun obicei de indexare, pentru a evita mai incolo surprizele neplacute. 

> Si functioneaza in acelasi fel. Aceasta a fost lectia despre biblioteci.