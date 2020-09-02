> Ok, știm ca avem nevoie de o definiție a structurii C, pentru ca lista este compusa din noduri definite ca structuri C. 

> Cream fișierul header ".h" si il protejam împotriva erorii de incluziune multipla. 

> >: cream un "typeder pentru declararea viitoarei liste.
> typedef struct s_list t_list; 

> Astfel putem scrie:
> struct s_list {} 

> loare un pointer la un sir de caractere 

> si, după cum va spuneam mai devreme, un element particular, un pointer la o structura "s_list", "next". 
> folosit "typedef" mai devreme, putem scrie
> t_list *next; 

> Sa trecem la funcția "main 

> Vom avea nevoie de definiția listei, deci vom include "list.h". 

> Returnam O. 

> întrucât operam asupra unei liste, vom crea un pointer la lista, un pointer la tipul definit de noi "t_list".

> Ce facem mai departe? 

> Inițializam lista cu valoarea "nuli". Deci avem nevoie sa includem <stdlib.h>. 

> Va voi explica asta mai încolo. 

> Vom adauga un nou nod in lista, cu valoarea "toto". 

> Vom repeta inca o data operația, de data asta cu "tata". 

> Si inca o data, cu "tutu". 

> vom crea o funcție "print_list" care va afișa conținutul listei noastre. 

> Sa nu uitam sa declaram prototipurile funcțiilor. 

> Funcția "add_link" returneaza un pointer la tipul "t_list", 

> primește ca parametru o lista si un "char*" care ne va permite sa dam valori nodurilor pe care le vom crea. 

> Funcția "print_list" primește un parametru de tip "t_list*". 

> Sa trecem la implementarea funcției "add_link". 

> Ce va face "add_link"? 

> Va opera asupra listei, deci nu uitam sa includem fișierul "list.h". 

> Va returna un "t_îist*" si va prelua ca parametri lista la care adaugam un nod si valoarea pe care o va stoca nodul. 

> Vom avea nevoie de funcția "malloc", deci includem <stdlib.h>. 

> Știm ca vom crea un nod, sa-l numim "tmp". 

> Returnam. Deși nu folosește la nimic, pentru ca vom avea "segmentation fault". 

> Deci facem ca pointerul "tmp" sa referentieze o zona disponibila de memorie, cu ajutorul funcției "malloc". 

> tmp = malloc(sizeof(t_list)); 

> Daca "tmp" nu este "nuli," înseamnă ca alocarea dinamica de memorie a reușit, 

> deci putem sa operam asupra nodului si sa ii dam o valoare. 

> Deci vom spune ca varîabîîa "str" dinsfr'uctura noastra, care e un pointercatre "char", ia valoarea "str" din parametru. 

> Iar elementul "next" este egal cu lista noastra
> tmp->next = list; 

> Daca "tmp" era "nuli", am returna "nuli", ceea ce ar induce o eroare. 

> Ce se intampla daca apelez prima data aceasta funcție? 

> Voi crea nodul "tmp". 

> Voi spune ca acesta conține valoarea "toto" si ca next pointeaza spre "list". 

> "List" este "nuli", deci pointerul "next" pointeaza la "nuli". 

> La 'afcTdiTea apeTTfrîmit ca parametru îfsta noastra, care are îe aceasta cFâfâ'valoarea nodului "tmp" definit la apelul anterior. 

> Creez un nou nod "tmp" care conține valoarea "tata", iar pointerul sau "next" pointeaza spre "list". 

> La al treilea apel, ii dau nodului "tmp" valoarea "tutu" si pointerul "next" pointeaza spre "list". 

> Sa scriem funcția "print_list" pentru a ne asigura ca totul funcționează. 

> Voi avea nevoie sa includ fișierul "list.h". 

> Returnez "void". 

> Primesc ca parametru "t_list *list". 

> Vreau sa afișez "str" care este un sir de caractere. 

> Voi folosi funcția "ft_putstr(list->str)". Deocamdată e simplu. 

> Știu ca trebuie sa iterez pe toate nodurile din lista. 

> Vom avea, așadar, nevoie de un "while". 

> Care sa fie condiția de oprire? 

> Știm ca pointerul "next" este egal cu adresa următorului element din lista. 

> Daca scriu "list->next" voi obține al doilea nod din lista (cel care conține valoarea "tata"). 

> Daca scriu inca un ”->next" ma deplasez la al treilea nod (cel care conține valoarea "toto"). 

> Iar daca mai scriu o data "->next" ajung la un pointer care pointeaza la "nuli”. 

> Aceasta poate fi o condiție de oprire a buclei. 

> Vom spune ca: list = list->next; 

> Iist->next ma duce pe nodul care conține "tata", 

> "list" pointeaza la acum la nodul care conține valoarea "tata". 

> Daca fac "list->next" ajung pe nodul care conține "toto". 

> Deci bucla "while" continua cat timp "list" e diferit de "nuli”. 

> Vom compila. 

> Executam si obținem cele 3 valori: "tutu", "tata", "toto". 

> Ce inseamna asta? 

> Cei mai perspicace au remarcat ca am scris apelurile in ordinea ("toto", "tata", "tutu"). 

> Dar se afiseaza in ordine inversa. 

> Daca revin la schema pe care am facut-o anterior, observam ca, de fiecare data când am adaugat un nod la lista, acesta a fost poziționat in capul listei. 

> Deci lista va avea elementele in ordinea inversa fata de cea in care au fost create.