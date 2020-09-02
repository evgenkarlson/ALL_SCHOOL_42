> In acest al doilea video va voi spune cum rezolvam problema constata in primul, echilibrarea arborilor binari.

> Ca sa va reamintesc, am văzut ca un arbore de genul asta nu e foarte bun, cred ca va dati seama de ce, si ca am prefera sa avem ceva de genul asta, care e mult mai echilibrat. 

> Vizual mai urat, dar mai echilibrat. 

> Vedem ca el are doi fii, el la fel, etc., si ca avem aproape același număr de elemente de fiecare parte. 

> Deci timpul de cautare va fi intotdeauna optim, ceea ce voiam sa obținem la inceput. 

> Singurele defecte al acestui arbore sunt ca pe de o parte va veți bate capul sa-l echilibrați, 

> si pe de alta parte va fi puțin mai lent la inserare si ștergere.

> Pentru a echilibra arborii vom utiliza ceva ce se numește arbore roșu si negru. 

> Sa vedem cum arata in C. Arata asa. 

> Deci avem in plus o enumerare care definește "culoarea" nodului, negru sau roșu. 

> Si apoi structura e aceeași, doar cu câmpul "culoare" in plus. 

> Exista un avantaj in a avea aceeași structura, fac o paranteza ca sa va explic, 

> si anume faptul ca ii pot spune compilatorului ca asta de fapt e o structura "s_btree". 

> Si el va spune, "ok, nici o problema, ti-l fac", 

> si veți putea folosi toate funcțiile de parcurgere pe care le-ati codat pentru arborii binari simpli, ceea ce va fi foarte util. 

> Va va evita faptul de a rescrie o gramada de cod când de fapt codul e exact același, si structura e aproape aceeași. 

> Se numește polimorfism, intr-o forma destul de primara in C, am putea face mult mai multe lucruri cu asta, dar le veți descoperi singuri.

> Deci de ce roșu si negru? Va voi face putina teorie. 

> Arborii roșu si negru au mai multe proprietăți. 

> Prima e ca nodul părinte (rădăcină), e negru. 

> A doua e ca toate frunzele, chiar si cele nule, sunt negre, de aceeași culoare cu rădăcină. 

> Exista o a treia proprietate, care zice ca un nod roșu nu are decât fii negri. 

> Sau sunt ambii nuli, sau unul e un nod adevarat si negru, sau ambii adevarati si negri, intelegeti ideea. 

> Ultima proprietate, cea mai interesanta, e ca de la orice nod din arbore, numărul de noduri negre parcurse intre el si una dintre frunze e același pentru toate frunzele acestui nod.

> Deci arborele e echilibrat. 

> E cam complicat sa înțelegeți asa, dar... 

> Deci, inserarea: va vom cere sa faceți asta, si va vom cere sa faceți si ștergerea. 

> Va voi arata doar un caz de inserare, apoi puteti sa cautati pe net, pentru ca Internetul cred ca explica mult mai bine ca mine, si puteti sa vedeți si scheme, ceva mai bine decât ce am făcut eu aici. 

> Va voi arata un caz simplu de inserare care va face sa intervină cele doua operații pe care le veți folosi.

> Pe de o parte, recolorarea unui nod, si pe de alta parte, rotirea arborelui sau a unui nod din arbore. 

> Va voi da un exemplu, veți intelege mai bine. 

> Pentru a însera intr-un arbore roșu si negru, începem printr-o înserare ca intr-un arbore binar clasic, prin dihotomie. 

> Va explic ce am pus in schema. 

> G = "grandparent" (bunic al nodului), P = "parent", U = "uncie", N = nodul pe care l-am inserat. 

> Vedeți culorile intre paranteze: "black" sau "red". 

> Deci după ce am făcut inserarea de baza, imaginati-va ca vom avea un arbore care arata asa. 

> Sa luam nodul care e aici, care e roșu (toate nodurile sunt inițial roșii). 

> Acest arbore nu respecta una dintre proprietățile arborilor roșu si negru, 

> si anume faptul ca acest "P", care e roșu, ar fi trebuit sa aiba doi fii negri. 

> Si de fapt are doar unul, cel care e nul. Celalalt e roșu. 

> Acum vom face ceva destul de complicat, din cauza ca unchiul e negru, si tatal roșu. 

> Vom face ceva pentru a-l echilibra, e un caz special, si sunt vreo 4-5 asa. 

> Vom roti arborele. Vom face o rotire spre dreapta, in jurul lui "G". 

> Daca va uitati mai jos, acesta e rezultatul rotirii. 

> "G" e in locul lui "U", cu "U" sub el (pentru ca ramane un arbore binar), si "P" e deasupra lui "G". 

> Daca va gândiți bine va veți da seama ca de fapt, daca fac asta cu arborele de intregi de la inceput, e inca valid, si tot putem sa-l parcurgem in adâncime si va fi tot sortat. 

> Pentru ca pana la urma, "G">"P", deci putem sa-l punem sub "P", in dreapta. 

> ’G">"P", deci putem sa-l punem sub "P", in dreapta. 

> Acum ne găsim in cazul acesta. 

> Deocamdată încălcăm o alta regula a arborilor roșu si negru, e ca părintele e roșu, si nu negru.

> Vom face o schimbare de culoare, intre "P" si "G", si va da asta: "P", care acum e rădăcină arborelui, devine negru, si "G" devine roșu. 

> Si acum avem un arbore binar echilibrat. 

> Sa stiti ca nu e singurul caz de inserare, sunt vreo 4 sau 5 cred, le veți vedea singuri.

> Si de fiecare data când faceți ceva de genul asta, trebuie sa va uitati in mod recursiv in abore, sa vedeți daca nu ati creat alte probleme.

> Poate faptul ca acest nod e negru sau roșu, orice culoare ar fi, va incalca alta proprietate mai sus in arbore, si va mai necesita niște schimbări.

> In mod normal rezolvam problema cu maxim 2 rotatii si 2-3 recolorari in cel mai rau caz. 

> Nu va voi arata restul cazurilor, le veți găsi singuri, si la fel si pentru ștergere. 

> Ce va voi arata pentru a termina acest video, e sa va dau doua-trei sfaturi. 

> Primul: programați o funcție care va afiseaza arborele. 

> Deci primul element, următoarele doua, etc. 

> Va sfătuiesc sa afișați si nodurile nule, si sa le depliati, va fi mai lizibil. 

> Aceasta va va permite sa va debugati funcțiile, sa vedeți daca inserarea merge corect pentru primele exerciții, si sa vedeți daca arborele e echilibrat pentru ultimele doua. 

> E destul de interesant, ia ceva timp sa programați funcția, dar e foarte utila când o aveți. 

> Al doilea sfat, e sa cititi cu atentie tot ce vedeți pe net, pentru ca arborii binari sunt foarte folosiți, multa lume ii utilizează, sunt foarte multe explicații chiar mai clare ca ale mele, si in care puteti găsi ceva mai mult. 

> O zi buna.