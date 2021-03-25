CC = g++
OBJS = chart.o candle.o util.o pattern.o
SRC = chart.cc candle.cc util.cc pattern.cc

all: $(OBJS)
	mv $^ ../obj

$(OBJS): $(SRC)
	$(CC) -c $^

clean:
	cd ../obj && rm $(OBJS)