CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror
CXXLIBS = -lGL -lGLU -lglut

main: src/main.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -o bin/main $(CXXLIBS)

.PHONY: clean
clean:
	rm -rf bin/main

.PHONY: run
run:
	bin/main $(ARGS)
