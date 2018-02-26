CC=g++
TARGET=libdatabase.so
FLAGS=-fPIC -shared -std=c++11

$(TARGET): DatabaseLib.o
	$(CC) -o $(TARGET) DatabaseLib.o $(FLAGS)

DatabaseLib.o: DatabaseLib.cpp DatabaseLib.h
	$(CC) -c -o DatabaseLib.o DatabaseLib.cpp $(FLAGS)