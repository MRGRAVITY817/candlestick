CC = g++
TARGET = main

all: $(TARGET)
	./$^

$(TARGET):
	cd obj && make all

clean:
	rm $(TARGET) && cd obj && make clean