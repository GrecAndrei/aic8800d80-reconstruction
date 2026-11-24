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


extern uint32_t dword_10386C;
extern uint32_t dword_103878;
extern uint32_t dword_103888;
extern uint32_t dword_103894;
extern uint32_t dword_10389C;
extern uint32_t dword_1038A4;
extern uint32_t dword_1038AC;
extern uint32_t dword_1038B4;
extern uint32_t dword_1038BC;
extern uint32_t dword_1038C4;
extern uint32_t dword_1038CC;
extern uint32_t dword_1038D4;
extern uint32_t dword_1038DC;
extern uint32_t dword_1038E4;
extern uint32_t dword_1038EC;
extern uint32_t off_103868;
extern uint32_t off_103870;
extern uint32_t off_103874;
extern uint32_t off_103884;
extern uint32_t off_103890;

// set_system_mode @ 0x103678, size 496 bytes
int  set_system_mode(int a1)
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

  *(uint32_t *)off_103868 = dword_10386C;
  if ( a1 )
  {
    switch ( a1 )
    {
      case 1:
        v11 = (unsigned int *)off_103870;
        v12 = (int *)off_103874;
        v13 = dword_10389C;
        v14 = *(uint32_t *)off_103870;
        v15 = aDumpDac150m;
        v16 = *(uint32_t *)off_103870 & 0x70 | 1;
        break;
      case 10:
        v1 = (unsigned int *)off_103870;
        v2 = (int *)off_103874;
        v3 = *(uint32_t *)off_103870;
        v4 = dword_103894;
        v5 = *(uint32_t *)off_103870;
        v6 = aDumpDpdTxRx;
        goto LABEL_24;
      case 14:
        v1 = (unsigned int *)off_103870;
        v2 = (int *)off_103874;
        v3 = *(uint32_t *)off_103870;
        v4 = dword_1038A4;
        v5 = *(uint32_t *)off_103870;
        v6 = aDumpLoftOut;
        goto LABEL_24;
      case 2:
        v11 = (unsigned int *)off_103870;
        v12 = (int *)off_103874;
        v13 = dword_1038AC;
        v14 = *(uint32_t *)off_103870;
        v15 = aDumpAdcIn;
        v16 = *(uint32_t *)off_103870 & 0x70 | 2;
        break;
      default:
        switch ( a1 )
        {
          case 3:
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038B4;
            v5 = *(uint32_t *)off_103870;
            v6 = aDumpRxDataIq;
            break;
          case 30:
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038BC;
            v5 = *(uint32_t *)off_103870;
            v6 = aDumpRcAdcIq;
            break;
          case 31:
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038CC;
            v5 = *(uint32_t *)off_103870;
            v6 = aDumpDccancelOu;
            break;
          case 32:
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038D4;
            v5 = *(uint32_t *)off_103870;
            v6 = aDumpPreDgcOutI;
            break;
          case 33:
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038DC;
            v5 = *(uint32_t *)off_103870;
            v6 = aDumpNotchOutIq;
            break;
          default:
            if ( a1 != 4 )
            {
              if ( a1 == 5 )
              {
                v1 = (unsigned int *)off_103870;
                v2 = (int *)off_103874;
                v3 = *(uint32_t *)off_103870;
                v4 = dword_1038E4;
                v5 = *(uint32_t *)off_103870;
                v6 = aDumpRcOutIq;
                break;
              }
              if ( a1 != 50 )
              {
                switch ( a1 )
                {
                  case 6:
                    v1 = (unsigned int *)off_103870;
                    v2 = (int *)off_103874;
                    v3 = *(uint32_t *)off_103870;
                    v4 = dword_1038EC;
                    v5 = *(uint32_t *)off_103870;
                    v6 = aDumpRcStatus;
                    break;
                  case 7:
                    v17 = (unsigned int *)off_103884;
                    v18 = (int *)off_103874;
                    v19 = dword_103888;
                    *(uint32_t *)off_103870 &= 0xFFFFFF70;
                    *v17 = *v17 & 0xFF00FFFF | 0x540000;
                    *v18 = v19;
                    dispatch_event_handler_1(aDumpLpfOutBpfO);
                    goto LABEL_22;
                  case 8:
                    v1 = (unsigned int *)off_103870;
                    v2 = (int *)off_103874;
                    v4 = dword_103888;
                    v6 = aDumpGainLoft2I;
                    *(uint32_t *)off_103884 = *(uint32_t *)off_103884 & 0xFF00FFFF | 0x570000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  case 81:
                    v1 = (unsigned int *)off_103870;
                    v2 = (int *)off_103874;
                    v4 = dword_103888;
                    v6 = aDumpGainLoftIn;
                    *(uint32_t *)off_103884 = *(uint32_t *)off_103884 & 0xFF00FFFF | 0x30000;
                    v3 = *v1;
                    v5 = *v1;
                    break;
                  default:
                    v1 = (unsigned int *)off_103870;
                    v2 = (int *)off_103874;
                    v3 = *(uint32_t *)off_103870;
                    v4 = dword_103878;
                    v5 = *(uint32_t *)off_103870;
                    if ( a1 == 9 )
                      v6 = aDumpAuxFifoOut;
                    else
                      v6 = aReselectMode;
                    break;
                }
                break;
              }
            }
            v1 = (unsigned int *)off_103870;
            v2 = (int *)off_103874;
            v3 = *(uint32_t *)off_103870;
            v4 = dword_1038C4;
            v5 = *(uint32_t *)off_103870;
            v6 = aDumpRcInIq;
            break;
        }
LABEL_24:
        *v1 = v5 & 0xFFFFFF00 | v3 & 0x70;
        *v2 = v4;
        dispatch_event_handler_1(v6);
        goto LABEL_22;
    }
    *v11 = v16 | v14 & 0xFFFFFF00;
    *v12 = v13;
    dispatch_event_handler_1(v15);
    goto LABEL_22;
  }
  v7 = (unsigned int *)off_103884;
  v8 = (int *)off_103874;
  v9 = dword_103888;
  *(uint32_t *)off_103870 &= 0xFFFFFF70;
  *v7 = *v7 & 0xFF00FFFF | 0x770000;
  *v8 = v9;
  dispatch_event_handler_1(aDumpLoftPwrInO);
LABEL_22:
  *(uint32_t *)off_103890 = 769;
  return write_timer_reg(500);
}
