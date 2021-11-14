main: ./grid.c ./grid1d.c ./grid2d.c ./system.c ./tester.c ./binConv.c ./main.c ./IO.c ./menu.c
	gcc -g -Wall -Wextra -Werror -o main ./grid.c ./grid1d.c ./grid2d.c ./system.c ./tester.c ./binConv.c ./main.c ./IO.c ./menu.c
clean:
	rm -f -r main