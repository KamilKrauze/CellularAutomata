main: ./IO.c ./grid.c ./system.c ./binConv.c ./menu.c
	g++ -g -Wall -Wextra -Werror -o main ./IO.c ./grid.c ./grid1d.c./grid2d.c ./main.c ./system.c ./binConv.c ./menu.c
tester: ./IO.c ./grid.c ./system.c ./binConv.c ./tester.c
	g++ -g -Wall -Wextra -Werror -o tester ./IO.c ./grid.c ./grid1d.c ./grid2d.c ./system.c ./binConv.c ./tester.c
clean:
	rm -f -r main
	rm -f -r tester