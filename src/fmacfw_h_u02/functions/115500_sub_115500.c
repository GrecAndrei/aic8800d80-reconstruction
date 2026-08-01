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

extern uint32_t off_11562C;
extern uint32_t off_115628;
extern uint32_t off_115634;
extern uint32_t dword_115630;
extern uint32_t off_115638;
extern uint32_t off_11563C;
extern uint32_t off_115640;
extern uint32_t off_115654;
extern uint32_t dword_115670;
extern uint32_t dword_11566C;
extern uint32_t off_115644;
extern uint32_t off_115668;
extern uint32_t off_115664;
extern uint32_t off_115648;
extern uint32_t dword_11564C;
extern uint32_t off_115650;
extern uint32_t dword_115658;
extern uint32_t dword_11565C;
extern uint32_t off_115660;

// rf_power_control @ 0x115500, size 296 bytes
int rf_power_control()
{
  uint32_t *v0; // r2
  uint8_t *v1; // r4
  uint32_t *v2; // r2
  uint8_t *v3; // r6
  uint32_t *v4; // r3
  uint8_t **v5; // r5
  int v6; // r3
  int result; // r0
  uint8_t *v8; // r7
  int v9; // r3
  int v10; // r3
  int v11; // r1
  uint32_t *v12; // r4

  v0 = off_11562C;
  *((uint32_t *)off_115628 + 14) |= 0x10u;
  *v0 &= ~0x2000000u;
  v1 = off_115634;
  check_feature_flag(2, dword_115630);
  v2 = off_115638;
  *(uint32_t *)off_115638 |= 0x80000000;
  v1[1] = 0;
  while ( (*v2 & 0x40000000) == 0 )
    ;
  v3 = off_11563C;
  if ( *((uint8_t *)off_11563C + 189) && **(int16_t **)off_115640 < 0 && *v1 != (*(uint32_t *)off_115654 & 0xF) )
    irq_disable_mmio_write(dword_115670, dword_11566C, 968);
  v4 = off_115638;
  v5 = (uint8_t **)off_115644;
  *(uint32_t *)off_115638 &= ~0x40000000u;
  *v4 &= ~0x80000000;
  v6 = (uint8_t)**v5;
  if ( v6 == 3 )
  {
    *(uint32_t *)off_115668 &= ~1u;
  }
  else if ( v6 == 1 )
  {
    *(uint32_t *)off_115664 &= ~0x20u;
  }
  if ( *(uint8_t *)off_115648 )
    *(uint32_t *)off_11562C |= 0x2000000u;
  else
    *((uint32_t *)off_115628 + 14) &= ~0x10u;
  result = check_feature_flag(2, dword_11564C);
  v8 = *(uint8_t **)off_115650;
  v9 = **(uint8_t **)off_115650;
  if ( v9 == 2 )
  {
    if ( **v5 == 3 )
LABEL_22:
      *(uint32_t *)off_115668 &= ~1u;
  }
  else
  {
    if ( !v3[189] )
    {
      *(uint32_t *)off_115654 = (uint8_t)(16 * *v1);
      v9 = (uint8_t)*v8;
    }
    if ( v9 == 1 )
    {
      v10 = dword_115658;
      v11 = dword_11565C;
      v12 = off_115660;
      do
      {
        if ( *(uint8_t *)(v10 + 37) )
        {
          result = v12[4];
          **(uint32_t **)(v10 + 340) = result;
        }
        v10 += 696;
      }
      while ( v10 != v11 );
    }
    if ( **v5 == 3 && *v8 == 2 )
      goto LABEL_22;
  }
  return result;
}

