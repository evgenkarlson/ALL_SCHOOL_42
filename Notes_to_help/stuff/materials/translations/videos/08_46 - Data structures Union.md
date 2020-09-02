> Buna ziua. 

> In acest video va voi vorbi despre un nou cuvânt cheie, "union se aseamana cu structurile, doar ca unde structurile pun datele unele langa altele, (cum ati văzut cu structura de tip punct, cu doua "inv-uri unul langa altul) uniunile ne permit sa accesam același spațiu de memorie, dar in mai multe feluri.

> Inca o data, cel mai bun mod de a va explica asta e printr-un exemplu 

> Am o structura "test" care conține un "int i", un "char c", un "float f' si un "char tab[4]", si acum voi crea o uniune, exact la fel ca o structura.

> "union", numele plus "u", deci "u_test", cu la sfarsit, nu uitati. 

> Voi pune același lucru in interior, si veți vedea la ce e utila o uniune. 

> Deci v-am spus ca diferența intre uniune si structura e ca strutura adauga elementele unul langa altul, si uniunea ne permite sa accesam același spațiu de memorie in mai multe feluri. 

> Va voi demonstra asta. 

> Voi pune aici "sizeoF, care ne permite sa aflam marimea unui element, deci de exemplu marimea structurii "s test”. 

> O voi afișa pe ecran. 

> Si vad acum ca structura are 16 bytes. 

> Vom verifica: un "int" are 4 bytes, un "char” e un byte in plus (5), un "float" 4 bytes (9), si un "char tab[4]" 4 in plus (deci 13). 

> Nu da 16... De ce? 

> Pur si simplu pentru ca compilatorul va face o zona tampon intre "char" si "float". 

> Pentru a accesa mai repede memoria, compilatorul pune elementele la adrese care sunt multipli de 4, pentru ca procesorul e pe 32 bits, deci va accesa cate 4 bytes deodata.

> Daca am fi fost pe 64 bits, am fi accesat cate 8 bytes, si ar fi făcut o zona tampon pana la 8. 

> Va voi demonstra asta in doua secunde. 

> Daca aici pun un "char xx[3]", recompilez, si-l execut, da tot 16. 

> Daca-I deplasez si-l pun după "float" de exemplu, vom trece la 20. 

> De ce? Pentru ca mai e un tampon de 1, deci "char [3]" are doar 3 bytes si cu tamponul, 4.

> Asta e pentru structura. 

> După cum vedeți, structura are o mărime care e suma tuturor elementelor cu zonele tampon in plus. 

> Acum trecem la uniune, si veți vedea ca asta schimba tot. 

> In "sizeof' voi folosi uniunea, si acum imi afiseaza o mărime de 4. 

> De fapt ia marimea celui mai mare element. 

> Un "int" e 4, un "char" e 1, un "float" e 4, si un "char tab[4]" e 4. 

> Va voi arata acum, daca pun "tab[1OJ", vom afișa 12 (din cauza zonei tampon). 

> Revin la 4. 

> Si acum va voi arata cum se folosește. 

> Vom crea un nou obiect de tip "union", deci "union u_test a", si pun "a.i = 42". 

> De fapt vom pune mai mult decât 42, vom pune un număr mai mare, 424242. 

> Asa va fi mai clar. 

> Ideea mea deocamdată e sa afișez "a.i", care va avea ca valoare 424242 după cum vedeți. 

> Daca acum accesez variabila mea prin "tab", un "int" e 4 bytes, si in "tab[4]", fiecare "char" e o bucata din "int". 

> In mod normal daca afișez "a.tab[O]", "a.tab[1]", "a.tab[2]", "a.tab[3]", voi accesa diferite parti din "int". 

> Sa vedem. O luam de la capat... 

> Ah, da, ar trebui sa adaug ceva pentru a le separa, pentru a avea un afisaj mai clar. 

> Asa veți vedea mai bine.. 

> lata. Deci vedem 50, 121, 6 si 0. 

> Sunt cei 4 bytes care compun "int"-ul meu. (Un "int" e pe 4 bytes.) 

> Putem sa ne amuzam si sa facem calculul, folosind "bc", 50 e 50, plus 121 * 256, (pentru ca primul byte e inmultit cu 256A0, al doilea * 256A1, al treilea * 256A2, al patrulea * 256A3) 

> Deci plus 6 * 256 * 256, si in mod normal avem numărul pe care-l aveam la inceput. 

> Deci după cum ati înțeles, o uniune ne permite sa accesam același spațiu de memorie in mai multe moduri. 

> Aceasta poate avea multe utilizări, va las pe voi sa le cautati. 

> Pana atunci sper ca ziua voastra nu va fi foarte grea, am făcut turul a tot ce trebuia văzut astazi. 