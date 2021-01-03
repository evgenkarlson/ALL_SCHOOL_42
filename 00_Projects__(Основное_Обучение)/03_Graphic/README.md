# Ветвь Графики


![graphic branch](./graphic.gif)


---------------------------------------------------------------------


<details>
<summary> КАРТА ПРОЕКТОВ </summary>

![map Holy_Graph](../Holy_Graph.png)

</details>


---------------------------------------------------------------------


<details>
<summary> БИБЛИОТЕКА MiniLibX </summary>

 </br>

`MiniLibX` - это простая библиотека отрисовки графики интерфейса `X-Window`/`Cocoa`, используемая студентами Школы 42 для решения проектов `ветки Графики`.

Она предостовляет возможность создания графического программного обеспечения без каких-либо знаний в области программирования `X-Window`. Библиотека обеспечивает инструментами для простого создание окна, рисования, управления изображениями, а так же управления основными событиями(нажатия клавиатуры, движение мыши).

## УСТАНОВКА MiniLibX НА LINUX

Для решения проектов ветки Графики вам понадибится библиотека для отрисовки графики.

На компьютерах в Школе 42 эта библиотека уже установлена по умолчанию. 

Но если вы решаететь проекты из дома используя `Linux` то вам нужно будет установить эту библиотеку самому, за несколько простых шагов используя по очереди в вашем терминале эти команды:

```
sudo apt update
sudo apt-get install -y libglu1-mesa-dev
sudo apt-get install -y freeglut3-dev
sudo apt-get install -y mesa-common-dev
sudo apt-get install -y libxext-dev
sudo apt-get install -y libxrandr-dev
sudo apt-get install -y libx11-dev
sudo apt-get install -y libbsd-dev 
sudo apt-get install -y libssl-dev

cd /usr/local/man/
sudo mkdir man1
cd ~
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make

sudo cp man/man1/* /usr/local/man/man1/
sudo cp libmlx.a /usr/local/lib/
sudo cp mlx.h /usr/local/include/
```

> При сборке `make` может вывести множество предупреждений, но это не значит, что оно не работает!

> Чтобы посмотреть страницу руководства MiniLibX откройте ссылки ниже или используйте в терминале команду: `man mlx`


## РУКОВОДСТВА ПО БИБЛИОТЕКЕ MiniLibX :

* [mlx](./minilibx_(library_for_solving_projects_of_this_branch)/man_mlx.md) - описание библиотеки;
* [mlx_new_window](./minilibx_(library_for_solving_projects_of_this_branch)/man_mlx_new_window.md) - управление окнами;
* [mlx_pixel_put](./minilibx_(library_for_solving_projects_of_this_branch)/man_mlx_pixel_put.md) - вывод пикселей и рисование внутри окна;
* [mlx_new_image](./minilibx_(library_for_solving_projects_of_this_branch)/man_mlx_new_image.md) - манипулирование изображениями;
* [Руководство по использованию изображений в minilibX](./minilibx_(library_for_solving_projects_of_this_branch)/how_use_images_in_mimilibx.md)
* [mlx_loop](./minilibx_(library_for_solving_projects_of_this_branch)/man_mlx_loop.md) - обработка событий клавиатуры или мыши;


## ЛИНКОВКА С БИБЛИОТЕКОЙ MiniLibX

Чтобы использовать функции `MiniLibX`, вам необходимо связать свое программное обеспечение с несколькими библиотеками, включая саму библиотеку `MiniLibX`. Для этого при компиляции проекта используйте флаги `-lbsd -lmlx -lXext -lX11` во время линковки. Пример:

		gcc -Wall -Wextra -Werror main.c -lbsd -lmlx -lXext -lX11

или следующие:

		gcc -Wall -Wextra -Werror main.c -lmlx -lXext -lX11


Если вам потребуется указать путь к этим библиотекам, используйте флаг `-L`.

		gcc main.c -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11


> Чтобы использовать функции `MiniLibX` на `macOS`, вам будет нужно связать свое программное обеспечение не только с библиотекой MiniLibX но и с несколькими системными фреймворками:
> 
>		gcc -Wall -Wextra -Werror main.c -lmlx -framework OpenGL -framework AppKit

## ИСТОЧНИКИ:

  * [Домашний репозиторий библиотеки minilibx](https://github.com/42Paris/minilibx-linux)
  * [Установка библиотеки minilibX](https://achedeuzot.me/2014/12/20/installer-la-minilibx/)
  * [Руководство по библиотеке `miniLibX`](https://harm-smits.github.io/42docs/libs/minilibx)
  * [Руководство по использованию изображений в minilibX](./minilibx_(library_for_solving_projects_of_this_branch)/how_use_images_in_mimilibx.md)


</details>




---------------------------------------------------------------------



<details>
<summary> ПОЛЕЗНЫЕ ССЫЛКИ ПО ПРОЕКТАМ ГРАФИЧЕСКОЙ ВЕТВИ </summary>

 </br>


## fdf (ft_wireframe)

> РАСТЕРИЗАЦИЯ И ОТОБРАЖЕНИЕ КАРКАСА ИЗ ФАЙЛА

* Формат `XPM` и `BMP` - вы должны уметь загружать изображения и сохранять их в стандартном формате:
  - [Формат `X PixMap`(XPM)](https://en.wikipedia.org/wiki/X_PixMap)
  - [Формат `BMP`](https://en.wikipedia.org/wiki/BMP_file_format)
  - [Конвертёр `XMP`](https://www.online-utility.org/image/convert/to/XMP)
  - [Создание "BMP" изображений на чистом "C"](https://stackoverflow.com/a/47785639)
  - [Формат BMP на StackOverflow](https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries)
  - [Объяснение формата BMP](https://web.archive.org/web/20080912171714/http://www.fortunecity.com/skyscraper/windows/364/bmpffrmt.html)
  - [документация по функции open()](https://man7.org/linux/man-pages/man2/open.2.html)
  - [Использование режима аргумента "O_CREAT"](https://stackoverflow.com/a/28466757)
* [Изучение компьютерной графики с нуля на `Scratchapixel.com`](https://www.scratchapixel.com/)
* [ВИДЕО ПО ЛИНЕЙНОЙ АЛГЕБРЕ [RU]](https://www.youtube.com/channel/UC6hAYNOWMmuqOBvFOuAFKwA)
* [ЛИНЕЙНАЯ АЛГЕБРА ДЛЯ РАЗРАБОТЧИКОВ ИГР [RU]](https://habr.com/ru/post/131931/)
* [Сущность линейной алгебры](https://www.youtube.com/playlist?list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab)
* [Вектор](https://www.khanacademy.org/math/linear-algebra/vectors-and-spaces/vectors/v/vector-introduction-linear-algebra)
* [Линейные комбинации и промежутки векторов](https://www.khanacademy.org/math/linear-algebra/vectors-and-spaces/linear-combinations/v/linear-combinations-and-span)
* [Вращение матрицы](https://en.wikipedia.org/wiki/Rotation_matrix)
* [Руководство по Перспективной проекции и трансформации](./books_for_graphics/perspective_projection.pdf)
* [Ecere 3D Coding Black Hole Tutorial](http://www.ecere.com/3dbhole/)
* [Алгоритм рисования линий DDA](https://www.youtube.com/watch?v=W5P8GlaEOSI)
* [Цифровой дифференциальный анализатор](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))
* [Алгоритм](https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/) рисования линии Брезенхема и [[видео с алгоритмом]](https://www.youtube.com/watch?v=RGB-wlatStc)
* [Линейный алгоритм Брезенхема - Википедия](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)
* [Математика для цветового градиента](https://stackoverflow.com/questions/12554614/maths-for-color-gradient)
* [Обнаружение видимой поверхности](https://www.tutorialspoint.com/computer_graphics/visible_surface_detection.htm)
* [3D Вращение](https://behreajj.medium.com/3d-rotations-in-processing-vectors-matrices-quaternions-10e2fed5f0a3)
* [Матрицы предварительного расчета](https://www.khanacademy.org/math/precalculus/precalc-matrices)
* [Линейная интерполяция](https://en.wikipedia.org/wiki/Linear_interpolation)
* [Кривая `Лиссажу`](https://en.wikipedia.org/wiki/Lissajous_curve)
* [Линейный алгоритм Сяолинь Ву](https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm)
* [Матрицы в математике](https://en.wikipedia.org/wiki/Matrix_(mathematics))
* [Преобразования матриц - OpenGL](https://open.gl/transformations)
* [Введение в Матрицы](https://www.khanacademy.org/math/precalculus/x9e81a4f98389efdf:matrices/x9e81a4f98389efdf:mat-intro/v/introduction-to-the-matrix)
* [Преобразование в 3D](https://www.cs.uic.edu/~jbell/CourseNotes/ComputerGraphics/3DTransforms.html)


## fract`ol (ft_fractal)

> ВИЗУАЛИЗАЦИЯ `ТРИПОВОГО` НАБОРА ФРАКТАЛОВ - `Mandelbrot` & `Julia`

* [Действительные, мнимые, комплексные числа.](https://www.wikihow.com/Plot-the-Mandelbrot-Set-By-Hand)
Найдите мнимые числа. Добавьте числа в функцию для Мандельброта.
* [Ниже макрос для формулы, который может быть полезен. Масштабируйте диапазон до известного минимума и максимума](https://stackoverflow.com/questions/5294955/how-to-scale-down-a-range-of-numbers-with-a-known-min-and-max-value)
* [Множества `Julia` и `Mandelbrot`. Руководство](https://lodev.org/cgtutor/juliamandelbrot.html)
* [Понимание множеств `Julia` и `Mandelbrot` - Карл Симс](http://www.karlsims.com/julia.html)
* [Рисование множества Мандельброта вручную](https://www.wikihow.com/Plot-the-Mandelbrot-Set-By-Hand)
* [Учебник по множеству `Mandelbrot`](https://jonisalonen.com/2013/lets-draw-the-mandelbrot-set/)
* [Фрактал `Julia` (Википедия)](https://en.wikipedia.org/wiki/Julia_set)
* [Альтернативные фракталы: 4d `Julia`](http://www.relativitybook.com/CoolStuff/julia_set_4d.html)
* [Код отрисовки `Julia`](https://stackoverflow.com/questions/33978167/julia-set-rendering-code)
* [Фрактал `Apollony`](https://prezi.com/k91ydacvfjqp/apollonian-gasket-fractal/)
* [Фрактал  Аполлония Пергского - `Apollony` (Википедия)](https://en.wikipedia.org/wiki/Apollonian_gasket)
* [Серпинский ковер - Википедия](https://en.wikipedia.org/wiki/Sierpi%C5%84ski_carpet)
* [Альтернативные фракталы](http://www.relativitybook.com/CoolStuff/julia_set.html)
* [Анимированный фрактал в реальном времени всего из 32 строк кода Javascript](http://slicker.me/fractals/animate.htm)
* [Видео по вселеной фракталов](http://www.fractal-animation.net/ufvp.html)
* [Фрактальное вдохновение на 'Deviantart'](https://www.deviantart.com/lyc/gallery)
* [Гиперсложные фракталы](http://bugman123.com/Hypercomplex/)
* [Альтернативные фракталы: наглядное руководство по фрактальной геометрии и дизайну](https://books.google.co.uk/books?id=SJRNoOaXs2wC)
* [Эксперименты со фракталами](https://github.com/foobar167/fractals)
* [Бесконечное деление конгруэнтных сходств](http://www.benpadiah.com/MISC_diagrams/pages/equations/holognomon.html)
* [Масштабирование диапазона до известного минимума и максимума](https://stackoverflow.com/questions/5294955/how-to-scale-down-a-range-of-numbers-with-a-known-min-and-max-value)
* [Примеры рекурсии на `Java`]()
* [Bugman123](http://bugman123.com/index.html)


## rt_v1 (miniRT)

> СОЗДАНИЕ ТРАССИРОВЩИКА ЛУЧЕЙ

* [Лекция 'Калифорнийского университета' в 'Дэвисе': 49 минут](https://www.youtube.com/watch?v=Ahp6LDQnK4Y)
* [Практическое руководство от `Disney` про отслеживание пути: 10 минут](https://www.youtube.com/watch?v=frLwRLS_ZR0)
* [Трассировка Лучей [ en ]](https://users.csc.calpoly.edu/~zwood/teaching/csc471/final09/nkowshik_webpage/)
* [Введение в трассировку лучей: простой метод создания 3D-изображений](https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-ray-tracing)
* [Минимальный трассировщик лучей: рендеринг простых фигур [ en ]](https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes)
* [Написание Трассировки Лучей в Rust](https://bheisler.github.io/post/writing-raytracer-in-rust-part-1/)
* [Курс 1 по трассировке лучей / трассировке пути](https://www.youtube.com/watch?v=1HYhrx9bzP8&ab_channel=NicolasBonneel)
* [Основы трассировки лучей, Часть 1: Основы трассировки лучей [ en ]](https://www.youtube.com/watch?v=gBPNO6ruevk&feature=youtu.be&ab_channel=NVIDIADeveloper)

* Книги по трассировке лучей:
  - [Главное о трассировке лучей](./books_for_graphics/basic_algo_ray_tracing.pdf)
  - [Основы трассировки лучей](./books_for_graphics/fundamentals_of_ray_tracing.pdf)
  - [Учебное пособие по трассировке лучей от команды 'Codermind'](./books_for_graphics/codermind_ray_tracing_tutorial.pdf)
  - [Практическое руководство - "Трассировка лучей за одни выходные"](./books_for_graphics/ray_tracing_in_a_weekend.pdf)
  - [Самоцветы с трассировкой лучей. Высококачественный рендеринг в реальном времени с помощью DXR и других API](./books_for_graphics/unofficial_ray_tracing_gems.pdf)
  - [Задача трассировщика лучей. Руководство по тестированию вашего первого 3D-рендерера](./books_for_graphics/jamis_buck_-_the_ray_tracer_challenge.epub)


## wolf3d (cub3d)

> СОЗДАНИЕ ИГРОВОГО ДВИЖКА, ТАКОГО ЖЕ КАК В ИГРЕ `wolfenstein`, C ПРОБРОСКОЙ ЛУЧЕЙ(`raycasting`)

* [Книга о том как создавался `Wolfenstein 3D`. О том как конкретно 'id Software' удалось превратить компьютер предназначеный для отображения статических изображений, текстовых редакторов и электронных таблиц в лучшую игровую платформу в мире, способную запускать игры со скоростью семьдесят кадров в секунду](./books_for_graphics/Wolfenstein_3D__Fabien_Sanglard_Game_Engine_Black_Book__CreateSpace.pdf)
* [Проброска лучей(`raycasting`) - Википедия](https://en.wikipedia.org/wiki/Ray_casting)
* [Полное руководство по проброске лучей(raycasting) 'Lode' ](http://lodev.org/cgtutor/raycasting.html)
* [Полное руководство по проброске лучей(raycasting) на французском языке (перевод английского руководства)](http://forums.mediabox.fr/wiki/tutoriaux/flashplatform/affichage/3d/raycasting)
* [Учебное пособие по `raycasting`. Теория](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
* [Создание 3D-движка в стиле Doom на C](https://www.youtube.com/watch?v=HQYsFshbkYw&ab_channel=Bisqwit)
* [Пример браузерной версии игры Wolfenstein 3D](http://users.atw.hu/wolf3d/)
* [Проброска лучей(raycasting) в JS](http://www.playfuljs.com/a-first-person-engine-in-265-lines/)
* [Учебное пособие по проброске лучей(`raycasting`) в `JS`](http://www.playfuljs.com/a-first-person-engine-in-265-lines/)
* [Движок от первого лица в 265 строках на JS](www.playfuljs.com/a-first-person-engine-in-265-lines/)
* [Проброска лучей(`raycasting`) через `Canvas`(инструмент для отрисовки в браузере)](https://mdn.github.io/canvas-raycaster/index.html)
* [Параллакс](https://en.wikipedia.org/wiki/Parallax)
* [Ортографическая проекция](https://en.wikipedia.org/wiki/Orthographic_projection)
* [Пример карт высот с проброской лучей(`raycasting`)](https://github.com/s-macke/VoxelSpace)
* [Изучение периферийного зрения в играх (с помощью Quake)](https://github.com/shaunlebron/blinky)
* [Карданный подвес как поворотная опора](https://en.wikipedia.org/wiki/Gimbal)
* [Блокировка Карданного подвеса](https://en.wikipedia.org/wiki/Gimbal_lock)
* [Технический доклад по системной инженерии](https://www.youtube.com/watch?v=lHLpKzUxjGk&ab_channel=UMKCSchoolofComputingandEngineering)
* [Stackoverflow question: `clock_gettime`](http://stackoverflow.com/questions/5167269/clock-gettime-alternative-in-mac-os-x)
* [Код для альтернативы `clock_gettime` в `os x`](https://gist.github.com/jbenet/1087739)


## ft_vox

> ГЕНЕРИРОВАНИЕ ЛАНДШАФТА

* [Реалистичный ландшафт в 130 строках на JS](http://www.playfuljs.com/realistic-terrain-in-130-lines/)


</details>


---------------------------------------------------------------------

### Материалы по Графике

  * [Эксперименты с Haxiomic GPU Fluid](http://haxiomic.github.io/GPU-Fluid-Experiments/html5/)
  * [Учебник по компьютерной графике от 'Lode'](https://lodev.org/cgtutor/)
  * [Учебники по компьютерной графике в `Javascript`](http://www.playfuljs.com/)
  * [OpenGL руководство для начинающих](http://www.opengl-tutorial.org/beginners-tutorials/)
  * [Песочница для экспериментов с графикой - GSL Sandbox](http://glslsandbox.com/e#25304.0)
  * [Статьи по компьютерной графике](https://iquilezles.org/www/index.htm)
  * [Многопоточность в C](https://softpixel.com/~cwright/programming/threads/threads.c.php)
  * [Расширенные руководства от разработчиков "n++ Game Devs"](http://www.metanetsoftware.com/dev/tutorials)

