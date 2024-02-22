all:
	g++ -Iinclude -Werror src/*.cpp

run: all
	./a.out
