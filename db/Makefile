CC=g++
CFLAGS=-std=c++11 -c -g  -fgnu-tm
INCLUDES=-I../
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)

all: $(SOURCES) $(OBJECTS)

.cc.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM) $(OBJECTS)

