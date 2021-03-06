CC=g++
TARGET=driver
FLAGS=-std=c++11 -I ./DatabaseLib -L ./DatabaseLib -ldatabase

.PHONY: clean

$(TARGET): DatabaseDriver.o
	$(CC) -o $(TARGET) DatabaseDriver.o $(FLAGS)

DatabaseDriver.o: DatabaseDriver.cpp
	make -C ./DatabaseLib/
	$(CC) -c -o DatabaseDriver.o DatabaseDriver.cpp $(FLAGS)

clean:
	rm -f *.o ./driver

run: $(TARGET)
	export LD_LIBRARY_PATH=DatabaseLib/; \
	./driver