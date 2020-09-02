# Instructions: #

* Только этот документ может служить в качестве справочника, не верьте слухам.
  > Only this page will serve as reference; do not trust rumors.
* Осторожно! Этот документ могут изменить за час до сдачи.
  > Watch out! This document could potentially change up to an hour before submission.
* Эти упражнения аккуратно расставлены в порядке сложности – от легких к сложным. Мы не примем во внимание, успешно выполненные сложные задачи, если легкие задачи не были верно выполнены.
  > These exercises are carefully laid out by order of difficulty - from easiest to hardest. We will not take into account a successfully completed harder exercise if an easier one is not perfectly functional.
* Будьте уверены, что ваши каталоги и файлы, в этих каталогах, имеют соответствующее права доступа.
  > Make sure you have the appropriate permissions on your files and directories.
* Вы должны следовать указаниям в каждой задаче.
  > You have to follow the submission procedures for every exercise.
* Ваши задачи будут проверены и оценены вашими одноклассниками.
  > Your exercises will be checked and graded by your fellow classmates.
* Ко всему прочему, ваши задачи будут проверены и оценены программой Moulinette.
  > On top of that, your exercises will be checked and graded by a program called Moulinette.
* Moulinette строга и дотошна в оценке ваших задач. Она полностью автоматизированна и нет другого пути, чтобы изменить оценку. Будьте максимально скрупулезным, чтобы избежать казусов.
  > Moulinette is very meticulous and strict in its evaluation of your work. It is entirely automated and there is no way to negotiate with it. So if you want to avoid bad surprises, be as thorough as possible.
* Задачи по Shell должны быть выполнены с `/bin/sh`.
  > Exercises in Shell must be executable with /bin/sh.
* Вы не можете оставить в каталоге больше файлов, чем указано в теме.
  > You cannot leave any additional file in your directory than those specified in the subject.
* Есть вопросы? Спроси у peer'ов справа или слева.
  > Got a question? Ask your peer on the right. Otherwise, try your peer on the left.
* Твой справочник называется Google / человек / интернет / ....
  > Your reference guide is called Google / man / the Internet / ....
* Изучите примеры тщательно. Они могут быть очень полезными в плане информации, которой может не упоминаться в теме...
  > Examine the examples thoroughly. They could very well call for details that are not explicitly mentioned in the subject...
* Проверьте раздел "C Piscine" на форуме в intranet.
  > Check out the "C Piscine" part of the forum on the intranet.
* By Odin, by Thor! Use your brain!!!

| !             |
| ------------- |
|	Время и дата, которые отражены в intra обозначают крайний срок сдачи вашей работы. По истечении указанного срока вы больше не сможете ничего сдать. Это время и дата также указывают на начало периода peer-проверки в соответствии с датами Бассейна по Си. Период peer-проверки длится 24 часа. После окончания 24 часов, отсутствующая peer-оценка станет 0s(:🚩некор._перевод🚩:) и вы получите оценку Moulinette.
> The time and date displayed on the intra indicate the deadline for your submission. Past that deadline, you won’t be able to hand in anything more. These time and date also indicate the start of the peer-evaluation period for the corresponding C Piscine date. This peer-evaluation period lasts exactly 24hrs. Once those 24hrs are up, your missing peer-grading will become 0s and you’ll receive Moulinette’s grade.

---

* Moulinette предвзята. Она не поймет и не затестит твой код, если он не соблюдает Norm'у. Moulinette основана на программе Norminator, которая проверяет файлы на соблюдение норм. TL;DR (too long; didn’t read / слишком длинно; не читал): будет тупо отправить часть работы, которая не будет проходить проверку через Norminator.
  > Moulinette is not very open-minded. It won’t try and understand your code if it doesn’t respect the Norm. Moulinette relies on a program called Norminator to check if your ﬁles respect the norm. TL;DR: it would be idiotic to submit a piece of work that doesn’t pass Norminator’s check.

* Использование запрещенных функций приравнивается к читерству. Читеры получат -42 и эта оценка не подлежит обсуждению.
  > Using a forbidden function is considered cheating. Cheaters get -42, and this grade is non-negotiable.
* Если ft_putchar() будет авторизованной функцией, то мы скомпилируем ваш код с нашим ft_putchar.c.
  > If ft_putchar() is an authorized function, we will compile your code with our ft_putchar.c.
* Если мы попросим саму программу, то вам будет достаточно предоставить main() функцию.
  > You’ll only have to submit a main() function if we ask for a program.
* Moulinette компилирует с этими флагами: -Wall -Wextra -Werror, и использует компилятор gcc.
  > Moulinette compiles with these flags: -Wall -Wextra -Werror, and uses gcc.
* Если твоя программа не скомпилируется, то ты получишь 0.
  > If your program doesn’t compile, you’ll get 0.

| !             |
| ------------- |
| Norminator должен быть запущен с флагом -R CheckForbiddenSourceHeader. Moulinette будет его тоже использовать
> Norminator must be launched with the -R CheckForbiddenSourceHeader flag. Moulinette will use it too.