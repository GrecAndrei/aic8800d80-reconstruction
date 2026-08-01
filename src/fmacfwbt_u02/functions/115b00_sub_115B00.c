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

extern uint32_t off_115B78;
extern uint32_t off_115B7C;
extern uint32_t dword_115B80;
extern uint32_t dword_115B84;
extern uint32_t off_115B8C;
extern uint32_t off_115B88;

// check_nvic_irq @ 0x115b00, size 118 bytes
int  check_nvic_irq(int a1, int a2)
{
  uint32_t *v2; // r4
  int v3; // r3
  int v4; // r2
  int v5; // r3
  int v6; // r5
  int i; // r2
  int result; // r0
  int v9; // r0
  void *v10; // r2

  v2 = off_115B78;
  v3 = *((uint32_t *)off_115B78 + 65);
  v4 = v3 << 27;
  if ( (v3 & 0x10) == 0 )
    goto LABEL_6;
  v5 = *(uint32_t *)off_115B7C;
  if ( (dword_115B80 & *(uint32_t *)off_115B7C) == 0 )
  {
    v6 = dword_115B84 & v5;
    if ( (v5 & 0x40000000) != 0 )
    {
      v9 = check_radio_flag(0);
      v10 = off_115B8C;
      *(uint32_t *)off_115B8C = 0x40000000;
      v2[97] = 16;
      if ( v6 < 0 )
        log_debug_b(v9, 0x40000000, (int)v10);
      goto LABEL_6;
    }
    if ( v6 < 0 )
    {
      log_debug_b(0, a2, v4);
      if ( !*((uint8_t *)off_115B88 + 3) )
      {
LABEL_6:
        for ( i = 0; ; ++i )
        {
          result = *(uint32_t *)(4 * i - 536813056) & *(uint32_t *)(4 * i - 536813312);
          if ( i == 1 )
          {
            if ( (result & 0xFFFFFFEF) != 0 )
              return 1;
          }
          else
          {
            if ( result )
              return 1;
            if ( i == 2 )
              return result;
          }
        }
      }
    }
  }
  return 1;
}

