# Cheatsheet - VSCode #

### 1 - Extensions ###
Easy Code
   * [Settings Sync](https://marketplace.visualstudio.com/items?itemName=Shan.code-settings-sync)
   * [Тема one-monokai / Monokai](https://marketplace.visualstudio.com/items?itemName=azemoh.one-monokai)
   * [Color Highlight / #RGB](https://marketplace.visualstudio.com/items?itemName=naumovs.color-highlight)
   * [Trailling spaces](https://marketplace.visualstudio.com/items?itemName=shardulm94.trailing-spaces)
   * [SirTori / Выделяет текущую глубину отступа](https://marketplace.visualstudio.com/items?itemName=SirTori.indenticator)
   * [Умное выравнивание колонок](https://marketplace.visualstudio.com/items?itemName=lmcarreiro.vscode-smart-column-indenter)
   * [MultiColorHighlighter](https://marketplace.visualstudio.com/items?itemName=456ken.multicolorhighlighter)
   * [Great Icons](https://marketplace.visualstudio.com/items?itemName=emmanuelbeziat.vscode-great-icons)
   * [Error Lens](https://marketplace.visualstudio.com/items?itemName=usernamehw.errorlens)
   * [C# Colors](https://marketplace.visualstudio.com/items?itemName=logerfo.csharp-colors)
   * [TODO Tree](https://marketplace.visualstudio.com/items?itemName=Gruntfuggly.todo-tree)
   * [favorites](https://marketplace.visualstudio.com/items?itemName=howardzuo.vscode-favorites)

Comment
   * [Comment Anchors](https://marketplace.visualstudio.com/items?itemName=ExodiusStudios.comment-anchors)
   * [Better Comment / через Ctrl+/](https://marketplace.visualstudio.com/items?itemName=Gruntfuggly.bettercomment)
   * [Comment divider](https://marketplace.visualstudio.com/items?itemName=stackbreak.comment-divider)

GitHub Markdown
   * [Markdown All in One / для работы с .md](https://marketplace.visualstudio.com/items?itemName=yzhang.markdown-all-in-one)
   * [Markdown table from CSV/TSV](https://marketplace.visualstudio.com/items?itemName=jojoco.markdownfromcsv)
   * [Github Markdown Preview](https://marketplace.visualstudio.com/items?itemName=bierner.github-markdown-preview)

Other
   * [pdf preview](https://marketplace.visualstudio.com/items?itemName=tomoki1207.pdf)

### 2 - settings.json ###
```
{
  "editor.minimap.enabled": false,     // disable mini-map
}
```

### 3 - Windows 10: Code Debug with Mingw-w64 ###
Установка [Mingw-w64](https://code.visualstudio.com/docs/cpp/config-mingw):
1. Скачиваем [Mingw-w64](http://mingw-w64.org/doku.php/download/mingw-builds) через Sourceforge и запускаем установщик. Прописываем путь установки в `C:\`
2. Для возможности использования инструментов в cmd.exe: перейдите в Мой компьютер / Свойства / Дополнительные параметры системы / Дополнительно / Переменные среды / Переменные среды для пользователя Username / Path → Изменить → Создать `C:\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin`.
3. Открываем cmd и пишем `gcc -v`, чтобы проверить работоспособность.

Настройка VSCode / debug:
1. Устанавливаем recommended расширения по типу [С++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
2. Меняем настройки терминала Ctrl+Shift+P / Preferences: Open Settings (JSON) / settings.json
```
{
  "terminal.integrated.shell.windows": "C:\\Windows\\System32\\cmd.exe", // [debug error] prevent fails of build task with defaultshell = powershell
}
```
3. Переходим к коду, который будем debug'ить: File / Open Workspace / *ваш проект* / main.c
4. Создаем `tasks.json`: Terminal / Configure Tasks:
```
{
  "tasks": [
    {
      "type": "shell",
      "label": "gcc.exe build active file",
      "command": "C:\\mingw-w64\\i686-8.1.0-posix-dwarf-rt_v6-rev0\\mingw32\\bin\\gcc.exe",
      "args": 
      [
        "-Wall",
        "-Wextra",
        "-Werror",
        "-g",
        "${file}",
        "-o",
        "${fileDirname}\\${fileBasenameNoExtension}.exe"
      ],
      "options": {
        "cwd": "C:\\mingw-w64\\i686-8.1.0-posix-dwarf-rt_v6-rev0\\mingw32\\bin"
      }
    }
  ],
  "version": "2.0.0"
}
```
5. Переходим опять к main.c и создаем `launch.json`: Debug / Add Configuration:
```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Build (gcc) and debug (gdb) active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:\\mingw-w64\\i686-8.1.0-posix-dwarf-rt_v6-rev0\\mingw32\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "gcc.exe build active file"
        }
    ]
}
```
6. Переходим опять к main.c и Debug / Start Debugging
7. Переключаемся через терминалы (WSL) через [Shell launcher](https://marketplace.visualstudio.com/items?itemName=Tyriar.shell-launcher)
```
{
    "shellLauncher.shells.windows": 
    [
        {
            "shell": "C:\\Windows\\System32\\wsl.exe",
            "label": "WSL Bash"
        },
        {
            "shell": "C:\\Windows\\System32\\cmd.exe",
            "label": "cmd"
        },
        {
            "shell": "C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe",
            "label": "PowerShell"
        },
        {
            "shell": "C:\\Program Files\\Git\\bin\\bash.exe",
            "label": "Git bash"
        }
    ],
}
```