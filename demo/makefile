# Formatting text with Troff

# Prefix directory
PREFIX=/usr/local
# Where to find heirloom troff binaries 
BINDIR=$(PREFIX)/bin
# Where to find heirloom troff libraries
LIBDIR=$(PREFIX)/lib
# Where to find utmac macros
MACDIR=$(LIBDIR)/tmac
# Where to find troff fonts
FNTDIR=$(LIBDIR)/font
# Where to find OTF fonts
OTFDIR=/usr/share/fonts/OTF

# Where to find Heirloom tools
# Heirloom troff
TROFF=$(BINDIR)/troff
# Heirloom dpost
DPOST=$(BINDIR)/dpost
# Where to find Utroff tools
TCHARS=$(BINDIR)/tchars

TROFFMACS=$(MACDIR)/
TROFFONTS=$(FNTDIR)/:$(OTFDIR)/
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

