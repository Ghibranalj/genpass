#ifndef GENPASS_H
#define GENPASS_H

char *help = "Usage: %s -hlusn <length>\n"
             "  -h: Show help\n"
             "  -l: Exclude lowercase\n"
             "  -u: Exclude uppercase\n"
             "  -s: Exclude symbols\n"
             "  -n: Exclude numbers\n"
             "  -b: Exclude bash string reserved characters\n"
             "  -c: Copy password to clipboard\n"
             "  <length>: length of password (default: 8)\n";

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "0123456789"
#define SYMBOLS "!#%^&*()_+-=[]{};:,./<>?~"
#define BASH "'\"`$@"
#define ALLCHARS LOWERCASE UPPERCASE NUMBERS SYMBOLS BASH

char get_random_char(char *charset);

#endif // GENPASS_H
