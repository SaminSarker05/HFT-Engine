run: main.o ma.o
	@g++ -o run main.o ma.o
	@./run

main.o: main.cpp
	@g++ -c main.cpp -std=c++17

ma.o: ma.cpp
	@g++ -c ma.cpp -std=c++17

clean:
	rm -f run *.csv *.o