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
extern uint32_t off_11B428;
extern uint32_t off_11B430;

// get_rf_capability @ 0x11b350, size 204 bytes
int  get_rf_capability(int result)
{
  uint32_t *v1; // r5
  char *v2; // r3
  int v3; // r2
  int v4; // r4
  int v5; // r6
  BOOL v6; // r3
  uint16_t **v7; // r7

  v1 = off_11B41C;
  if ( *((uint8_t *)off_11B41C + 160) )
  {
    v2 = (char *)off_11B41C + 28 * result;
    v3 = *((uint32_t *)v2 + 6);
    v2[47] = 1;
    v4 = result;
    v5 = 8 * result;
    if ( !v3 )
    {
      switch ( (char)result )
      {
        case 0:
          v6 = (*(uint32_t *)off_11B420 & 0x30) == 0;
          goto LABEL_6;
        case 1:
          v6 = (*(uint32_t *)off_11B420 & 0x300) == 0;
          goto LABEL_6;
        case 2:
          v6 = (*(uint32_t *)off_11B420 & 0x3000) == 0;
          goto LABEL_6;
        case 3:
          v6 = (*(uint32_t *)off_11B420 & 0x30000) == 0;
          goto LABEL_6;
        case 4:
          v6 = (*(uint32_t *)off_11B420 & 3) == 0;
LABEL_6:
          if ( v6 )
            goto LABEL_9;
          v7 = (uint16_t **)off_11B424;
          break;
        default:
          v7 = (uint16_t **)off_11B424;
          if ( **(uint16_t **)off_11B424 >= 0 )
            goto LABEL_9;
          irq_disable_mmio_write(off_11B430, (int)aTxlHeEdcaQueue, 520);
          break;
      }
      if ( **v7 < 0 )
      {
        return unknown_12f2c8(off_11B430, (int)aTxlHeMuEdcaSta, 684);
      }
      else
      {
LABEL_9:
        v1[v5 - v4 + 6] = off_11B428;
        return invalid_instruction_trap(v4);
      }
    }
  }
  return result;
}
