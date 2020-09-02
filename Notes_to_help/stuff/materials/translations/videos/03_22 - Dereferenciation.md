Hello. In this video, we'll see how we can use pointers, aka dereferencing pointers, meaning access the variable towards which it points. Let's use the same main as earlier. We have a variable "a" (an int), a variable "ptr", which is a pointer to int. I've given the variable "a" a value of 3. And "ptr" equals to "a"'s address. Now... If I want to see the value of the variable pointed by "ptr", For that - you'll see it's pretty simple - you just have to write " *ptr " Here's a mnemotechnic way to remember this "ptr" is a pointer... to int. so *ptr... is an int ! As simple as this. If you memorise this, you'll have less problems with pointers. So here, I'm going to use a function, called "ft_putnbr", which allows me to display numbers. What does it take as parameters? It takes an int ! So here, if I hadn't used an int, there'd be an error message during compilation. " *ptr " is an int. It means "I'm going to check the address pointed by ptr" Let's try and compile this main. Here we go! The value 3 is displayed. Now... Just to show you that we did indeed get the value of "a", I'm going to display the value 3 first, then I'll change it's value to 42, and add a "\n" to make the display clearer And on the next line, I'll re-display the value of " *ptr ". And you'll see... So I've modified "a". Oops, something went wrong... Sorry... We needed inverted comas here... See, inverted comas and quotation marks are not the same thing. inverted comas are for a character's value, and we'll see quotation marks later on. Sorry again. Here we go. Let's execute our program. See, we have 3 there, for the first display of " *ptr ", and the second time we have 42. So it allowed me to display the value. But I could also change the value directly. For example: If I do " *ptr = 42; ", and set "a" to be displayed by my function Compiling again... See, it's the same thing ! So basically, by writing *ptr here, what happens? First action: so, ptr is an address, *ptr I'm checking what's at this address, And now, at this address, where I'm at, I'm giving it the value 42. Pretty simple so far (!) Now, let's make things a little harder. What's interesting is that we can have pointers to pointers. So for example, here I'm gonna do "**ptr2" which is a pointer to pointer to int. So the address that "ptr2" contains, is the address of a pointer to int. So if we follow the same logic as before, I'm gonna have to give "ptr2" the address of a pointer to int, because I can't give it it address of "a" straight away, so I'm going to give it ptr's address. And now, well, we're going to do the same thing, except I'm going to add a second asterisk, and here too... and you'll see that we're going to get the exact same result. Because "ptr2" is the address of "ptr", when I do "ptr2", what's " ptr2"'s title? well it's a pointer to int. Now, I'm adding another asterisk. The first time, I went to see what was in "ptr"'s address, "ptr2" contains an address, I'm checking what's at this address, it happens to be another address, so I'm adding a second asterisk, so, second action: I'm going further a notch. Now I'm checking "a", and from here, I will be able to display it, so "ptr2" is an int, so I can type this, and it should work. It worked! And just for fun... I'm going to show you a main I prepared just for this, we can do this infinitely! See, we have "ptr", "ptr2", "ptr3", etc... (pointer to pointer to pointer to ...) "ptr" is a pointer to int, it points to "a". "ptr2" is a pointer to pointer to int, etc... You see at the end? I'm going to display "a"'s value, but going through "ptr7". Pointer to pointer to... You get it, loads of pointers. But I'll still be able to display the value of "a". Let's check if it worked So here I've compiled with my second main. And it displays the value "3". So from "ptr7', going through many pointers, I was able to display "a"'s value. So now you know how to dereference pointers. In the next video, we'll cover Pointer Arithmetic.

> Buna ziua, in acest video vom vedea cum putem dereferentia un pointer: cum putem accesa valoarea

> variabilei spre care pointeaza. 

> lata funcția "main" utilizata si in videoclipul anterior. 

> Avem o variabila "a" de tip "int" si un pointer "ptr" carea pointeaza spre un "int". 

> După cum am văzut mai devrem am pus in "a" valoarea 3.

> Pointerul "ptr" pointeaza spre adresa variabilei "a", cum am văzut inainte. 

> Acum vreau sa accesez valoarea variabilei spre care pointeaza "ptr". 

> E destul de simplu, trebuie doar scris "*ptr". 

> Daca vreți sa va amintiți, "ptr" e un pointer spre "int", deci "*ptr" este un "int". 

> Chiar e atat de simplu. 

> Asta e tot ce trebuie sa va amintiți ca sa nu aveți probleme cu pointerii. 

> Folosesc funcția "ft_putnbr" care-mi permite sa afișez un număr, si deci daca o apelez asa...

> Vedeți ca primește ca parametru un "int", deci as avea eroare daca nu ii dau un "int". 

> In cazul de fata "*ptr" e un "int", pentru ca ”*ptr" inseamna ca ma voi uita la adresa pointata de "ptr". 

> Compilez.. 

> Execut si obțin valoarea 3. 

> Acum, ca sa va dovedesc ca intr-adevar căutăm valoarea lui "a", 

> voi afișa o data "a", apoi ii voi schimba valoarea. li dau acum valoarea 42, afișez si un "\n" sa fie mai clar, si reafisez valoarea din "*ptr",

> si veți vedea... Avem o eroare... 

> ghilimelele duble ("). 

> Trebuie sa folosim ’ in loc de " atunci când avem un singur un caracter. Vom vedea in alt video la ce folosesc

> ghilimelele duble ("). 

> Acum reexecut, si prima data afișez 3, apoi afișez 42. 

> Deci am reușit sa vad valoarea. 

> Dar pot de asemenea modifica direct valoarea. 

> Deci daca fac "*ptr = 42;", si afișez valoarea lui "a", reîncep, recompilez... si am același lucru. 

> Deci când scriu "*ptr" aici ce se intampla? 

> Prima acțiune, "ptr" este o adresa, deci cu "*ptr" voi vedea ce e la aceasta adresa, 

> si apoi pun valoarea 42 la adresa la care ma găsesc.

> Deocamdată e destul de simplu. 

> Complicam puțin lucrurile, veți vedea ca putem avea pointeri către pointeri. 

> Deci "ptr2" este un pointer la pointer la "int".

> Deci "ptr2" pointeaza spre adresa unui pointer la "int". 

> Lui "ptr2" ii voi asigna adresa unui pointer către "int", deci adresa pointerului "ptr", nu adresa lui "a". 

> Acum fac același lucru, dar adaug o noua steluta *... 

> Si aici. Si vom avea același rezultat. 

> Pentru ca "ptr2" conține adresa "ptr". Când fac "*ptr2" obțin un pointer către "int". Acum adaug o noua steluta; deci prima data ma duc sa vad ce e in adresa pointata de "ptr2".

> In cazul de fata e o noua adresa, si cu a doua * merg cu un rang mai departe, 

> si ajung la variabila "a". 

> Si acum pot sa o afișez. 

> Deci ”**ptr2" e un "int", deci toate operațiunile acestea vor funcționa. 

> Sa vedem daca merge. 

> In mod normal... merge. 

> Doar pentru amuzamentul vostru va voi arata un exemplu pe care il am pregătit. 

> Putem face asta la infinit. 

> Deci am "ptr", "ptr2", "ptr3", etc., si am pointer către pointer către pointer, etc. 

> Cred ca ati înțeles logica: "ptr" e un pointer către "int", deci pointeaza către "a", 

> "ptr2" e un pointer către pointer către "int", etc. 

> Afișez valoarea lui "a" trecând prin "ptr7", pointer către pointer către... Multi pointeri. 

> Si voi afișa valoarea lui "a".

> Vom vedea daca merge. In mod normal, da.

> Daca totul e ok.

> M-am încurcat... Reincerc, o sa reusesc pana la urma. 

> Am compilat "main2.c". 

> Se afiseaza valoarea 3, deci prin "ptr7", la care am ajuns prin multi pointeri, am putut afișa valoarea lui "a". 

> Ati invatat cum sa dereferentiati pointerii si cum sa va jucati cu ei,

> in videoul următor vom vedea aritmetica cu pointeri.
