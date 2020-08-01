.SILENT: b5 r5 compile clean rebuild

compile:
	mkdir -p build
	cd build && cmake .. -G "Ninja"
	cd build && ninja

clean:
	rm -rf build

rebuild: clean compile

b5: compile
	build/five
r5:
	build/five