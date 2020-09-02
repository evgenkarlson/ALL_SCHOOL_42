> Welcome to the bonus part of the day. This part isn't mandatory for today's exercises. But it'll be useful for your career as a developer. And for the rest of the bootcamp too. So earlier we talked about standard output Actually, it isn't 100% accurate...

Добро пожаловать в бонусную часть дня. Эта часть не является обязательной для сегодняшних упраженений, но она будет полезна в вашей карьере в роли разработчика и на протяжении самого бассейна тоже. Итак, ранее мы говорили о ст.п.вывода и на самом деле, он не на 100% точный.

> There are two types of outputs : standard output, and standard error. So using our favorite example : "cat file.txt" Everything went fine, the file's content is displayed on the standard output.

Существует два типа вывода: ст. поток вывода и ошибок. Итак, используем наш любимый пример: "cat file.txt", все прошло прекрасно, содержимое файла отобразилось в ст.п. вывода.

> However, if try doing "cat" on a file that doesn't exist, it'll display a message on the error output. Let's say I do a "cat file.txt | rev" The file's being displayed in reverse.Which means the file's content has been displayed on the standard output.

Однако, если мы попробуем выполнить "cat" на файле, который не существует, то нам отобразится сообщение в ст.п. ошибок. Допустим, я выполню "cat file.txt | rev". Содержимое файла отобразилось в обратном порядке, что означает что содержимое файла отобразилось в ст.п. вывода.

> The pipe's interpreted the standard output as the "rev"'s standard input and the "rev" has done its job. However, if I do this on a file that doesn't exist... cat will display the error on the standard error channel, "rev" won't read from this error channel, as it only reads from the standard output, which is now its standard input, so the message won't be displayed. It can be interesting. Or not.

Конвейер "|" интерпретировал ст.п. вывода, как ст.п. ввода "rev" и сам "rev" выполнил свою задачу. Однако, если я выполню это на несуществующем файле, то "cat" нам выведет ошибку в ст.п. ошибок, а "rev" не считать из этого ст.п. ошибок, т.к. он может считывать только из ст.п. вывода, который в данный момент является ст.п. ввода, все это значит, что сообщение не отобразится. Это все может быть занимательным, а может и нет.

> You may also reverse the error message if you want. How? By adding more redirections, If we want to redirect the standard error channel's message, and handle it as if it was a standard output, we'll do this... So 2 represents the standard error's output. the 1 represents the standard output.

Вы также можее реверсировать сообщение об ошибке, если захотите. Как? Добавив дополнительные переадресации, если мы хотим перенаправить сообщение ст.п. ошибок, и обработать его так, как если бы он был ст.п. вывода. Чтож, сделаем это. Итак, "2" представляет собой ст.п. вывода ошибок, а "1" - ст.п. вывода.

> We tell it that everything there is on the standard error channel has to be treated as if it was a standard output. So, if we add " | rev ", we can see the message is in reverse. Because it's been treated like a standard output. Identically, we can redirect everything that's in the standard error channel (2) into a file.

Мы говорим ему, что все, что есть в ст.п. ошибок, должно обрабатываться, как если бы это был ст.п. вывода. Итак, если мы добавим " | rev", то мы увидим сообщение в реверсе, потому что оно было обработано, как ст.п. вывода. Аналогично, мы можем перенаправить все, что есть в ст.п. ошибок "2" в файл.

> For example, if I do this ... I'm asking 2 to be redirected into "error" and keep everything that's in "error". we can see our earlier error message And once again, if we do this 2-3 times in a row, it's only displayed once, because it's been overwritten and there's a double redirection, which will allow you to place your error messages at the end of the file.

Например, если я сделаю это "cat azeaze 2> error", я прошу "2" перенаправить в "error" и сохранив все это в самом "error". Мы можем посмотреть наше предыдущее сообщение об ошибке (error), и еще раз, если мы сделаем это 2-3 раза подряд, то оно будет отображаться только один раз, потому что оно было перезаписано. Также ведь есть двойное перенаправление ">>", которое позволяет вам разместить сообщения об ошибках в конце файла.

> All of this can be quite practical if you have a list of files containing error messages, but you want to keep only the part that worked or only the part that didn't work, etc... Thanks to those redirections, you'll be able to gather all erroneous files into one error file.

Все это может быть вполне практичным, если у вас есть список файлов, которые содержат сообщения об ошибках, но вы хотите сохранить только ту часть, которая работала, или только ту, которая не работала и т.д.... Благодаря этим переадресациям, вы сможете собрать все ошибочные файлы в один файл с сообщениями об ошибках.

> Something else, that may be useful... a very special file ... that isn't really a file, but oh well... It's called "/dev/null" What is it? Basically, everything that's written towards "/dev/null" will simply be erased. Forgotten. So here, nothing's gonna happen. The "/dev/null" file doesn't really exist. So nothing's been added to it. Whatever. So what can we use it for?

И еще кое-что, то что может быть вам полезно. Очень особенный файл. На самом деле это не файл, но да ладно. Он называется "/dev/null". Что это? По сути, все что будет списано в "/dev/null", будет попросту стерто, забыто. Итак, тут ничего не произойдет, файл "/dev/null" на самом деле не существует. Так что ничего в него добавлено не было. Неважно. Так в каких ситуациях его можно применить?

> We can use it to delete a part, and keep only error messages, for example. If we want to display all error messages, it's a real mess. You need to go back up, check, and stuff... If we tell it "everything worked, redirect this towards /dev/null" ... and there you go! Displaying only error messages. So once again, this may be very practical for debugging or check whether your scripts work as they should. That's something very important to know for the future.

Мы можем применить его, например, для удаления какой-либо части и сохранения только сообщений об ошибках. У нас будет полный бардак, если мы захотим отобраить все сообщения об ошибках. Мы все время будем матать назад, проверять и все такое... Если мы скажем "Все что работает - перенаправить в /dev/null", и вуаля! Выводятся только сообщения об ошибках. Так что еще раз повторюсь, это может быть очень практично для отладки (debug) или проверки того, работают ли ваши скрипты так, как они должны работать. Это очень важно знать на будущее.