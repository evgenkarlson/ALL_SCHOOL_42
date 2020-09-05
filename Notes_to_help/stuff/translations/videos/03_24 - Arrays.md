Hello. In this video, we'll talk about arrays. Actually, earlier on, we've seen we could declare "a" and "b" on the stack, and that we could go from one to the other
Now. I'd like to have 10 ints rather than declare 10 variables like a,b,c,d,e,f,g... etc till I have 10, I'd like to declare a variable that possesses 10 ints 'within'
That's called an array. Here's a piece of code used earlier We could declare an int by writing "int b" Now I'm gonna call it "tab" and you're going to discover a new syntax. When I write "int tab[10]", I'm saying that on the stack, there'll be 10 ints And that "tab" will be some sort of implicit pointer on the first of these ints We're still using pointers Now, look : Here, in "putaddr", I used to give it an address, Here I'm going to give it "tab" instead. And if I want to display one of tab's numbers, so far I haven't set any... we'll be able to access one of tab's elements by using square brackets ( [ ] ) For example, the first element is "tab[0]" You'll understand why in a moment. First, let me show you that it works. Compiling & executing We can see that "tab" is an address And that "tab[0]" has the value '42'. Now let me explain why the first element of "tab" is "tab[0]", Basically, "tab[something]" is like writing " *( tab + brackets' content ) " When I write this ... see these two lines? "tab[0] = 42;", or *(tab + 0) = 42 It's the exact same thing. Let me prove it to you. Re-compiling, re-launching. I still have the value "42". I told you that "tab" was some sort of pointer, that points towards the 1st element of an array of ints. When I do "+ 0", it's the address of the first element and when I do *(tab + 0) I get an int which is the 1st element on my array. So "tab[0]" and "*(tab + 0)" are the exact same thing, If I wanted to access the 4th element, Well I'd do "tab + 3". ("tab + 0" for the 1st, "tab + 1" for the 2nd, "tab + 2" for the 3rd, etc... Remember in a previous video ? Normally with "+ 3" , as we're using ints, by taking their real size into account, it's actually "+ 12" : " + 3 * 4 bytes " because an int = 4 bytes. So I've used both "*(tab + 3)" and "tab[3]". And it works. So here I have a memory slot that's allocated 10 elements. If the first element is at "+ 0", the last is at ... "+ 9"! And not at "+ 10". Be careful. When you have an array of 10 elements, the last element is the array's length "- 1" to access it. Because, in order to access the first element, we access it by "0". Now that we've seen this, I'm going to prove that it is indeed a pointer. So imagine... I'm going to use "*ptr" and do "ptr = tab;" "tab" being an address. (I hope it compiles) It does. All good. So "ptr" has taken tab's value Reminder: "tab" is an address. the address of the first element of the array I allocated. So if I do "*(ptr + 3)" "ptr + 3" is an address "*(ptr + 3)" is an int Let's give it a value, such as 867,
and here I'll display "tab[3]" Will it work ...? 867. All good! See, arrays are just another way of writing pointers arithmetics more simply. and (at the top) it also allows us to declare more elements Just to be thorough, let me show you something else. Let's make an array of ints... and underneath, I'm going to create an array containing two elements ... actually, let's add more things. This one, I shall call "tabptr". It'll contain 2 pointers to int. It's an array of pointers to int. And we could do this to infinity (pointer to pointer to pointer to...) Let's imagine now... I want to modify "tab2" from "tabptr"... "tabprt[0]" is a pointer to int so it'll take an int's address. solet's give it tab's value. "tabptr[1]" is equal to "tab2" and now I want to modify "tab2[3]" through "tabptr". - I've linked tabptr[0] - To check out tab2[3], it's easy... tabptr[1] represents "tab2" and now, [3], if I set the value to 42, it should work. Let's remove what we don't need. Let's give it a shot... Sorry this video is so long... The value of "tab2[3]" has been set to 42. You'll see that this is all very logical. How could I rewrite this with pointers? And this is the last thing we'll see in this video. So. How could I rewrite this with pointers? As I've said, when you do : "something[something]" it's the same thing as doing : " *(what's on the left + what's in brackets) " So I'm going to transform "tabptr[1][3]" into something with asterisks. Let's start by moving the "[3]" and add an asterisk. What's on the left of "[3]'? it's "tabptr[1]". so "+ 3". That, is equal to 42. Normally those two lines do the same. Let's test this. Still displaying 42.
Now let's do the same with "[1]". Recompiling... Relaunching... Still displaying 42. The point I wanted to make ... The line bellow is equivalent to this. So, the point I wanted to make ... We said that "tabptr" was an array of pointers to int. And I said earlier that "tab" was an array of ints. So "tab" is some sort of pointer to int. So "tabptr" is some sort of pointer to pointer to int. And you can clearly see that. 'cause in order to access my int, (to set its value to 42) I had to use two asterisks. 1st time, I took the address contained in "tabptr" and added 1. - talks about bytes - I checked what was at this address. At this address, we actually have "tab2" and then I added "+ 3" to "tab2" and also checked what was at this address. So it's as if I wrote "tab2[3]" and gave it the value 42. Here you go, those were the basics of arrays. Beware... Sorry, I'm almost done. Beware... If I write this... (look onscreen) "tab" is NOT a pointer to pointer to int. Be really careful with this. Basically, behind your array, there's a pointer to int. You can access it in the function, using two square brackets, but as soon as you want to pass it another function, you'll have problems. You'll have to try things with arrays of arrays. But now that you've seen how to make array pointers, and simple arrays, arrays of ints, arrays of pointers to (...) ints, it's up to you to practice and test things. That's it.

> Buna ziua. In acest video vom vorbi despre tablouri. 

> Mai devreme am vazut ca putem declara variabilele "a" si "b" pe stiva, 

> si ca ne putem plimba intre cele doua pentru ca sunt foarte aproape in stiva. 

> Acum as vrea sa am 10 valori "int". 

> In loc sa definesc 10 variabile de tip "int", voi declara o singura variabila care contine 10 valori de tip. Acesta este un tablou. 

> Luam niste cod pe care-l aveam dinainte. 

> Putem declara o variabila simpla de tip "int" scriind "int b;". 

> Acum voi scrie "tab", si veti vedea o noua modalitate de scriere: 

> cand scriu "int tab[10];", spun ca pe stiva vor exista 10 valori "int", iar "tab" va fi un pointer implicit spre prima dintre aceste valori "int". 

> Vorbim tot despre pointeri. 

> Aici, in "putaddr" de obicei pun o adresa, acum pun "tab". 

> Si aici daca vreau sa afisez o valoare din "tab" (desi deocamdata n-am inserat niciuna), voi utiliza iarasi"[]". 

> Pentru a accesa primul element, scriu "tab[O]". 

> Veti vedea imediat de ce scriu *'tab[O]". 

> Va arat prima data ca merge. 

> "tab[O]" are valoarea 42. 

> Compilez... 

> Execut... 

> Vedem ca "tab" e o adresa, si ca ”tab[O]" e 42. E ceea ce voiam. 

> Acum va voi explica de ce prima valoare din tablou este "tab[OJ". 

> Deocamdata nu e foarte clar... 

> Pentru ca "[0]" (de fapt a pune ceva intre paranteze patrate) e echivalent cu "*(tab + ce e intre paranteze) 

> Deci "tab[0]=42;" si "*(tab+0)=42;" e exact acelasi lucru. 

> Si va voi demonstra asta. 

> Recompilez... 

> Reexecut... 

> Am tot valoarea 42. 

> Asta pentru ca "tab" este un pointer spre primul element dintr-un tabou de "int". 

> Deci cand scriu +0, e adresa primului element. 

> Deci cand scriu *(tab+O) ajung pe un "int” care e primul element al tabelului. 

> Deci "tab[OJ" e acelasi lucru cu ce am scris mai sus. 

> Daca vreau sa accesez al patrulea element din tablou, voi scrie *(tab+3). 

> Operatia +3 (din cauza ca folosim ”int"-uri) inseamna de fapt in memorie +12. Deci +3*4 bytes. 

> Pentru ca tipul "int" ocupa 4 bytes. 

> Deci reincep, dupa ce am pus "[3]" mai jos, si "+3" mai sus, si tot merge. 

> Deci am un spatiu de memorie de 10 elemente. 

> Daca primul element din tablou are indexul 0, atunci ultimul element are indexul 9, si nu indexul 10, va rog sa fiti atenti. 

> Pentru a accesa ultimul element din tablou, indexul lui e dat de lungimea tabloului minus 1. 

> Pentru ca accesam primul element cu 0. 

> Acum ca am vazut asta va voi demonstra ca e un pointer. 

> Declaram un pointer "*ptr". 

> Si scriu "ptr = tab;", caci "tab" e o adresa. Sper ca va compila, pentru ca uneori pot fi probleme. 

> Compileaza fara erori. Revin in program. 

> "ptr" a luat valoarea lui "tab". "tab" dupa cum va amintiti e o adresa. 

> E adresa primului element al tabloului. 

> Deci daca scriu "*(ptr+3)"... "ptr+3" e o adresa, "*(ptr+3)" e un "int". 

> Si ii dau valoarea 867. 

> Si aici voi afisa tot "tab[3J". 

> Oare o sa mearga? 

> 867... Deci inca suntem ok. 

> Vedeti, tablourile sunt o maniera de a scrie mai simplu aritmetica pointerilor si ne permit sa declaram un numar de elemente. 

> Pentru a fi exhaustivi vom declara un tablou de intregi. 

> Si mai jos voi face un tablou... 

> Hai sa fim chiar completi. 

> II vom numi "tab2", tot cu 10 elemente. 

> Si lui ii spunem "tabptr" ca sa nu va incurcati, 

> si el are doua elemente, dar ce elemente? Pe stiva voi pune doi pointeri catre "int". 

> Este un tablou de pointeri spre "int". 

> Si putem face asta la infinit. 

> Sa modificam asta.. 

> Imaginati-va ca vreau sa modific "tab2" prin intermediul "tabptr". 

> Deci care e tipul lui "tabptrfOj"? Pointer catre "int". 

> Deci el va primi adresa unui "int", deci ii voi da valoarea lui "tab". 

> tabptr[1] = tab2; 

> Si acum vreau sa modific "tab2[3J" prin "tabptr" acum ca am legat "tabptr" la tablouri. 

> ar trebui sa mearga. 

> Pentru a vedea "tab2[3] , folosesc tabptr[1]" care e echivalent la "tab2", si acum adaug [3]", si daca pun 42

> ar trebui sa mearga. 

> Voi sterge afisarea adresei. Vom incerca.. 

> Deci dupa cum vedeti, in "tabptr[OJ" (care e un pointer catre "int") am pus valoarea lui "tab", in "tabptr[1]", "tab2". 

> Si retestam, deci prin "tabptr" am setat corect valoarea lui "tab2[3]" la 42. 

> Veti vedea ca e foarte logic ceea ce facem. 

> Cum putem face asta cu pointeri? (Cu asta terminam videoul.) 

> Cum scriem asta cu pointeri? 

> V-am spus ca daca punem ceva intre e ca si cum am scrie * elementul din stanga plus ce e intre paranteze. 

> Deci voi transforma "tabptr[1][3]" in ceva cu stelute. 

> Voi incepe prin a scapa de "[3]". 

> Deci "*(tabptr[1] + 3)", pentru ca "tabptr[1J" e elementul din stanga lui "[3]". 

> (tabptr[1] + 3) = 42; 

> Va rearat linia. In mod normal cele doua linii sunt echivalente. 

> Vom testa. 

> Ar trebui sa compileze... 

> Afisam tot 42. 

> Acum facem aceeasi operatie pentru "[1]". 

> Recompilez... Relansez... Afisam tot 42! 

> Deci linia de mai jos e echivalenta cu asta. 

> Deci la ce voiam sa ajung... Vedeti ca "tabptr" e un tablou de pointer catre "int". 

> Si "tab" e un tablou de "int", deci e un pointer catre "int". 

> Deci "tabptr" e un pointer de pointeri catre "int", 

> ceea ce se vede bine pentru ca pentru a accesa un "int", 

> (elementul la care ajung pana la urma e un "int" caruia pot sa-i dau valoarea 42) 

> trebuit sa folosesc doua stelute. 

> Prima data am adaugat 1 la adresa continuta in "tabptr", 

> deci 4 pentru ca un pointer e echivalent la 4 bytes... 

> de fapt chiar 8, pentru ca fiind pe 64 bits un pointer are 8 bytes, 

> am vazut ce se gaseste la aceasta adresa... 

> Si de fapt acolo se gaseste "tab2". 

> Deci am ajuns la "tab2". 

> Si la "tab2" am adaugat 3, si am cautat ce se afla la aceasta adresa, ca si cum as fi scris "tab2[3J", si i-am dat valoarea 42. 

> Am facut o trecere rapida prin tablouri. 

> Atentie, ultimul punct de care am uitat. 

> Atentie, daca scrieti asta: "int tab[10][10];", "tab" nu e un pointer de pointeri catre "int". 

> Si trebuie sa fiti foarte atenti la asta, pentru ca de fapt "tab" e un pointer catre "int". 

> Doar ca puteti sa-l accesati intr-o functie folosind cele doua paranteze patrate, 

> dar daca vreti sa-l dati unei alte functii veti avea probleme. 

> Deci va las pe voi sa va jucati cu tablourile de tablouri, 

> acum ca ati vazut ca putem avea tablouri de pointeri, tablouri simple, 

> deci tablouri de "int", de pointeri catre "int" si de pointeri catre pointeri catre "int".. 

> Va las deci pe voi sa va jucati cu ele.
