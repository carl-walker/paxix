src = src


all: build clean

build: 
	cd $(src) && make && cd .. && mv $(src)/paxic . && mv $(src)/pvm .
clean:
	cd $(src) && make clean
