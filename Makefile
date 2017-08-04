.phony: clean

all: dutch bsearch permutation

clean:
	rm -rfv dutch bsearch permutation

bsearch: bsearch.c
	gcc $^ -o $@

dutch: dutch.c
	gcc $^ -o $@

permutaion: permutation.c
	gcc $^ -o $@

