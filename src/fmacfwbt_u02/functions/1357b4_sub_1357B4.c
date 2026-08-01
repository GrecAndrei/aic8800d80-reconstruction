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

extern uint32_t off_135870;
extern uint32_t dword_135878;
extern uint32_t off_135874;
extern uint32_t dword_135880;
extern uint32_t dword_13587C;

// hci_vendor_read_rf @ 0x1357b4, size 186 bytes
uint32_t * hci_vendor_read_rf(char *a1)
{
  int v2; // r8
  unsigned int v3; // r1
  int v4; // r6
  int v5; // r3
  int v6; // r1
  char *v7; // r4
  int v8; // r12
  char *v9; // r3
  char v10; // t1
  int v12; // r1

  v2 = *((uint32_t *)off_135870 + 5);
  irq_lock(6154, 6);
  v3 = *(uint16_t *)a1;
  v4 = *((uint16_t *)a1 + 7);
  if ( v3 <= 5 )
  {
    v12 = dword_135878;
    *(uint16_t *)(v2 + 16) = 0;
    state_check_feature(256, v12, v4);
    if ( !v4 )
      return rf_write_cal_param(*((uint16_t *)a1 + 8) & 0x3FFF);
  }
  else
  {
    v5 = *(uint16_t *)(v2 + 14);
    v6 = (uint16_t)(v3 - 6);
    v7 = a1 + 18;
    if ( v6 + v5 > 800 )
    {
      if ( **(int16_t **)off_135874 < 0 )
      {
        mmio_field_update(dword_135880, dword_13587C, 1236);
        v5 = *(uint16_t *)(v2 + 14);
      }
      v6 = (uint16_t)(800 - v5);
    }
    v8 = v2 + 20 + v5;
    if ( v6 )
    {
      do
      {
        v9 = v7 - 18;
        v10 = *v7++;
        *(uint8_t *)(v9 - a1 + v8) = v10;
      }
      while ( v7 != &a1[v6 + 18] );
    }
    *(uint16_t *)(v2 + 16) = v6;
    state_check_feature(256, dword_135878, v4);
    if ( !v4 )
      return rf_write_cal_param(*((uint16_t *)a1 + 8) & 0x3FFF);
  }
  return (uint32_t *)event_dispatch(v4);
}

