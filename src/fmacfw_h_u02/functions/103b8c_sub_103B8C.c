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


extern uint32_t dword_103D80;
extern uint32_t dword_103D8C;
extern uint32_t dword_103D9C;
extern uint32_t dword_103DA8;
extern uint32_t dword_103DB0;
extern uint32_t dword_103DB8;
extern uint32_t dword_103DC0;
extern uint32_t dword_103DC8;
extern uint32_t dword_103DD0;
extern uint32_t dword_103DD8;
extern uint32_t dword_103DE0;
extern uint32_t dword_103DE8;
extern uint32_t dword_103DF0;
extern uint32_t dword_103DF8;
extern uint32_t dword_103E00;
extern uint32_t off_103D7C;
extern uint32_t off_103D84;
extern uint32_t off_103D88;
extern uint32_t off_103D98;
extern uint32_t off_103DA4;

// bb_start_cmd @ 0x103b8c, size 496 bytes
int  bb_start_cmd(int a1)
{
  unsigned int *v1; // r2
  int *v2; // r4
  unsigned int v3; // r1
  int v4; // r5
  unsigned int v5; // r3
  const char *v6; // r0
  unsigned int *v7; // r4
  int *v8; // r5
  int v9; // r6
  unsigned int *v11; // r2
  int *v12; // r4
  int v13; // r5
  int v14; // r1
  const char *v15; // r0
  int v16; // r3
  unsigned int *v17; // r4
  int *v18; // r5
  int v19; // r6

  *(uint32_t *)off_103D7C = dword_103D80;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v11 = (unsigned int *)off_103D84;
        v12 = (int *)off_103D88;
        v13 = dword_103DB0;
        v14 = *(uint32_t *)off_103D84;
        v15 = aDumpDac150m;
        v16 = *(uint32_t *)off_103D84 & 0x70 | 1;
        break;
      case 10:
        v1 = (unsigned int *)off_103D84;
        v2 = (int *)off_103D88;
        v3 = *(uint32_t *)off_103D84;
        v4 = dword_103DA8;
        v5 = *(uint32_t *)off_103D84;
        v6 = aDumpDpdTxRx;
        goto LABEL_24;
      case 14:
        v1 = (unsigned int *)off_103D84;
        v2 = (int *)off_103D88;
        v3 = *(uint32_t *)off_103D84;
        v4 = dword_103DB8;
        v5 = *(uint32_t *)off_103D84;
        v6 = aDumpLoftOut;
        goto LABEL_24;
      case 2:
        v11 = (unsigned int *)off_103D84;
        v12 = (int *)off_103D88;
        v13 = dword_103DC0;
        v14 = *(uint32_t *)off_103D84;
        v15 = aDumpAdcIn;
        v16 = *(uint32_t *)off_103D84 & 0x70 | 2;
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
            v6 = aDumpRxDataIq;
            break;
          case 30:
            v1 = (unsigned int *)off_103D84;
            v2 = (int *)off_103D88;
            v3 = *(uint32_t *)off_103D84;
            v4 = dword_103DD0;
            v5 = *(uint32_t *)off_103D84;
            v6 = aDumpRcAdcIq;
            break;
          case 31:
            v1 = (unsigned int *)off_103D84;
            v2 = (int *)off_103D88;
            v3 = *(uint32_t *)off_103D84;
            v4 = dword_103DE0;
            v5 = *(uint32_t *)off_103D84;
            v6 = aDumpDccancelOu;
            break;
          case 32:
            v1 = (unsigned int *)off_103D84;
            v2 = (int *)off_103D88;
            v3 = *(uint32_t *)off_103D84;
            v4 = dword_103DE8;
            v5 = *(uint32_t *)off_103D84;
            v6 = aDumpPreDgcOutI;
            break;
          case 33:
            v1 = (unsigned int *)off_103D84;
            v2 = (int *)off_103D88;
            v3 = *(uint32_t *)off_103D84;
            v4 = dword_103DF0;
            v5 = *(uint32_t *)off_103D84;
            v6 = aDumpNotchOutIq;
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
                v6 = aDumpRcOutIq;
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
                    v6 = aDumpRcStatus;
                    break;
                  case 7:
                    v17 = (unsigned int *)off_103D98;
                    v18 = (int *)off_103D88;
                    v19 = dword_103D9C;
                    *(uint32_t *)off_103D84 &= 0xFFFFFF70;
                    *v17 = *v17 & 0xFF00FFFF | 0x540000;
                    *v18 = v19;
                    alloc_tx_event(aDumpLpfOutBpfO);
                    goto LABEL_22;
                  case 8:
                    v1 = (unsigned int *)off_103D84;
                    v2 = (int *)off_103D88;
                    v4 = dword_103D9C;
                    v6 = aDumpGainLoft2I;
                    *(uint32_t *)off_103D98 = *(uint32_t *)off_103D98 & 0xFF00FFFF | 0x570000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  case 81:
                    v1 = (unsigned int *)off_103D84;
                    v2 = (int *)off_103D88;
                    v4 = dword_103D9C;
                    v6 = aDumpGainLoftIn;
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
                      v6 = aDumpAuxFifoOut;
                    else
                      v6 = aReselectMode;
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
            v6 = aDumpRcInIq;
            break;
        }
LABEL_24:
        *v1 = v5 & 0xFFFFFF00 | v3 & 0x70;
        *v2 = v4;
        alloc_tx_event(v6);
        goto LABEL_22;
    }
    *v11 = v16 | v14 & 0xFFFFFF00;
    *v12 = v13;
    alloc_tx_event(v15);
    goto LABEL_22;
  }
  v7 = (unsigned int *)off_103D98;
  v8 = (int *)off_103D88;
  v9 = dword_103D9C;
  *(uint32_t *)off_103D84 &= 0xFFFFFF70;
  *v7 = *v7 & 0xFF00FFFF | 0x770000;
  *v8 = v9;
  alloc_tx_event(aDumpLoftPwrInO);
LABEL_22:
  *(uint32_t *)off_103DA4 = 769;
  return mmio_read32(500);
}
