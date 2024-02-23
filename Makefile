all:
	g++ -Iinclude -Werror -std=c++20 -g src/*.cpp

run: all
	./a.out
