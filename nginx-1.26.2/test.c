int main() {
  int i = 10;
  int *a = 0;
  if (i == 0) {
    a = (void *)(1UL<<47);
  } else if (i == 10) {
    a = (void *)2;
  }
  int *c = a;
}
