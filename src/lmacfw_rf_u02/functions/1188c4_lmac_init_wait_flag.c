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

extern uint32_t off_1188F0;

// lmac_init_wait_flag @ 0x1188c4, size 42 bytes
// Doc: lmac_init_wait_flag [mac]: Polls a flag register and waits for it to become 1
// lmac_init_wait_flag [mac]: Polls a flag register and waits for it to become 1
int lmac_init_wait_flag()
{
  if ( sub_11E34C(0) == 1 )
    *(uint32_t *)off_1188F0 = 48;
  return sub_11E1E4(0);
}

