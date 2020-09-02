> Buna ziua. 

> In acest video va voi arata cum sa folosiți comenzile de preprocesor 

> pentru a putea șterge sau adauga parti de cod intr-un fișier ".c" de exemplu. 

> Veți folosi asta destul de des in ".h", si voi reveni la asta in videoul următor. 

> Comenzile se numesc "if’, "ifdef', "ifndef', "endif' si "elif'. 

> Va voi arata un exemplu ca sa fie totul mai clar. 

> Am un fișier "main.c", si voi face (cum ati văzut deja comenzile "define", ne vom folosi de ele), voi face deci un "ifdef', daca am definit, deci daca exista un "#define TOTO atunci voi face niște lucruri aici, de exemplu voi... include "main"-ul.

> Daca nu, daca nu am definit "TOTO", ”main"-ul nici macar nu va aparea. 

> Deci aici, "ifdef-ul înseamnă: daca "TOTO" e definit, tot ce e intre aceste si 'Wendif' va fi adaugat in fișier. 

> Daca nu, nu va fi adaugat 

> Deci aici a fost definit "TOTO"? Nu. 

> Deci cum "TOTO" nu a fost definit, voi face un "cpp main.c”, nu mai e nimic. 

> Același lucru in sens invers, "ifndef' e versiunea inversa, adica daca "TOTO" nu exista, atunci tot ce e intre "ifndef' si "endif'-ul corespunzător ar trebui sa apara pe ecran. 

> Deci după cum vedeți de data asta "main"-ul meu a reapărut. 

> Bineînțeles putem sa asamblam aceste comenzi, de exemplu "#ifndef TITI" si după aceea putem pune un alt "endif' aici, de exemplu "#ifndef TITI" si după aceea putem pune un alt "endif' aici, si acum condiția e ca daca "TOTO" nu e definit, atunci vom afișa ce e intre "endif'-ul acesta si "ifndef', si daca "TITI" nu exista, vom afișa ce e intre acest "ifndef' si acest "endif. 

> In mod normal acum ”main"-ul ar trebui sa apara, pentru ca nu sunt definite nici 'TOTO", nici "TITI".

> Vom vedea acum ca a aparut "main"-ul. 

> Acum pentru a putea defini 'TOTO", va amintiți ca am văzut "define"-urile. 

> V-am spus ca putem sa utilizam macrouri, putem sa le folosim si doar ca sa definim "TOTO”. 

> Deci daca scriu asta, e o comanda valida. 

> Deci "TOTO" nu va fi inlocuit cu nimic, dar nu e grav, 

> pentru ca la nivel de preprocesor am definit "TOTO” ca fiind ceva care exista. 

> Deci acum, sperând ca m-ati urmărit, "ifndef' (deci daca "TOTO" nu a fost definit), si cum acum e definit, nu-mi mai apare "main"-ul. 

> Deci pe langa "ifndef' si "ifdef', mai aveți si "elif', care va va permite sa faceți "else if', dar va sfătuiesc sa le evitati si sa faceți blocuri "ifdef', "ifndef', va fi mai simplu, si cu asta in mod normal veți putea proteja fișierele ".h", si vom vedea cum in videoul următor.