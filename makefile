main: ./binConv.c ./grid.c ./grid1d.c ./grid2d.c ./IO.c ./itoa.c ./main.c ./menu.c ./system.c ./tester.c
	gcc -g -Wall -Wextra -Werror -o main ./binConv.c ./grid.c ./grid1d.c ./grid2d.c ./IO.c ./itoa.c ./main.c ./menu.c ./system.c ./tester.c
clean:
	rm -f -r main