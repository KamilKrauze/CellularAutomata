main: ./IO.c ./grid.c ./main.c ./system.c ./binConv.c ./menu.c
	g++ -g -Wall -Wextra -Werror -o main ./IO.c ./grid.c ./main.c ./system.c ./binConv.c ./menu.c
clean:
	rm -f -r main