# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -Wextra -pedantic -ansi -O3 -std=c++11 

# Target executable

scrambler: main.cpp lodepng.cpp scramble_algs.cpp key_generator.cpp
	$(CXX) $(CXXFLAGS) -o scrambler main.cpp lodepng.cpp scramble_algs.cpp key_generator.cpp

clean:
	-rm -f scrambler