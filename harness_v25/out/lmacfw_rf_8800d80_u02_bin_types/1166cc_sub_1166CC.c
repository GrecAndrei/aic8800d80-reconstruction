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

extern uint32_t dword_116830;
extern uint32_t dword_116834;
extern uint32_t off_116820;
extern uint32_t dword_11682C;
extern uint32_t dword_116828;
extern uint32_t off_116824;

// sub_1166CC @ 0x1166cc, size 340 bytes
int  sub_1166CC(int a1, int a2, int a3)
{
  int v3; // r10
  int v4; // r11
  int v6; // r5
  int v8; // r3
  int v10; // r0
  int v11; // r4
  int v12; // r5
  int v13; // r3
  int v14; // r2
  int16_t v15; // r1
  int v16; // r0
  int16_t v17; // r5
  int v18; // r0
  int16_t v19; // r5
  char v20; // r2
  int v22; // r1
  int v23; // r0
  int16_t v24; // r2
  int v25; // r0

  v3 = dword_116830;
  v4 = dword_116834;
  v6 = *(uint8_t *)(dword_116830 + 152 * a1 + 32);
  v8 = *(uint32_t *)(dword_116834 + 224 * v6 + 72);
  if ( !v8 )
  {
    if ( **(int16_t **)off_116820 >= 0 )
    {
LABEL_9:
      v11 = rf_alloc_or_init(1, 24);
      if ( !v11 )
        return 1;
      goto LABEL_4;
    }
LABEL_8:
    rf_cmd_send_n264(dword_11682C, dword_116828, 520);
    goto LABEL_9;
  }
  v10 = *(uint8_t *)(v8 + 4);
  if ( **(int16_t **)off_116820 < 0 && v10 == 2 )
    goto LABEL_8;
  v11 = rf_alloc_or_init(v10 != 0, 24);
  if ( !v11 )
    return 1;
LABEL_4:
  v12 = v4 + 224 * v6;
  sub_11DA78(v12, v11);
  v13 = *(uint32_t *)(v11 + 28);
  if ( *(uint8_t *)(v12 + 94) == 2 )
  {
    v22 = v3 + 152 * a1;
    *(uint32_t *)(v13 + 108) = *(uint32_t *)(v22 + 36);
    LOWORD(v22) = *(uint16_t *)(v22 + 40);
    v23 = *(uint32_t *)(v12 + 88);
    *(uint8_t *)(v13 + 105) = 2;
    *(uint32_t *)(v13 + 114) = v23;
    v24 = *(uint16_t *)(v12 + 92);
    v25 = *(uint32_t *)(v12 + 88);
    *(uint16_t *)(v13 + 112) = v22;
    *(uint16_t *)(v13 + 118) = *(uint16_t *)(v12 + 92);
    *(uint8_t *)(v13 + 106) = 0;
    *(uint8_t *)(v13 + 107) = 0;
    *(uint8_t *)(v13 + 104) = 72;
    *(uint32_t *)(v13 + 120) = v25;
    *(uint16_t *)(v13 + 124) = v24;
  }
  else
  {
    v14 = v3 + 152 * a1;
    v15 = *(uint16_t *)(v12 + 92);
    *(uint32_t *)(v13 + 108) = *(uint32_t *)(v14 + 36);
    v16 = *(uint32_t *)(v12 + 88);
    v17 = *(uint16_t *)(v14 + 40);
    *(uint32_t *)(v13 + 114) = v16;
    v18 = *(uint32_t *)(v14 + 36);
    *(uint16_t *)(v13 + 112) = v17;
    *(uint16_t *)(v13 + 118) = v15;
    *(uint32_t *)(v13 + 120) = v18;
    *(uint16_t *)(v13 + 124) = v17;
    *(uint8_t *)(v13 + 106) = 0;
    *(uint8_t *)(v13 + 107) = 0;
    *(uint8_t *)(v13 + 104) = 72;
    *(uint8_t *)(v13 + 105) = 1;
  }
  v19 = *((uint16_t *)off_116824 + 70) + 1;
  *((uint16_t *)off_116824 + 70) = v19;
  v20 = *(uint8_t *)(v3 + 152 * a1 + 32);
  *(uint16_t *)(v13 + 126) = 16 * v19;
  *(uint32_t *)(v11 + 44) = a2;
  *(uint32_t *)(v11 + 48) = a3;
  *(uint8_t *)(v11 + 15) = v20;
  *(uint8_t *)(v11 + 16) = a1;
  sub_1165B0(v11, 5);
  return 0;
}

