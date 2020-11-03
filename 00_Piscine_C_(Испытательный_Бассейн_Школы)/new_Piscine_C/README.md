# Обновленный Бассейн по Си.

Чтобы разобраться в заданиях используйте обучающие видео `Школы 42` на 10-30 минут с теорией и примерами(используйте в плеере функцию субтитров и их перевода на нужный вам язык):

- [Shell and Git video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxxhvwi0PGmXb5isUdVwmsg8)
- [C00 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxz5wbzZn4tfUhF4djgzscB-)
- [C01 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxytsXWxZx6odBJMbRktIHTs)
- [C05 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxxZbeH9b0VC-nC6QsJRw5Ah)
- [C06 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxxDlCkkCX262SI90TsllYUW)
- [C07 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxzNYF00nlmx624twFlamqLt)
- [C08 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxxMI_GiGGb2hxMcd3IwNYRy)
- [C09 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxw6n6q_i8wek6U7t7CeAXhU)
- [C11 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxx8sKygTdqtOPytqN7sb0Vz)
- [C12 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxwmUOmyYSaI6gD1UyfF9MSj)
- [C13 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxzusAgMiybYwkLvuMFbVat9)
> Как правило, информации из видео никогда не будет достаточно. Поэтому всю нужную информацию для обучения вы ищите самостоятельно через интернет!




# Базовый рабочий процесс в стенах Школы 42

#### Ваш основной рабочий процесс в стенах `Школы 42` будет примерно таким:

- Вы регистрируетесь в проекте и дожидатесь создания вашего репозитория `git`.
- Копируете `URL` адрес репозитория и клонируете его в папку на вашем компьютере.
- Создаете папку для первого упражнения внутри папки репозитория.
- Создаете файл для первого упражнения.
- Выпоняете упражнение.
- Проверяете наличие дополнительных файлов.
- Проверяете файл через `Norminette`.
- Загружаете выполненное вами задние в ваш `git` репозиторий и переходите к следующему упражнению.
- Убедитесь, что вы все отправили(`git push`).
- `Moulinette` должен будет проверить вашу работу.


#### Или, выражаясь чуть терминами из командной строки…:

- Скачиваете копию репозитория с задниями:
```
	git clone <repo url> <folder to be created>
```

- Переходите в скачанный каталог:
```
	cd <path to cloned folder>
```

- Создаете папку которая будет содержать выполненое задание:
```
	mkdir ex00
```

- Переходите в каталог где будет храниться выполненное задние:
```
	cd ex00
```

- Пишете код:
```
	vim <exercisename>.c
```

- Компилируете и проверяете код на ошибки:
```
	gcc -Werror -Wall -Wextra <exercisename>.c
```

- Проверяете, что в папке с упражнениями нет посторонних файлов:
```
	ls -la
```

- Проверяете форматирование с помощью `Norminette`.
```
	norminette -R CheckForbiddenSourceHeader
```

- Добавляете файлы, которые хотим зарегестрировать и запушить:
```
	git add <exercisename>.c
```

- Регистрируете изменения, помечая их комментарием:
```
	git commit <exercisename>.c -m "message"
```

- Загружаете файл на сервер, в предоставленный вам репозиторий (после первого раза вы сможете использовать просто `git push`):
```
	git push origin master
```

- переходите к следующему заданию...




# Карта Обновленного Бассейна по Си:

![](map_of_the_new_Piscine_C.png)
