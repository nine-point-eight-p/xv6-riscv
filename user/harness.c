#include "kernel/types.h"
#include "user/user.h"

#include "libafl_qemu.h"

static const int BUF_SIZE = 50;

void fuzz(uint8 *data, uint64 size) {
  if (size > 0 && data[0] == 'A') {
    if (size > 1 && data[1] == 'B') {
      if (size > 2 && data[2] == 'C') {
        printf("Found target!\n");
        LIBAFL_QEMU_END(LIBAFL_QEMU_END_CRASH);
      }
    }
  }
}

int main() {
  uint8 data[BUF_SIZE] = {};
  uint64 size = LIBAFL_QEMU_START_VIRT((uint64) data, BUF_SIZE);
  fuzz(data, size);
  LIBAFL_QEMU_END(LIBAFL_QEMU_END_OK);

  for (;;) ;
}
