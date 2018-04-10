#! /bin/sh


# Copyright (c) 2012 Pierre-Jean Fichet.
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or
# without modification, are permitted provided that the
# following conditions are met:
#  1. Redistributions of source code must retain the above
# copyright notice, this list of conditions and the following
# disclaimer.
#  2. Redistributions in binary form must reproduce the above
# copyright notice, this list of conditions and the following
# disclaimer in the documentation and/or other materials
# provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
# BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
# OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# $Id: mkgreek.sh,v 0.2 2013/07/11 20:18:49 pj Exp pj $



# Extract polytonic greek characters from Unicode table
# and build a list to be used on C programms.
# The table can be found on:
# http://unicode.org/Public/6.0.0/ucd/UnicodeData.txt



echo "{"

export LC_ALL=C && sed -n -e "/GREEK/p" UnicodeData.txt \
| cut -d ';' -f 2,1 \
| sed -e "
/ACROPHONIC/d;
/MUSICAL/d;
/HETA/d;
/COMBINING/d;
/ARCHAIC/d;
/SIGN/d;
/SYMBOL/d;
/PAMPHYLIAN/d;
/LUNATE/d;
/SHO/d;
/SMALL CAPITAL/d;
/SUBSCRIPT/d;
/KORONIS/d; # almost like PSILI
/PROSGEGRAMMENI/d; # use IOTA SUBSCRIPT instead
/STIGMA/d; # almost like SIGMA
/DIGAMMA/d; # almost like SIGMA
/KOPPA/d; # KAPPA replaced it
/SAN/d; # SIGMA replaced it
/YOT/d; #
/TURNED/d;
/CROSS/d;
/COPTIC/d;
/MODIFIER/d;
s/GREEK //g;
s/SMALL LETTER ALPHA/a/g;
s/SMALL LETTER BETA/b/g;
s/SMALL LETTER GAMMA/g/g;
s/SMALL LETTER DELTA/d/g;
s/SMALL LETTER EPSILON/e/g;
s/SMALL LETTER ZETA/z/g;
s/SMALL LETTER ETA/h/g;
s/SMALL LETTER THETA/q/g;
s/SMALL LETTER IOTA/i/g;
s/SMALL LETTER KAPPA/k/g;
s/SMALL LETTER LAMDA/l/g;
s/SMALL LETTER MU/m/g;
s/SMALL LETTER NU/n/g;
s/SMALL LETTER XI/c/g;
s/SMALL LETTER OMICRON/o/g;
s/SMALL LETTER PI/p/g;
s/SMALL LETTER RHO/r/g;
s/SMALL LETTER FINAL SIGMA/$/g;
s/SMALL LETTER SIGMA/s/g;
s/SMALL LETTER TAU/t/g;
s/SMALL LETTER UPSILON/u/g;
s/SMALL LETTER PHI/f/g;
s/SMALL LETTER CHI/x/g;
s/SMALL LETTER PSI/y/g;
s/SMALL LETTER OMEGA/w/g;
s/SMALL LETTER SAMPI/#5/g;
s/CAPITAL LETTER ALPHA/A/g;
s/CAPITAL LETTER BETA/B/g;
s/CAPITAL LETTER GAMMA/G/g;
s/CAPITAL LETTER DELTA/D/g;
s/CAPITAL LETTER EPSILON/E/g;
s/CAPITAL LETTER ZETA/Z/g;
s/CAPITAL LETTER ETA/H/g;
s/CAPITAL LETTER THETA/Q/g;
s/CAPITAL LETTER IOTA/I/g;
s/CAPITAL LETTER KAPPA/K/g;
s/CAPITAL LETTER LAMDA/L/g;
s/CAPITAL LETTER MU/M/g;
s/CAPITAL LETTER NU/N/g;
s/CAPITAL LETTER XI/C/g;
s/CAPITAL LETTER OMICRON/O/g;
s/CAPITAL LETTER PI/P/g;
s/CAPITAL LETTER RHO/R/g;
s/CAPITAL LETTER SIGMA/S/g;
s/CAPITAL LETTER TAU/T/g;
s/CAPITAL LETTER UPSILON/U/g;
s/CAPITAL LETTER PHI/F/g;
s/CAPITAL LETTER CHI/X/g;
s/CAPITAL LETTER PSI/Y/g;
s/CAPITAL LETTER OMEGA/W/g;
s/LETTER SAMPI/*#5/g;
s/QUESTION MARK/;/g;
s/ANO TELEIA/:/g;
s/ TONOS/\//g;
s/ PSILI/\)/g;
s/ DASIA/\(/g;
s/ VARIA/\\\\\\\\/g;
s/ OXIA/\//g;
s/ PERISPOMENI/\=/g;
s/ YPOGEGRAMMENI/\|/g;
s/ DIALYTIKA/+/g;
s/ VRACHY/\'/g;
s/ MACRON/\&/g;
s/ WITH//g;
s/ AND//g;
/;TONOS/d;
/;PSILI/d;
/;DASIA/d;
/;VARIA/d;
/;OXIA/d;
/;PERISPOMENI/d;
/;YPOGEGRAMMENI/d;
/;DIALYTIKA/d;
/;VRACHY/d;
/;MACRON/d;
# reverse order and add c syntax
s/^\([^;]*\);\(.*\)/\t{\"\2\", 0x\1,},/g;" \
| sort

echo "}"
