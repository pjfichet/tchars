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
** $Id: utf8doc.c,v 0.2 2013/07/11 20:18:49 pj Exp pj $
*/


/*
How to build UTF-8 characters from the unicode hexadecimal value

UTF-8 is explained on: https://en.wikipedia.org/wiki/UTF-8

# UTF-8 table:

The UTF-8 table show how characters can be build:

Bits	First		Last		Bytes	Byte 1		Byte 2		Byte 3		Byte 4		Byte 5		Byte 6
7		U+0000		U+007F		1		0xxxxxxx
11		U+0080		U+07FF		2		110xxxxx	10xxxxxx
16		U+0800		U+FFFF		3		1110xxxx	10xxxxxx	10xxxxxx
21		U+10000		U+1FFFFF	4		11110xxx	10xxxxxx	10xxxxxx	10xxxxxx
26		U+200000	U+3FFFFFF	5		111110xx	10xxxxxx	10xxxxxx	10xxxxxx	10xxxxxx
31		U+4000000	U+7FFFFFFF	6		1111110x	10xxxxxx	10xxxxxx	10xxxxxx	10xxxxxx	10xxxxxx


# Hexadecimal table:
The hexadecimal table show which hexadecimal value
correspond to bytes:

0	0000	8	1000
1	0001	9	1001
2	0010	A	1010
3	0011	B	1011
4	0100	C	1100
5	0101	D	1101
6	0110	E	1110
7	0111	F	1111


# First byte
So, the first byte of each line of the UTF-8 table is
on the form:

0000 0000 1100 0000 = C0
0000 0000 1110 0000 = E0
0000 0000 1111 0000 = F0
0000 0000 1111 1000 = F8
0000 0000 1111 1100 = FC


# Binary operators

We can use binary operators to build the characters,
explanation about binary operators can be found on:
http://www.bien-programmer.fr/bits.htm


# Second and following bits:

Erase begin with 3F:	0000 0000 0011 1111
Concatenate with 80:	0000 0000 1000 0000



# Binary operations:

0xxxxxxx
byte 1: >> 1

110xxxxx	10xxxxxx
byte 1: >> 6 | C0
byte 2: & 3F | 80

1110xxxx	10xxxxxx	10xxxxxx
byte 1: >> 12 | E0
byte 2: >> 6 & 3F | 80
byte 3: & 3F | 80

11110xxx	10xxxxxx	10xxxxxx	10xxxxxx
byte1: >> 18 | F0
byte2: >> 12 & 3F | 80
byte3: >> 6 & 3F | 80
byte4: & 3F | 80

111110xx	10xxxxxx	10xxxxxx	10xxxxxx	10xxxxxx
byte1: >> 24 | F8
byte2: >> 18 & 3F | 80
byte3: >> 12 & 3F | 80
byte4: >> 6 & 3F | 80
byte5: & 3F | 80

1111110x	10xxxxxx	10xxxxxx	10xxxxxx	10xxxxxx	10xxxxxx
byte1: >> 30 | FC
byte2: >> 24 & 3F | 80
byte3: >> 18 & 3F | 80
byte4: >> 12 & 3F | 80
byte5: >> 6 & 3F | 80
byte6: & 3F | 80

*/

#include <stdio.h>

void
codetochars(char code[17])
{
	unsigned x=0;
	char a=0, b=0, c=0, d=0, e=0, f=0;
	int i=0;

	/*
	** loop from http://johnsantic.com/comp/htoi.html
	** to build binary from string
	** License is unknown
	*/
    for (i=0; code[i] && i<17; i++) {
        if (code[i] >= '0' && code[i] <= '9')
            x = (x << 4) + (code[i] - '0');
        else if (code[i] >= 'A' && code[i] <= 'F')
            x = (x << 4) + (code[i] - 'A' + 10);
        else if (code[i] >= 'a' && code[i] <= 'f')
            x = (x << 4) + (code[i] - 'a' + 10);
        else 
			break;
    }
	/*
	** End of loop from http://johnsantic.com
	*/


	/* build bytes */
	if (x<0x0080) {
		a = x; // 0xxxxxxx
	}
	else if (x < 0x800) {
		a = ((x >> 6) | 0xC0); // 110xxxxx
		b = ((x & 0x3F) | 0x80); // 10xxxxxx
	}
	else if (x < 0x10000) {
		a = ((x >> 12) | 0xE0); // 1110xxxx
		b = (( (x >> 6) & 0x3F) | 0x80);
		c = ((x & 0x3F) | 0x80);
	}
	else if (x < 0x200000) {
		a = ((x >> 18) | 0xF0); // 11110xxx
		b = (((x >> 12) & 0x3F) | 0x80);
		c = (((x >> 6) & 0x3F) | 0x80);
		d = ((x& 0x3F) | 0x80);
	}
	else if (x < 0x4000000) {
		a = ((x>> 24) | 0xF8); // 111110xx
		b = (((x>> 18) & 0x3F) | 0x80);
		c = (((x>> 12) & 0x3F) | 0x80);
		d = (((x>> 6) & 0x3F) | 0x80);
		e = ((x& 0x3F) | 0x80);
	}
	else if (x < 0x7FFFFFFF) {
		a = ((x>> 30) | 0xFC); // 1111110x
		b = (((x>> 24) & 0x3F) | 0x80);
		c = (((x>> 18) & 0x3F) | 0x80);
		d = (((x>> 12) & 0x3F) | 0x80);
		e = (((x>> 6) & 0x3F) | 0x80);
		f = ((x& 0x3F) | 0x80);
	}
	else
		printf("%s is not in unicode range\n", code);

	/* Fancy print bytes */
	printf("%c%c%c%c%c%c", a, b, c, d, e, f);
	printf(" %x", a);
	if (b) printf(" %x", b);
	if (c) printf(" %x", c);
	if (d) printf(" %x", d);
	if (e) printf(" %x", e);
	if (f) printf(" %x", f);
	putchar('\n');

}

/*
** We could also reverse...
*/
/*
void
charstocode(char *chars)
{

}
*/

/*
** Simple loop to use codetochar()
*/
void
main(void)
{
	char code[17];
	char g;
	int i=0;
	while ( (g=getchar()) != '\n'){
		code[i++]=g;
		if (i==16)
			break;
	}
	code[i]=0;
	codetochar(code);
}
