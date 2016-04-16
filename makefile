CC := g++
WARN := -Wall -Wextra -Wconversion

# -DNDEBUG disables assert
#CCOPTS := $(WARN) -O -DNDEBUG

# assert is enabled
# CCOPTS := $(WARN) -O
CCOPTS := -O

all: generate string_test

generate: generator.cpp
	$(CC) $(CCOPTS) -o $@ $<

string_test: bm.o kmp.o bf.o testMain.o
	$(CC) -o $@ $^

bm.o: bm.cpp bm.h
	$(CC) $(CCOPTS) -c -o $@ $<

kmp.o: kmp.cpp kmp.h
	$(CC) $(CCOPTS) -c -o $@ $<

bf.o: bf.cpp bf.h
	$(CC) $(CCOPTS) -c -o $@ $<

testMain.o: test_main.cpp bm.h kmp.h bf.h
	$(CC) $(CCOPTS) -c -o $@ $<

clean:
	rm -rf *.o testMain bm kmp bf
	echo Clean Done.