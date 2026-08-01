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

extern uint32_t off_11B41C;
extern uint32_t off_11B420;
extern uint32_t off_11B424;
extern uint32_t dword_11B430;
extern uint32_t dword_11B434;
extern uint32_t dword_11B42C;
extern uint32_t dword_11B428;

// get_rf_capability @ 0x11b350, size 204 bytes
int  get_rf_capability(int result, int a2, int a3, int a4)
{
  uint32_t *v4; // r5
  char *v5; // r3
  int v6; // r2
  int v7; // r4
  int v8; // r6
  BOOL v9; // r3
  int16_t **v10; // r7

  v4 = off_11B41C;
  if ( *((uint8_t *)off_11B41C + 160) )
  {
    v5 = (char *)off_11B41C + 28 * result;
    v6 = *((uint32_t *)v5 + 6);
    v5[47] = 1;
    v7 = result;
    v8 = 8 * result;
    if ( !v6 )
    {
      switch ( (char)result )
      {
        case 0:
          v9 = (*(uint32_t *)off_11B420 & 0x30) == 0;
          goto LABEL_6;
        case 1:
          v9 = (*(uint32_t *)off_11B420 & 0x300) == 0;
          goto LABEL_6;
        case 2:
          v9 = (*(uint32_t *)off_11B420 & 0x3000) == 0;
          goto LABEL_6;
        case 3:
          v9 = (*(uint32_t *)off_11B420 & 0x30000) == 0;
          goto LABEL_6;
        case 4:
          v9 = (*(uint32_t *)off_11B420 & 3) == 0;
LABEL_6:
          if ( v9 )
            goto LABEL_9;
          v10 = (int16_t **)off_11B424;
          break;
        default:
          v10 = (int16_t **)off_11B424;
          if ( **(int16_t **)off_11B424 >= 0 )
            goto LABEL_9;
          irq_disable_mmio_write(dword_11B430, dword_11B434, 520);
          break;
      }
      if ( **v10 < 0 )
      {
        return unknown_12f2c8(dword_11B430, dword_11B42C, 684, a4);
      }
      else
      {
LABEL_9:
        v4[v8 - v7 + 6] = dword_11B428;
        return invalid_instruction_trap(v7);
      }
    }
  }
  return result;
}

