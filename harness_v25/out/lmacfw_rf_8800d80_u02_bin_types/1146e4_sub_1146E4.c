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

extern uint32_t off_114810;
extern uint32_t off_114814;
extern uint32_t dword_114818;
extern uint32_t dword_11481C;

// sub_1146E4 @ 0x1146e4, size 298 bytes
// Doc: sub_12146E4 [util]: LMAC helper with large stack frame and pointer dereference
// sub_12146E4 [util]: LMAC helper with large stack frame and pointer dereference
int  sub_1146E4(int a1, int a2, unsigned int a3)
{
  uint32_t *v6; // r6
  int v7; // r5
  unsigned int v8; // r5
  int v9; // r1
  int v11; // [sp+0h] [bp-140h] BYREF
  int v12; // [sp+4h] [bp-13Ch]
  int v13; // [sp+10h] [bp-130h]
  uint8_t v14[120]; // [sp+14h] [bp-12Ch] BYREF
  int v15; // [sp+8Ch] [bp-B4h]
  int v16; // [sp+10Ch] [bp-34h]
  uint8_t v17[4]; // [sp+124h] [bp-1Ch] BYREF
  uint8_t v18[8]; // [sp+128h] [bp-18h] BYREF
  uint8_t v19[4]; // [sp+130h] [bp-10h] BYREF
  uint8_t v20[2]; // [sp+134h] [bp-Ch] BYREF
  uint8_t v21[10]; // [sp+136h] [bp-Ah] BYREF

  if ( !*(uint32_t *)off_114810 )
    lmac_state_get_n_e0();
  v6 = off_114814;
  v7 = dword_114818;
  MEMORY[0x1D8](*(uint32_t *)off_114814 + 4096, 320, &v11);
  if ( v11 == v7 )
  {
    v8 = a1 & 2;
    v12 |= a1;
    if ( (a1 & 2) == 0 )
      goto LABEL_5;
  }
  else
  {
    sub_100200(&v11, 0xFFu, 0x140u);
    v11 = v7;
    v13 = 0;
    v15 = 0;
    v16 = 0;
    v8 = a1 & 2;
    v12 = a1;
    if ( (a1 & 2) == 0 )
    {
LABEL_5:
      if ( (a1 & 0x100000) == 0 )
        goto LABEL_6;
      goto LABEL_14;
    }
  }
  sub_1282E8(v14, a2, 6);
  v8 = 6;
  if ( (a1 & 0x100000) == 0 )
  {
LABEL_6:
    if ( (a1 & 0x200000) == 0 )
      goto LABEL_7;
    goto LABEL_15;
  }
LABEL_14:
  sub_1282E8(v17, a2 + v8, 2);
  v8 += 2;
  if ( (a1 & 0x200000) == 0 )
  {
LABEL_7:
    v9 = a1 << 9;
    if ( (a1 & 0x400000) == 0 )
      goto LABEL_8;
    goto LABEL_16;
  }
LABEL_15:
  sub_1282E8(v18, a2 + v8, 8);
  v9 = a1 << 9;
  v8 += 8;
  if ( (a1 & 0x400000) == 0 )
  {
LABEL_8:
    if ( (a1 & 0x800000) == 0 )
      goto LABEL_9;
    goto LABEL_17;
  }
LABEL_16:
  sub_1282E8(v19, a2 + v8, 4);
  v8 += 4;
  if ( (a1 & 0x800000) == 0 )
  {
LABEL_9:
    if ( (a1 & 0x1000000) == 0 )
      goto LABEL_10;
LABEL_18:
    sub_1282E8(v21, a2 + v8, 10);
    if ( a3 >= v8 + 10 )
      goto LABEL_11;
LABEL_19:
    msg_parse(dword_11481C, v9);
    goto LABEL_11;
  }
LABEL_17:
  sub_1282E8(v20, a2 + v8, 2);
  v8 += 2;
  if ( (a1 & 0x1000000) != 0 )
    goto LABEL_18;
LABEL_10:
  if ( a3 < v8 )
    goto LABEL_19;
LABEL_11:
  rf_event_handler_n258();
  sub_114298();
  return MEMORY[0x1E0](*v6 + 4096, 320);
}

