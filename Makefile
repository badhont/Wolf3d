NAME 		= wolf3d
CC			= gcc
CFLAGS 		= -g -Wall -Wextra -Werror

ID_UN 		= $(shell id -un)
SRC_PATH 	= srcs/
OBJ_PATH 	= objs/
INC_PATH	= includes/ \
				libft/includes/
LIBFT 		= libft/

SDL_NUM		= $(shell ls /Users/$(ID_UN)/.brew/Cellar/sdl2/ | tail -1)
TTF_NUM		= $(shell ls /Users/$(ID_UN)/.brew/Cellar/sdl2_ttf/ | tail -1)
IMG_NUM		= $(shell ls /Users/$(ID_UN)/.brew/Cellar/sdl2_image/ | tail -1)
MIX_NUM		= $(shell ls /Users/$(ID_UN)/.brew/Cellar/sdl2_mixer/ | tail -1)

INC_PATH	+=	/Users/$(ID_UN)/.brew/Cellar/sdl2/$(SDL_NUM)/include/ \
				/Users/$(ID_UN)/.brew/Cellar/sdl2/$(SDL_NUM)/include/SDL2/ \
				/Users/$(ID_UN)/.brew/Cellar/sdl2_ttf/$(TTF_NUM)/include/ \
				/Users/$(ID_UN)/.brew/Cellar/sdl2_image/$(IMG_NUM)/include/ \
				/Users/$(ID_UN)/.brew/Cellar/sdl2_mixer/$(MIX_NUM)/include/

SRC_NAME 	= 	main.c \
				ft_displaytools.c \
				ft_events.c \
				ft_exit.c \
				ft_new_surface.c \
				ft_outils.c \
				ft_parsing.c \
				ft_raycasting.c \
				ft_wolf_loop.c \
				linedrawer.c \
				ft_ui.c \
				ft_text_utils.c \
				ft_inventory.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
LSDL2 	 = -L/Users/$(ID_UN)/.brew/lib/ -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@Make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIBFT) -lft $(INC) $(LSDL2)
	@echo "\033[1;34;2m FRIED CHICKEN READY TO BE EATEN ~ (__)=3 ~\033[0m"
	@echo "\033[0;31;3m                        (ALL RULE DONE)                               ~ (__)=3 ~\033[0m"

$(OBJ) : | $(OBJ_PATH)

$(OBJ_PATH) :
	@mkdir objs

$(OBJ_PATH)%.o: $(SRC_PATH)%.c includes/wolf3d.h $(INC_PATH) Makefile
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LIBFT) clean
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;33;2m IVE EATEN HALF OF THE CHICKEN , ONE WORD AND WINGS ERADICATION WILL BE ORDERED \033[0m"
	@echo "\033[0;31;3m                        (CLEAN RULE DONE)                             ~ (__)=3 ~ \033[0m"

fclean: clean
	@make -C $(LIBFT) fclean
	@rm -f $(NAME)
	@echo "\033[1;31;2m JOB DONE SERGEANT WingZLord NO MORE WINGS ARE DETECTED IN THE bckt (-_-)ゞ\033[0m"
	@echo "\033[0;31;3m                        (FCLEAN RULE DONE)                            ~ (__)=3  ~\033[0m"

re: fclean all
	@echo "\033[0;35;2m BTW I'VE SUCCESSFULLY REFILL 24 WINGS JUST FOR YOU (♥_♥)ゞ\033[0m"
	@echo "\033[0;31;3m                        (RE RULE DONE)                                ~ (__)=3  ~\033[0m"

.PHONY: all re clean fclean
