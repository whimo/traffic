.PHONY: compile
compile:
	g++ -c -std=c++14 main.cpp
	g++ main.o -o traffic.app -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: run
run:
	@./traffic.app

all: compile run
