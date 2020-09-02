> Buna ziua. 

> In acest video va voi arata cum cu ajutorul preprocesorului putem proteja fișierele ”.h" contra incluziunilor multiple. 

> Deja, ce sunt incluziunile multiple de ".h"? 

> Abia ati invatat "include", si va voi arata deja ceva ce va va pune probleme. 

> Daca nu le protejați, veți avea probleme cu fișierele ".h". 

> Aici am un "main", intr-un fișier "main.c", pe care-l voi compila, care include pur si simplu un fișier "testl.h". 

> Va voi arata acest fișier "testl.h". Acest fișier conține doar Winclude "test2.h"’. 

> "test2.h", cum cred ca ati intuit, va conține un "include" de "testl.h". 

> Deci preprocesorul va încerca sa faca includerile de cate ori poate. 

> Bineînțeles va dati seama ca am făcut o bucla infinita, si ca vom avea probleme. 

> Va voi arata asta... Si vedeți, avem o problema. 

> Cum putem face sa evitam asta? 

> Pentru ca probabil uneori vreți ca un fișier sa-l includă pe altul, etc., veți vedea ca poate fi util mai târziu. 

> Deci cum vom putea proteja fișierele ".h"? 

> lata modalitatea pe care o vom aplica.

> Vom începe prin ceva care e clasic in C, "#ifndef", daca inca n-am definit macroul, (bazat pe numele fișierului ca sa nu ne batem capul, si acesta e si standardul) "_FT_", numele fișierului in majuscule (pentru ca in general macrourile le scriem cu majuscule), "_H"

> Asta vrea sa zică: daca acest macrou nu e definit, in acest caz includem asta. 

> Daca devine definit, nu-l mai includem. 

> Veți vedea, facand asta in mod normal n-ar trebui inca sa mearga, mai trebuie adaugat ceva. 

> Va trebui, o data intrat in acest "if', sa fac in asa fel incat sa nu mai intru niciodată. 

> Deci voi face in asa fel ca acest fișier ",h" sa fie inclus doar o singura data. 

> E foarte simplu: daca am intrat inauntru, e pentru ca "	FT_TEST1_H 

> Deci când intru înăuntru, il voi defini. Veți vedea: "	FT_TEST1_H	 " Si acest lucru, in mod normal, va face ca "testT' sa poate fi inclus o singura data.

> Demonstrație... Acum compilează. 

> Daca fac un "cpp main.c", iata ce se intampla. Va aminititi ca "main.c" include "testl.h". 

> Si veți vedea ca "testl.h" a inclus "test2.h" care a inclus "testl.h". Ah, nu, "testl.h" doar a inclus "test2.h". 

> De fapt "test2.h" a încercat sa includă "testl.h", dar nu era nimic in el.

> Voi incerca sa va pun ceva cod, ca sa vedeți mai clar. 

> Voi pune aici un prototip de funcție: "void pouetl(void)". 

> Asa veți vedea mai bine, va fi puțin mai clar. 

> Deci "pouetl" e in "testl", si in "test2" voi pune "pouet2". 

> Vedeți ca nu am protejat "test2", dar nu e foarte grav pentru ca din cauza ca "testT' va fi inclus o singura data, sunt asigurat acum, si n-am mai protejat "test2". 

> In mod normal, trebuie sa va protejați toate fișierele ".h", dar acum dau doar un exemplu. 

> Va voi arata ce rezulta. După cum bine vedeți, "testl" a fost inclus. 

> Prima data când am intrat in "testl", testam cu "ifndef'... si nu e definit. Continuam deci sa coboram. 

> Acum avem includerea "test2". De fapt după ce am avut "define" continuam sa coboram si includem deci "test2". 

> "test2" include "testT', reface o verificare de "	FT_TEST1_H	", si de data asta a fost definit. 

> Deci nu vom include ce este intre "ifndef' si "endif', si nu vom mai reinclude "test2".

> Revin in "test2", continui sa cobor, aici scriu linia asta, 

> ies din "test2", intru in "testl" (revin in el), scriu linia asta, si am terminat de inclus "testT' in "main". 

> Deci vedeți ca am inclus cu succes "test2" si "testT', 

> In mod normal (ca sa fim exhaustivi), ar fi trebuit sa protejam si "test2", punând, si acum ar trebui sa fie un reflex: când creați un fișier "h", trebuie sa-l protejați imediat, punând asta. 

> Daca ar fi sa dau un sfat, invatati sa faceți macrouri in "vim" sau "emacs", in asa fel incat sa va introducă condiția in mod automat. 

> Veți pierde mai puțin timp asa. 

> Fiți foarte atenti, veți vedea, o data ce definiți "test2" de exemplu, ca-l puteti folosi si mai jos in cod.

> Si asta poate fi problematic. 

> Imaginati-va ca in "main" (nu știu de ce am face asta), dar in "main", aici, voi face un "#ifndef	FT_TEST2_H	”, si daca nu e definit, voi include "main"-ul. 

> Veți vedea ca acum daca fac "cpp", "main"-ul nu mai e aici. 

> Pentru ca o data ce am definit macroul, indiferent unde, (fișierele au fost adaugate fișierului meu ".c") e definit pentru totdeauna. 

> bSi daca mai e si altceva care folosește același macrou, același "deține", "ifndef' nu va merge, si "ifdef' va merge. 

> Deci fiți foarte atenti sa puneți numele corecte, etc., daca nu, veți avea mari probleme. 

> Ati invatat acum cum sa protejați fișierele ".h" contra incluziunilor multiple.