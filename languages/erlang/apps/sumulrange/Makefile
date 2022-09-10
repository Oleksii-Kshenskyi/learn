all: compile run

clean: _build
	rm -rf _build
	rm -f sumulrange

compile:
	rebar3 escriptize
	cp _build/default/bin/sumulrange .

run: ./sumulrange
	./sumulrange 10000
