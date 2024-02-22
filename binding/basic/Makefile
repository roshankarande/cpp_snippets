LIBS := $(shell python3 -m pybind11 --includes)
EXT := $(shell python3-config --extension-suffix)
MODULE := module

info:
	@echo LIBS :: $(LIBS)
	@echo EXT :: $(EXT)
	@echo MODULE :: $(MODULE)

build:
	g++-13 -O3 -Wall -shared -std=c++11 -fPIC $(LIBS) $(MODULE).cpp -o $(MODULE)$(EXT)

run:
	python3 main.py

clean:
	rm -rf *cpython*