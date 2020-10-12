CC = ghc
ODIR = obj
BINDIR = bin
SOURCES = $(wildcard *.hs)
DEPS = $(patsubst %.hs, $(BINDIR)/%, $(SOURCES))
INPUTDIR = input
INPUT = $(wildcard $(INPUTDIR)/*)

all: $(DEPS)

run: all
	@for e in $(DEPS); do \
	    for i in $(INPUT); do \
		$$e < $$i; \
	    done; \
	done;
	    

clean:
	rm -r $(ODIR) $(BINDIR)

$(BINDIR):
	mkdir $(BINDIR)

$(ODIR):
	mkdir $(ODIR)

$(DEPS) : $(BINDIR)/% : %.hs $(BINDIR) $(ODIR)
	$(CC) $< -odir $(ODIR) -hidir $(ODIR) -o $@

