main: ./binConv.c ./grid.c ./IO.c ./menu.c
	g++ -g -Wall -Wextra -Werror -o main ./binConv.c ./grid.c ./IO.c ./menu.c
clean:
	rm -f -r main