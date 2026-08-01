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

extern uint32_t off_103D7C;
extern uint32_t dword_103D80;
extern uint32_t off_103D84;
extern uint32_t off_103D88;
extern uint32_t dword_103DB0;
extern uint32_t dword_103DB4;
extern uint32_t dword_103DA8;
extern uint32_t dword_103DAC;
extern uint32_t dword_103DB8;
extern uint32_t dword_103DBC;
extern uint32_t dword_103DC0;
extern uint32_t dword_103DC4;
extern uint32_t dword_103DC8;
extern uint32_t dword_103DCC;
extern uint32_t dword_103DD0;
extern uint32_t dword_103DD4;
extern uint32_t dword_103DE0;
extern uint32_t dword_103DE4;
extern uint32_t dword_103DE8;
extern uint32_t dword_103DEC;
extern uint32_t dword_103DF0;
extern uint32_t dword_103DF4;
extern uint32_t dword_103DF8;
extern uint32_t dword_103DFC;
extern uint32_t dword_103E00;
extern uint32_t dword_103E04;
extern uint32_t off_103D98;
extern uint32_t dword_103D9C;
extern uint32_t dword_103E08;
extern uint32_t dword_103E0C;
extern uint32_t dword_103E10;
extern uint32_t dword_103D8C;
extern uint32_t dword_103D90;
extern uint32_t dword_103D94;
extern uint32_t dword_103DD8;
extern uint32_t dword_103DDC;
extern uint32_t dword_103DA0;
extern uint32_t off_103DA4;

// bb_start_cmd @ 0x103b8c, size 496 bytes
int  bb_start_cmd(int a1)
{
  unsigned int *v1; // r2
  int *v2; // r4
  unsigned int v3; // r1
  int v4; // r5
  unsigned int v5; // r3
  int v6; // r0
  void *v7; // r2
  unsigned int *v8; // r4
  int *v9; // r5
  int v10; // r6
  int v11; // r0
  int v12; // r1
  int v14; // r1
  unsigned int *v15; // r2
  int *v16; // r4
  int v17; // r5
  int v18; // r1
  int v19; // r0
  int v20; // r3
  unsigned int v21; // r1
  void *v22; // r2
  unsigned int *v23; // r4
  int *v24; // r5
  int v25; // r6
  int v26; // r0
  int v27; // r1

  *(uint32_t *)off_103D7C = dword_103D80;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v15 = (unsigned int *)off_103D84;
        v16 = (int *)off_103D88;
        v17 = dword_103DB0;
        v18 = *(uint32_t *)off_103D84;
        v19 = dword_103DB4;
        v20 = *(uint32_t *)off_103D84 & 0x70 | 1;
        break;
      case 10:
        v1 = (unsigned int *)off_103D84;
        v2 = (int *)off_103D88;
        v3 = *(uint32_t *)off_103D84;
        v4 = dword_103DA8;
        v5 = *(uint32_t *)off_103D84;
        v6 = dword_103DAC;
        goto LABEL_24;
      case 14:
        v1 = (unsigned int *)off_103D84;
        v2 = (int *)off_103D88;
        v3 = *(uint32_t *)off_103D84;
        v4 = dword_103DB8;
        v5 = *(uint32_t *)off_103D84;
        v6 = dword_103DBC;
        goto LABEL_24;
      case 2:
        v15 = (unsigned int *)off_103D84;
        v16 = (int *)off_103D88;
        v17 = dword_103DC0;
        v18 = *(uint32_t *)off_103D84;
        v19 = dword_103DC4;
        v20 = *(uint32_t *)off_103D84 & 0x70 | 2;
        break;
      default:
        switch ( a1 )
        {
          case 3:
            v1 = (unsigned int *)off_103D84;
            v2 = (int *)off_103D88;
            v3 = *(uint32_t *)off_103D84;
            v4 = dword_103DC8;
            v5 = *(uint32_t *)off_103D84;
            v6 = dword_103DCC;
            break;
          case 30:
            v1 = (unsigned int *)off_103D84;
            v2 = (int *)off_103D88;
            v3 = *(uint32_t *)off_103D84;
            v4 = dword_103DD0;
            v5 = *(uint32_t *)off_103D84;
            v6 = dword_103DD4;
            break;
          case 31:
            v1 = (unsigned int *)off_103D84;
            v2 = (int *)off_103D88;
            v3 = *(uint32_t *)off_103D84;
            v4 = dword_103DE0;
            v5 = *(uint32_t *)off_103D84;
            v6 = dword_103DE4;
            break;
          case 32:
            v1 = (unsigned int *)off_103D84;
            v2 = (int *)off_103D88;
            v3 = *(uint32_t *)off_103D84;
            v4 = dword_103DE8;
            v5 = *(uint32_t *)off_103D84;
            v6 = dword_103DEC;
            break;
          case 33:
            v1 = (unsigned int *)off_103D84;
            v2 = (int *)off_103D88;
            v3 = *(uint32_t *)off_103D84;
            v4 = dword_103DF0;
            v5 = *(uint32_t *)off_103D84;
            v6 = dword_103DF4;
            break;
          default:
            if ( a1 != 4 )
            {
              if ( a1 == 5 )
              {
                v1 = (unsigned int *)off_103D84;
                v2 = (int *)off_103D88;
                v3 = *(uint32_t *)off_103D84;
                v4 = dword_103DF8;
                v5 = *(uint32_t *)off_103D84;
                v6 = dword_103DFC;
                break;
              }
              if ( a1 != 50 )
              {
                switch ( a1 )
                {
                  case 6:
                    v1 = (unsigned int *)off_103D84;
                    v2 = (int *)off_103D88;
                    v3 = *(uint32_t *)off_103D84;
                    v4 = dword_103E00;
                    v5 = *(uint32_t *)off_103D84;
                    v6 = dword_103E04;
                    break;
                  case 7:
                    v22 = off_103D84;
                    v23 = (unsigned int *)off_103D98;
                    v24 = (int *)off_103D88;
                    v25 = dword_103D9C;
                    v26 = dword_103E08;
                    v27 = *(uint32_t *)off_103D84 & 0x70;
                    *(uint32_t *)off_103D84 &= 0xFFFFFF70;
                    *v23 = *v23 & 0xFF00FFFF | 0x540000;
                    *v24 = v25;
                    alloc_tx_event(v26, v27, v22);
                    goto LABEL_22;
                  case 8:
                    v1 = (unsigned int *)off_103D84;
                    v2 = (int *)off_103D88;
                    v4 = dword_103D9C;
                    v6 = dword_103E0C;
                    *(uint32_t *)off_103D98 = *(uint32_t *)off_103D98 & 0xFF00FFFF | 0x570000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  case 81:
                    v1 = (unsigned int *)off_103D84;
                    v2 = (int *)off_103D88;
                    v4 = dword_103D9C;
                    v6 = dword_103E10;
                    *(uint32_t *)off_103D98 = *(uint32_t *)off_103D98 & 0xFF00FFFF | 0x30000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  default:
                    v1 = (unsigned int *)off_103D84;
                    v2 = (int *)off_103D88;
                    v3 = *(uint32_t *)off_103D84;
                    v4 = dword_103D8C;
                    v5 = *(uint32_t *)off_103D84;
                    if ( a1 == 9 )
                      v6 = dword_103D90;
                    else
                      v6 = dword_103D94;
                    break;
                }
                break;
              }
            }
            v1 = (unsigned int *)off_103D84;
            v2 = (int *)off_103D88;
            v3 = *(uint32_t *)off_103D84;
            v4 = dword_103DD8;
            v5 = *(uint32_t *)off_103D84;
            v6 = dword_103DDC;
            break;
        }
LABEL_24:
        v14 = v3 & 0x70;
        *v1 = v5 & 0xFFFFFF00 | v14;
        *v2 = v4;
        alloc_tx_event(v6, v14, v1);
        goto LABEL_22;
    }
    v21 = v18 & 0xFFFFFF00;
    *v15 = v20 | v21;
    *v16 = v17;
    alloc_tx_event(v19, v21, v15);
    goto LABEL_22;
  }
  v7 = off_103D84;
  v8 = (unsigned int *)off_103D98;
  v9 = (int *)off_103D88;
  v10 = dword_103D9C;
  v11 = dword_103DA0;
  v12 = *(uint32_t *)off_103D84 & 0x70;
  *(uint32_t *)off_103D84 &= 0xFFFFFF70;
  *v8 = *v8 & 0xFF00FFFF | 0x770000;
  *v9 = v10;
  alloc_tx_event(v11, v12, v7);
LABEL_22:
  *(uint32_t *)off_103DA4 = 769;
  return mmio_read32(500);
}

