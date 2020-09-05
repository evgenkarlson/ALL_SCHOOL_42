Hello again. In this video, I'm going to tell you about Pointer Arithmetics. I hope you're focused, because this is usually the moment where people drop out. You'll see, it's quite simple really, but for some mysterious reason, people usually struggle with these notions... Let's do this! Here's the main I've prepared. I've declared "a" and "b", both ints. I've assigned values to those variables, and then I'm using self-made functions to display the address of "a", and then display its value. And then same for "b" (address then value) Let's see what happens. See, we have the address of "a" and "b". Notice how similar those addresses are? "a" is actually 4 bytes further from "b". That's normal. I told you about the stack earlier. And when you declare objects on the stack... - the stack is actually all the way at the top of the addresses - ... so when you declare something on the stack, you go through addresses downwards. The difference between "a" and "b" is 4, because an int is 4 bytes. So here you go. The address of "a" is 4 bytes away from the address of "b". Now that I'm aware of this, I'll be able to use pointers to move to "a" and to "b". Let's create a pointer "*ptr". and "ptr = &b;" (the address of "b") Yes. I've selected b's address, as I told you, "b" is after "a" on the stack, but the address comes first... that's just how it is. If I wanted to do the exact same thing here, I'd have to write this... That used to be "a"'s address ("&a"), "ptr" being the address of "b" you'd think we could write "ptr + 4", as "b" is 4 bytes away from "a"... But our compiler is smarter than that. It knows "ptr" is a pointer to int. So when you type "ptr" + a value, it multiplies this value by the size of an int It's logical for you to move int by int, so to go from "b" to "a", I'd have to type "ptr + 1". Now. Here I used to display the value of "a"... To display the value of the pointed object, we used an asterisk. So "*ptr" should display the value of "b". But now I can do "ptr + 1". Normally I should be allowed to do this. So what does that mean? It means I'm taking the address contained within "ptr", I'm gonna do +1, the compiler knows it's a pointer to int, so it's going to add 4 bytes, and this asterisk means "check out what's at this new address". Logically, I should display the address of "a", and its value (3). Even though I'm using "ptr", which points to "b" Recompiling. Relaunching. Here you go. If you compare this to our previous result, I've displayed the address of "a". Wait, there's a slight difference... That's odd... Oh yeah, that's because I recompiled and relaunched the program, so it doesn't have the EXACT same address... But that's okay. What's important is that I am indeed displaying "a"'s address, even though I used "b"'s address. 'Cause addresses can change every time you relaunch a program. But that's another story. Now that we've done this, I want to show you that it's different with "chars" ... So imagine I change my int here and replace it with a char, So "char a", "char b" and instead of "ptr" pointing to an int, I'm going to make it point to a char. I need to change this because I can't use 3 anymore as it requires characters... so I'm going to use the ASCII character '3' for "a", just to mess with you. I'm going to use the ASCII character 'o' for "b", and here, I'm going to replace "ft_putnbr" by "ft_putchar", because we want to display characters. So here, normally, I have "a" with the ASCII value of '3', "b" with the ASCII value of 'o', "ptr" that points to "b", "ptr + 1", which should be the address of "b" + 1. Yes. A char is one byte. So when you move from char to char, we move byte by byte. Just to show you, I'm going to add extra lines. I'm taking the address of "b", I'm going to display the address of "b". And then I'll display the rest. ... typing ... Recompiling & relaunching. As you can see, "ptr + 1" (one byte because we're using chars) and we can do this with any type of variable. And every time you do, the computer knows the variable's size you're pointing to. So it'll be able to "move" accordingly. Last detail... Just for laughs. Let's use ints again. I'm going to change the value of "a" to 1, the value of "b" to 42. We'll keep what displays the address of "b". And change "ptr + 1" into "ptr + a". You can 'call' a pointer with an int. It's the same as 1. 1 being a static variable. Let's check out the output. The address of "b" is displayed. Same for the address of "a'. And I forgot to display something... I forgot to change my ft_putchar into a ft_putnbr... See, I've displayed 1, which is the value of "a" from "ptr" which pointed to "b". We've covered Pointer Arithmetics. See it wasn't that complicated, was it? Just remember that you can do calculations with an address, and then use an asterisk to check what's at this address.

> Buna ziua. In acest video vom vorbi despre aritmetica pointerilor. 

> Sper sa va concentrati pentru ca este momentul in care in general lumea se pierde. 

> Sunt lucruri destul de simple, dar in mod ciudat lumea are probleme cu aceste notiuni... 

> lata o functie "main" pregatita in avans. 

> Variabilele "a" si ”b" sunt de tip "int" cu valori asignate. 

> Am folosit functiile definite mai sus pentru a afisa adresa variabilei "a", valoarea lui "a", adresa lui "b", valoarea lui "b". 

> Sa vedem rezultatul. 

> Execut... 

> Compilez... 

> Execut... 

> Observam ca "a" si "b" au aproape aceeasi adresa, doar ca adresa lui "a" este la 4 bytes departare de "b". 

> Este normal, am vorbit anterior despre stiva ("stack"). Cand declarati ceva pe stiva (care e in capatul superior al adreselor), adresele scad in valoare. 

> Deci diferenta intre "a" si "b" e de 4 pentru ca tipul "int" ocupa 4 bytes. 

> lata asadar explicatia pentru care adresa lui "a" este cu 4 bytes mai mare decat adresa lui "b". 

> Acum voi putea utiliza pointerii pentru a ma deplasa 

> Deci voi face un pointer: 

> Si voi face ca in "ptr" sa am adresa lui "b

> Daca vreau sa reproduc ce aveam inainte, ar trebui sa pun, in locul adresei lui "a", ("ptr" este adresa lui "b") deci adresa lui "a" ar trebui sa fie ptr+4. 

> Dar compilatorul e mai destept, stie ca "ptr" este un pointer la "int", si va multiplica valoarea pe care o aditionati cu dimensiunea tipului (aici "int"). 

> Pentru ca e logic ca vreti sa va mutati din "int" in "int". 

> Deci ca sa ajung de la "b" la "a", trebuie sa scriu ptr+1. 

> Aici afisam valoarea lui "a". 

> Mai devreme am folosit * pentru a afisa o valoare. 

> Deci "*ptr" ar trebui sa afiseze valoarea lui "b". 

> In schimb nimic nu imi interzice sa scriu *(ptr+1). 

> Deci iau adresa din "ptr", fac +1, si compilatorul stie ca sunt intr-un pointer catre "int", deci aduna 4 bytes, si * va spune "vezi ce e la adresa asta". 

> Deci in mod logic aici afisez adresa si valoarea lui 

> Deci voi afisa 3, chiar daca aici "ptr" pointa catre "b". 

> Recompilez... 

> Daca comparati cu executia anterioara a programului veti vedea ca am afisat adresa lui "a". 

> E o mica diferenta, e ciudat... 

> De fapt e pentru ca am recompilat programul si reexecutat programul, dar e ok... 

> Important e ca sunt pe "a", chiar daca am pornit cu adresa lui "b". 

> De fiecare data cand relansez programul adresele se pot schimba, dar asta e o alta poveste. 

> Vom vedea ca daca avem variabile de tip "char", unele lucruri se vor schimba. 

> Sa folosim variabilele "a" si "b" de tip "char", si pointerul "*ptr" la "char" (in loc de "int"). 

> Voi schimba aici, pentru ca nu mai pot pune numarul 3, voi pune caracterul ASCII 3 (doar ca sa va incurc putin...). 

> Voi pune caracterul ASCII 'o' in "b". 

> Si aici in loc de "ft_putnbr" folosim "ft_putchar" care afiseaza un character. 

> Deci acum am "a" care contine valoarea ASCII '3', "b" care contine 'o', "ptr" care pointeaza catre "b", ptr+1 va contine adresa lui "b" plus 1, pentru ca tipul "char" are dimensiunea de 1 byte (deci ne deplasam din byte in byte). 

> De altfel voi adauga o linie in plus: voi afisa adresa lui "b", iar apoi restul. 

> Recompilam si executam... 

> Observati ca diferenta dintre adresa lui "b" si adresa lui "a" este 1, pentru ca acum lucrez pe "char". 

> Putem face asta cu orice tip de variabile. 

> Si de fiecare data compilatorul cunoaste marimea variabilei catre care pointati, deci se va deplasa in mod corect. 

> Ultimul punct, doar pentru a ne amuza.. 

> Voi reveni rapid la variabile de tip "int". 

> Voi repune "int"-uri si ne vom distra doua secunde... In fine, pe mine ma distreaza... 

> Voi pune a=1 si b=42. 

> Vom pastra... inclusiv afisajul adresei lui "b". 

> Si aici voi pune ptr+a. 

> Si la fel aici pun plus "a". 

> Pentru ca putem face suma dintre un pointer si un "int", e ca si cum as pune 1, 

> 1 e o variabila statica, ce nu va misca, ”a" chiar e o variabila, dar nu conteaza. 

> Deci cand fac asta ce se intampla? Afisez adresa lui "b", adresa lui "a"... 

> Si... am uitat sa schimb "putchar" in "putnbr". 

> Deci iata ca am afîsat 1, care e valoarea lui "a". 

> Plecand de la "ptr" care pointeaza catre "b". 

> Am facut turul aritmeticii de pointeri, nu e mai complicata de-atat, trebuie sa va amintiti ca puteti face calcule cu o adresa, si apoi folosi * pentru a vedea ce e la noua adresa.
