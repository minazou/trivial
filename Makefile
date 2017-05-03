.phony: clean

all: dutch bsearch

clean:
	rm -rfv dutch bsearch

bsearch: bsearch.c
	gcc $^ -o $@

dutch: dutch.c
	gcc $^ -o $@
