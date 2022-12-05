CXXFLAGS = -g -Wall --pedantic -fno-elide-constructors -std=c++2a
PHYSIM = -I ~/Desktop/codes/physim/include

solar: main.cpp 
	$(CXX) $(CXXFLAGS) $(PHYSIM) -o $@ $<

clear: 
	rm data/*.txt