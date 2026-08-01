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

extern uint32_t off_11BF90;
extern uint32_t dword_11BF94;
extern uint32_t dword_11BF98;
extern uint32_t dword_11BF9C;
extern uint32_t dword_11BFA0;
extern uint32_t dword_11BFA8;
extern uint32_t off_11BFA4;

// handle_radio_done @ 0x11bee0, size 174 bytes
// Doc: sub_121BEE0 [unknown]: Init/setup function loading globals and checking state with stack frame
// sub_121BEE0 [unknown]: Init/setup function loading globals and checking state with stack frame
int handle_radio_done()
{
  uint32_t *v0; // r4
  int v1; // r6
  int v2; // r7
  int v3; // r5
  char v4; // r8
  char *v5; // r3
  uint32_t *v6; // r2
  int result; // r0
  char v8; // r1
  int v9; // r3
  int v10; // r1
  void *v11; // r0
  uint32_t v12[28]; // [sp+0h] [bp-90h] BYREF
  char v13; // [sp+70h] [bp-20h] BYREF

  v0 = off_11BF90;
  v1 = *((uint32_t *)off_11BF90 + 1);
  if ( v1 )
  {
    v2 = *((uint32_t *)off_11BF90 + 2);
    fault_handler(off_11BF90);
    v3 = v0[4];
    if ( v3 )
      goto LABEL_3;
  }
  else
  {
    v3 = *((uint32_t *)off_11BF90 + 4);
    v2 = 0;
    if ( v3 )
    {
LABEL_3:
      memcpy(v12, dword_11BF94, 144);
      v4 = *((uint8_t *)v0 + 160);
      if ( v12[1] )
        fault_handler(dword_11BF94);
      if ( v12[8] )
        fault_handler(dword_11BF98);
      if ( v12[15] )
        fault_handler(dword_11BF9C);
      if ( v12[22] )
        fault_handler(dword_11BFA0);
      init_radio_data();
      v0[4] = v3;
      *((uint8_t *)v0 + 160) = v4;
      v0 = off_11BF90;
      v5 = (char *)v12;
      v6 = off_11BF90;
      do
      {
        result = *((uint32_t *)v5 + 5);
        v8 = v5[24];
        v6[10] = result;
        v5 += 28;
        *((uint8_t *)v6 + 44) = v8;
        v6 += 7;
      }
      while ( &v13 != v5 );
      if ( v1 )
        goto LABEL_14;
      return result;
    }
  }
  result = init_radio_data();
  v0[4] = v3;
  if ( v1 )
  {
LABEL_14:
    v9 = dword_11BFA8;
    v10 = *((uint32_t *)off_11BFA4 + 4);
    v11 = off_11BF90;
    v0[2] = v2;
    v0[1] = v9;
    return unknown_worker(v11, v10 + 5000);
  }
  return result;
}

