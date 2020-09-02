> Buna ziua. 

> In acest video va voi arata cum sa faceți macrouri cu preprocesorul, folosind comanda de preprocesor "define". 

> Pentru a folosi comanda "define", trebuie pur si simplu scris "#define", scrieți numele comenzii preprocesor, de exemplu "TOTO", si prin ce va fi înlocuita.

> Atentie, un "#define" înlocuiește exact, cuvânt cu cuvânt comanda cu ce ati scris in dreapta. 

> In afara de cateva cazuri particulare pe care le vom vedea mai târziu, pentru ca putem face macrouri inteligente. 

> Deci, de exemplu, vreau ca "TOTO" sa fie înlocuit cu "int". 

> Deci cum voi scrie "TOTO" undeva (aici de exemplu am scris 'TOTO"), in momentul precompilarii ("cpp main.c”), "TOTO" a fost înlocuit cu un "int".

> Pot scrie absolut orice, de exemplu... chiar orice. 

> In faza de precompilare, deci in faza de preprocesor, nu gândește ce face, ia doar macroul meu si il va inlocui in mod exact. 

> Asta e bine pentru ca putem sa facem macrouri de genul asta, care ne vor permite de exemplu sa facem ca in loc de "int" sa punem "TOTO", puteti sa va amuzați sa faceți asta. 

> Sau puteti pune un text, sa zicem, un exemplu simplu, ne putem amuza sa punem "Bonjour bienvenue", 

> si unde veți scrie "TOTO" va fi înlocuit cu stringul "Bonjour bienvenue", cu ghilimele. 

> Inseamna ca aici, daca scriu asta (trebuie sa repun nnt" aici), daca pun un "char *str", si apoi voi pune ca "str = TOTO;", uitati ce va rezulta: 'str = "Bonjour bienvenue";'. 

> Deci puteti scrie fraze la începutul fișierelor voastre, sau chiar sa le puneți intr-un ".h", si sa folosiți aceeași fraza in mai multe funcții, si asa cel puțin aveți un macrou, si puteti sa-l schimbați intr-un singur loc, ceea ce-l va schimba peste tot.

> E cam același principiu cu prototipurile de funcții din ".h". 

> Celalalt avantaj al macrourilor, puteti de asemenea sa le folosiți sa faceți macrouri mai inteligente, punând paranteze, si dandu-le parametri.

> Sunt parametri care vor fi inlocuiti pur si simplu; deci de exemplu ii dau un parametru "x", si de fiecare data când voi scrie "TOTO" cu ceva intre paranteze, il voi inlocui cu un "int x;". 

> Acum veți vedea ce rezulta. 

> Nu va sfătuiesc sa faceți asta, pentru ca codul va deveni foarte repede ilizibil. 

> Dar e una dintre utilizările "#define". 

> Voi declara o variabila "a", chiar si fara punct si virgula. 

> O variabila "b". 

> Si iata ce da acum când fac "cpp main.c": "int a;", "int b;". 

> După cum vedeți codul e mult mai puțin lizibil. 

> Deci nu va sfătuiesc sa faceți lucruri de genul asta. 

> "#define" va permite de asemenea sa faceți uniuni intre stringuri. 

> Atentie, asta e ceva mai complicat. 

> E ultimul exemplu pe care vi-l voi arata. 

> Puteti scrie de exemplu "#x", si "#x" înseamnă ca va înlocui "TOTO" cu parametru intre paranteze, prin valoarea care e in 'TOTO". 

> Deci, de exemplu, daca aici pun un "char *str". 


> Si apoi voi pune "str" egal cu (repun acum, si-l scot din macrou), deci "str" egal cu asta... 
> daca acum fac un "write(1, str, 1);”, in mod logic voi afișa pe ecran "a".

> Daca acum ma voi amuza sa schimb asta cu "b", voi putea afișa "b". 

> Acum un ultim exemplu ca sa fie foarte clar, aici as scrie "bonjour Ies aminches",


