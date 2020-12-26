all: compile run

clean: _build
	rm -rf _build
	rm -f sumulfile

compile:
	rebar3 escriptize
	cp _build/default/bin/sumulfile .

run: ./sumulfile
	./sumulfile ints.txt
