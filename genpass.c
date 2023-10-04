#include <openssl/rand.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include  "genpass.h"


int main(int argc, char **argv) {
  srand(time(NULL));

  bool lowercase = true;
  bool uppercase = true;
  bool numbers = true;
  bool symbols = true;

  char c = 0;
  while ((c = getopt (argc, argv, "lusnh")) != -1) {
    switch (c) {
    case 'l':
        lowercase = false;
        break;
    case 'u':
        uppercase = false;
        break;
    case 's':
        symbols = false;
        break;
    case 'n':
        numbers = false;
        break;
    case 'h':
    case '?':
        fprintf(stderr,help, argv[0]);
        return -1;
    }
  }

  // get arg after flags
  int index = optind;
  int len = argv[index] ? atoi(argv[index]) : 8;

  if (lowercase == false && uppercase == false && numbers == false &&
      symbols == false) {
    puts("Error: Invalid charset");
    return 1;
  }

  char charset[strlen(LOWERCASE) + strlen(UPPERCASE) + strlen(NUMBERS) +
               strlen(SYMBOLS) + 1] = {};

  if (lowercase) {
    strcat(charset, LOWERCASE);
  }
  if (uppercase) {
    strcat(charset, UPPERCASE);
  }
  if (numbers) {
    strcat(charset, NUMBERS);
  }
  if (symbols) {
    strcat(charset, SYMBOLS);
  }

  char password[len + 1];
  memset(password, 0, len + 1);

  for (int i = 0; i < len; i++)
    password[i] = get_random_char(charset);

  password[len] = '\0';

  puts(password);
}

char get_random_char(char *charset) {
  int len = strlen(charset);

  int r = rand();
  int index = r % len;
  return charset[index];
}
