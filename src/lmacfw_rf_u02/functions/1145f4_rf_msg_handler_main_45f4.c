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

extern uint32_t off_1146D8;
extern uint32_t off_1146DC;
extern uint32_t dword_1146E0;

// rf_msg_handler_main_45f4 @ 0x1145f4, size 228 bytes
// Doc: rf_msg_handler_main_45f4 [rf]: Top-level RF message handler dispatching on message id with stack-local context
// rf_msg_handler_main_45f4 [rf]: Top-level RF message handler dispatching on message id with stack-local context
int  rf_msg_handler_main_45f4(int a1, int a2, unsigned int a3)
{
  unsigned int v6; // r4
  int v8; // [sp+0h] [bp-144h] BYREF
  int v9; // [sp+4h] [bp-140h]
  uint8_t v10[272]; // [sp+14h] [bp-130h] BYREF
  uint8_t v11[4]; // [sp+124h] [bp-20h] BYREF
  uint8_t v12[8]; // [sp+128h] [bp-1Ch] BYREF
  uint8_t v13[4]; // [sp+130h] [bp-14h] BYREF
  uint8_t v14[2]; // [sp+134h] [bp-10h] BYREF
  uint8_t v15[14]; // [sp+136h] [bp-Eh] BYREF

  if ( !*(uint32_t *)off_1146D8 )
    lmac_state_get_n_e0();
  MEMORY[0x1D8](*(uint32_t *)off_1146DC + 4096, 320, &v8);
  if ( v8 != dword_1146E0 )
    return -1;
  if ( (v9 & a1) == 0 )
    return 1;
  v6 = (uint8_t)v9 & (uint8_t)a1 & 2;
  if ( ((uint8_t)v9 & (uint8_t)a1 & 2) != 0 )
  {
    sub_1282E8(a2, v10, 6);
    v6 = 6;
    if ( (a1 & 0x100000) == 0 )
    {
LABEL_7:
      if ( (a1 & 0x200000) == 0 )
        goto LABEL_8;
      goto LABEL_19;
    }
  }
  else if ( (a1 & 0x100000) == 0 )
  {
    goto LABEL_7;
  }
  sub_1282E8(a2 + v6, v11, 2);
  v6 += 2;
  if ( (a1 & 0x200000) == 0 )
  {
LABEL_8:
    if ( (a1 & 0x400000) == 0 )
      goto LABEL_9;
    goto LABEL_17;
  }
LABEL_19:
  sub_1282E8(a2 + v6, v12, 8);
  v6 += 8;
  if ( (a1 & 0x400000) == 0 )
  {
LABEL_9:
    if ( (a1 & 0x800000) == 0 )
      goto LABEL_10;
    goto LABEL_15;
  }
LABEL_17:
  sub_1282E8(a2 + v6, v13, 4);
  v6 += 4;
  if ( (a1 & 0x800000) == 0 )
  {
LABEL_10:
    if ( (a1 & 0x1000000) == 0 )
      goto LABEL_11;
    goto LABEL_14;
  }
LABEL_15:
  sub_1282E8(a2 + v6, v14, 2);
  v6 += 2;
  if ( (a1 & 0x1000000) != 0 )
  {
LABEL_14:
    sub_1282E8(a2 + v6, v15, 10);
    v6 += 10;
  }
LABEL_11:
  if ( a3 < v6 )
    return -2;
  else
    return 0;
}

