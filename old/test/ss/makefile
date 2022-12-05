CXXFLAGS = -g -Wall --pedantic -fno-elide-constructors -std=c++2a
DIR = -I ../../../physim  -I ../../

compile: main.cpp
	g++ -o main main.cpp $(CXXFLAGS) $(DIR)

execute: compile
	./main
	rm main
	
clear: 
	rm data/*.txt