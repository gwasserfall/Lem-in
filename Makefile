FLAGS=-g

all:
	gcc $(FLAGS) -I./includes ./preflight/*.c ./rooms/*.c ./anthill/*.c ./libft/libft.a main.c output/*.c links/*.c -o lemon

test:
	./lemon < test_hill1.txt

rm:
	$(RM) visi

visi:
	gcc ./visualiser/*.c -lSDL2 -o visi