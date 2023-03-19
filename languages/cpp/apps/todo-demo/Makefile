c: ./build/
	rm -rf build
cm: ./CMakeLists.txt
	mkdir -p build && cd build && cmake .. -G "Unix Makefiles"
b: cm
	cd build && make -j16
r: b
	build/todo