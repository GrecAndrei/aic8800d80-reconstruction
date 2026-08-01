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

extern uint32_t off_114D28;
extern uint32_t off_114D2C;

// ke_task_handler @ 0x114c30, size 248 bytes
// Doc: patch_apply_4ca0 [patch]: Apply a 4-byte firmware/code patch to target
// patch_apply_4ca0 [patch]: Apply a 4-byte firmware/code patch to target
int  ke_task_handler(int a1, int a2, unsigned int a3)
{
  int v6; // r4
  unsigned int v7; // r5
  uint32_t v9[4]; // [sp+0h] [bp-4Ch] BYREF
  uint8_t v10[4]; // [sp+10h] [bp-3Ch] BYREF
  uint8_t v11[12]; // [sp+14h] [bp-38h] BYREF
  uint8_t v12[20]; // [sp+20h] [bp-2Ch] BYREF
  uint8_t v13[8]; // [sp+34h] [bp-18h] BYREF
  uint8_t v14[4]; // [sp+3Ch] [bp-10h] BYREF
  uint8_t v15[4]; // [sp+40h] [bp-Ch] BYREF
  uint8_t v16[8]; // [sp+44h] [bp-8h] BYREF

  if ( !*(uint32_t *)off_114D28 )
    get_ke_env();
  MEMORY[0x1D8](*(uint32_t *)off_114D2C + 0x2000, 72, v9);
  if ( v9[0] != patch_apply_17c )
    return -1;
  v6 = a1 & v9[1];
  if ( !v6 )
    return 1;
  v7 = v6 & 1;
  if ( (v6 & 1) != 0 )
  {
    memcpy(a2, v10, 4);
    v7 = 4;
    if ( (v6 & 2) == 0 )
    {
LABEL_7:
      if ( (v6 & 4) == 0 )
        goto patch_apply_n_23a;
      goto LABEL_22;
    }
  }
  else if ( (v6 & 2) == 0 )
  {
    goto LABEL_7;
  }
  memcpy(a2 + v7, v11, 12);
  v7 += 12;
  if ( (v6 & 4) == 0 )
  {
patch_apply_n_23a:
    if ( (v6 & 8) == 0 )
      goto rf_state_check_n_3a6;
    goto LABEL_20;
  }
LABEL_22:
  memcpy(a2 + v7, v12, 20);
  v7 += 20;
  if ( (v6 & 8) == 0 )
  {
rf_state_check_n_3a6:
    if ( (v6 & 0x20) == 0 )
      goto patch_apply_n_232;
    goto LABEL_18;
  }
LABEL_20:
  memcpy(a2 + v7, v13, 4);
  v7 += 4;
  if ( (v6 & 0x20) == 0 )
  {
patch_apply_n_232:
    if ( (v6 & 0x40) == 0 )
      goto patch_apply_n_22e;
    goto LABEL_16;
  }
LABEL_18:
  memcpy(a2 + v7, v14, 4);
  v7 += 4;
  if ( (v6 & 0x40) == 0 )
  {
patch_apply_n_22e:
    if ( (v6 & 0x80) == 0 )
      goto patch_apply_n_22a;
    goto patch_apply_c90;
  }
LABEL_16:
  memcpy(a2 + v7, v15, 4);
  v7 += 4;
  if ( (v6 & 0x80) != 0 )
  {
patch_apply_c90:
    memcpy(a2 + v7, v16, 4);
    v7 += 4;
  }
patch_apply_n_22a:
  if ( a3 < v7 )
    return -2;
  else
    return 0;
}

