<h1 align="center"><code> MinilibX </code></h1>


Здесь содержится резервная копия исходного кода библиотеки для отрисовки графики `MinilibX`, которая потребуется вам для решения проектов ветки Графики.

### ОПИСАНИЕ ###

`MinilibX` - это простая библиотека отрисовки графики интерфейса `X-Window`, используемая студентами Школы 42 для решения проектов ветки Графики.

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


### РУКОВОДСТВО ПО БИБЛИОТЕКЕ MiniLibX :

* [mlx](man_mlx.md) - описание библиотеки;
* [mlx_new_window](man_mlx_new_window.md) - управление окнами;
* [mlx_pixel_put](man_mlx_pixel_put.md) - вывод пикселей и рисование внутри окна;
* [mlx_new_image](man_mlx_new_image.md) - манипулирование изображениями;
* [mlx_loop](man_mlx_loop.md) - обработка событий клавиатуры или мыши;


## Полезные ссылки ##

* [Руководство по ветке Графики](https://qst0.github.io/ft_libgfx/)
* [42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)
* [Tutorial on MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
* [Useful links and info by lcouto et al](https://www.notion.so/miniRT-5f6fcdf6d05e4742b6c38f0588f12436)
* [install minilibx](https://achedeuzot.me/2014/12/20/installer-la-minilibx/)

