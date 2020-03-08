CXXFLAGS = -Wall -ggdb

LDFLAGS = -lm

TARGETS = main

all:	$(TARGETS)

main: main.o
	g++ -o $@ $^ $(LDFLAGS)

clean:
		rm -f *.o *~

cleanall:	clean
		rm -f $(TARGETS)
