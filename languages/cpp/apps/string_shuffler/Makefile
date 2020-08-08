.SILENT: all clean compile rebuild

all: rebuild

compile:
	mkdir -p build
	cd build && cmake .. -G "Ninja"
	cd build && ninja

clean:
	rm -rf build

rebuild: clean compile