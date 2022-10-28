CXXFLAGS = -g -Wall --pedantic -fno-elide-constructors -std=c++2a
DIR = -I ../physim

compile: main.cpp
	g++ -o main main.cpp $(CXXFLAGS) $(DIR)

execute: compile
	./main
	rm main
	