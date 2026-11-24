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


extern uint32_t dword_117EB0;
extern uint32_t dword_117EB8;
extern uint32_t dword_117EC8;
extern uint32_t off_117EAC;
extern uint32_t off_117EB4;
extern uint32_t off_117EBC;
extern uint32_t off_117EC0;
extern uint32_t off_117ECC;
extern uint32_t off_117ED8;

// ll_state_check @ 0x117d30, size 380 bytes
int  ll_state_check(int result, uint32_t *a2)
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
    v3 = **(uint8_t **)off_117EAC;
    v4 = result;
    switch ( v3 )
    {
      case 2:
        v6 = error_trap();
        if ( v6 )
        {
          v7 = off_117ED8;
          if ( *((uint32_t *)off_117ED8 + 2057) )
          {
            v8 = mem_word_load(dword_117EB0);
            *v6 = 8;
            v6[1] = 0;
            v6[3] = 0;
            v6[2] = 18;
            v9 = *a2 & 0xF;
            v10 = v8;
            v24 = *(uint32_t *)(v4 + 84) & 0x3FFFFFFF;
            v23 = v9;
            memcpy(v6 + 4, (char *)&v23, 8u);
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
            v14 = off_117EB4;
            *((uint16_t *)v10 + 6) = v11;
            v15 = dword_117EB8;
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
              *(uint32_t *)off_117EBC = 1;
            }
            v17 = (int *)off_117EC0;
            v18 = *(uint16_t *)(v4 + 32);
            v19 = *a2 & 0xF;
            ++*(uint32_t *)off_117EC0;
            event_dispatch("cfms: %x, sn=%d, st=%d\r\n", v4, v18, v19);
            cmd_handler_a(dword_117EC8, v10);
            result = check_init_flag();
            if ( *v17 )
            {
              v20 = *v17 - 1;
              v21 = *(uint32_t *)off_117EBC;
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
            return log_printf(aErrTxlCfmNoBuf);
          }
        }
        else
        {
          return log_printf(aErrNoMsgPkt);
        }
        break;
      case 1:
        v22 = *a2 & 0xF;
        v24 = v2 & 0x3FFFFFFF;
        v23 = v22;
        mutex_lock(18, (char *)&v23, 8u, v2 & 0x3FFFFFFF);
        return event_dispatch("cfms: %x, sn=%d, st=%d\r\n", v4, *(uint16_t *)(v4 + 32), *a2 & 0xF);
      case 3:
        *(uint32_t *)((uint32_t *)(uintptr_t)off_117ECC)[0] = *a2 & 0xF;
        gpio_set_pin8();
        break;
    }
  }
  return result;
}
