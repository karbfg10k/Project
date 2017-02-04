CC = clang-3.8
CFLAGS  = -std=c99 -g -O0 -Weverything -lm

TARGET = fizzbuzz

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
