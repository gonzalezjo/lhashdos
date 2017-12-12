#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Settings
const int  amt = 50000; // strings to generate
const char ign = 'v';   // character to base strings off of 

// Typedefs
typedef char str[33];

// Algorithm to fill a buffer
void fill(const int amt, str *buf) { 
  static const char *symbols = "!\"#$%&'()*+,-./"; // Picked randomly. Nothing special about these.

  memset(buf, ign, amt * sizeof(str)); // Fill the buffer with junk that doesn't affect the hash
  for (int i = amt; i; i--) // Generates amt strings
    for (int j = 0; j < 31; j += 2) // Fills the character slots in those strings
      buf[i][j] = symbols[(i >> j) % 15]; // Magic

  for (int i = amt; i; i--) // Terminate all strs
    buf[i][32] = '\0'; // Adds the terminator
}

// Creates buffer, calls fill on it, and prints results. 
int main(int argc, char **argv) {
  str *buffer = (str*) malloc(sizeof(str) * amt); // Allocate buffer

  fill(amt, buffer); // Fill buffer

  for(int i = 0; i < amt; i++) // Print buffer contents
    puts(buffer[i]); // Call to puts for printing
  
  return 0;
}
