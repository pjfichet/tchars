PREFIX=$(HOME)/dev
BINDIR=$(PREFIX)/bin
ROFF=$(BINDIR)/roff
PDF=$(BINDIR)/pdf
mkfn=$(BINDIR)/mkfn
FNTDIR=$(PREFIX)/lib/font
TCHARS=$(BINDIR)/tchars
OTFDIR=GFS_PYRSOS

all: devutf/GFSPyrsos tchars.pdf

devutf:
	@echo "Creating the devutf directory."
	@test -d devutf || mkdir devutf
	@echo "fonts 1 LinLibertine_R" > $@/DESC
	@echo "res 720" >> $@/DESC
	@echo "hor 1" >> $@/DESC
	@echo "ver 1" >> $@/DESC
	@echo "unitwidth 10" >> $@/DESC
	@cp $(FNTDIR)/devutf/LinLibertine_R $@/

GFS_Pyrsos.zip:
	@echo "Downloading a GFSPyrsos.otf font (OFL license)"
	@wget -q http://greekfontsociety-gfs.gr/_assets/fonts/GFS_Pyrsos.zip

GFS_PYRSOS/GFSPyrsos.otf: GFS_Pyrsos.zip
	@unzip -q GFS_Pyrsos.zip $@

devutf/GFSPyrsos.ttf: GFS_PYRSOS/GFSPyrsos.otf devutf
	@fontforge -lang=ff -c "Open(\"$<\"); Generate(\"$@\");" > /dev/null 2>&1

devutf/GFSPyrsos: devutf/GFSPyrsos.ttf
	@cat $< | $(mkfn) -b -l -o -r720 -Slatn -t $(notdir $@) -f "$<" > $@


%.pdf: %.tr
	@echo "Generating $@"
	@$(TCHARS) $< | $(ROFF) -F./ | $(PDF) -pa4 > $@

clean:
	@rm -rf GFS_PYRSOS GFS_Pyrsos.zip devutf
	@rm -f tchars.tmp tchars.to tchars.ps tchars.pdf

