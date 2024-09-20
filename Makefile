run: build
	@./run

build:	main.cpp
	@g++ -o run main.cpp -std=c++17