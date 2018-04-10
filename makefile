# Packaging directory
DESTDIR=
# Prefix directory
PREFIX=/opt/utroff
# Where to place binaries
BINDIR=$(PREFIX)/bin
# Where to place libraries
MANDIR=$(PREFIX)/man
# Install binary
INSTALL = /usr/bin/install
# C compiler
CC=gcc
# compilier flags
CFLAGS=-O
# Compiler warning
WARN=-Wall
# Support for locale specific character 
EUC=-DEUC
# Linker flags
LDFLAGS=
# Additionnal libraries to link with
LIBS=
# C preprocessor flags.
# Use -D_GNU_SOURCE for Linux with GNU libc.
# Use -D_INCLUDE__STDC_A1_SOURCE for HP-UX.
CPPFLAGS=-D_GNU_SOURCE
# Strip
STRIP=strip -s -R .comment -R .note

BIN=tchars
MAN=tchars.1


all: $(BIN) $(MAN)

clean:
	rm -rf $(BIN) $(BIN:%=%.o) $(MAN)

%.1 %.7: %.man
	sed -e "s|@BINDIR@|$(BINDIR)|g" $< > $@


$(DESTDIR)$(BINDIR) \
$(DESTDIR)$(MANDIR)/man1:
	test -d $@ || mkdir -p $@

$(DESTDIR)$(MANDIR)/man1/%: % $(DESTDIR)$(MANDIR)/man1
	$(INSTALL) -c -m 644 $(@F) $@

$(DESTDIR)$(BINDIR)/%: % $(DESTDIR)$(BINDIR)
	$(INSTALL) -c $(@F) $@

install: $(BIN:%=$(DESTDIR)$(BINDIR)/%) $(MAN:%=$(DESTDIR)$(MANDIR)/man1/%)

uninstall:
	rm $(BIN:%=$(DESTDIR)$(BINDIR)/%)
	rmdir $(DESTDIR)$(BINDIR)
	rm $(MAN:%=$(DESTDIR)$(MANDIR)/man1/%)
	rmdir $(DESTDIR)$(MANDIR)/man1 $(DESTDIR)$(MANDIR)


