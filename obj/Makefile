CC = g++
TARGET = main
LIB_OBJ = chart.o candle.o util.o
MAIN_OBJ = main.o
OBJS = $(MAIN_OBJ) $(LIB_OBJ)

all: $(TARGET)
	mv $^ ..

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(LIB_OBJ): 
	cd ../lib && make all

$(MAIN_OBJ): 
	cd ../src && make all

clean: 
	rm *.o