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


extern uint32_t off_115AA8;
extern uint32_t off_115AAC;
extern uint32_t off_115AB4;
extern uint32_t off_115AB8;
extern uint32_t off_115ABC;
extern uint32_t off_115AC0;
extern uint32_t off_115AC4;
extern uint32_t off_115AC8;
extern uint32_t off_115ACC;
extern uint32_t off_115AD0;
extern uint32_t off_115AD4;
extern uint32_t off_115AD8;
extern uint32_t off_115ADC;
extern uint32_t off_115AE0;

// gpio_read_input @ 0x11597c, size 300 bytes
uint8_t *gpio_read_input()
{
  uint32_t *v0; // r4
  uint8_t *v1; // r5
  uint32_t *v2; // r2
  uint32_t *v3; // r2
  int *v4; // r1
  int v5; // r1
  uint32_t *v6; // r2
  uint32_t *v7; // r1
  uint8_t **v8; // r1
  int v9; // r3
  uint8_t *result; // r0
  int v11; // r2
  uint32_t *v12; // r3
  uint32_t *v13; // r3
  uint32_t *v14; // r3

  v0 = off_115AA8;
  v1 = off_115AAC;
  *(uint8_t *)off_115AAC = *(uint8_t *)off_115AA8 & 0xF;
  check_status_bits(2, "d %d,", *v0 & 0xF);
  if ( *v0 << 28 )
  {
    v2 = off_115AB8;
    *(uint32_t *)off_115AB4 &= ~0x80000000;
    *v0 = 0;
    while ( (*v2 & 4) == 0 )
      ;
    v3 = off_115AB4;
    v4 = (int *)off_115AC0;
    *(uint32_t *)off_115ABC = 4;
    v5 = *((uint8_t *)v4 + 189);
    *v3 |= 0x80000000;
    if ( v5 )
      *(uint32_t *)((char *)v3 + 0xFFFFFFD4) |= 0x8000000u;
  }
  else
  {
    *(uint32_t *)off_115AD0 &= ~0x8000000u;
  }
  v6 = off_115AC4;
  v7 = off_115AA8;
  *(uint32_t *)off_115AC4 |= 0x111u;
  v1[1] = 1;
  *v7 = 32;
  v8 = (uint8_t **)off_115AC8;
  *v6 &= 0xFFFFFEEE;
  v9 = **v8;
  if ( v9 == 3 )
  {
    v13 = off_115AD4;
    *(uint32_t *)off_115AD4 |= 1u;
    if ( (*v13 & 4) != 0 )
      *(uint32_t *)off_115AD8 = 512;
  }
  else if ( v9 == 1 )
  {
    ipc_wait_flag();
    v14 = off_115AE0;
    *(uint32_t *)off_115ADC |= 0x20u;
    v14[20] |= 0x20000u;
    v14[20] |= 0x8000u;
    v14[20] |= 0x10000u;
    v14[20] = v14[20] & 0xFFFFFFC0 | 0x37;
    v14[23] = v14[23] & 0x7FFFFFFC | 0x80000001;
  }
  result = off_115ACC;
  v11 = 0;
  *(uint8_t *)off_115ACC = 0;
  while ( 1 )
  {
    v12 = (uint32_t *)(4 * v11++ - 536813312);
    if ( (v12[64] & *v12) != 0 )
      break;
    if ( v11 == 3 )
      return result;
  }
  *result = 1;
  return result;
}
