CC = g++
TARGET = main
OBJ = main.o
SRC = main.cc

all: $(OBJ)
	mv $^ ../obj

$(OBJ): $(SRC)
	$(CC) -c $^

clean:
	cd ../obj && rm $(OBJ)