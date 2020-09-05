> Vom vedea in acest video cum putem scrie intr-un descriptor de fișier. 

> Se foloste funcția sistem "write" care primește 3 parametrii: 

> primul parametru este descriptorul de fișier in care scriem, al doilea parametru e ceea ce trebuie scris, si al treilea parametru este numărul de octeti de scris. 

> Funcția "write" returneaza numărul de octeti scrisi sau "-1" in caz de eroare. 

> Am reluat programul de baza pentru deschiderea unui fișier. 

> Voi scrie o funcție "ft_putchar" care primește ca parametri un descriptor de fișier si un "char". 

> Vom scrie pe descriptorul "fd" valoarea variabile "c" de tip "char". 

> Voi apela aceasta funcția imediat după deschiderea fișierului pentru a scrie 'Z'. 

> Compilez codul. 

> Execut programul. 

> Fișierul 42 a fost creat si are dimensiunea de 1 octet. 

> Daca deschidem fișierul vedem ca exista un "Z". 

> Re-executam programul. 

> In fișier exista un singur "Z". 

> Aici intervin flag-urile funcției "open" despre care am vorbit anterior.

> Vom cere lui "open" sa deschidă fișierul in modul "append 

> care ne permite sa scriem după ultimul octet prezent in fișier. 

> Voi compila. 

> Voi executa programul. 

> Fișierul conține acum doua caractere "Z". 

> Si acum trei. 

> Vom încerca sa scriem ceva mai interesant in loc de "Z". 

> Voi redenumi funcția "ft_putchar" in "ft_putstr_fd 

> care va prelua un pointer la "char" drept parametru. 

> Si voi scrie "Hello world !\n". 

> Recompilez codul. 

> Execut programul. 

> Fișierul 42 conține valoarea "Hello worldl". 

> Pot lansa programul de mai multe ori pentru a scrie de tot atatea ori. 

> încheiem aici cu scrierea intr-un descriptor de fișier, ne revedem in videoul următor sa vedem cum putem citi dintr-un fișier.