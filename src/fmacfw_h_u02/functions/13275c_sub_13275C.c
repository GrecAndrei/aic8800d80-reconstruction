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

extern uint32_t off_1327B8;
extern uint32_t dword_1327BC;
extern uint32_t dword_1327C0;

// get_phy_status_byte @ 0x13275c, size 92 bytes
int  get_phy_status_byte(int a1)
{
  int v2; // r0
  int v3; // r3
  int v4; // r4
  int v5; // r0
  char v6; // r2
  int v7; // t1
  int v8; // r0
  int result; // r0

  v2 = *(uint8_t *)(a1 + 192);
  if ( **(int16_t **)off_1327B8 >= 0 )
  {
LABEL_2:
    if ( !v2 )
      goto LABEL_7;
    goto LABEL_3;
  }
  if ( !v2 )
  {
    irq_disable_mmio_write(dword_1327BC, dword_1327C0, 707);
    v2 = *(uint8_t *)(a1 + 192);
    goto LABEL_2;
  }
LABEL_3:
  v3 = a1 + 192;
  v4 = a1 + 192 + v2;
  v5 = 0;
  do
  {
    v7 = *(uint8_t *)++v3;
    v6 = v7;
    if ( (int)(v7 & 0xFFFFFF7F) > v5 )
      v5 = v6 & 0x7F;
  }
  while ( v3 != v4 );
LABEL_7:
  cmd_char_validate();
  result = rf_set_mode(a1, v8);
  *(uint8_t *)(a1 + 350) = 0;
  return result;
}

