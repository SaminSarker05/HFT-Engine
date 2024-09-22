run: ma_signal.o volume_signal.o main.o
	@g++ -o run main.o ma_signal.o volume_signal.o
	@./run

main.o: main.cpp
	@g++ -c main.cpp -std=c++17

ma_signal.o: ma_signal.cpp
	@g++ -c ma_signal.cpp -std=c++17

volume_signal.o: volume_signal.cpp 
	@g++ -c volume_signal.cpp -std=c++17

clean:
	rm -f run *.csv *.o