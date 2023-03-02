NAME = fractol

CC = cc
RM = rm -f

FIL_C = mandelbrot.c julia.c burning_ship.c

FIL_TOOL = zoom.c button.c cws_strct.c color.c main.c

FLI_O = $(FIL_C:.c=.o)

FLI_O_TOOL = $(FIL_TOOL:.c=.o)

all : $(NAME) fract_ol.h

$(NAME) : $(FLI_O) $(FLI_O_TOOL)
	$(CC) $(FLI_O) $(FLI_O_TOOL)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c fract_ol.h
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
		$(RM) $(FLI_O) $(FLI_O_TOOL)

fclean : clean
		$(RM) $(NAME)

re : fclean all