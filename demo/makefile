# Formatting text with Troff

# Prefix directory
PREFIX=/opt/utroff
# Where to find heirloom troff binaries 
BINDIR=$(PREFIX)/bin
# Where to find heirloom troff libraries
LIBDIR=$(PREFIX)/lib
# Where to find troff and OTF fonts
TROFFONTS = $(LIBDIR)/font/:/usr/share/fonts/OTF/:/home/pj/doc/troff/font/

# Where to find Heirloom tools
# Heirloom troff
TROFF=$(BINDIR)/troff
# Heirloom dpost
DPOST=$(BINDIR)/dpost
# Where to find Utroff tools
TCHARS=$(BINDIR)/tchars

TROFFMACS=$(MACDIR)/
export TROFFONTS
export TROFFMACS

all: tchars.pdf

%.tmp: %.tr
	@echo "Generating $@"
	@$(TCHARS) $< > $@

%.to: %.tmp
	@echo "Generating $@"
	@$(TROFF) $< > $@

%.ps: %.to
	@echo "Generating $@"
	@cat $< | $(DPOST) -pa4 >$@

%.pdf: %.ps
	@echo "Generating $@"
	@ps2pdf -dPDFSETTINGS=/prepress -dEmbedAllFonts=true \
		-sFONTPATH=$(TROFFONTS) $< $@

clean:
	@rm -f *.tmp *.to *.ps *.pdf

