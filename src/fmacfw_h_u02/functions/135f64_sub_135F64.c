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

extern uint32_t dword_135FFC;
extern uint32_t dword_135FF8;
extern uint32_t dword_136000;
extern uint32_t off_136004;
extern uint32_t off_136008;
extern uint32_t off_13600C;
extern uint32_t off_136010;

// patch_code_load @ 0x135f64, size 148 bytes
int  patch_code_load(int a1, uint8_t *a2, int16_t a3, int16_t a4)
{
  int16_t v6; // r2
  int v7; // r0
  int v9; // r0
  uint32_t *v10; // r1
  uint32_t *v11; // r4
  int v12; // r6
  int v13; // r0
  unsigned int v14; // r3
  int *v15; // r3
  int v16; // r3

  alloc_tx_event(dword_135FFC, dword_135FF8);
  v6 = a3;
  v7 = dword_136000 + 1320 * *a2;
  if ( *(uint8_t *)(v7 + 106) == 2 && !*(uint8_t *)(v7 + 108) )
  {
    v9 = hci_cmd_handler(7u);
    v6 = a3;
    if ( !v9 )
    {
      bsscfg_get(*a2);
      *(uint8_t *)off_136004 = 0;
      v6 = a3;
      if ( (__get_CPSR() & 1) == 0 )
      {
        __disable_irq();
        *(uint32_t *)off_136008 = 1;
      }
      v10 = off_13600C;
      v11 = off_136010;
      v12 = *(uint32_t *)off_13600C;
      v13 = *(uint32_t *)off_13600C + 1;
      v14 = *((uint32_t *)off_136010 + 1) & 0xFFFFFFEF;
      *(uint32_t *)off_13600C = v13;
      v11[1] = v14;
      if ( v13 )
      {
        v15 = (int *)off_136008;
        *v10 = v12;
        v16 = *v15;
        if ( !v12 )
        {
          if ( v16 )
            __enable_irq();
        }
      }
    }
  }
  mac_write_header_word(7175, a4, v6);
  return 0;
}

