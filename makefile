# Packaging directory
DESTDIR=
# Prefix directory
PREFIX=/usr/local/
# Where to place binaries
BINDIR=$(PREFIX)/bin
# Where to place libraries
MANDIR=$(PREFIX)/man

# C compiler
CC=cc
# compilier flags
CFLAGS=-Wall -O
# Linker flags
LDFLAGS=
OBJS=tchars.o

all: tchars tchars.1

clean:
	rm -rf $(OBJS) tchars tchars.1

%.o: %.c
	$(CC) -c $(CFLAGS) $<
tchars: tchars.o
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.1 %.7: %.man
	sed -e "s|@BINDIR@|$(BINDIR)|g" $< > $@

$(DESTDIR)$(BINDIR)/%: %
	test -d $(DESTDIR)$(BINDIR) || mkdir -p $(DESTDIR)$(BINDIR)
	install -c $< $@

$(DESTDIR)$(MANDIR)/man1/%: %
	test -d $(DESTDIR)$(MANDIR)/man1 || mkdir -p $(DESTDIR)$(MANDIR)/man1
	install -c -m 644 $< $@

install: $(DESTDIR)$(BINDIR)/tchars $(DESTDIR)$(MANDIR)/man1/tchars.1

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/tchars
	rm -f $(DESTDIR)$(MANDIR)/man1/tchars.1

