#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define str_s sizeof(str)
#define ignored 'v'

typedef char str[33];

const char *symbols = "!\"#$%&'()*+,-./";
void fill(const int amt, str *buf) { 
  for (int i = amt; i; i--)
    for (int j = 0; j < 31; j += 2)
      buf[i][j] = symbols[(i >> j) % 15];

  for (int i = amt; i; i--)
    buf[i][32] = '\0';
}

int main(int argc, char **argv) {
  const long amt = 50000; // strings to generate
  str *buffer = (str*) malloc(str_s * amt);

  memset(buffer, ignored, amt * str_s); // where v = 
  fill(amt, buffer);

  for(int i = 0; i < amt; i++)
    puts(buffer[i]);
  
  return 0;
}
