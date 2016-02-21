src = src


all: build clean

build: 
	cd $(src) && make && cd .. && mv $(src)/paxic .
clean:
	cd $(src) && make clean
