SRC := $(shell find src -name "*.cpp")

all:
	g++ $(SRC) -Iinclude -o main -lgdi32 -luser32