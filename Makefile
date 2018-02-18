.phony: clean

all: dutch bsearch permutation bsearch_r quicksort

clean:
	rm -rfv dutch bsearch permutation bsearch_r quicksort

bsearch: bsearch.c
	gcc $^ -o $@

bsearch_r: bsearch_r.c
	gcc $^ -o $@

dutch: dutch.c
	gcc $^ -o $@

permutaion: permutation.c
	gcc $^ -o $@

quicksort: quicksort.c
	gcc $^ -o $@
