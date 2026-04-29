SRC := $(shell find src -name "*.cpp")

all:
	g++ $(SRC) -Iinclude -o c_mulation -lgdi32 -luser32