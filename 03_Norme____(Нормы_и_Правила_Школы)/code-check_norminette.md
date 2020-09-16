# Проверка кода - Code check #

![pageimage](src/page1image3852832-small-13.png)


# 1. Установка программы Norminette #

> Если вы не в аудитории школы 42 и у вас не установлен Norminette то выполните по очередно эти команы.

Устанавливаем нужные для работы программы/библиотеки:
```
sudo apt install ruby ruby-bundler ruby-dev build-essential -y
```


Скачиваем само приложение Norminette из официального репозитория школы 42 и сохраняем туда откуда он должен будет работать:
```
git clone https://github.com/42Paris/norminette.git ~/.norminette/
```


Переходим в саму папку с искодниками програмы
```
cd  ~/.norminette
```


И запускаем сборку программы Norminette:
```
bundle
```


Для удобства использования мы возьмем `alias` и свяжем ассоциацией имя программмы с адресом до её исполняемого файла:
```
echo 'alias norminette="~/.norminette/norminette.rb"' >> ~/.bashrc
```


Зарегистрируем изменения:
```
source ~/.bashrc
```


> Если у вас `zsh` то файл будет называться `~/.zshrc`.



[[Видео по установке Norminette на Linux]](https://youtu.be/Y1Sz3GEzN6E)

[[Видео по установке Norminette на maOS]](https://youtu.be/MpoAev-ds-o)

[[Видео по установке Norminette на Windows]](https://youtu.be/hljxcMs_zxU)




# 2. Проверка кода на соответствие нормам через Norminette: #

* Для проверки файлов типа `.с` нужно использовать команду `norminette -R CheckForbiddenSourceHeader`:
```
norminette -R CheckForbiddenSourceHeader main.c
```

* Для проверки файлов типа `.h` используется только `norminette`, без флагов.
```
norminette header.h
```

* Если у вас `bash` то для быстрой проверки файла `main.c` в программе Norminette мы можем добавить в файл `~/.bashrc` ассоциацию в виде вот этой строчки(если файла `~/.bashrc` нет, то создайте его):
> Если у вас `zsh` то файл будет называться `~/.zshrc`.
```
alias norm="norminette -R CheckForbiddenSourceHeader"
```

Затем перезапустите терминал и чтобы проверить код в файле main.c набирите
```
norm main.c
```


# 3. Компиляция и проверка кода на критичные ошибки через компилятор gcc #

Для проверки файла `main.c` через стандартные проверяющие флаги компилятора - откройте терминал, перейдите в дерикторию с вашим файлом `main.c` и набирите:
```
gcc -Wall -Wextra -Werror main.c -o test
```

Так же, для ускорения процесса компиляции-проверки можно испотльзовать `alias`.

Добавляем в файл `~/.bashrc` ассоциацию в виде вот этой строчки(если файла `~/.bashrc` нет, то создайте его):

> Если у вас `zsh` то файл будет называться `~/.zshrc`.

```
alias main="gcc -Wall -Wextra -Werror main.c -o test"
```

Затем перезапустите терминал, перейдите в дерикторию с файлом `main.c` и набирите:
```
main
```
