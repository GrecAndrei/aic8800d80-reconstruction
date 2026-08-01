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

extern uint32_t off_115368;
extern uint32_t dword_11536C;

// ioctl_dispatch @ 0x11526c, size 248 bytes
// Doc: patch_apply_lsl_r4_24 [patch]: Computes shifted patch value (r4<<24) during firmware patch application
// patch_apply_lsl_r4_24 [patch]: Computes shifted patch value (r4<<24) during firmware patch application
int  ioctl_dispatch(int a1, int a2, unsigned int a3)
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

  if ( !*(uint32_t *)patch_apply_n_184 )
    check_status_flags();
  MEMORY[0x1D8](*(uint32_t *)off_115368 + 0x2000, 72, v9);
  if ( v9[0] != dword_11536C )
    return -1;
  v6 = a1 & v9[1];
  if ( !v6 )
    return 1;
  v7 = v6 & 1;
  if ( (v6 & 1) != 0 )
  {
    memcpy_aligned(a2, v10, 4);
    v7 = 4;
    if ( (v6 & 2) == 0 )
    {
patch_apply_n_23e:
      if ( (v6 & 4) == 0 )
        goto patch_apply_n_23a_52ae;
      goto LABEL_22;
    }
  }
  else if ( (v6 & 2) == 0 )
  {
    goto patch_apply_n_23e;
  }
  memcpy_aligned(a2 + v7, v11, 12);
  v7 += 12;
  if ( (v6 & 4) == 0 )
  {
patch_apply_n_23a_52ae:
    if ( (v6 & 8) == 0 )
      goto LABEL_9;
    goto LABEL_20;
  }
LABEL_22:
  memcpy_aligned(a2 + v7, v12, 20);
  v7 += 20;
  if ( (v6 & 8) == 0 )
  {
LABEL_9:
    if ( (v6 & 0x20) == 0 )
      goto patch_apply_n_232_52b6;
    goto LABEL_18;
  }
LABEL_20:
  memcpy_aligned(a2 + v7, v13, 4);
  v7 += 4;
  if ( (v6 & 0x20) == 0 )
  {
patch_apply_n_232_52b6:
    if ( (v6 & 0x40) == 0 )
      goto patch_apply_lsl_r4_24;
    goto LABEL_16;
  }
LABEL_18:
  memcpy_aligned(a2 + v7, v14, 4);
  v7 += 4;
  if ( (v6 & 0x40) == 0 )
  {
patch_apply_lsl_r4_24:
    if ( (v6 & 0x80) == 0 )
      goto patch_apply_n_22a;
    goto patch_apply_n_21c;
  }
LABEL_16:
  memcpy_aligned(a2 + v7, v15, 4);
  v7 += 4;
  if ( (v6 & 0x80) != 0 )
  {
patch_apply_n_21c:
    memcpy_aligned(a2 + v7, v16, 4);
    v7 += 4;
  }
patch_apply_n_22a:
  if ( a3 < v7 )
    return -2;
  else
    return 0;
}

