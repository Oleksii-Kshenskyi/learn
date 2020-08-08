.SILENT: all clean compile rebuild val

all: rebuild

compile:
	mkdir -p build
	cd build && cmake .. -G "Ninja"
	cd build && ninja

clean:
	rm -rf build

rebuild: clean compile

val: compile
	valgrind -s --leak-check=full --show-leak-kinds=all build/wls