.SILENT: all clean bl linux compile run

clean:
	rm -rf build

bl: linux compile

linux:
	mkdir -p build
	cd build && conan install .. --build=missing
	cd build && mkdir -p cmakebuild && cd cmakebuild && cmake ../.. -G "Ninja" -DCMAKE_BUILD_TYPE=Release

compile:
	cd build/cmakebuild && cmake --build .

run:
	build/cmakebuild/bin/cocmbo