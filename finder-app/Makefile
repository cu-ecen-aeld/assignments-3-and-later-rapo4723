#CROSS_COMPILE := aarch64-none-linux-gnu-
CC := gcc
SRC := writer.c
TARGET = writer

all: $(TARGET)

$(TARGET) :
	$(CROSS_COMPILE)$(CC) $(SRC) -o $(TARGET)

clean:
	-rm -f *.o $(TARGET)
