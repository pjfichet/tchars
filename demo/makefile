# Formatting text with Troff

# Where to find Heirloom tools
TROFF=/opt/utroff/bin/troff
DPOST=/opt/utroff/bin/dpost
# Where to find tchars
TCHARS=../tchars
#where to find troff fonts
FNTDIR=/opt/utroff/lib/font
# where to find otf fonts
OTFDIR=GFS_PYRSOS

TROFFONTS=$(FNTDIR)/:$(OTFDIR)/
export TROFFONTS


GFS_Pyrsos.zip:
	@echo "Downloading a GFSPyrsos.otf font (OFL license)"
	@wget -q http://greekfontsociety-gfs.gr/_assets/fonts/GFS_Pyrsos.zip

GFS_PYRSOS/GFSPyrsos.otf: GFS_Pyrsos.zip
	@unzip -q GFS_Pyrsos.zip $@


all: GFS_PYRSOS/GFSPyrsos.otf tchars.pdf

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
	@rm -rf GFS_PYRSOS GFS_Pyrsos.zip
	@rm -f tchars.tmp tchars.to tchars.ps tchars.pdf

