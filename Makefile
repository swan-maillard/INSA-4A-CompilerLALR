all:
	g++ -Iinclude src/*.cpp

run: all
	./a.out
