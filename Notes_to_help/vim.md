#  Vim  #
```
Зашел в вим
@
Не вышел
```
Vim — мощный текстовый редактор с полной свободой настройки и автоматизации, возможными благодаря расширениям и надстройкам. Он позволяет работать с файлами даже в чистом текстовом (консольном) режиме.

Установка:
```
sudo apt install vim -y
```



# Шпаргалка  #

`:term` – открыть терминал в vim

`:q!` – принудительно выйти

`:w` – сохранить

`:wq` – сохранить и выйти

`сtrl + w` – переключаться между окнами

Игра по vim: vim-adventures.com

Шпаргалка: eax.me/vim-commands




# Устанавливаем заголовок 42 #

![](../03_Norme____(Нормы_и_Правила_Школы)/src/002.png)

Для создания заголовка `42header` мы используем плагин, который скачаем и установим с помощью пакетного менеджера `Vundle`.

> #### Плагин нужен только тем, кто работает на своем пк/ноутбуке. На компьютерах школы 42 все и так прекрасно работает.

* Чтобы скачать `Vundle` понадобится установить систему контроля версий `Git`(если `git` установлен пропустите этот пункт). 
```
sudo apt install git
```


* Теперь скачиваем `git` репозиторий c менеджером `Vundle`.
```
mkdir -p ~/.vim/bundle
git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim
```


* Далее мы настраиваем `Vim`и пакетный менеджер `Vundle`, а также запишем в очередь на установку наш плагин `42header`. Открываем файл настроек `~/.vimrc`(Если у вас такого файла нет то создайте его) и вставляем следующие настройки в конец файла:
```

set number
set cursorline
set cursorcolumn
set autoindent
set cindent
highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$\|\s+\s{1}/
highlight MoreThan80 ctermbg=blue guibg=blue
:2match MoreThan80 /\%81v.\+/
set tabstop=4
set shiftwidth=4


set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'pandark/42header.vim'

" Add plugins here

call vundle#end()
filetype plugin indent on


```


* Установим и обновим прописанные в `~/.vimrc` плагины. Откройте `vim` и выполните в нем команду:
```
:PluginInstall
```



* Пропишем в файле настроек нашей командной оболочки имя пользователя `$USER` и почту `$MAIL` для нашего заголовка `42header`. Заходим в `~/.bashrc` (или `~/.zshrc`если у вас такой) и прописываем там строки:
```
export USER=тут_будет_ваш_login
export MAIL=тут_будет_ваш_email
```


* Проверяем. Перезагружаем терминал и запускаем `vim`. Для проверки плагина используем эту команду:
```
:FortyTwoHeader
```


> Чтобы поменять команду с `:FortyTwoHeader` на команду `:Stdheader` - измените строку `187` в `~/.vim/bundle/42header.vim/plugin/42header.vim` на:
> ```
> command! Stdheader call s:fortytwoheader()
> ```


> Чтобы сделать печать заголовка при нажатии на кнопку `F5`, пропишите в файле `~/.vimrc`:
> ```
> nmap <f5> :Stdheader<CR>
> ``` 
> (если файла нет, то создайте его).




# Скачиваем и устанавливаем цветовую схему `Monokai` для подсветки кода #
```
mkdir -p ~/.vim/colors
git clone https://github.com/sickill/vim-monokai.git ~/vim-monokai
mv -v ~/vim-monokai/colors/monokai.vim ~/.vim/colors/
rm -Rf ~/vim-monokai
```


# Хитрости для Vim #


Пропишите эти команды в конце файла `~/.vimrc`, который содержит параметры программы `vim`. Они настроят некоторые части программы и упростят написание кода:

 * показать нумерацию строк
```
set number
```

 * Подсвечивает курсор
```
set cursorline
```

 * Подсвечивает текущую строчку
```
set cursorcolumn
```

 * Копирует отступы с текущей строки и добавляет их при добавлении новой
```
set autoindent
```

 * `cindent` копирует отступы с текущей строки и добавляет их при добавлении новой для `*.c` файлов
```
set cindent
```

 * Подсвечивает красным пробелы в конце строки
```
highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$\|\s+\s{1}/
```

 * Подсвечивает синим строку, если та будет превышать 80 знаков
```
highlight MoreThan80 ctermbg=blue guibg=blue
:2match MoreThan80 /\%81v.\+/
```

 * Определяет ширину 1-ой Tab'уляции в 4 пробела
```
set tabstop=4
```

 * Определяет ширину 1-ой Tab'уляции в 4 пробела, при сдвиге выделенного вертикального блока вправо
```
set shiftwidth=4
```

