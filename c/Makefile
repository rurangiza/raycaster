NAME		=	raycast
USER		:=	$(shell whoami)

# FOLDERS
SRC_FOLDER	=	./src

# FILES
SRC			=	$(SRC_FOLDER)/main.c \
				$(SRC_FOLDER)/init.c \
				$(SRC_FOLDER)/update.c \
				$(SRC_FOLDER)/render.c \
				$(SRC_FOLDER)/destroy.c \
#$(SRC_FOLDER)/*.c

CC			=	gcc #-std=c99
FLAGS		=	-Wall -Werror -Wextra
DEBUG		+=	-g -fsanitize=address
FLAGS		+=	-I./includes

ifeq ($(USER), lupin)
	SDL_LIB = -I/opt/homebrew/Cellar/sdl2/2.26.5/include -L/opt/homebrew/Cellar/sdl2/2.26.5/lib -lSDL2
else ifeq ($(USER), arurangi)
	SDL_LIB = -I/Users/arurangi/.brew/Cellar/sdl2/2.26.5/include -L/Users/arurangi/.brew/Cellar/sdl2/2.26.5/lib/ -lSDL2
endif

# COLORS
CGREEN		=	\033[0;32m
CMAGENTA	=	\033[0;35m
CBLUE		=	\033[0;94m
CRESET		=	\033[0m



build:
	@echo "$(CBLUE)> building..$(CRESET)"
	$(CC) $(SRC) $(FLAGS) -o $(NAME) $(SDL_LIB);

run:
	@echo "$(CGREEN)> running..$(CRESET)"
	./raycast;

clean:
	@echo "$(CMAGENTA)> cleaning..$(CRESET)"
	rm raycast;