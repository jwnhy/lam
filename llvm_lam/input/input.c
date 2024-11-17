#include <stdint.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

#define LAM_U57_BITS 6 
#define LAM_NONE 0
#define LAM_U57_MASK (0x3fULL << 57)
#define LAM_U57_MAX 0x3fULL

#define ARCH_GET_UNTAG_MASK     0x4001
#define ARCH_ENABLE_TAGGED_ADDR 0x4002
#define ARCH_GET_MAX_TAG_BITS   0x4003
#define ARCH_FORCE_TAGGED_SVA	0x4004

static int set_lam(uint64_t lam) {
  int ret = 0;
  uint64_t ptr = 0;
  if (lam != LAM_U57_BITS && lam != LAM_NONE)
    return -1;

  syscall(SYS_arch_prctl, ARCH_ENABLE_TAGGED_ADDR, lam);
  syscall(SYS_arch_prctl, ARCH_GET_UNTAG_MASK, &ptr);

  if (lam == LAM_U57_BITS)
    ret = (ptr != ~(LAM_U57_MASK));
  else if (lam == LAM_NONE)
    ret = (ptr != -1ULL);

  return ret;
}

static uint64_t set_metadata(uint64_t src, unsigned int meta)
{
	uint64_t metadata = meta;

  if (meta > LAM_U57_MAX)
    return -1;

  metadata = (meta % ((1UL << LAM_U57_BITS) - 1) + 1) << 57;
	metadata |= (src & ~(LAM_U57_MASK));
	return metadata;
}

int main(int argc, char *argv[]) {
  int a = 10;
  uint64_t p = (uint64_t)&a;
  set_lam(LAM_U57_BITS);
  p = set_metadata(p, 0x1);
  printf("%lx\n", p);
  printf("%d\n", *(int*)p);
  return a;
}
