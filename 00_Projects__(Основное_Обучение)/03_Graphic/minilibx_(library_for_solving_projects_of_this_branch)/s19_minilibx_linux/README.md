# minilibx linux
minilibx tested on mint (ubuntu), deepin (debian based) and manjaro (arch).

## Why?
Some people having difficulties to install the minilibx from the school 42, I modified a version found on [Achedeuzot](https://achedeuzot.me/2014/12/20/installer-la-minilibx/) adding simply by adding a strlcpy.
By the way Thank you to Achedeuzot for those files and explanations !

## How to?
First, let's install OpenGL ! here is the command for debian based versions.
```bash
sudo apt update
sudo apt install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

Then,
```bash
cd minilibx
make
```
the installation will raise alot of warnings, it doesn't mean it is not working as long as there are no errors.

To test your installation, use
```bash
cd ./test
./mlx-test
```

If for some reason, it didnt work the first time, read the error logs and use
```bash
make re
```
It's important ! 

Finally, if, like me, you are starting from a basic OS installation, this commands migh also be useful.
```bash
sudo apt install build-essential
```
## Compile
To compile on linux, you need some special flags...
```makefile
$(CC) $(OBJS) libmlx.a -lm -lX11 -lXext -o $(NAME)
```
## Good luck !
If this is useful to you do not hesitate to let me know with a little star !
You can also contact me on the 42 slack @agossuin
