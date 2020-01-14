FLAGS=-g

SRC_FILES = $(shell find src -name "*.c")
INCLUDES = -I./includes -I./libft
LIBRARY = ./libft/libft.a

lemin: ./libft/libft.a
	@printf "Compiling lemin executable. "
	@$(CC) $(INCLUDES) $(LIBRARY) $(SRC_FILES) ./main.c -o lemin
	@printf "\x1B[32mDone!\x1B[37m\n"

./libft/libft.a:
	@printf "Compiling libft library. "
	@$(MAKE) -C libft > /dev/null
	@$(MAKE) -C libft clean > /dev/null
	@printf "\x1B[32mDone!\x1B[37m\n"

