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

extern uint32_t off_10CA58;
extern uint32_t off_10CA60;
extern uint32_t off_10CA78;
extern uint32_t off_10CA5C;
extern uint32_t off_10CA64;
extern uint32_t off_10CA68;
extern uint32_t off_10CA6C;
extern uint32_t off_10CA70;
extern uint32_t dword_10CA74;

// check_status_bit @ 0x10c9a0, size 182 bytes
int check_status_bit()
{
  int v0; // r4
  int result; // r0
  uint32_t *v2; // r2
  uint8_t *v3; // r3
  uint32_t *v4; // r2
  uint32_t *v5; // r2
  uint32_t *v6; // r2

  v0 = *(uint32_t *)off_10CA58;
  if ( (*(uint32_t *)off_10CA58 & 0x20) != 0 )
  {
    v6 = off_10CA60;
    *(uint32_t *)off_10CA78 = 32;
    *v6 = 32;
    irq_disable_global_2(0x80000);
  }
  result = v0 << 27;
  if ( (v0 & 0x10) != 0 )
  {
    v5 = off_10CA60;
    *(uint32_t *)off_10CA78 = 16;
    *v5 = 16;
    result = irq_disable_global_2(0x100000);
  }
  if ( (v0 & 2) != 0 )
  {
    result = irq_disable_global_2(0x8000000);
    *(uint32_t *)off_10CA78 = 2;
  }
  if ( (v0 & 0x40000000) != 0 )
  {
    result = default_handler(1);
    *(uint32_t *)off_10CA60 = 0x40000000;
  }
  if ( v0 < 0 )
  {
    v2 = off_10CA60;
    *(uint32_t *)off_10CA5C = 0x80000000;
    *v2 = 0x80000000;
  }
  if ( (v0 & 0x20000000) == 0 )
  {
    v3 = off_10CA64;
    if ( !*(uint8_t *)off_10CA64 || !*(uint32_t *)off_10CA68 )
      return result;
LABEL_16:
    v4 = off_10CA6C;
    v3[1] = 1;
    *v4 |= 1u;
    return result;
  }
  v3 = off_10CA64;
  *(uint32_t *)off_10CA60 = 0x20000000;
  if ( *v3 )
    goto LABEL_16;
  if ( (*(uint32_t *)off_10CA70 & dword_10CA74) == 0x10000 )
    return process_event();
  return result;
}

