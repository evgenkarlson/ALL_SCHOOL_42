# Cheatsheet - GitHub Markdown #

Источники:
* https://github.com/sandino/Markdown-Cheatsheet
* https://www.markdownguide.org/basic-syntax

---

## 0. Оглавление / Contents ##

* [0. Оглавление / Contents](#0-%d0%9e%d0%b3%d0%bb%d0%b0%d0%b2%d0%bb%d0%b5%d0%bd%d0%b8%d0%b5--contents)
* [1. Заголовки / Headers](#1-%d0%97%d0%b0%d0%b3%d0%be%d0%bb%d0%be%d0%b2%d0%ba%d0%b8--headers)

```md
* [1. Оглавление / Contents](#0-%d0%9e%d0%b3%d0%bb%d0%b0%d0%b2%d0%bb%d0%b5%d0%bd%d0%b8%d0%b5--contents)
```

---

## 1. Заголовки / Headers ##

# h1 #
## h2 ##
### h3 ###
#### h4 ####
##### h5 #####
###### h6 ######

Alt-H1
======

Alt-H2
------

```md
# h1 #
## h2 ##
### h3 ###
#### h4 ####
##### h5 #####
###### h6 ######

Alt-H1
======

Alt-H2
------
```

---

## 2. Игнорирование синтаксиса / Syntax ignore ##

\*literal asterisks\*

```md
\*literal asterisks\*
```

```md
Markdown provides backslash escapes for the following characters:

\ backslash
` backtick
* asterisk
_ underscore
{} curly braces
[] square brackets
() parentheses
# hash mark
+ plus sign
- minus sign (hyphen)
. dot
! exclamation mark
```

---

## 3. Ссылки / Links ##

* [Обычная ссылка в строке](https://www.google.com)
* [Обычная ссылка с title](https://www.google.com "Сайт Google")
* [Относительная ссылка на документ](../blob/master/LICENSE)
* <img src="https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png" width="15">
* ![text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Title is optional")

```md
* [Ссылка в строке](https://www.google.com)
* [Ссылка с title](https://www.google.com "Сайт Google")
* [Относительная ссылка на документ](../blob/master/LICENSE)
* <img src="https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png" width="15">
* ![text](https://github.com/adam-p/markdown-here/raw/master/src/common/images/icon48.png "Title is optional")
```

---

## 0. YouTube video ##

[![Boxxy](https://img.youtube.com/vi/Yavx9yxTrsw/0.jpg)](https://www.youtube.com/watch?v=Yavx9yxTrsw)

```md
[![Boxxy](https://img.youtube.com/vi/Yavx9yxTrsw/0.jpg)](https://www.youtube.com/watch?v=Yavx9yxTrsw)

[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/YOUTUBE_VIDEO_ID_HERE/0.jpg)](https://www.youtube.com/watch?v=YOUTUBE_VIDEO_ID_HERE)
```

---

## 4. Горизонтальные линии / Horizontal lines ##

Дефисы `---`

---

Звездочки `***`

***

Подчеркивание `___`

___

## 5. Списки / Lists ##

### Ненумерованный список ###

* Можно размечать звездочками
  * Item 2a
    * Item 3b

- Или минусами

+ Или плюсами

```md
* Можно размечать звездочками
  * Item 2a
    * Item 3b

- Или минусами

+ Или плюсами
```

### Нумерованный список ###

1. Первый пункт нумерованного списка
2. Второй пункт
   * Ненумерованный вложенный список.
3. Сами числа не имеют значения, лишь бы это были цифры
   1. Нумерованный вложенный список
4. И еще один пункт.

   Внутри пунктов списка можно вставить абзацы с таким же отступом. Обратите внимание на пустую строку выше и на пробелы в начале (нужен по меньшей мере один, но здесь мы добавили три, чтобы также выровнять необработанный Markdown).

   Чтобы вставить разрыв строки, но не начинать новый параграф, нужно добавить два пробела перед новой строкой.  
   Этот текст начинается с новой строки, но находится в том же абзаце.  
   (В некоторых обработчиках, например на Github, пробелы в начале новой строки не нужны.)

```md
1. Первый пункт нумерованного списка
2. Второй пункт
   * Ненумерованный вложенный список.
3. Сами числа не имеют значения, лишь бы это были цифры
   1. Нумерованный вложенный список
4. И еще один пункт.

   Внутри пунктов списка можно вставить абзацы с таким же отступом. Обратите внимание на пустую строку выше и на пробелы в начале (нужен по меньшей мере один, но здесь мы добавили три, чтобы также выровнять необработанный Markdown).

   Чтобы вставить разрыв строки, но не начинать новый параграф, нужно добавить два пробела перед новой строкой.  
   Этот текст начинается с новой строки, но находится в том же абзаце.  
   (В некоторых обработчиках, например на Github, пробелы в начале новой строки не нужны.)
```

---

## 6. Форматирование текста / Formatting text ##

_курсив 1_ или *курсив 2*  
__жирный текст 1__ или **жирный текст 2**  
___жирный курсив 1___ или ***жирный курсив 2***  
~~Зачеркнутый текст~~  
_Вы **можете** комбинировать ~~их~~_

```md
_курсив 1_ или *курсив 2*  
__жирный текст 1__ или **жирный текст 2**  
___жирный курсив 1___ или ***жирный курсив 2***  
~~Зачеркнутый текст~~  
_Вы **можете** комбинировать ~~их~~_
```

---

## 7. Перенос строки / New line ##

1. Для переноса на новую строку в конце предыдущей строки необходимо добавить два пробела `string1  `:  
   string1  
   string2  
   string3

   ```md
   string1  
   string2  
   string3
   ```

2. Пример текста с разрывом строки:  
   text1

   text2

   ```md
   text1

   text2
   ```

---

## 8. Код и подсветка синтаксиса / Code and syntax hightlight #

Блоки кода являются частью функций Markdown, но не подсветка синтаксиса. Однако многие обработчики, например Github или Markdown Here, поддерживают подсветку синтаксиса. Список поддерживаемых языков и способ их указания может различаться. Markdown Here поддерживает десятки языков (и не-языков, например синтаксис diff и заголовки HTTP); полный список и способ указания языков см. на странице [highlight.js demo-странице](https://highlightjs.org/static/demo/).

`Код` в строке обрамляется `обратными апострофами`.

```md
`Код` в строке обрамляется `обратными апострофами`.
```

Блоки кода выделяются либо тремя обратными апострофами ``` либо четырьмя пробелами в каждой строке. Рекомендуется использовать три апострофа, т.к. они проще и только они поддерживают подсветку синтаксиса.

```javascript
var s = "Подсветка JavaScript";
alert(s);
```

``````
```javascript
var s = "Подсветка JavaScript";
alert(s);
```
``````

```diff
- text in red
+ text in green
! text in orange
# text in gray
@@ purple @@
```

``````
```diff
- text in red
+ text in green
! text in orange
# text in gray
@@ purple @@
```
``````

---

## 9. Цитаты / Quotes ##

> С помощью цитат очень удобно в письме обозначать исходный текст.  
>> Эта строка - часть той же цитаты и является подцитатой.

Разрыв цитаты.

> Это очень длинная строка, но она будет правильно процитирована даже при размещении на нескольких строках. Продолжаем писать, чтобы эта строка не вмещалась на одной строке в любом окне. Кстати, в цитатах можно *использовать* **форматирование**.

```md
> С помощью цитат очень удобно в письме обозначать исходный текст.  
>> Эта строка - часть той же цитаты и является подцитатой.

Разрыв цитаты.

> Это очень длинная строка, но она будет правильно процитирована даже при размещении на нескольких строках. Продолжаем писать, чтобы эта строка не вмещалась на одной строке в любом окне. Кстати, в цитатах можно *использовать* **форматирование**.
```

---

## 10. Таблицы / Tables ##

| Вариант 1   | Вариант 2 | Вариант 3   |
| ----------- |----------:| :----------:|
| стандартная | Выровнять | Выровнять   |
| запись      | строки    | строки      |
| строк       | вправо    | по серидине |

```md
| Вариант 1   | Вариант 2 | Вариант 3   |
| ----------- |----------:| :----------:|
| стандартная | Выровнять | Выровнять   |
| запись      | строки    | строки      |
| строк       | вправо    | по серидине |
```

Вертикальные линии `|` обозначают столбцы. Внешние вертикальные линии не обязательны и нужны только, чтобы сам код Markdown выглядел красиво.

---

## 11. Emoji & Hotkey ##

### Emoji ###

:+1: :sparkles: :camel: :tada: :rocket: :metal:

```md
:+1: :sparkles: :camel: :tada: :rocket: :metal:
```

Ссылки на списки всех поддерживаемых emoji:
* [webfx.com](https://www.webfx.com/tools/emoji-cheat-sheet/)
* [ikatyang list](https://github.com/ikatyang/emoji-cheat-sheet#objects)

### Hotkey ###

<kbd>⌘F</kbd> + <kbd>⌘</kbd>

```md
<kbd>⌘F</kbd> + <kbd>⌘</kbd>
```

Ссылки на списки всех поддерживаемых alt-кодов:
* [posterpresentations.com](https://www.posterpresentations.com/alt-code-cheatsheet.html)

---

## 12. Список задач / Task lists ##

* [x] complete task
  * [x] complete subtask
* [ ] incomplete task
* [x] @mentions, #refs, [links](), **formatting**, and <del>tags</del> supported

```md
* [x] complete task
  * [x] complete subtask
* [ ] incomplete task
* [x] @mentions, #refs, [links](), **formatting**, and <del>tags</del> supported
```

---

## 13. Встроенный / Inline - HTML ##

Порой Markdown понимает чистый HTML.
<h3>HTML</h3>
<p> Some HTML code here </p>

<dl>
  <dt>Список определений</dt>
  <dd>Это то, что люди иногда используют.</dd>

  <dt>Markdown внутри HTML</dt>
  <dd>Работает *не очень** хорошо. Используйте HTML-<em>теги</em>.</dd>
</dl>

```html
<h3>HTML</h3>
<p> Some HTML code here </p>

<dl>
  <dt>Список определений</dt>
  <dd>Это то, что люди иногда используют.</dd>

  <dt>Markdown внутри HTML</dt>
  <dd>Работает *не очень** хорошо. Используйте HTML-<em>теги</em>.</dd>
</dl>
```

<details>
   <summary>Title 1</summary>
      <p>Content 1 Content 1 Content 1 Content 1 Content 1</p>
</details>

```html
<details>
   <summary>Title 1</summary>
      <p>Content 1 Content 1 Content 1 Content 1 Content 1</p>
</details>
```