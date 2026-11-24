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


extern uint32_t dword_117D70;
extern uint32_t dword_117D78;
extern uint32_t dword_117D88;
extern uint32_t off_117D6C;
extern uint32_t off_117D74;
extern uint32_t off_117D7C;
extern uint32_t off_117D80;
extern uint32_t off_117D8C;
extern uint32_t off_117D98;

// check_cal_status @ 0x117bf0, size 380 bytes
int  check_cal_status(int result, uint32_t *a2)
{
  int v2; // r3
  int v3; // r2
  int v4; // r4
  uint8_t *v6; // r6
  uint8_t *v7; // r9
  uint32_t *v8; // r0
  int v9; // r12
  uint32_t *v10; // r7
  unsigned int v11; // r3
  uint16_t v12; // lr
  int v13; // r2
  uint32_t *v14; // r1
  int v15; // r3
  int *v16; // r12
  int *v17; // r6
  int v18; // r2
  int v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r6
  int v23; // [sp+0h] [bp-28h] BYREF
  int v24; // [sp+4h] [bp-24h]

  v2 = *(uint32_t *)(result + 84);
  if ( v2 < 0 )
  {
    v3 = **(uint8_t **)off_117D6C;
    v4 = result;
    switch ( v3 )
    {
      case 2:
        v6 = util_call_void();
        if ( v6 )
        {
          v7 = off_117D98;
          if ( *((uint32_t *)off_117D98 + 2057) )
          {
            v8 = list_pop(dword_117D70);
            *v6 = 8;
            v6[1] = 0;
            v6[3] = 0;
            v6[2] = 18;
            v9 = *a2 & 0xF;
            v10 = v8;
            v24 = *(uint32_t *)(v4 + 84) & 0x3FFFFFFF;
            v23 = v9;
            memcpy_1(v6 + 4, (char *)&v23, 8u);
            v11 = *((uint16_t *)v7 + 4122);
            if ( v11 > 0x186 )
            {
              v13 = 0;
              LOWORD(v11) = 0;
              v12 = 1;
            }
            else
            {
              v12 = v11 + 1;
              v13 = 8 * v11;
            }
            v14 = off_117D74;
            *((uint16_t *)v10 + 6) = v11;
            v15 = dword_117D78;
            v16 = (int *)(*v14 + v13);
            v16[1] = (int)v6;
            *v16 = v15 & *v16 | 0x400000C;
            LOBYTE(v15) = v7[3074];
            *((uint16_t *)v7 + 4122) = v12;
            v7[3074] = v15 + 1;
            v10[1] = v16;
            *((uint8_t *)v10 + 14) = 1;
            *v10 = 0;
            v10[2] = 12;
            if ( (__get_CPSR() & 1) == 0 )
            {
              __disable_irq();
              *(uint32_t *)off_117D7C = 1;
            }
            v17 = (int *)off_117D80;
            v18 = *(uint16_t *)(v4 + 32);
            v19 = *a2 & 0xF;
            ++*(uint32_t *)off_117D80;
            alloc_tx_event("cfms: %x, sn=%d, st=%d\r\n", v4, v18, v19);
            wlan_ioctl_handler_1(dword_117D88, v10);
            result = rf_is_idle();
            if ( *v17 )
            {
              v20 = *v17 - 1;
              v21 = *(uint32_t *)off_117D7C;
              *v17 = v20;
              if ( !v20 )
              {
                if ( v21 )
                  __enable_irq();
              }
            }
          }
          else
          {
            return debug_printf(aErrTxlCfmNoBuf);
          }
        }
        else
        {
          return debug_printf(aErrNoMsgPkt);
        }
        break;
      case 1:
        v22 = *a2 & 0xF;
        v24 = v2 & 0x3FFFFFFF;
        v23 = v22;
        kmalloc(18, (char *)&v23, 8u, v2 & 0x3FFFFFFF);
        return alloc_tx_event("cfms: %x, sn=%d, st=%d\r\n", v4, *(uint16_t *)(v4 + 32), *a2 & 0xF);
      case 3:
        *(uint32_t *)((uint32_t *)(uintptr_t)off_117D8C)[0] = *a2 & 0xF;
        rf_cmd_wakeup();
        break;
    }
  }
  return result;
}
