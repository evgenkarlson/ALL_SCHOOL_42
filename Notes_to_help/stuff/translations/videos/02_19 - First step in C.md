Hello and welcome to this first day of C : day 02.  I'm going to show you how to write your first program in C, and how to compile it so that it can be executed by the machine. First, let's open the file "jour02.c" with emacs The ".c" extension lets us (and the machine) know it's a source file. As soon as you open (or create) a file.c with emacs, use Ctrl-C and Ctrl-H to generate the school Header. If you're using vim, you'll have to use Fn-F1. We'll start by declaring our program's entry point with the function main(). In C, all functions have a type (int, char, etc..) they return a value of that type whenever they are used. So here we're going to create the main() function, which returns an int. If your function doesn't return anything, you'll have to write "void" (= null). No variable means nothing to return. As our function main() returns an int, let's write the return right now. Assuming there was no error in our code, we'll use the default return code: return(0) The "0" indicates everything went well. Normally, main() takes arguments, but for your first program, we won't. Here we go. We created a function that does nothing but return 0. Just saying "everything went fine". Let's save our file with Ctrl-X Ctrl-S, with Ctrl-Z, emacs will run in the background. You can see in the Shell that the task was suspended. Now, let's compile our file with gcc, which is the compiler. gcc has several options, for instance -o which allows us to define the type of gcc output file, meaning the name of the executable we've created. So let's create an executable called "jour02", using the source file "jour02.c" Be careful not to mix them up, otherwise you'll overwrite "jour02.c" There we go! gcc has created our file. See in our directory we now have 2 files : "jour02" and "jour02.c" We now have the executable (see files' access rights) to make sure we're executing it in the current directory, we'll use "./" before our executable's name. That launches our program, but as it doesn't do anything, there's no output. So let's make it do something. With "fg" (foreground) we reopen emacs. Let's use a basic system call : write(). So, if you remember (or not), we'll use write() on the standard output, which is the File Descriptor (1) We'll just display one character, for instance "@", and specify how many characters we want to display from this string, so here, just one. Let's quickly check out write()'s man, we can do this simply by doing Meta-X man... ... we'll look at the man 2 write(). write() is a system call. mans are indexed by type, and man 2 is about system calls. so we want to type "man 2 write". It splits our window into two. To switch windows, just do Ctrl-X-O. As you can see, write() requires the header "#include so that the compiler has the declaration and knows what arguments are required and what the output parameter is. So let's add this header. Stil Ctrl-X-O to switch windows. We can see that write() requires a file descriptor, - The (1) that represents our program's standard output - a buffer - which is a string. In our case just "@", and a size - number of bites to be displayed - Save your modifications (Ctrl-X, Ctrl-S), suspend emacs (Ctrl-Z) Re-compile. Everything went fine. Launch your program. "@" is being displayed on-screen. Why is there a "%" at the end ? Because there's no carriage return in our program. So let's add one ("\n") and change the size of our string to 2 characters. Re-compiling, re-launching... That's better! Now that we're created our first function, let's move it to a sub-function, which we'll call ft_putchar(), which will also return an int. So, ft_putchar() will take a "char c" and we'll simply take the write() from the main() and move it up. Cut the line with Ctrl-K. Do it twice to get the carriage return too Paste with Ctrl-Y and in our sub-function we'll be able to write the character... ... It's a little complicated,... with the ampersand "&" we give a character's address, instead of the character itself, which allows us to transform it into a string (char *) Here, we can either return(0), which means everything went well, either change the function's type to void (returns nothing). Let's use return(0). We're going to use our function ft_putchar() and this time we'll use simple quotes because it's a character, not a string. We're going to do a second time for the "\n". Let's close the man window with Ctrl-X-1. As you can see, our program will start its execution from the main() The main() calls the sub-function ft_putchar(). ft_putchar() displays what we put as parameter in the "char c". It returns, then we're back to the point of execution at the end of this function. Then we carry on. And then we end up with a ft_putchar() of a line-break ("\n"). in this case, write(1 ... ), the "char c" becomes "\n", it's one character, so 1. We return, and we're done. Let's test this. Ctrl-X Ctrl-S save our program. Re-compiling launching It did what we wanted. Now. Let's try something a little more complex. Let's create a function that displays N-times the character passed as argument. Let's call it ft_nputchar(). So we need the character we want to be displayed, and an int(n) for the number of times we want that character displayed. Here, we'll simply use this int(n) to count. We could modify it the hard way, but let's try and keep it simple for now. We need a counter "i", which will start from 0. And we're going to add a loop with while() - while (i) is smaller than (n) ... while (i < n) { ... } , we'll display the character - by calling our ft_putchar() function and as long as it's lower than (n), we'll increase (i) i = i + 1; and once (i) is equal to (n), it'll stop. So if we say that the argument (n) is equal to (1), we start with (i), which equals to (0), therefore smaller than (1), starting our first loop. we increase (i) by (1). So (i) goes from (0) to (1). The loop starts over again. As (i) isn't lower than (1), the expression is wrong, so we exit our loop while() and return (0) So we'll try the same thing... Here we'll call ft_nputchar(), and ask it to display 42 times the character "@" followed by a line-break. Ctrl-Z, emacs runs in the background. Re-compiling Launching. Okay. Let's check. Normally we should have 43 characters, because the "\n" counts as a character too Here we go. We have 43 characters! With these simple examples, you should be able to write your own programs in C Up to you to do the rest ! Cheers!



> Buna ziua si bine ati venit in aceasta prima zi de limbaj C, ziua 02. 

> Vom vedea impreuna cum sa scrieti primul vostru program si cum sa il compilati astfel incat sa fie executat de catre calculator.

> Mai intai, vom deschide cu "emacs" un fisier jour02.c. 

> Extensia .c ne va permite noua si calculatorului sa recunoastem ca este vorba de un fisier sursa. 

> Dupa ce ati deschis un fisier .c cu ajutorul utilitarului "emacs" veti genera un header folosind combinatia de taste Control+C, Control+H. 

> Aceasta combinatie va genera un header standard de-al scolii. 

> Daca folositi utilitarul "vim", va trebui sa folositi tasta F1. 

> Vom incepe prin a declara punctul de intrare in program: functia "main". 

> Fiecare functie scrisa in limbajul C are asociat un tip. 

> Acesta este tipul valorii returnate de functie. Vom incepe asadar sa scriem functia "main" care returneaza o valoare de tip "int".

> Daca functia nu ar returna nimic, vom scrie ca returneaza "void" (care e o valoare nula). 

> Deci nu va returna nimic. 

> Intrucat functia noastra returneaza un "int", 

> vom scrie o instructiune "return(O)" care semnifica faptul ca programul s-a incheiat fara eroare. 

> Prin conventia aceasta semnifica faptul ca totul s-a terminat cu bine. 

> In mod normal, functia "main" are argumente, dar in cazul acestui program vom neglija acest aspect.

> Tocmai am scris o functie care nu face nimic, 

> doar returneaza valoarea 0 semnificand faptul ca executia programului s-a incheiat fara eroare. 

> Vom salva fisierul folosind Control+X, Control+S. 

> Folosind Control+Z vom pune editorul "emacs" in background. Vedeti in "shell" ca e suspendat. 

> Vom compila fisierul folosind compilatorul "gcc". 

> Compilatorul "gcc" are mai multe optiuni. 

> Vom folosi optiunea "-o" care permite specificarea fisierului de iesire, numele executabilului pe care-l vom crea.

> Vom indica un nume pentru fisierul de iesire: jour02. 

> Si-i dam fisierul sursa, jour02.c. 

> Atentie sa nu folositi drept fisier de iesire, fisierul sursa pe care tocmai l-ati creat (jour02.c), deoarece compilatorul va suprascrie continutul acestuia!

> "gcc" a creat fisierul executabil. 

> Priviti, in director avem un fisier jour02 si un fisier jour02.c. 

> Putem executa acum, dupa cum indica drepturile fisierului (optiunea x). 

> Pentru a fi sigur ca executam un fisier din directorul current vom folosi si jour02. 

> Programul este executat si cum nu face nimic, nu vedem nimic afisat. 

> In continuare il vom face sa afiseze ceva. 

> Cu "fg" repunem "emacs" in prim plan ("foreground"). 

> Vom folosi apelul de sistem "write". 

> Vom folosi iesirea standard, care are identificatorul de fisier 1. 

> Vom afisa un singur caracter, si-i spunem cate caractere are sirul, deci unul singur.

> Vom verifica manualul (man) functiei "write". 

> Vom face asta prin Windows+X, man. 

> Si ne vom uita la "man 2 write". 

> "Write" este un apel sistem. Man-urile sunt clasificate pe tipuri, iar 2 este tipul sistem. 

> Deci am cerut "man"-ul de tip 2 al lui "write". 

> Fereastra este impartita in doua. 

> Pentru a trece de la o fereastra la alta folositi Control+X, O. 

> Primul lucru: "write" necesita folosirea header-ului <unistd.h>, pentru ca compilatorul sa stie care e declaratia lui "write",

> si sa stie care-i sunt parametrii, si cel de retur. 

> Deci vom scrie... "#include <unistd.h>". 

> Folositi tot Control+X, O pentru a trece de la o fereastra la alta. 

> "write" cere un file descriptor, deci 1, care reprezinta iesirea standard a programului nostru, 

> un buffer care e un sir de caractere (noi i-am dat unul care contine doar 

> si dimensiunea (numarul de bytes care trebuie scrisi). 

> Salvam programul cu Control+X, Control+S. 

> Control+Z pentru a suspenda "emacs". 

> Si relansam compilarea. 

> Totul a decurs ok. 

> Relansam programul. 

> Si ne afiseaza un pe ecran. 

> De ce ne afiseaza un procent dupa? 

> Poate pentru ca nu avem un retur la linie. 

> Adaugam un retur la linie ("\n") si-i spunem ca sirul nostru are acum 2 caractere. 

> Recompilam. 

> Si relansam. 

> Acum pare mai bine. 

> Acum ca am facut aceasta prima functie, vom pune "write" intr-o functie "ft_putchar()",

> care va returna si ea un "int". 

> Deci "putchar" va lua un parametru "char c". 

> Si vom pune "write"-ul din "main" mai sus. 

> Folositi Control+K pentru operatia "Cut" (de doua ori pentru a lua si returul la linie). 

> In functia noastra putem scrie caracterul pe care l-am primit. 

> Aici vom face ceva ce e probabil cam complicat pentru voi, 

> vom da adresa caracterului in loc de caracterul in sine (cu 

> ceea ce ne va permite sa-l transformam in sir de caractere (ceea ce numim "char *"). 

> Deci aici putem sau sa returnam 0 (totul e ok), sau sa punem "void" (functia nu returneaza nimic).

> In cazul de fata doar returnam 0. 

> Vom folosi functia "ft_putchar". 

> Si aici vom folosi' in loc de ", pentru a preciza ca e un caracter, 

> si nu un sir de caractere. 

> Si o vom face de doua ori, pentru a putea transmite si "\n". 

> Folositi Control+X, 1 pentru a inchide fereastra "man" din partea de jos. 

> Programul nostru se va executa incepand cu "main". 

> Apoi intram in "main", 

> apelam functia "ft_putchar", pe care o vedem aici, 

> scrie ceea ce i-am dat in parametrul "char c", 

> face "return", si ne gasim la finalul acestei functii. 

> Apoi continuam. 

> Si ajungem la "ft_putchar" care afiseaza returul la linie, "\n". 

> La fel, revenim aici, la "write", cu "c" egal cu '\n', revenim din functie, si am terminat.

> Testam. 

> Cu Control+X, Control+S salvam programul. 

> Recompilam. 

> Relansam. 

> Si a afisat ceea ce voiam. 

> Trecem la o ultima etapa putin mai complicata: o functie care afiseaza de "n" ori caracterul trimis ca parametru. 

> O numim "ft_nputchar". 

> "c" este caracterul pe care vrem sa il scriem, iar "int n" este numarul de aparitii. 

> Aici folosim acest "int n" pentru a numara. 

> Deci sau il vom modifica (decrementandu-l), vom folosi un contor "i",

> care porneste de la 0. 

> Cat timp "i" este mai mic decat "n", 

> vom afisa in bucla caracterul

> apeland functia "ft_putchar". 

> Si vom incrementa contorul "i", 

> "j = j + 1" pentru a avea contorul de bucla, 

> si o data ce "i" este egal cu "n", ne oprim. 

> Deci daca dam un parametru "n" egal cu 1, 

> incepem cu i = 0, 

> 0 < 1, deci totul e ok si executam prima data bucla. 

> Incrementam "i" cu 1 si acesta trece de la 0 la 1. 

> Revenim in bucla, si avem 1 < 1, 

> expresia e falsa. 

> Deci bucla se opreste. 

> Si ne aflam aici, returnand 0 pentru ca functia e gata. Vom incerca acelasi lucru, vom apela "ft_nputchar" pentru a afisa de 42 de ori caracterul 

> si apoi un retur la linie. 

> Control+Z pentru a pune "emacs" in background. 

> Recompilez. 

> Relansez. 

> Sa verificam. 

> In mod normal vom avea 43 de caractere, pentru ca avem si caracterul "\n" la final. 

> Avem deci 43 de caractere ca rezultat al programului nostru. 

> Sunteti acum pregatiti sa scrieti primul vostru program in C. 

> A fost un exemplu foarte simplu. 

> Nu mai ramane decat sa treceti la treaba! Multumesc.