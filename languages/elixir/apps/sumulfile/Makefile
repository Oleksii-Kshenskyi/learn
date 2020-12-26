all: clean compile run

clean:
	rm -rf _build sumulfile

compile:
	mix escript.build

run: sumulfile
	./sumulfile ints.txt