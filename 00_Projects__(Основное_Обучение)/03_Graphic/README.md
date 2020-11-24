# Ветвь Графики #


![graphic branch](./graphic.gif)

---

<details>
<summary> КАРТА ПРОЕКТОВ </summary>

![map Holy_Graph](../Holy_Graph.png)

</details>

---


# Библиотека MiniLibX #


### ОПИСАНИЕ ###
`minilibx` - это простая библиотека отрисовки графики интерфейса `X-Window`, используемая студентами Школы 42 для решения проектов ветки Графики.

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

* Чтобы посмотреть страницу руководства MiniLibX используйте команду: `man mlx`
* При компиляции проекта используйте флаги `-lbsd -lmlx -lXext -lX11`. Пример:
```
clang -Wall -Wextra -Werror main.c -lbsd -lmlx -lXext -lX11
```

### ПОДКЛЮЧЕНИЕ ЗАГОЛОВОЧНОГО ФАЙЛА БИБЛИОТЕКИ ###

`mlx.h` должен быть включен для правильного использования `MiniLibX API`. Он содержит только прототипы функций, никакой структуры не требуется:

		#include <mlx.h>


### ЛИНКОВКА MiniLibX ###

Чтобы использовать функции `MiniLibX`, вам необходимо связать свое программное обеспечение с несколькими библиотеками, включая саму библиотеку `MiniLibX`. Для этого при компиляции проекта используйте флаги `-lbsd -lmlx -lXext -lX11` во время линковки. Пример:

		-lbsd -lmlx -lXext -lX11

или следующие:

		-lmlx -lXext -lX11

> Пример:
>
>		clang -Wall -Wextra -Werror main.c -lbsd -lmlx -lXext -lX11:


> Вам также может потребоваться указать путь к этим библиотекам, используя флаг `-L`:
>
>		gcc FILE -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11



### КОНЦЕПЦИЯ X-WINDOW ###

`X-Window` - это сетевая графическая система для `Unix`. Он основан на двух основных частях:

 - С одной стороны, ваше программное обеспечение хочет что-то нарисовать на экране и/или получить записи с клавиатуры и мыши.
 - С другой стороны, `X-Server` управляет экраном, клавиатурой и мышью (его часто называют «дисплеем»).
 - Между этими двумя объектами должно быть установлено сетевое соединение для отправки заказов на рисование (от программного обеспечения к `X-Server`) и событий клавиатуры/мыши (от `X-Server` к программному обеспечению).


### ФУНКЦИИ БИБЛИОТЕКИ ###

Прежде всего, вам необходимо инициализировать соединение между вашим программным обеспечением и дисплеем. Как только это соединение будет установлено, вы сможете использовать другие функции `MiniLibX` для отправки сообщений  к `X-Server`, например «Я хочу нарисовать желтый пиксель в этом окне» или «Пользователь нажал клавишу?».

Функция `mlx_init()` создаст это соединение. Никаких параметров не требуется, и он вернет нулевой(`NULL` ) или ненулевой указатель, как идентификатор `mlx`, используемый для дальнейших вызовов библиотечных подпрограмм. 

Если `mlx_init()` не может установить соединение с `X-Server`, он вернет `NULL`(нулевой указатель), в противном случае в качестве идентификатора соединения будет возвращен ненулевой указатель.

Все остальные функции `MiniLibX` описаны на следующих страницах руководства:

* `man mlx_new_window` - управление окнами;управление окнами;
* `man mlx_pixel_put` - вывод пикселей и рисование внутри окна;
* `man mlx_new_image` - манипулирование изображениями;
* `man mlx_loop` - обработка событий клавиатуры или мыши;

---
Управление окнами;управление окнами(`man mlx_new_window`):
  - void *mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );
> возвращает нулевой (`NULL`) или ненулевой указатель в качестве идентификатора окна.

  - int mlx_clear_window( void *mlx_ptr, void *win_ptr );
  - int mlx_destroy_window( void *mlx_ptr, void *win_ptr )
---
Вывод пикселей и рисование внутри окна(`man mlx_pixel_put`):

  - int	mlx_pixel_put( void *mlx_ptr, void *win_ptr, int x, int y, int color );
  - int	mlx_string_put( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );
  - `color int` = 0 + r + g + b
---
Манипулирование изображениями(`man mlx_new_image`):
  - void	mlx_new_image ( void *mlx_ptr, int width, int height );
  - int		mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );
  - char	*mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );

>  `bits_per_pixel` : бит на один пиксель;

>  `size_line`      : количество бит для одной строки;

>  `endian`         : 0 для маленького 1 для большого;

  - int		mlx_destroy_image ( void *mlx_ptr, void *img_ptr );
  - unsigned int	mlx_get_color_value ( void *mlx_ptr, int color );
  - void 	*mlx_xpm_to_image ( void *mlx_ptr, char **xpm_data, int *width, int *height );
  - void 	*mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );
---
Обработка событий клавиатуры или мыши(`man mlx_loop`):
  > `mlx_loop` это в основном `update()` в других движках.
  - int		mlx_loop ( void *mlx_ptr );
  - int		mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
  - int		mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
  - int		mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
  - int		mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );



## Полезные ссылки ##

* [Руководство по ветке Графики](https://qst0.github.io/ft_libgfx/)
* [42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)
* [Tutorial on MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
* [Useful links and info by lcouto et al](https://www.notion.so/miniRT-5f6fcdf6d05e4742b6c38f0588f12436)
* [install minilibx](https://achedeuzot.me/2014/12/20/installer-la-minilibx/)



