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

extern uint32_t off_12937C;
extern uint32_t dword_129378;
extern uint32_t off_129380;
extern uint32_t off_129394;
extern uint32_t off_129390;
extern uint32_t dword_129398;
extern uint32_t off_129384;
extern uint32_t off_12938C;
extern uint32_t off_129388;
extern uint32_t off_12939C;

// ipc_msg_receive @ 0x1291b0, size 454 bytes
unsigned int  ipc_msg_receive(unsigned int result, int a2, int a3)
{
  int v3; // r3
  uint32_t *v4; // r7
  int v6; // r2
  int v7; // r12
  unsigned int v8; // r6
  unsigned int v9; // r5
  uint8_t *v10; // r8
  unsigned int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r3
  unsigned int v14; // r1
  uint8_t *v15; // r5
  uint32_t *v16; // r3
  int v17; // r3
  int v18; // r1
  int v19; // r0
  uint8_t *v20; // r5
  uint32_t *v21; // r2
  int v22; // r1
  int v23; // r0
  int v24; // r3

  v3 = *(uint8_t *)(a3 + 116);
  v4 = off_12937C;
  v6 = *(uint32_t *)(a3 + 4);
  v7 = *(uint8_t *)off_12937C;
  v8 = *(uint16_t *)(dword_129378 + 696 * v3 + 32);
  *(uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFE;
  v9 = result;
  if ( v7 )
  {
    if ( result )
    {
      if ( *(uint8_t *)(a3 + 114) )
      {
        v10 = (uint8_t *)(result + 4);
      }
      else
      {
        v10 = (uint8_t *)(result + 4);
        if ( ((*(uint8_t *)((*(uint8_t *)(a3 + 117) >> 3) + result + 4) >> (*(uint8_t *)(a3 + 117) & 7))
            & 1) != 0 )
        {
          v16 = off_129380;
          *(uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFC | 2;
          if ( (*v16 & 0x200) != 0 )
            *v16 &= ~0x200u;
          if ( !*((uint8_t *)v4 + 29) )
          {
            v17 = *((uint32_t *)off_129394 + 4);
            v18 = *(uint16_t *)(*(uint32_t *)off_129390 + 56);
            v19 = dword_129398;
            v4[5] = a3;
            *((uint8_t *)v4 + 29) = 5;
            ke_event_lock(v19, v18 + v17);
          }
        }
        else
        {
          *(uint32_t *)(a3 + 4) = v6 & 0xFFFFFFFC;
        }
      }
      v11 = *v10 & 0xFE;
      result = v8 >> 3;
      if ( v11 <= v8 >> 3
        && result <= *(uint8_t *)(v9 + 1) - 4 + v11
        && (result += v9, (*(uint8_t *)(result - v11 + 5) & (1 << (v8 & 7))) != 0) )
      {
        if ( (*(uint32_t *)off_129380 & 0x200) != 0 )
          *(uint32_t *)off_129380 &= ~0x200u;
        if ( !*(uint8_t *)off_129384 )
        {
          mm_beacon_irq();
          if ( !*((uint8_t *)v4 + 28) || (*(uint32_t *)off_12938C & 4) != 0 )
          {
            *(uint8_t *)off_129388 = 0;
          }
          else
          {
            v20 = off_129388;
            if ( *(uint8_t *)off_129388 && (find_pending_command() != 1 || !*((uint32_t *)off_12939C + 126)) )
              ble_conn_get(*(uint8_t *)(a3 + 116), 0, 0);
            *v20 = 1;
          }
          v21 = off_129394;
          v22 = *(uint16_t *)(*(uint32_t *)off_129390 + 58);
          v23 = dword_129398;
          *(uint32_t *)(a3 + 4) |= 4u;
          v24 = v21[4];
          v4[5] = a3;
          *((uint8_t *)v4 + 29) = 6;
          return ke_event_lock(v23, v22 + v24);
        }
      }
      else
      {
        v12 = *(uint32_t *)(a3 + 4) & 0xFFFFFFFB;
        *(uint8_t *)off_129388 = 0;
        *(uint32_t *)(a3 + 4) = v12;
      }
    }
  }
  else if ( result
         && (*(uint32_t *)off_12938C & 4) == 0
         && (v13 = *(uint8_t *)(result + 4) & 0xFE, v14 = v8 >> 3, v13 <= v8 >> 3)
         && v14 <= *(uint8_t *)(result + 1) - 4 + v13
         && (*(uint8_t *)(result + v14 - v13 + 5) & (1 << (v8 & 7))) != 0 )
  {
    v15 = off_129388;
    if ( *(uint8_t *)off_129388 )
    {
      result = find_pending_command();
      if ( result != 1 || !*((uint32_t *)off_12939C + 126) )
        result = ble_conn_get(*(uint8_t *)(a3 + 116), 0, 0);
    }
    *v15 = 1;
  }
  else
  {
    *(uint8_t *)off_129388 = 0;
  }
  return result;
}

