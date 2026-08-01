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

extern uint32_t off_11C014;
extern uint32_t dword_11C018;
extern uint32_t dword_11C010;

// ke_event_process @ 0x11bf38, size 216 bytes
// Doc: ke_event_process [unknown]: unknown helper, low-confidence guess
// ke_event_process [unknown]: unknown helper, low-confidence guess
BOOL  ke_event_process(int a1, int a2)
{
  uint8_t *v2; // r10
  int *v3; // r4
  int v5; // r3
  int v6; // r7
  int v7; // r9
  int v9; // r11
  int v10; // r1

  v2 = off_11C014;
  v3 = *((int **)off_11C014 + 4);
  if ( !v3 )
  {
    v6 = *(uint32_t *)(a1 + 72);
    v7 = *((uint32_t *)off_11C014 + 10);
    goto LABEL_11;
  }
  v5 = v3[1];
  v6 = *(uint32_t *)(a1 + 72);
  v7 = *((uint32_t *)off_11C014 + 10);
  if ( v5 != a2 )
  {
    v9 = dword_11C018;
    while ( v5 - a2 < 0 )
    {
      v10 = *((uint8_t *)v3 + 8);
      if ( v10 == *(uint8_t *)(a1 + 95) )
      {
        dispatch_event_handler(v9, v10);
        check_kernel_state_alt2(v2 + 16, v3);
        *((uint8_t *)v3 + 9) &= ~1u;
        v3 = (int *)*v3;
        if ( !v3 )
          break;
      }
      else
      {
        v3 = (int *)*v3;
        if ( !v3 )
          break;
      }
      v5 = v3[1];
      if ( v5 == a2 )
        goto LABEL_8;
    }
LABEL_11:
    if ( (uint8_t)v2[90] > 1u )
    {
      *(uint8_t *)(a1 + 85) |= 4u;
      return v6 != v7;
    }
    goto LABEL_14;
  }
LABEL_8:
  if ( (uint8_t)v2[90] > 1u )
  {
    check_kernel_state_alt2(dword_11C010, a1 + 76);
    *(uint8_t *)(a1 + 85) = *(uint8_t *)(a1 + 85) & 0xFC | 2;
    ++v2[91];
    return v6 != v7;
  }
LABEL_14:
  *(uint8_t *)(a1 + 85) |= 2u;
  ++v2[91];
  return v6 != v7;
}

