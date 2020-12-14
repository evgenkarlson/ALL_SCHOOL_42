<h1 align="center"><code> MinilibX </code></h1>


Здесь содержится резервная копия исходного кода библиотеки для отрисовки графики `MinilibX`, которая потребуется вам для решения проектов ветки Графики.


### ОПИСАНИЕ ###

`MiniLibX` - это простая библиотека отрисовки графики интерфейса `X-Window`/`Cocoa`, используемая студентами Школы 42 для решения проектов `ветки Графики`.

Она предостовляет возможность создания графического программного обеспечения без каких-либо знаний в области программирования `X-Window`. Библиотека обеспечивает инструментами для простого создание окна, рисования, управления изображениями, а так же управления основными событиями(нажатия клавиатуры, движение мыши).



## УСТАНОВКА MINILIBX НА LINUX ##
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



### СПРАВОЧНИК ПО БИБЛИОТЕКЕ MiniLibX :

* [mlx](man_mlx.md) - описание библиотеки;
* [mlx_new_window](man_mlx_new_window.md) - управление окнами;
* [mlx_pixel_put](man_mlx_pixel_put.md) - вывод пикселей и рисование внутри окна;
* [mlx_new_image](man_mlx_new_image.md) - манипулирование изображениями;
* [Руководство по использованию изображений в minilibX](how_use_images_in_mimilibx.md)
* [mlx_loop](man_mlx_loop.md) - обработка событий клавиатуры или мыши;



## ЛИНКОВКА С БИБЛИОТЕКОЙ MiniLibX

Чтобы использовать функции `MiniLibX`, вам необходимо связать свое программное обеспечение с несколькими библиотеками, включая саму библиотеку `MiniLibX`. Для этого при компиляции проекта используйте флаги `-lbsd -lmlx -lXext -lX11` во время линковки. Пример:

		gcc -Wall -Wextra -Werror main.c -lbsd -lmlx -lXext -lX11

или следующие:

		gcc -Wall -Wextra -Werror main.c -lmlx -lXext -lX11


Если вам потребуется указать путь к этим библиотекам, используйте флаг `-L`.

		gcc main.c -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11


---------------------------------------------------------------------
> Чтобы использовать функции `MiniLibX` на `macOS`, вам будет нужно связать свое программное обеспечение не только с библиотекой MiniLibX но и с несколькими системными фреймворками:
> 
>		gcc -Wall -Wextra -Werror main.c -lmlx -framework OpenGL -framework AppKit
---------------------------------------------------------------------



## Полезные ссылки ##

* [Домашний репозиторий библиотеки minilibx](https://github.com/42Paris/minilibx-linux)
* [Установка библиотеки minilibX](https://achedeuzot.me/2014/12/20/installer-la-minilibx/)
* [Руководство по библиотеке `miniLibX`](https://harm-smits.github.io/42docs/libs/minilibx)
* [Руководство по использованию изображений в minilibX](how_use_images_in_mimilibx.md)


