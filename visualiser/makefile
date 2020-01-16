FLAGS=-Wall -Werror -Wextra -g

SRC_FILES = $(shell find src -name "*.c")
DONE = @printf "\x1B[32mDone!\x1B[37m\n"
INCLUDES = -I./includes -I../lib/libft
RPAD = 45
LIBRARY = -L./lib -lSDL2 -lSDL2_gfx -lSDL2_image -L../lib/libft -lft

all: -visual

-visual:
	@printf "%-$(RPAD)s" "Compiling visual executable. "
	@$(CC) $(FLAGS) $(SRC_FILES) $(INCLUDES) $(LIBRARY) ./main.c -o visual
	$(DONE)