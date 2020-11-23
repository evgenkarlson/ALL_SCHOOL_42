
#include	"mlx.h"
#include	"mlx_int.h"

#define	WIN1_SX		242
#define	WIN1_SY		242
#define	IM1_SX		42
#define	IM1_SY		42
#define	IM3_SX		242
#define	IM3_SY		242

void	*mlx;
void	*win1;
void    *win2;
void    *win3;
void    *im1;
void	*im2;
void	*im3;
void	*im4;
int	bpp1;
int	bpp2;
int	bpp3;
int	bpp4;
int	sl1;
int	sl2;
int	sl3;
int	sl4;
int	endian1;
int	endian2;
int	endian3;
int	endian4;
char	*data1;
char	*data2;
char	*data3;
char	*data4;
int	xpm1_x;
int	xpm1_y;

int	local_endian;

int	color_map_1(void *win,int w,int h);
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);

int	expose_win1(void *p)
{
  mlx_put_image_to_window(mlx,win1,im3,0,0);
}

int	expose_win2(void *p)
{
  mlx_put_image_to_window(mlx,win2,im4,0,0);
  mlx_put_image_to_window(mlx,win2,im2,0,0);
}

int	key_win1(int key,void *p)
{
  printf("Key in Win1 : %d\n",key);
  if (key==0xFF1B)
    exit(0);
}

int	key_win2(int key,void *p)
{
  printf("Key in Win2 : %d\n",key);
  if (key==0xFF1B)
    exit(0);
}

int	key_win3(int key,void *p)
{
  printf("Key in Win3 : %d\n",key);
  if (key==0xFF1B)
    mlx_destroy_window(mlx,win3);
}

int	mouse_win1(int button,int x,int y, void *p)
{
  printf("Mouse in Win1, button %d at %dx%d.\n",button,x,y);
}

int	mouse_win2(int button,int x,int y, void *p)
{
  printf("Mouse in Win2, button %d at %dx%d.\n",button,x,y);
}

int	mouse_win3(int x,int y, void *p)
{
  printf("Mouse moving in Win3, at %dx%d.\n",x,y);
}


int	main()
{
  int	a;

  printf("MinilibX Test Program\n");
  a = 0x11223344;
  if (((unsigned char *)&a)[0] == 0x11)
    local_endian = 1;
  else
    local_endian = 0;
  printf(" => Local Endian : %d\n",local_endian);

  printf(" => Connection ...");
  if (!(mlx = mlx_init()))
    {
      printf(" !! KO !!\n");
      exit(1);
    }
  printf("OK (use_xshm %d pshm_format %d)\n",((t_xvar *)mlx)->use_xshm,((t_xvar *)mlx)->pshm_format);

  printf(" => Window1 %dx%d \"Title 1\" ...",WIN1_SX,WIN1_SY);
  if (!(win1 = mlx_new_window(mlx,WIN1_SX,WIN1_SY,"Title1")))
    {
      printf(" !! KO !!\n");
      exit(1);
    }
  printf("OK\n");

  printf(" => Colormap sans event ...");
  color_map_1(win1,WIN1_SX,WIN1_SY);
  printf("OK\n");
  sleep(2);

  printf(" => Clear Window ...");
  mlx_clear_window(mlx,win1);
  printf("OK\n");
  sleep(2);

  printf(" => Image1 ZPixmap %dx%d ...",IM1_SX,IM1_SY);
  if (!(im1 = mlx_new_image(mlx,IM1_SX,IM1_SY)))
    {
      printf(" !! KO !!\n");
      exit(1);
    }
  data1 = mlx_get_data_addr(im1,&bpp1,&sl1,&endian1);
  printf("OK (bpp1: %d, sizeline1: %d endian: %d type: %d)\n",bpp1,sl1,endian1,
	 ((t_img *)im1)->type);

  printf(" => Fill Image1 ...");
  color_map_2(data1,bpp1,sl1,IM1_SX,IM1_SY,endian1, 1);
  printf("OK (pixmap : %d)\n",(int)((t_img *)im1)->pix);

  printf(" => Put Image1 ...");
  mlx_put_image_to_window(mlx,win1,im1,20,20);
  printf("OK\n");
  sleep(2);

  printf(" => Destroy Image1 ... ");
  mlx_destroy_image(mlx, im1);
  printf("OK\n");
  sleep(2);

  printf(" => Image3 ZPixmap %dx%d ...",IM3_SX,IM3_SY);
  if (!(im3 = mlx_new_image(mlx,IM3_SX,IM3_SY)))
    {
      printf(" !! KO !!\n");
      exit(1);
    }
  data3 = mlx_get_data_addr(im3,&bpp3,&sl3,&endian3);
  printf("OK (bpp3 %d, sizeline3 %d endian3 %d type %d)\n",bpp3,sl3,endian3,
	 ((t_img *)im3)->type);

  printf(" => Fill Image3 ...");
  color_map_2(data3,bpp3,sl3,IM3_SX,IM3_SY,endian3, 1);
  printf("OK (pixmap : %d)\n",(int)((t_img *)im3)->pix);

  printf(" => Put Image3 ...");
  mlx_put_image_to_window(mlx,win1,im3,20,20);
  printf("OK\n");
  sleep(2);

  printf(" => String ...");
  mlx_string_put(mlx,win1,5,WIN1_SY/2,0xFF99FF,"String output");
  mlx_string_put(mlx,win1,15,WIN1_SY/2+20,0x00FFFF,"MinilibX test");
  printf("OK\n");
  sleep(2);

  printf(" => Xpm from file ...");
  if (!(im2 = mlx_xpm_file_to_image(mlx,"open.xpm",&xpm1_x,&xpm1_y)))
    {
      printf(" !! KO !!\n");
      exit(1);
    }
  data2 = mlx_get_data_addr(im2,&bpp2,&sl2,&endian2);
  printf("OK (xpm %dx%d)(img bpp2: %d, sizeline2: %d endian: %d type: %d)\n",
	 xpm1_x,xpm1_y,bpp2,sl2,endian2,((t_img *)im2)->type);
  sleep(2);

  printf(" => Put xpm ...");
  mlx_put_image_to_window(mlx,win1,im2,0,0);
  mlx_put_image_to_window(mlx,win1,im2,100,100);
  printf("OK\n");
  sleep(2);

  printf(" => 2nd window,");
  win2 = mlx_new_window(mlx,WIN1_SX,WIN1_SY,"Title2");
  if (!(im4 = mlx_new_image(mlx,IM3_SX, IM3_SY)))
    {
      printf(" !! KO !!\n");
      exit(1);
    }
  data4 = mlx_get_data_addr(im4,&bpp4,&sl4,&endian4);
  color_map_2(data4,bpp4,sl4,IM3_SX,IM3_SY,endian4, 2);

  printf(" 3rd window, Installing hooks ...");
  win3 = mlx_new_window(mlx,WIN1_SX,WIN1_SY,"Title3");
  mlx_expose_hook(win1,expose_win1,0);
  mlx_mouse_hook(win1,mouse_win1,0);
  mlx_key_hook(win1,key_win1,0);
  mlx_expose_hook(win2,expose_win2,0);
  mlx_mouse_hook(win2,mouse_win2,0);
  mlx_key_hook(win2,key_win2,0);
  mlx_key_hook(win3,key_win3,0);

  mlx_hook(win3, MotionNotify, PointerMotionMask, mouse_win3, 0);

  printf("OK\nNow in Loop. Just play. Esc in 3 to destroy, 1&2 to quit.\n");
  
  mlx_loop(mlx);
}


int	color_map_1(void *win,int w,int h)
{
  int	x;
  int	y;
  int	color;

  x = w;
  while (x--)
    {
      y = h;
      while (y--)
        {
          color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
	  mlx_pixel_put(mlx,win,x,y,color);
        }
    }
}


int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type)
{
  int	x;
  int	y;
  int	opp;
  int	dec;
  int	color;
  int	color2;
  unsigned char *ptr;

  opp = bpp/8;
  printf("(opp : %d) ",opp);
  y = h;
  while (y--)
    {
      ptr = data+y*sl;
      x = w;
      while (x--)
        {
	  if (type==2)
	    color = (y*255)/w+((((w-x)*255)/w)<<16)
	      +(((y*255)/h)<<8);
	  else
	    color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
          color2 = mlx_get_color_value(mlx,color);
	  dec = opp;
	  while (dec--)
	    if (endian==local_endian)
	      {
		if (endian)
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[4-opp+dec];
		else
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[dec];
	      }
	    else
	      {
		if (endian)
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[opp-1-dec];
		else
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[3-dec];
	      }
        }
    }

}
