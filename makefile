build:
	clang++ main.cpp grid.cpp colors.cpp position.cpp block.cpp game.cpp -o tetris -std=c++11 -I/opt/local/include -L/opt/local/lib -lraylib
	./tetris


clean:
	rm -f tetris 

