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


extern uint32_t dword_103E98;
extern uint32_t dword_103EA4;
extern uint32_t dword_103EB4;
extern uint32_t dword_103EC0;
extern uint32_t dword_103EC8;
extern uint32_t dword_103ED0;
extern uint32_t dword_103ED8;
extern uint32_t dword_103EE0;
extern uint32_t dword_103EE8;
extern uint32_t dword_103EF0;
extern uint32_t dword_103EF8;
extern uint32_t dword_103F00;
extern uint32_t dword_103F08;
extern uint32_t dword_103F10;
extern uint32_t dword_103F18;
extern uint32_t off_103E94;
extern uint32_t off_103E9C;
extern uint32_t off_103EA0;
extern uint32_t off_103EB0;
extern uint32_t off_103EBC;

// pmu_write_control @ 0x103ca4, size 496 bytes
int  pmu_write_control(int a1)
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

  *(uint32_t *)off_103E94 = dword_103E98;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v11 = (unsigned int *)off_103E9C;
        v12 = (int *)off_103EA0;
        v13 = dword_103EC8;
        v14 = *(uint32_t *)off_103E9C;
        v15 = aDumpDac150m;
        v16 = *(uint32_t *)off_103E9C & 0x70 | 1;
        break;
      case 10:
        v1 = (unsigned int *)off_103E9C;
        v2 = (int *)off_103EA0;
        v3 = *(uint32_t *)off_103E9C;
        v4 = dword_103EC0;
        v5 = *(uint32_t *)off_103E9C;
        v6 = aDumpDpdTxRx;
        goto LABEL_24;
      case 14:
        v1 = (unsigned int *)off_103E9C;
        v2 = (int *)off_103EA0;
        v3 = *(uint32_t *)off_103E9C;
        v4 = dword_103ED0;
        v5 = *(uint32_t *)off_103E9C;
        v6 = aDumpLoftOut;
        goto LABEL_24;
      case 2:
        v11 = (unsigned int *)off_103E9C;
        v12 = (int *)off_103EA0;
        v13 = dword_103ED8;
        v14 = *(uint32_t *)off_103E9C;
        v15 = aDumpAdcIn;
        v16 = *(uint32_t *)off_103E9C & 0x70 | 2;
        break;
      default:
        switch ( a1 )
        {
          case 3:
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(uint32_t *)off_103E9C;
            v4 = dword_103EE0;
            v5 = *(uint32_t *)off_103E9C;
            v6 = aDumpRxDataIq;
            break;
          case 30:
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(uint32_t *)off_103E9C;
            v4 = dword_103EE8;
            v5 = *(uint32_t *)off_103E9C;
            v6 = aDumpRcAdcIq;
            break;
          case 31:
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(uint32_t *)off_103E9C;
            v4 = dword_103EF8;
            v5 = *(uint32_t *)off_103E9C;
            v6 = aDumpDccancelOu;
            break;
          case 32:
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(uint32_t *)off_103E9C;
            v4 = dword_103F00;
            v5 = *(uint32_t *)off_103E9C;
            v6 = aDumpPreDgcOutI;
            break;
          case 33:
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(uint32_t *)off_103E9C;
            v4 = dword_103F08;
            v5 = *(uint32_t *)off_103E9C;
            v6 = aDumpNotchOutIq;
            break;
          default:
            if ( a1 != 4 )
            {
              if ( a1 == 5 )
              {
                v1 = (unsigned int *)off_103E9C;
                v2 = (int *)off_103EA0;
                v3 = *(uint32_t *)off_103E9C;
                v4 = dword_103F10;
                v5 = *(uint32_t *)off_103E9C;
                v6 = aDumpRcOutIq;
                break;
              }
              if ( a1 != 50 )
              {
                switch ( a1 )
                {
                  case 6:
                    v1 = (unsigned int *)off_103E9C;
                    v2 = (int *)off_103EA0;
                    v3 = *(uint32_t *)off_103E9C;
                    v4 = dword_103F18;
                    v5 = *(uint32_t *)off_103E9C;
                    v6 = aDumpRcStatus;
                    break;
                  case 7:
                    v17 = (unsigned int *)off_103EB0;
                    v18 = (int *)off_103EA0;
                    v19 = dword_103EB4;
                    *(uint32_t *)off_103E9C &= 0xFFFFFF70;
                    *v17 = *v17 & 0xFF00FFFF | 0x540000;
                    *v18 = v19;
                    event_dispatch(aDumpLpfOutBpfO);
                    goto LABEL_22;
                  case 8:
                    v1 = (unsigned int *)off_103E9C;
                    v2 = (int *)off_103EA0;
                    v4 = dword_103EB4;
                    v6 = aDumpGainLoft2I;
                    *(uint32_t *)off_103EB0 = *(uint32_t *)off_103EB0 & 0xFF00FFFF | 0x570000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  case 81:
                    v1 = (unsigned int *)off_103E9C;
                    v2 = (int *)off_103EA0;
                    v4 = dword_103EB4;
                    v6 = aDumpGainLoftIn;
                    *(uint32_t *)off_103EB0 = *(uint32_t *)off_103EB0 & 0xFF00FFFF | 0x30000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  default:
                    v1 = (unsigned int *)off_103E9C;
                    v2 = (int *)off_103EA0;
                    v3 = *(uint32_t *)off_103E9C;
                    v4 = dword_103EA4;
                    v5 = *(uint32_t *)off_103E9C;
                    if ( a1 == 9 )
                      v6 = aDumpAuxFifoOut;
                    else
                      v6 = aReselectMode;
                    break;
                }
                break;
              }
            }
            v1 = (unsigned int *)off_103E9C;
            v2 = (int *)off_103EA0;
            v3 = *(uint32_t *)off_103E9C;
            v4 = dword_103EF0;
            v5 = *(uint32_t *)off_103E9C;
            v6 = aDumpRcInIq;
            break;
        }
LABEL_24:
        *v1 = v5 & 0xFFFFFF00 | v3 & 0x70;
        *v2 = v4;
        event_dispatch(v6);
        goto LABEL_22;
    }
    *v11 = v16 | v14 & 0xFFFFFF00;
    *v12 = v13;
    event_dispatch(v15);
    goto LABEL_22;
  }
  v7 = (unsigned int *)off_103EB0;
  v8 = (int *)off_103EA0;
  v9 = dword_103EB4;
  *(uint32_t *)off_103E9C &= 0xFFFFFF70;
  *v7 = *v7 & 0xFF00FFFF | 0x770000;
  *v8 = v9;
  event_dispatch(aDumpLoftPwrInO);
LABEL_22:
  *(uint32_t *)off_103EBC = 769;
  return timer_delay(500);
}
