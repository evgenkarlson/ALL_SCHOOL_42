> Buna ziua si bine ati venit la o noua zi de piscina. 

> Vom vedea azi etapele de compilare. 

> V-am pregătit niște fișiere pentru teste. 

> Pana acum erați obisnuiti sa compilați toate fișierele .c pentru a scoate un executabil. 

> Va dau un exemplu, va arat "main.c". 

> Care conține "ft_putstr" si "ft_putchar". 

> Deci are nevoie de ambele pentru a compila. 

> Vom compila "main.c" cu "ft_putchar" si "ft_putstr". 

> Vom scoate un executabil "j07" cu opțiunea "-o". 

> Compilează, lansam "j07" care returneaza "42" si un retur la linie. 

> Vom face acum compilarea in doua faze. 

> In prima faza vom compila fișierele ".c" in limbaj mașina, 

> vom trece de la codul sursa (".c") in limbajul mașina care e 

> si apoi vom face o a doua etape, legarea fișierele ".o" pentru a genera un executabil. 

> Deci vom șterge "j07", si vom compila fișierele unul cate unul cu "gcc -c", care face doar compilarea. 

> Vom începe cu "ft_putstr". 

> Compilează... Nu rezulta un executabil, in schimb vedem ca avem un "ft_putstr.o". 

> Același lucru pentru "ft_putchar". 

> Si același lucru pentru "main.c". 

> Acum avem "ft_putchar.o", "ft_putstr.o" si "main.o". 

> Ajunge acum sa legam aceste fișiere ".o". 

> Tot in executabilul "j07". 

> Si rezulta același lucru. 

> De ce facem asta? 

> Pentru ca daca veți începe sa aveți proiecte mari, cu multe fișiere si multe funcții, va va permite sa luati fiserele unul cate unul, si sa compilați doar fișierele modificate cu ajutorul "makefile".

> De exemplu daca modificam "ft_putchar.c", vom putea doar sa recompilam fișierul lui ".o". 

> Vedeți cum recompilez "ft_putchar.c" in "ft_putchar.o”. 

> Si refac legaturile intre fișierele ".o" pentru a avea noul executabil. 

> Ne va permite sa lucram mai repede, si sa recompilam mult mai puțin cod de fiecare data, in loc sa recompilam toate fișierele ".c" când majoritatea sunt deja in ".o".
