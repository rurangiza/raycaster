NAME		=	raycast

# FOLDERS
SRC_FOLDER	=	./src

# FILES
SRC			=	$(SRC_FOLDER)/main.c \
				$(SRC_FOLDER)/init.c \
				$(SRC_FOLDER)/update.c \
				$(SRC_FOLDER)/render.c \
				$(SRC_FOLDER)/destroy.c \
#$(SRC_FOLDER)/*.c

CC			=	gcc -std=c99
FLAGS		=	-Wall -Werror -Wextra
SANATIZE	=	-fsanitize=address
SDL_LIB		=	-I/opt/homebrew/Cellar/sdl2/2.26.5/include -L/opt/homebrew/Cellar/sdl2/2.26.5/lib -lSDL2

# COLORS
CGREEN		=	\033[0;32m
CMAGENTA	=	\033[0;35m
CBLUE		=	\033[0;94m
CRESET		=	\033[0m



build:
	@echo "$(CBLUE)> building..$(CRESET)"
	$(CC) $(SRC) -o $(NAME) $(SDL_LIB);

run:
	@echo "$(CGREEN)> running..$(CRESET)"
	./raycast;

clean:
	@echo "$(CMAGENTA)> cleaning..$(CRESET)"
	rm raycast;