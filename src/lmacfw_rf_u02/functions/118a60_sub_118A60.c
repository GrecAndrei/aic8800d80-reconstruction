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


extern uint32_t off_118C50;
extern uint32_t off_118C58;
extern uint32_t off_118C5C;
extern uint32_t off_118C60;
extern uint32_t off_118C6C;
extern uint32_t off_118C70;
extern uint32_t off_118C74;
extern uint32_t off_118C78;
extern uint32_t off_118C7C;
extern uint32_t off_118C84;
extern uint32_t off_118C8C;

// handle_hci_event @ 0x118a60, size 496 bytes
int  handle_hci_event(char *a1)
{
  unsigned int v1; // r7
  int v2; // r5
  int v4; // r1
  uint32_t *v5; // r3
  int v6; // r2
  int v7; // r6
  uint32_t *v8; // r3
  uint8_t *v9; // r3
  uint32_t *v10; // r3
  int v11; // r0
  int v12; // r1
  uint32_t *v13; // r3
  uint32_t *v14; // r2
  uint32_t *v16; // r2
  char v17; // r6
  uint32_t *v18; // r3
  uint32_t *v19; // r3
  uint32_t *v20; // r3
  uint32_t *v21; // r3
  uint32_t *v22; // r3
  int v23; // [sp+0h] [bp-14h] BYREF
  uint16_t v24; // [sp+4h] [bp-10h]
  char a1a[4]; // [sp+8h] [bp-Ch] BYREF
  uint16_t v26; // [sp+Ch] [bp-8h]

  v1 = (uint8_t)a1[1];
  v2 = (uint8_t)a1[41];
  if ( v1 == 255 )
  {
    v16 = off_118C60;
    v17 = *a1;
    *(uint32_t *)off_118C5C = -1;
    *v16 = -1;
    v7 = (uint8_t)(v17 + 4 * v2);
    check_interrupt_flag(256, "add gtk:%d,%d\r\n", (uint8_t)a1[41], (uint8_t)a1[40]);
  }
  else
  {
    if ( **(uint16_t **)off_118C50 < 0 && v1 > 3 )
      flash_ctrl_init((int)aStaIdxStaMax, (int)aMmSecMachwkeyW, 1424);
    check_interrupt_flag(256, "add ptk:%d,%d\r\n", v1, (uint8_t)a1[40]);
    v4 = ((uint32_t *)(uintptr_t)off_118C58)[1];
    v23 = ((uint32_t *)(uintptr_t)off_118C58)[0];
    v24 = v4;
    memcpy_large(a1a, (char *)&v23, 6u);
    v5 = off_118C60;
    v6 = v26;
    *(uint32_t *)off_118C5C = *(uint32_t *)a1a;
    v7 = (uint8_t)(v1 + 16);
    *v5 = v6;
  }
  switch ( a1[40] )
  {
    case 0:
      v18 = off_118C6C;
      *(uint32_t *)off_118C6C = *((uint32_t *)a1 + 2);
      v18[1] = *((uint32_t *)a1 + 3);
      v18[2] = *((uint32_t *)a1 + 4);
      v18[3] = *((uint32_t *)a1 + 5);
      v11 = 256;
      v12 = 0;
      break;
    case 1:
      v8 = off_118C6C;
      *(uint32_t *)off_118C6C = *((uint32_t *)a1 + 2);
      v8[1] = *((uint32_t *)a1 + 3);
      v8[2] = *((uint32_t *)a1 + 4);
      v9 = *(uint8_t **)off_118C70;
      *(uint32_t *)off_118C74 = *((uint32_t *)a1 + 5);
      if ( (*v9 & 1) != 0 )
      {
        v10 = off_118C78;
        *(uint32_t *)off_118C78 = *((uint32_t *)a1 + 6);
        v10[1] = *((uint32_t *)a1 + 7);
        v10[2] = *((uint32_t *)a1 + 8);
        v10[3] = *((uint32_t *)a1 + 9);
      }
      else
      {
        *(uint32_t *)off_118C84 &= ~1u;
      }
      v11 = 512;
      v12 = 4096;
      break;
    case 2:
      v13 = off_118C6C;
      *(uint32_t *)off_118C6C = *((uint32_t *)a1 + 2);
      v13[1] = *((uint32_t *)a1 + 3);
      v13[2] = *((uint32_t *)a1 + 4);
      v13[3] = *((uint32_t *)a1 + 5);
      v11 = 768;
      v12 = 0;
      break;
    case 3:
      v11 = 256;
      v12 = 4096;
      goto LABEL_21;
    case 4:
      v22 = off_118C6C;
      *(uint32_t *)off_118C6C = *((uint32_t *)a1 + 2);
      v22[1] = *((uint32_t *)a1 + 3);
      v22[2] = *((uint32_t *)a1 + 4);
      v22[3] = *((uint32_t *)a1 + 5);
      v11 = 1024;
      v12 = 4096;
      goto LABEL_19;
    case 6:
      v11 = 1280;
      v12 = 0;
      goto LABEL_21;
    case 7:
      v11 = 1280;
      goto LABEL_18;
    case 8:
      v11 = 768;
LABEL_18:
      v19 = off_118C6C;
      *(uint32_t *)off_118C6C = *((uint32_t *)a1 + 2);
      v19[1] = *((uint32_t *)a1 + 3);
      v19[2] = *((uint32_t *)a1 + 4);
      v19[3] = *((uint32_t *)a1 + 5);
      v12 = 0x2000;
LABEL_19:
      v20 = off_118C78;
      *(uint32_t *)off_118C78 = *((uint32_t *)a1 + 6);
      v20[1] = *((uint32_t *)a1 + 7);
      v20[2] = *((uint32_t *)a1 + 8);
      v20[3] = *((uint32_t *)a1 + 9);
      break;
    default:
      if ( **(uint16_t **)off_118C50 < 0 )
        flash_ctrl_init(off_118C8C, (int)aMmKeyRamParamG, 159);
      v11 = 0;
      v12 = 4096;
LABEL_21:
      v21 = off_118C6C;
      *(uint32_t *)off_118C6C = *((uint32_t *)a1 + 2);
      v21[1] = *((uint32_t *)a1 + 3);
      v21[2] = *((uint32_t *)a1 + 4);
      v21[3] = *((uint32_t *)a1 + 5);
      break;
  }
  v14 = off_118C7C;
  *(uint32_t *)off_118C7C = (16 * v2) | (4 * (uint8_t)a1[42]) | v11 | (v7 << 16) | v12 | 0x40000000;
  while ( (*v14 & 0x40000000) != 0 )
    ;
  return v7;
}
