SOURCES = $(wildcard *.c)
INPUTDIR = input
INPUT = $(wildcard $(INPUTDIR)/*)
BINDIR = bin
DEPS = $(patsubst %.c, $(BINDIR)/%, $(SOURCES))
CC = gcc

all: $(DEPS)

run: all
	@for e in $(DEPS); do \
	    for i in $(INPUT); do \
		echo $$e < $$i; \
		$$e <  $$i; \
	    done; \
	done;

$(BINDIR):
	mkdir $(BINDIR)

$(DEPS) : $(BINDIR)/% : %.c $(BINDIR)
	$(CC) $< -g -o $@
