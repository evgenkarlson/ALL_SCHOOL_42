# 4 - Code check #
Проверяем код на правильность.

### 4.1 - Code check: Norminette ###
Проверка кода на соответствие нормам  
В школе. Проверка файлов стандартной Norminette:
   * Для проверки использовать команду norminette -R CheckForbiddenSourceHeader в каталоге файлов типа .с
   * Для проверки файлов типа .h используется только norminette, без флагов
   * Альяс, который упрощает работу. В файле ~/.zshrc пропишите следующую строку (если файла ~/.zshrc нет то создайте его):
   ```alias norm="norminette -R CheckForbiddenSourceHeader"```. Затем перезапустите терминал и набирите norm.

Вне школы. Репозиторий [AzRunRCE](https://github.com/AzRunRCE/42-C-Norme)
   * Уже готовый .exe 42-C-Norme/bin/Debug/appRegex.exe. Код перемещаем в файл My_app.c и запускаем exe.
   * Установите ```sudo apt install mono-complete```, чтобы использовать .exe файлы на Linux через ```mono program.exe```.
   * Альяс, который упрощает работу. В файле ~/.zshrc пропишите следующую строку (если файла ~/.zshrc нет то создайте его):
    ```alias norm="cd /mnt/d/Work/21school/21school_piscine-c/.debug/ && mono appRegex.exe && cd -"``` Затем перезапустите терминал и набирите norm.

### 4.2 - Code check: 42Stupidity ###
❗️ Не стоить думать, что ваш код идеален, если он прошел все тесты 42Stupidity. Я вас предупредил. ❗️
Компилирует, тестит и проверяет официальной Norminette.
1.	Клонируем репоз. в домашний каталог в новую папку 42Stupidity
```
git clone https://github.com/mirror12k/42us-stupidity.git ~/42Stupidity
```
2.	Переходим в созданный каталог и создаем каталог, где будут храниться наши решения с файлами
```
cd ~/42Stupidity && mkdir day02/ex00
```
Или клонируем свой репоз. с выполненными заданиями day02 в текущий каталог
```
git clone vogsphere@vogsphere.21-school.ru:intra/2019/activities/piscine_c_day_02/nick day02
```
3.	spawn skript cоздает скрипты (сценарий проверки) для всех задач из каталога day02
```
./spawn.pl <day_repo> config_d<day_number>.pl
```
4.	Компилируем соотвествующий main.c для каждой функции
```
./tools/build.sh
```
5.	Проверяем наши ответы. Выполняем все тесты для каждой функции. Хорошие тесты будут отмечены, как 'good', ошибки будут выведены с большими восклицательными знаками.
```
./tools/check_all.sh
```
6.	Проверяем наши ответы на Normiette с соотвествующими флагами
```
./tools/verify.sh
```
7. Мои alias, мне так проще, не вините меня. У меня просто в папке .debug все эти инструменты для проверки
```
alias day03="cd /mnt/d/Work/21school/21school_piscine-c/.debug && ./spawn.pl ../03_day03 config_d03.pl && ./tools/build.sh && ./tools/check_all.sh && cd -"
```

### 4.3 - Code check: Towel ###
Упрощает работу (на основе 42Stupidity), действие в одну команду.
1. Клонируем репозиторий в домашний каталог в новую папку Towel
```
git clone https://github.com/oscardemadriz/towel.git ~/Towel
```
2. Переходим в созданный каталог ```cd ~/Towel```
2. Клонируем свой репоз. с выполненными заданиями day05 в текущий каталог Towel
```
git clone vogsphere@vogsphere.21-school.ru:intra/2019/activities/piscine_c_day_05/nick day05
```
3. Возможно понадобится сменить права доступа ```chmod +x towel.sh```
4. Проверяем на Norminette, комплируем и тестим ```./towel.sh day05```

### 4.4 - Code check: lifehack's
1. В ~/.zshrc, компилируем с флагами и проверяем main.c
```
alias main="gcc -Wall -Wextra -Werror main.c -o test && ./test"
```