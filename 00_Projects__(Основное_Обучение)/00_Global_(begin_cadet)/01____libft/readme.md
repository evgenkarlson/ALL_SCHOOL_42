## Libft puzzles. Загадки первой библиотеки. [ENG/RUS]

### Authour: [@ftothmur](https://profile.intra.42.fr/users/ftothmur)
### [Orignal](https://forum.intra.42.fr/topics/20397/messages?page=1)

___

### Добрый день, друзья.

**Одна из самых волнующих меня частей проекта «libft» был квест: определить оптимальынй порядок проектирования функций. Это меня волнует до сих пор, и я решил поделиться с вами своими наработками. По сути это реализация принципа ["Не повторяй себя" или по-аглийски DRY](https://ru.wikipedia.org/wiki/Don%E2%80%99t_repeat_yourself)**

#### Что я обнаружил.
**Во-первых** то, что код многих функций повторяется. Результаты анализа сходситва я поместил в **таблицу 1**. «location boundary» – границы участка памяти. Он в таблице представлен двух видами: «buffer size» (это нечто подобное, но не равное массиву), и «string» (это блок памяти границы которого определены разделителем '\0'). Если этот показатель пуст, значит мы имеем дело с участком памяти определяемым иначе: например с базовым типом данных, или связанным перечнем, определение границ которых слишком отличается, чтобы укладываться в эту схему. «ptr arithmetic» говорит о перемещении указателя внутри функции. Почти всегда это связано с циклами. «assignment» определяет назначение, т. е. т.&nbsp;е. смену значения некоторых переменных внутри функции. Блок показателей «system» включает все возможные системные вызовы: «allocation» – выделение памяти, представленный «free» и «malloc», а также системой вводы и вывода «IO», из которых в пределах данного проекта доступна только одна функция: «write». Ещё подобные же блоки можно обнаружитьв рекомендацих других студентво для подготовки к экзаменам.

**Во-вторых**, можно выделить более сложные отношения, например частные случаи (А ⊆ Б. А являются вызовом функции Б, когда не менее одного параметра становятся константами). Можно также говорить о ⋂ (пересечении), ∪ (объединении), \ (строгом или, XOR), = (равенстве). Оставляю эти понятия работе вашей интуиции. (См. **рисунок 1**)

Почти все функции str имеют код подобный ft_strlen: ищут конец строки. Есть ряд функций, работающих с разделителем, только в его качестве используется или не конец строки, или не только он: ft_memchr, ft_strsplit и другие. Большинство прочих функций mem и некоторые другие зависимы от передаваемого им размера буфера.
Некоторые функции типа ft_strnlen работают одновременно и с размером буфера и с концом строки.

Несколько функций не представлены в задании явно, но могут быть очень полезны, если вы их напишите. Кстати они же могут послужить тем, что вы положите в раздел «бонус» для защиты. (См. **рисунок 2**).

## Коротко.
### Я предлагаю вашему вниманию **таблицу 2**, последний столбец которой содержит рекомендуемый мной порядок проектирования функций. Помните о том, что я писал про общий и частный случай, про сходства функций. Используйте эту информацию.
___
> &gt; _**Picture 1. Рисунок 1**_
> &gt; *ft_bzero ⊆ ft_memset, ft_strcpy ⊆ ft_memccpy, ft_strcmp ⊆ ft_strncmp, ft_strcat ⊆ ft_strncat, ft_strstr ⊆ ft_strnstr, ft_strequ ⊆ ft_strnequ, ft_ischar ⊆ ft_isalpha, (ft_isupper ∪ ft_islower) = ft_isalpha, (ft_isdigit ∪ ft_isalpha) = ft_isalnum ⊆ ft_isprint, (ft_isnotprint ∪ ft_isprint) = ft_isascii, ft_isspace ⊆ ft_isascii, ft_strnew ⊆ ft_memalloc, ft_strdel ⊆ ft_memdel, ft_strdup ⊆ ft_strjoin, ft_putnbr ⊆ ft_putnbr_fd, ft_putchar ⊆ ft_putchar_fd, ft_putstr ⊆ ft_putstr_fd ⊆ ft_putchar_fd, ft_lstdelone ⊆ ft_lstdel, ft_putendl ⊆ ft_putendl_fd ⊆ ft_putchar_fd, ft_strlen ⊆ ft_strnlen, ft_malloc ⊆ ft_realloc ⊆ ft_memjoin, (ft_itoa ⋂ ft_putnbr_fd) = ft_itostr, ft_strnequ \ ft_strncmp = logic_op().
Combinations (Комбинации): ft_strncpy : ft_strnlen + ft_strcpy + ft_bzero, ft_memccpy : ft_memcpy + ft_memchr, ft_memmove : ft_memcpy + ft_memrcpy, ft_memchr : ft_ischar etc. (и т.д.)*

___
- **ft_ischar**. Takes two character values, returns 1 if the characters are equal, and 0 otherwise. Принимает два символьных значения, возвращает 1, если символы равны, и иначе 0.
- **ft_islower**. Is an ASCII lowercase letter. Является ли строчной буквой из множества ASCII
- **ft_isnotprint**. Denial ft_isprint. Отрицание ft_isprint.
- **ft_isspace**. Whether the input character is a void character is one of 5 from ASCII set. Является ли входной символ знаком пустоты, одним из 5 из множества ASCII.
- **ft_isupper**. Is it an ASCII capital letter? Является ли заглавной буквой из множества ASCII?
- **ft_itostr**. Accepts an integer value and a pointer to a string. Converts an integer to a string. Принимает целое значение и указатель на строку. Преобразует целое в строку.
- **ft_memjoin**. Some combination of ft_realloc and ft_strjoin, but only the boundaries of the memory sections are the sizes of the buffers. Некоторое объединение ft_realloc и ft_strjoin, но только границами участков памяти выступают размеры буферов.
- **ft_memrcpy**. Copies, moving from the last character to the first. Копирует, двигаясь от последнего символа к первому.
- **ft_realloc**. The handwritten implementation of the function of the same name, only this can be better protected, and then there is no way to do without passing the size of the buffer. Рукописная реализация одноимённой функции, только эту можно лучше защитить, и тут никак не обойтись без передачи размера буфера.
- **ft_strnlen**. Returns the minimum value of the length of the string and the maximum size (buffer). Возвращает минимальное значение из длины строки и максимального размера (буфера).
___
### Table 2. Таблица 2.
| name/имя      | part/часть    | order/порядок |
| ------------- | ------------- | ------------- |
|ft_ischar      | Expansion	    |  1            |      
|ft_isdigit	    | Part1	        |  1            |   
|ft_islower	    | Expansion	    |  1            |
|ft_isspace	    | Expansion	    |  1            |
|ft_isupper	    | Expansion	    |  1            |
|ft_strrev 	    | Exapnsion     |  1            |
|ft_itostr	    | Expansion	    |  1            |
|ft_memcmp	    | Part1	        |  1            |
|ft_memcpy	    | Part1	        |  1            |
|ft_memset	    | Part1	        |  1            |
|ft_putchar_fd	|Part2          |  1            |
|ft_realloc	    |Expansion	    |  1            |   
|ft_striter	    |Part2	        |  1            |
|ft_strmap	    |Part2	        |  1            |
|ft_strnlen	    |Expansion	    |  1	          |
|ft_bzero	      |Part1		      |  2            |
|ft_atoi	      |Part1	        |  2            |
|ft_isalpha	    |Part1		      |  2            |
|ft_lstnew	    |Bonus		      |  2            |
|ft_memchr	    |Part1		      |  2            | 
|ft_memrcpy	    |Expansion	    |  2            | 
|ft_putchar	    |Part2		      |  2            |
|ft_putstr_fd	  |Part2	        |  2            |  
|ft_striteri	  |Part2		      |  2            |   
|ft_strlen	    |Part1		      |  2            |
|ft_strmapi	    |Part2		      |  2            |    
|ft_strncmp	    |Part1		      |  2            |   
|ft_tolower	    |Part1		      |  2            |   
|ft_toupper	    |Part1		      |  2            |   
|ft_isalnum	    |Part1		      |  3            | 
|ft_lstdelone	  |Bonus	        |  3            |   
|ft_memalloc	  |Part2		      |  3            |
|ft_memccpy	    |Part1		      |  3            |
|ft_memdel	    |Part2		      |  3            |
|ft_memmove	    |Part1		      |  3            |
|ft_power	      |Expansion	    |  3            |     
|ft_putendl_fd	|Part2	        |  3            |   
|ft_putstr	    |Part2		      |  3            | 
|ft_strcat	    |Part1		      |  3            |
|ft_strclr	    |Part2		      |  3            |
|ft_strcmp	    |Part1		      |  3            |
|ft_strcpy	    |Part1		      |  3            |
|ft_strjoin	    |Part2		      |  3            |
|ft_strnchr	    |Expansion	    |  3            |           
|ft_strnequ	    |Part2		      |  3            |
|ft_isprint	    |Part1		      |  4            |
|ft_itoa	      |Part2		      |  4            |
|ft_lstdel	    |Bonus		      |  4            |
|ft_putendl	    |Part2		      |  4            |
|ft_putnbr_fd   |Part2	        |  4            |      
|ft_strchr	    |Part1		      |  4            |      
|ft_strdel	    |Part2		      |  4            |     
|ft_strdup	    |Part1		      |  4            |      
|ft_strequ	    |Part2		      |  4            |     
|ft_strlcat	    |Part1		      |  4            |     
|ft_strncat	    |Part1		      |  4            |     
|ft_strncpy	    |Part1		      |  4            |    
|ft_strnew	    |Part2		      |  4            |      
|ft_strnotchr   |Expansion	    |  4            |                                           
|ft_strrchr	    |Part1		      |  4            |       
|ft_isascii	    |Part1		      |  5            |       
|ft_lstadd	    |Bonus		      |  5            |      
|ft_putnbr	    |Part2		      |  5            |       
|ft_strnstr	    |Part1		      |  5            |    
|ft_lstiter	    |Bonus		      |  6            |      
|ft_strstr	    |Part1		      |  6            |     
|ft_lstmap	    |Bonus		      |  7            |       
|ft_strsub	    |Part2	        |	 7            |      
|ft_strtrim	    |Part2		      |  7            |     
|ft_strsplit	  |Part2		      |  8            |
