#include <stdint.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
  int a = 10;
  uint64_t p = (uint64_t)&a;
  p &= ~(0x1ull << 48);
  a = *(int*)p;
  printf("%d\n", a);
  return a;
}
