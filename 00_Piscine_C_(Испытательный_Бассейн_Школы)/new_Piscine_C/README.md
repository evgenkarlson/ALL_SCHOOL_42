# Обновленный Бассейн по Си.

Чтобы разобраться в заданиях используйте обучающие видео `Школы 42` на 10-30 минут с теорией и примерами(используйте в плеере функцию субтитров и их перевода на нужный вам язык):

- [Shell and Git video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxxhvwi0PGmXb5isUdVwmsg8)
- Shell00
- Shell01
- [C00 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxz5wbzZn4tfUhF4djgzscB-)
- C00
- [C01 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxytsXWxZx6odBJMbRktIHTs)
- C01
- C02
- C03
- C04
- [C05 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxxZbeH9b0VC-nC6QsJRw5Ah)
- C05
- [C06 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxxDlCkkCX262SI90TsllYUW)
- C06
- [C07 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxzNYF00nlmx624twFlamqLt)
- C07
- [C08 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxxMI_GiGGb2hxMcd3IwNYRy)
- C08
- [C09 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxw6n6q_i8wek6U7t7CeAXhU)
- C09
- C10
- [C11 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxx8sKygTdqtOPytqN7sb0Vz)
- C11
- [C12 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxwmUOmyYSaI6gD1UyfF9MSj)
- C12
- [C13 video](https://www.youtube.com/playlist?list=PLVQYiy6xNUxzusAgMiybYwkLvuMFbVat9)
- C13


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

```
git clone <repo url> <folder to be created>    //Скачиваете копию репозитория с задниями

cd <path to cloned folder>                     //Перейти в скачанный каталог

mkdir ex00                                     //Создаем папку которая будет содержать выполненое задание

cd ex00                                        //Переходим в каталог где будем хранить выполненное задние.

vim <exercisename>.c                           //Пишем код.

gcc -Werror -Wall -Wextra <exercisename>.c     //Компилируем и проверяем код на ошибки.

ls -la                                         //Проверяем, что в папке с упражнениями нет посторонних файлов.

norminette -R CheckForbiddenSourceHeader       //Проверяем форматирование с помощью `Norminette`.

git add <exercisename>.c                       //Добавляем файлы, которые хотим зарегестрировать и запушить.

git commit <exercisename>.c -m "message"       //Регистрируем изменения, помечая их комментарием.

git push origin master                         //Загружаем файл на сервер, в предоставленный вам репозиторий (после первого раза вы сможете использовать просто `git push`).

переходите к следующему заданию...

```



# Карта Обновленного Бассейна по Си:

![map_of_old_Piscine_C](map_of_new_Piscine_C.png)
