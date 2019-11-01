
CC=g++
CFLAGS=-std=c++11 -g  -pthread -I./ 
# LDFLAGS= -lpthread -lscaledkv -pthread -lpmemobj -lpmem
LDFLAGS = -pthread -lpmemobj -lpmem
SUBDIRS= core sys db
SUBSRCS=$(wildcard core/*.cc)  $(wildcard sys/*.cc) $(wildcard db/*.cc)
OBJECTS=$(SUBSRCS:.cc=.o)
EXEC=ycsbc

all: $(SUBDIRS) $(EXEC)

$(SUBDIRS):
	$(MAKE) -C $@

$(EXEC): $(wildcard *.cc) $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $@; \
	done
	$(RM) $(EXEC)

.PHONY: $(SUBDIRS) $(EXEC)

