# order is important, libraries first
modules = api

.PHONY: all %.all clean %.clean doxy %.doxy

all : ${modules:%=all.%}

all.%:
	cd $* && make all

clean:  ${modules:%=clean.%}
	rm -rf lib/*.h bin/*.dSYM

clean.%:
	cd $* && make clean

test: all
	python allTests.py

doxy : ${modules:%=doxy.%}

doxy.%:
	cd $* && make doxy