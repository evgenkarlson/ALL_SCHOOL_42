INC=/usr/X11R6/include
HT=OpenBSD
DOCP=do_cp



INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -O3 -I..

NAME= mlx-test
SRC = main.c
OBJ = $(SRC:.c=.o)

all	:$(NAME)

$(NAME)	:$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm

clean	:
	rm -f $(NAME) $(OBJ) *~ core *.core


re	: clean all
