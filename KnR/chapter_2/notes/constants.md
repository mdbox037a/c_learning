# constants

section 2.3

## integers

int         1234
long        123456789l
unsigned    1234u

## floating point

double      123.4
            1e-2
float       10.2f
long        10.2345678910111213l

## base-x

decimal         31
octal       0   037
hex         0x  0x1f

long            0x1fl
unsigned        0x1fu
both            0x1ful

## character constants

an integer in ''

'0'       not zero, but the numeric code in the machine character set
'\ooo'    byte-size pattern in octal
'\xhh'    byte-size pattern in hex

## string constants/string literals

a character array in ""
always terminated with \0

N.B.: 'x' is an integer with some value in the character set; "x" is any array
with two elements: x and \0

## enumerations constants

a list of constant integer values
ex:
    enum boolean { NO, YES };
    no --> 0
    yes --> 1
    and so on, unless specified, and the pattern continues from there

ex:
    enum months { JAN = 1, FEB, MAR, APR }
    JAN --> 1
    FEB --> 2
    and so on...
