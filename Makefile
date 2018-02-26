CC=g++
TARGET=driver
FLAGS=-std=c++11 -I ./DatabaseLib -L ./DatabaseLib -ldatabase

$(TARGET): DatabaseDriver.o
	$(CC) -o $(TARGET) DatabaseDriver.o $(FLAGS)

DatabaseDriver.o: DatabaseDriver.cpp
	$(CC) -c -o DatabaseDriver.o DatabaseDriver.cpp $(FLAGS)