#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <inttypes.h>

#define LOBYTE(x) ((uint8_t)((x) & 0xFF))
#define HIBYTE(x) ((uint8_t)(((x) >> 8) & 0xFF))
#define LOWORD(x) ((uint16_t)((x) & 0xFFFF))
#define HIWORD(x) ((uint16_t)(((x) >> 16) & 0xFFFF))
#define LODWORD(x) ((uint32_t)(x))
#define HIDWORD(x) ((uint32_t)(((uint64_t)(x) >> 32)))

extern uint32_t off_116EF8;

// chip_init_sequence @ 0x116e7c, size 124 bytes
// Doc: chip_init_sequence [mac]: Run post-patch initialization sequence
// chip_init_sequence [mac]: Run post-patch initialization sequence
int chip_init_sequence()
{
  int v0; // r0
  int inited; // r0
  char *v2; // r5
  char *v3; // r6
  char *v4; // r0
  uint32_t *v5; // r5
  int result; // r0

  queue_counters_equal();
  kernel_event_wait();
  v0 = configure_hardware_regs();
  init_buf_188290(v0);
  inited = fw_magic_check(0);
  init_radio_data(inited);
  v2 = (char *)off_116EF8 + 12;
  memset((int *)off_116EF8, 0, 0x204u);
  v3 = v2 + 420;
  do
  {
    zero_8_bytes(v2);
    *((uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((uint32_t *)v2 + 6) = 0;
    *((uint32_t *)v2 + 7) = 0;
    v4 = v2 + 16;
    v2 += 84;
    zero_8_bytes(v4);
  }
  while ( v2 != v3 );
  v5 = off_116EF8;
  zero_8_bytes((char *)off_116EF8 + 432);
  v5[114] = 0;
  v5[115] = 0;
  v5[105] = 0;
  *((uint8_t *)v5 + 446) = 0;
  *((uint8_t *)v5 + 500) = 0;
  result = zero_8_bytes(v5 + 112);
  *((uint16_t *)v5 + 254) = 0;
  return result;
}

