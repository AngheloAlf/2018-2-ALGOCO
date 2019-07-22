##
# @file	 Makefile
# @brief For counter

CXX	 = clang++
CXXFLAGS = -g -O2 -Wall

all: tst

tst: main.o counter.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: counter.hh
counter.o: counter.cc

clean:
	rm -f main.o counter.o tst

.PHONY: all clean
