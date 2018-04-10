/*
** Copyright (c) 2012 Pierre-Jean Fichet.
** All rights reserved.
** 
** Redistribution and use in source and binary forms, with or
** without modification, are permitted provided that the
** following conditions are met:
**  1. Redistributions of source code must retain the above
** copyright notice, this list of conditions and the following
** disclaimer.
**  2. Redistributions in binary form must reproduce the above
** copyright notice, this list of conditions and the following
** disclaimer in the documentation and/or other materials
** provided with the distribution.
** 
** THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS
** ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
** BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
** MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS
** BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
** OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
** $Id: tchars.c,v 0.7 2017/12/06 09:05:30 pj Exp pj $
*/

#include <stdio.h>
#include <string.h>

typedef struct runelist runelist;

struct runelist
{
	char *tag;
	unsigned hexa;
};

runelist alphabeta[] =
{
	/* This list must be sorted */
	{"#5", 0x03E1,},
	{"$", 0x03C2,},
	{"*#5", 0x03E0,},
	{":", 0x0387,},
	{";", 0x037E,},
	{"A", 0x0391,},
	{"A&", 0x1FB9,},
	{"A'", 0x1FB8,},
	{"A(", 0x1F09,},
	{"A(/", 0x1F0D,},
	{"A(=", 0x1F0F,},
	{"A(\\", 0x1F0B,},
	{"A)", 0x1F08,},
	{"A)/", 0x1F0C,},
	{"A)=", 0x1F0E,},
	{"A)\\", 0x1F0A,},
	{"A/", 0x0386,},
	{"A/", 0x1FBB,},
	{"A\\", 0x1FBA,},
	{"B", 0x0392,},
	{"C", 0x039E,},
	{"D", 0x0394,},
	{"E", 0x0395,},
	{"E(", 0x1F19,},
	{"E(/", 0x1F1D,},
	{"E(\\", 0x1F1B,},
	{"E)", 0x1F18,},
	{"E)/", 0x1F1C,},
	{"E)\\", 0x1F1A,},
	{"E/", 0x0388,},
	{"E/", 0x1FC9,},
	{"E\\", 0x1FC8,},
	{"F", 0x03A6,},
	{"G", 0x0393,},
	{"H", 0x0397,},
	{"H(", 0x1F29,},
	{"H(/", 0x1F2D,},
	{"H(=", 0x1F2F,},
	{"H(\\", 0x1F2B,},
	{"H)", 0x1F28,},
	{"H)/", 0x1F2C,},
	{"H)=", 0x1F2E,},
	{"H)\\", 0x1F2A,},
	{"H/", 0x0389,},
	{"H/", 0x1FCB,},
	{"H\\", 0x1FCA,},
	{"I", 0x0399,},
	{"I&", 0x1FD9,},
	{"I'", 0x1FD8,},
	{"I(", 0x1F39,},
	{"I(/", 0x1F3D,},
	{"I(=", 0x1F3F,},
	{"I(\\", 0x1F3B,},
	{"I)", 0x1F38,},
	{"I)/", 0x1F3C,},
	{"I)=", 0x1F3E,},
	{"I)\\", 0x1F3A,},
	{"I+", 0x03AA,},
	{"I/", 0x038A,},
	{"I/", 0x1FDB,},
	{"I\\", 0x1FDA,},
	{"K", 0x039A,},
	{"L", 0x039B,},
	{"M", 0x039C,},
	{"N", 0x039D,},
	{"O", 0x039F,},
	{"O(", 0x1F49,},
	{"O(/", 0x1F4D,},
	{"O(\\", 0x1F4B,},
	{"O)", 0x1F48,},
	{"O)/", 0x1F4C,},
	{"O)\\", 0x1F4A,},
	{"O/", 0x038C,},
	{"O/", 0x1FF9,},
	{"O\\", 0x1FF8,},
	{"P", 0x03A0,},
	{"R", 0x03A1,},
	{"R(", 0x1FEC,},
	{"S", 0x03A3,},
	{"T", 0x03A4,},
	{"U", 0x03A5,},
	{"U&", 0x1FE9,},
	{"U'", 0x1FE8,},
	{"U(", 0x1F59,},
	{"U(/", 0x1F5D,},
	{"U(=", 0x1F5F,},
	{"U(\\", 0x1F5B,},
	{"U+", 0x03AB,},
	{"U/", 0x038E,},
	{"U/", 0x1FEB,},
	{"U\\", 0x1FEA,},
	{"W", 0x03A9,},
	{"W(", 0x1F69,},
	{"W(/", 0x1F6D,},
	{"W(=", 0x1F6F,},
	{"W(\\", 0x1F6B,},
	{"W)", 0x1F68,},
	{"W)/", 0x1F6C,},
	{"W)=", 0x1F6E,},
	{"W)\\", 0x1F6A,},
	{"W/", 0x038F,},
	{"W/", 0x1FFB,},
	{"W\\", 0x1FFA,},
	{"X", 0x03A7,},
	{"Y", 0x03A8,},
	{"Z", 0x0396,},
	{"a", 0x03B1,},
	{"a&", 0x1FB1,},
	{"a'", 0x1FB0,},
	{"a(", 0x1F01,},
	{"a(/", 0x1F05,},
	{"a(/|", 0x1F85,},
	{"a(=", 0x1F07,},
	{"a(=|", 0x1F87,},
	{"a(\\", 0x1F03,},
	{"a(\\|", 0x1F83,},
	{"a(|", 0x1F81,},
	{"a)", 0x1F00,},
	{"a)/", 0x1F04,},
	{"a)/|", 0x1F84,},
	{"a)=", 0x1F06,},
	{"a)=|", 0x1F86,},
	{"a)\\", 0x1F02,},
	{"a)\\|", 0x1F82,},
	{"a)|", 0x1F80,},
	{"a/", 0x03AC,},
	{"a/", 0x1F71,},
	{"a/|", 0x1FB4,},
	{"a=", 0x1FB6,},
	{"a=|", 0x1FB7,},
	{"a\\", 0x1F70,},
	{"a\\|", 0x1FB2,},
	{"a|", 0x1FB3,},
	{"b", 0x03B2,},
	{"c", 0x03BE,},
	{"d", 0x03B4,},
	{"e", 0x03B5,},
	{"e(", 0x1F11,},
	{"e(/", 0x1F15,},
	{"e(\\", 0x1F13,},
	{"e)", 0x1F10,},
	{"e)/", 0x1F14,},
	{"e)\\", 0x1F12,},
	{"e/", 0x03AD,},
	{"e/", 0x1F73,},
	{"e\\", 0x1F72,},
	{"f", 0x03C6,},
	{"g", 0x03B3,},
	{"h", 0x03B7,},
	{"h(", 0x1F21,},
	{"h(/", 0x1F25,},
	{"h(/|", 0x1F95,},
	{"h(=", 0x1F27,},
	{"h(=|", 0x1F97,},
	{"h(\\", 0x1F23,},
	{"h(\\|", 0x1F93,},
	{"h(|", 0x1F91,},
	{"h)", 0x1F20,},
	{"h)/", 0x1F24,},
	{"h)/|", 0x1F94,},
	{"h)=", 0x1F26,},
	{"h)=|", 0x1F96,},
	{"h)\\", 0x1F22,},
	{"h)\\|", 0x1F92,},
	{"h)|", 0x1F90,},
	{"h/", 0x03AE,},
	{"h/", 0x1F75,},
	{"h/|", 0x1FC4,},
	{"h=", 0x1FC6,},
	{"h=|", 0x1FC7,},
	{"h\\", 0x1F74,},
	{"h\\|", 0x1FC2,},
	{"h|", 0x1FC3,},
	{"i", 0x03B9,},
	{"i&", 0x1FD1,},
	{"i'", 0x1FD0,},
	{"i(", 0x1F31,},
	{"i(/", 0x1F35,},
	{"i(=", 0x1F37,},
	{"i(\\", 0x1F33,},
	{"i)", 0x1F30,},
	{"i)/", 0x1F34,},
	{"i)=", 0x1F36,},
	{"i)\\", 0x1F32,},
	{"i+", 0x03CA,},
	{"i+/", 0x0390,},
	{"i+/", 0x1FD3,},
	{"i+=", 0x1FD7,},
	{"i+\\", 0x1FD2,},
	{"i/", 0x03AF,},
	{"i/", 0x1F77,},
	{"i=", 0x1FD6,},
	{"i\\", 0x1F76,},
	{"k", 0x03BA,},
	{"l", 0x03BB,},
	{"m", 0x03BC,},
	{"n", 0x03BD,},
	{"o", 0x03BF,},
	{"o(", 0x1F41,},
	{"o(/", 0x1F45,},
	{"o(\\", 0x1F43,},
	{"o)", 0x1F40,},
	{"o)/", 0x1F44,},
	{"o)\\", 0x1F42,},
	{"o/", 0x03CC,},
	{"o/", 0x1F79,},
	{"o\\", 0x1F78,},
	{"p", 0x03C0,},
	{"r", 0x03C1,},
	{"r(", 0x1FE5,},
	{"r)", 0x1FE4,},
	{"s", 0x03C3,},
	{"t", 0x03C4,},
	{"u", 0x03C5,},
	{"u&", 0x1FE1,},
	{"u'", 0x1FE0,},
	{"u(", 0x1F51,},
	{"u(/", 0x1F55,},
	{"u(=", 0x1F57,},
	{"u(\\", 0x1F53,},
	{"u)", 0x1F50,},
	{"u)/", 0x1F54,},
	{"u)=", 0x1F56,},
	{"u)\\", 0x1F52,},
	{"u+", 0x03CB,},
	{"u+/", 0x03B0,},
	{"u+/", 0x1FE3,},
	{"u+=", 0x1FE7,},
	{"u+\\", 0x1FE2,},
	{"u/", 0x03CD,},
	{"u/", 0x1F7B,},
	{"u=", 0x1FE6,},
	{"u\\", 0x1F7A,},
	{"w", 0x03C9,},
	{"w(", 0x1F61,},
	{"w(/", 0x1F65,},
	{"w(/|", 0x1FA5,},
	{"w(=", 0x1F67,},
	{"w(=|", 0x1FA7,},
	{"w(\\", 0x1F63,},
	{"w(\\|", 0x1FA3,},
	{"w(|", 0x1FA1,},
	{"w)", 0x1F60,},
	{"w)/", 0x1F64,},
	{"w)/|", 0x1FA4,},
	{"w)=", 0x1F66,},
	{"w)=|", 0x1FA6,},
	{"w)\\", 0x1F62,},
	{"w)\\|", 0x1FA2,},
	{"w)|", 0x1FA0,},
	{"w/", 0x03CE,},
	{"w/", 0x1F7D,},
	{"w/|", 0x1FF4,},
	{"w=", 0x1FF6,},
	{"w=|", 0x1FF7,},
	{"w\\", 0x1F7C,},
	{"w\\|", 0x1FF2,},
	{"w|", 0x1FF3,},
	{"x", 0x03C7,},
	{"y", 0x03C8,},
	{"z", 0x03B6,},
};

char letters[60]="abcdefghijklmnopqrstuvwxyz\
ABCDEFGHIJKLMNOPQRSTUVWXYZ\
:;";

// the characters #$*:;5 are currently ignored
char code[11]=")(\\+/=|'&";

FILE *in; // input file
int l=1; // line number
int u=1; // print utf8 char

/*
** Print the utf8 char corresponding to the
** unicode hexadecimal code.
*/
void
hexatochars(unsigned hexa)
{
	char a=0, b=0, c=0, d=0;

	/*
	** From U+000 to U+007F
	** Utf8 is coded on 1 byte of the form:
	** 0xxxxxxx
	*/
	if (hexa<0x0080) {
		a = hexa; // 0xxxxxxx
	}
	/*
	** From U+0080 to U+07FF
	** Utf8 is coded on 2 byte of the form:
	** 110xxxxx 10xxxxxx
	*/
	else if (hexa < 0x800) {
		a = ((hexa >> 6) | 0xC0); // 110xxxxx
		b = ((hexa & 0x3F) | 0x80); // 10xxxxxx
	}
	/*
	** From U+0800 to U+FFFF
	** Utf8 is coded on 3 byte of the form:
	** 1110xxxx 10xxxxxx 10xxxxxx
	*/
	else if (hexa < 0x10000) {
		a = ((hexa >> 12) | 0xE0); // 1110xxxx
		b = (( (hexa >> 6) & 0x3F) | 0x80);
		c = ((hexa & 0x3F) | 0x80);
	}
	/*
	** From U+10000	to U+10FFFF
	** Utf8 is coded on 4 byte of the form:
	** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
	*/
	else if (hexa < 0x110000) {
		a = ((hexa >> 18) | 0xF0); // 11110xxx
		b = (((hexa >> 12) & 0x3F) | 0x80);
		c = (((hexa >> 6) & 0x3F) | 0x80);
		d = ((hexa & 0x3F) | 0x80);
	}
	/*
	** Out of unicode range
	** (RFC 3629 ends Utf8 at U+10FFFF)
	*/
	else {
		fprintf(stderr,
		"tchars: [%x] is not in unicode range, file xxx, line %d\n",
		hexa, l);
	}
	printf("%c%c%c%c", a, b, c, d);
}

/*
** Search for rune in runelist alphabeta,
** print the unicode char if rune is found,
** else, recursively try without the last
** of the rune.
*/
int
searchrune(char rune[6])
{
	runelist *min, *mid, *max;
	min = alphabeta;
	for (max = alphabeta; max->tag; max++)
		;

	// Binary search
	while ( min <= max) {
		mid = min + (max-min)/2;
		// rune is before mid
		if (strcmp(rune, mid->tag) < 0) {
			max = mid-1;
		}
		// rune is after mid
		else if (strcmp(rune, mid->tag) > 0) {
			min = mid+1;
		}
		// rune found
		else {
			if (u)
				hexatochars(mid->hexa);
			else
				printf("\\U'%x'", mid->hexa);
			return 0;
		}
	}
	// rune not found
	char *p;
	char c;
	for ( p=rune; *p; p++)
		;
	--p;
	c=*p;
	*p='\0';	
	searchrune(p);
	putchar(c);
	fprintf(stderr,
		"tchars: [%s] not found, file xxx, line %d\n", 
		p, l);
	return 1;
}



/*
** Transform beta code until the first
** newline if bp=0, or the first
** space, tab or newline if bp=1
** Transformation is done by collecting runes,
** and sending them to searchrune().
*/
int
betalpha(char c, int bp)
{
	char rune[6];
	int r=0;
	int done=0;
	char *p;

	for (p=letters; *p; p++){
		if (c==*p) {
			rune[r++]=c;
			done=1;
			break;
		}
	}
	if (done==0)
		putchar(c);


	while ( (c=getc(in)) != EOF ) {
		done=0;
		// letter: print previous rune
		// and begin a new one
		for (p=letters; *p; p++){
			if ( c==*p) {
				if (r>0) {
					rune[r]='\0';		
					searchrune(rune);
					r=0;
				}
				rune[r++]=c;
				done=1;
				break;
			}
		}
		// after a letter, look for tags
		if (r>0) {
			for (p=code; *p; p++){
				if ( c==*p ) {
					rune[r++]=c;
					done=1;
					break;
				}
			}
		}
		// other characters, print rune and char
		if (done==0) {
			if (r>0) {
			rune[r]='\0';
			if (rune[0]=='s') {
				// final sigma
				rune[0]='$';
			}
			searchrune(rune);
			r=0;
			}
			putchar(c);

			// break on demand //
			if ( c=='\n')
				return 0;
			else if ( bp && (c==' ' || c =='\t') )
				return 0;
		}
	}
	// EOF: print rune and newline
	if (r>0){
		rune[r]='\0';
		searchrune(rune);
	}
	putchar('\n');
	return 1;
}

/*
** Inside a betacode block,
** transform each line which
** does not begin by a '.'
** until .CE is found.
*/
int
inblock(void)
{
	char c;

	while ( (c=getc(in)) != EOF) {
		if (c != '.') {
			if (betalpha(c, 0))
				return 1;
			l++;
			continue;
		}
		putchar(c);
		c = getc(in);
		if (c != 'C')
			goto line;
		putchar(c);
		c = getc(in);
		if (c != 'E')
			goto line;
		putchar(c);
		c = getc(in);

		switch (c) {
			case ' ':
			case '\n':
				putchar(c);
				return 0;
			case EOF:
				return 1;
			default:
				goto line;
		}

		line:
			if (c==EOF)
				return 1;
			putchar(c);
			while ( (c=getc(in)) != '\n' && c !=EOF)
				putchar(c);
			if (c==EOF)
				return 1;
			putchar(c);
			l++;
			continue;
	} // end of while loop
	fprintf(stderr, 
	"tchars: .CE not found, file xxx, line %d\n", l);
	return 1;
}

/*
** read input file,
** and transform betacode which is:
** - first word after .CW
** - whole line after .CL
** - whole block between .CS and .CE
*/
int
parsefile(void)
{	
	char c, d;
	while ( (c=getc(in)) != EOF) {

		putchar(c);
		if (c != '.') 
			goto line;

		c = getc(in);
		putchar(c);
		if (c != 'C')
			goto line;

		c = getc(in);
		putchar(c);
/*
		if (c== ' ' || c=='\t') {
			if (betalpha(0, 1))
				break;
			l++;
			continue;
		}
		else if (c=='W' || c =='L' || c == 'S') {
*/
		if (c=='W' || c =='L' || c == 'S') {
			d = c;
			c=getc(in);
			putchar(c);
			if (c!=' ' && c!='\t' && c!='\n')
				goto line;
			if (d=='W') {
				if (betalpha(0, 1))
					break;
				l++;
			}
			if (d=='L'){
				if (betalpha(0, 0))
					break;
				l++;
			}
			else if (d=='S') {
				if (inblock())
					break;
			}
			continue;
		}


		line:
			while ( (c=getc(in)) != '\n')
				putchar(c);
			putchar('\n');
			l++;
			continue;

	} // End of while loop
	return 0;
}


int
main(int argc, char **argv)
{
	argc--;
	argv++;
	if (argc == 0) {
		in = stdin;
		parsefile();
		return 0;
	}
	else if ( argv[0][0]=='-' && argv[0][1]=='e'){
		u=0;
		argc--;
		argv++;
	}
	for ( ; argc >0; argc--, argv++) {
		in = fopen(argv[0], "r");
		if ( in == 0 ) {
			perror(argv[0]);
			return 1;
		}
		parsefile();
	}
	return 0;
}

