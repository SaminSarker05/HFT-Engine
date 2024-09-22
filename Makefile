run: build
	@./run

build:	main.cpp
	@g++ -o run main.cpp -std=c++17

clean:
	rm -f run *.csv