# [Vim](https://ru.wikibooks.org/wiki/Vim) #
```
Зашел в вим
@
Не вышел
```

# Vim: Шпаргалка  #

`:term` – открыть терминал в vim

`:q!` – принудительно выйти

`:w` – сохранить

`:wq` – сохранить и выйти

`сtrl + w` – переключаться между окнами

Игра по vim: [vim-adventures.com]
Шпаргалка: [eax.me/vim-commands]



# Vim: [Vundle plugin manager](https://github.com/VundleVim/Vundle.vim)  #

`Vundle` - это сокращение от `Vim bundle`. Он упрощает установку плагинов и исполняемых файлов в `vim`

Vundle позволяет ...

 * отслеживать и настраивать плагины прямо в.vimrc
 * установить настроенные плагины (также известные как скрипты / пакет)
 * обновить настроенные плагины
 * поиск по названию всех доступных скриптов Vim
 * очистить неиспользуемые плагины
 * выполните вышеуказанные действия в одним нажатием клавиши с интерактивным режимом

Vundle автоматически ...

 * управляет путем выполнения ваших установленных скриптов
 * восстанавливает теги справки после установки и обновления



# Vim: 42header #
❗️ Плагин нужен только тем, кто работает на своем пк / ноутбуке. На компьютерах Школы все и так прекрасно работает. ❗️
Заголовок школы 42 - обязателен! Без него `Normanette` будет ругаться, а `Moulinette` откажется проверять.

 * Создаем папку под `vim` плагины в домашнем каталоге, если ее там нет:
```
mkdir -p ~/.vim/after/plugin
```

 * Скачиваем, перемещаем и удаляем из дом.каталога
```
git clone https://github.com/pandark/42header.vim.git ~/42header.vim

mv -v ~/42header.vim/plugin/42header.vim ~/.vim/after/plugin/

rm -rf ~/42header.vim
```

 * Настраиваем `$USER` и `$MAIL`. Заходим в `~/.bashrc` (или `~/.zshrc`) и прописываем строки:
```
export USER=*username*
export MAIL=*usermail*
```

 * Перезагружаем терминал и тестим в `vim` этой командой 
```
:FortyTwoHeader
```


 * Чтобы поменять с `:FortyTwoHeader` на `:Stdheader` - измените строку `187` в `~/.vim/after/plugin/42header.vim` на:
```
command! Stdheader call s:fortytwoheader()
```

 * Чтобы сделать печать заголовка при нажатии на f5, пропишите в файле `~/.vimrc`:
```
nmap <f5> :Stdheader<CR>
``` 
(если его нет, то создайте).

* Так же, вы можете использовать заголовок [[42 Header]](https://marketplace.visualstudio.com/items?itemName=kube.42header) через редактор [VSCode](https://code.visualstudio.com/).



# Vim: [Monokai тема](https://github.com/tomasr/molokai) + Syntax hightlight #
 * Создаем папку под настройки vim в домашнем каталоге, если ее там нет
```
mkdir -p ~/.vim/colors
```

 * Скачиваем, устанавливаем и удаляем скачанную папку
```
git clone https://github.com/sickill/vim-monokai.git ~/vim-monokai

mv -v ~/vim-monokai/colors/monokai.vim ~/.vim/colors/

rm -Rf ~/vim-monokai
```

 * [Airline](https://github.com/vim-airline/vim-airline): темы стрелок. Прописываем в `~/.vimrc` в раздел `bundle`:
```
Plugin 'vim-airline/vim-airline'
Plugin 'Yavor-Ivanov/airline-monokai-subtle.vim'
```

 * Прописываем в `~/.vimrc` в конце дока:

> Подсветка синтаксиса
   ```
   syntax enable
   ```

> Выбор цветовой схемы
   ```
   colorscheme monokai
   let g:airline_theme = 'monokai_subtle'
   ```

> Если стрелки не заработали
   ```
   let g:airline_powerline_fonts = 1
   ```

 * Для установки и обновления плагинов через `Vundle` в `vim` пишем 
```
:PluginInstall
``` 
и перезагружаем терминал



# Vim: Code lifehack's #

Пропишите данные команды в конце файла vim ~/.vimrc:

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

