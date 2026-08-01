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

extern uint32_t off_121B74;
extern uint32_t dword_121B78;
extern uint32_t off_121B70;
extern uint32_t off_121B7C;
extern uint32_t off_121B90;
extern uint32_t dword_121B98;
extern uint32_t dword_121B94;
extern uint32_t off_121B80;
extern uint32_t off_121B88;
extern uint32_t off_121B84;
extern uint32_t dword_121B8C;

// mmio_clear_bit @ 0x121b14, size 90 bytes
unsigned int mmio_clear_bit()
{
  int16_t **v0; // r0
  int v1; // r3
  int *v2; // r4
  int v3; // r2
  unsigned int result; // r0
  uint32_t *v5; // r2

  v0 = (int16_t **)off_121B74;
  v1 = dword_121B78;
  *(uint32_t *)off_121B70 &= ~2u;
  v2 = (int *)off_121B7C;
  v3 = **v0;
  *(uint32_t *)off_121B7C = v1;
  if ( v3 < 0 && *(uint32_t *)off_121B90 << 28 )
  {
    mmio_field_update(dword_121B98, dword_121B94, 472);
    v1 = *v2;
  }
  *(uint32_t *)off_121B80 = v1 | v2[1];
  result = rf_ant_switch_set(0);
  v5 = off_121B88;
  *(uint32_t *)off_121B84 = dword_121B8C;
  *v5 &= 0xFFFBFFFE;
  return result;
}

