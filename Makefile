FLAGS=-g

SRC_FILES = $(shell find src -name "*.c")
INCLUDES = -I./includes -I./libft
LIBRARY = -L./libft -lft
RPAD = 45

all: -lemin

-lemin: ./libft/libft.a
	@printf "%-$(RPAD)s" "Compiling lemin executable. "
	@$(CC) $(INCLUDES) $(LIBRARY) $(SRC_FILES) ./main.c -o lemin
	@printf "\x1B[32mDone!\x1B[37m\n"

./libft/libft.a:
	@printf "%-$(RPAD)s" "Compiling libft library. "
	@$(MAKE) -s -C libft
	@$(MAKE) -s -C libft clean
	@printf "\x1B[32mDone!\x1B[37m\n"

clean:
	@$(RM) lemin

fclean: clean
	@$(RM) ./libft/libft.a