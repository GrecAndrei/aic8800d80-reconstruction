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

extern uint32_t off_12BE18;
extern uint32_t off_12BE20;
extern uint32_t off_12BE24;
extern uint32_t off_12BE28;
extern uint32_t off_12BE1C;
extern uint32_t off_12BE30;
extern uint32_t dword_12BE38;
extern uint32_t dword_12BE34;
extern uint32_t off_12BE2C;
extern uint32_t dword_12BE3C;

// rf_read_irq_flags @ 0x12bd40, size 214 bytes
int rf_read_irq_flags()
{
  int v0; // r4
  int v1; // r5
  uint16_t *v2; // r6
  int v3; // r2
  int v4; // r1
  uint32_t *v6; // r3

  v0 = (*(uint32_t *)off_12BE18 >> 25) & 1;
  if ( (*(uint32_t *)off_12BE18 & 0x2000000) == 0
    && 32 * *(uint32_t *)off_12BE20
     - 2000
     - *((uint16_t *)off_12BE24 + 92)
     - *((uint16_t *)off_12BE24 + 93) < 0 )
  {
    return v0;
  }
  v1 = *(uint32_t *)off_12BE28;
  if ( !*(uint32_t *)off_12BE28 )
    return 1;
  v2 = (uint16_t *)off_12BE24;
  v3 = *(uint32_t *)(v1 + 12);
  v4 = *((uint16_t *)off_12BE24 + 93);
  if ( v3 - *((uint32_t *)off_12BE1C + 4) - 2000 - *((uint16_t *)off_12BE24 + 92) - v4 < 0 )
  {
    if ( **(int16_t **)off_12BE30 < 0 && v3 - *((uint32_t *)off_12BE1C + 4) + 5000 < 0 )
    {
      mmio_clear_register(dword_12BE38, dword_12BE34, 575);
      return 0;
    }
    return 0;
  }
  else
  {
    if ( **(uint8_t **)off_12BE2C != 1 )
      return 1;
    if ( **(int16_t **)off_12BE30 < 0 && v3 - *((uint32_t *)off_12BE1C + 4) - v4 < 0 )
    {
      mmio_clear_register(dword_12BE3C, dword_12BE34, 580);
      v3 = *(uint32_t *)(v1 + 12);
      v4 = v2[93];
    }
    v6 = off_12BE1C;
    *((uint32_t *)off_12BE1C + 2) = 0x40000;
    v6[12] = v3 - v4;
    v6[2] = 4;
    return 1;
  }
}

