// obfuscated for dumb reasons, will probably upload version with better names eventually

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char p[33];
const char *s="!\"#$%&'()*+,-./";
void f(const int t,p*o) { 
  for(int i=t;i;i--)for(int j=0;j<31;j+=2)o[i][j]=s[(i>>j)%15];
  for(int i=t;i;i--)o[i][32]='\0';
}

int main(int argc,char**argv) {
  const long t=1337;
  p*b=(p*)malloc(sizeof(p)*t);
  memset(b,'v',t*sizeof(p));
  f(t,b);
  for(int i=0;i<t;i++)puts(b[i]);
  return 0;
}
