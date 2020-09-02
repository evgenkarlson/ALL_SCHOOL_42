# 2 - bash #

### 2.1 - bash: Шпаргалка ###
```
cd *каталог* – перейти в каталог
cd .. – выйти на каталог ниже
ls -la – показать все файлы вкл. скрытые
rm Rf *каталог* - удалить каталог с файлами без запросов на резрешение удаления
sudo su – выйти в root
exit – выйти из root
dpkg --list - показать установленные пакеты
sudo apt-get purge --auto-remove packagename - удалить установленный пакет
```

### 2.2 - bash: upgrate to zsh to oh-my-zsh
Зачем переходить на zsh - [habr](https://habr.com/ru/post/326580/).

Установка под WSL:
1. Устанавливаем zsh sudo `apt-get install zsh`
2. Скачиваем и устанавливаем oh-my-zsh `sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"`
3. Перезагружаем терминал

Настройка:
1. Чтобы выбрать новую тему, в файле ~/.zshrc исправьте значение переменной `ZSH_THEME="agnoster"` и перезагрузите терминал.
   * Тема agnoster: для нормальной работы требуется скачать шрифты [fonts-powerline](https://github.com/powerline/fonts) и перезагрузка терминала.
     * Для VSCode: не забудьте скачать и установить сами шрифты себе, [DejaVuSansMono](https://github.com/powerline/fonts/tree/master/DejaVuSansMono).
       Заходим в терминал → кликаем   на значок слева сверху → Настройки → Шрифт → Выбираем `DejaVu Sans Mono for Powerline`.
   * Делим строку (~с текущей директорией и >input) на две строки: редактируем файл `~/.oh-my-zsh/themes/agnoster.zsh-theme` → 82 строка (раздел promt_end), `echo -n "%{%f%}"` меняем   на `echo -n "\n%{%f%}"`. Если хотите чтобы перед input у вас был символ ">", то `echo -n "\e[m\n>%{%f%}"` и перезагрузка терминала.
2. Чтобы были подсказки по установке пакетов - добавляем строчку в ~/.zshrc,  `. /etc/zsh_command_not_found`