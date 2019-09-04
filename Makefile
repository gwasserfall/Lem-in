FLAGS=-g

all:
	gcc $(FLAGS) -I./includes ./preflight/*.c ./rooms/*.c ./anthill/*.c ./libft/libft.a main.c pathing/*.c output/*.c -o lemon

test:
	./lemon < test_hill1.txt