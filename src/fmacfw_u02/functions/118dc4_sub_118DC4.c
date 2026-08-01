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

extern uint32_t dword_118F44;
extern uint32_t dword_118F30;
extern uint32_t off_118F34;
extern uint32_t dword_118F40;
extern uint32_t dword_118F3C;
extern uint32_t off_118F38;

// rf_channel_get @ 0x118dc4, size 362 bytes
int  rf_channel_get(int a1, int a2, int a3)
{
  int v3; // r9
  int v4; // r5
  int v6; // r10
  int v8; // r3
  int v10; // r2
  int v11; // r4
  int v12; // r5
  int v13; // r3
  int v14; // r2
  int v15; // r0
  int v16; // t1
  int16_t v17; // r12
  int16_t v18; // lr
  int v19; // r5
  int16_t v20; // r5
  char v21; // r2
  int v23; // r1
  int v24; // r0
  int v25; // lr
  int v26; // r0
  int16_t v27; // r2

  v3 = dword_118F44;
  v4 = dword_118F30;
  v6 = *(uint8_t *)(dword_118F44 + 696 * a1 + 34);
  v8 = *(uint32_t *)(dword_118F30 + 1320 * v6 + 72);
  if ( !v8 )
  {
    if ( **(int16_t **)off_118F34 >= 0 )
    {
LABEL_9:
      v11 = ke_mutex_guard(1, 24);
      if ( !v11 )
        return 1;
      goto LABEL_4;
    }
LABEL_8:
    mmio_clear_register(dword_118F40, dword_118F3C, 520);
    goto LABEL_9;
  }
  v10 = *(uint8_t *)(v8 + 4);
  if ( **(int16_t **)off_118F34 < 0 && v10 == 2 )
    goto LABEL_8;
  v11 = ke_mutex_guard((*(uint8_t *)(dword_118F30 + 1320 * v6 + 1224) | v10) != 0, 24);
  if ( !v11 )
    return 1;
LABEL_4:
  v12 = v4 + 1320 * v6;
  rf_check_temperature(v12, v11);
  v13 = *(uint32_t *)(v11 + 72);
  if ( *(uint8_t *)(v12 + 106) == 2 )
  {
    v23 = v3 + 696 * a1;
    v24 = *(uint32_t *)(v12 + 100);
    v25 = *(uint32_t *)(v23 + 38);
    *(uint8_t *)(v13 + 109) = 2;
    *(uint16_t *)(v13 + 116) = *(uint16_t *)(v23 + 42);
    LOWORD(v23) = *(uint16_t *)(v12 + 104);
    *(uint32_t *)(v13 + 118) = v24;
    v26 = *(uint32_t *)(v12 + 100);
    *(uint8_t *)(v13 + 110) = 0;
    *(uint8_t *)(v13 + 111) = 0;
    v27 = *(uint16_t *)(v12 + 104);
    *(uint32_t *)(v13 + 112) = v25;
    *(uint8_t *)(v13 + 108) = 72;
    *(uint16_t *)(v13 + 122) = v23;
    *(uint32_t *)(v13 + 124) = v26;
    *(uint16_t *)(v13 + 128) = v27;
  }
  else
  {
    v14 = v3 + 696 * a1;
    v15 = *(uint32_t *)(v12 + 100);
    v16 = *(uint32_t *)(v14 + 38);
    v14 += 38;
    v17 = *(uint16_t *)(v12 + 104);
    v18 = *(uint16_t *)(v14 + 4);
    v19 = *(uint32_t *)v14;
    *(uint32_t *)(v13 + 112) = v16;
    *(uint16_t *)(v13 + 128) = *(uint16_t *)(v14 + 4);
    *(uint32_t *)(v13 + 124) = v19;
    *(uint16_t *)(v13 + 116) = v18;
    *(uint32_t *)(v13 + 118) = v15;
    *(uint16_t *)(v13 + 122) = v17;
    *(uint8_t *)(v13 + 110) = 0;
    *(uint8_t *)(v13 + 111) = 0;
    *(uint8_t *)(v13 + 108) = 72;
    *(uint8_t *)(v13 + 109) = 1;
  }
  v20 = *((uint16_t *)off_118F38 + 254) + 1;
  *((uint16_t *)off_118F38 + 254) = v20;
  v21 = *(uint8_t *)(v3 + 696 * a1 + 34);
  *(uint16_t *)(v13 + 130) = 16 * v20;
  *(uint32_t *)(v11 + 88) = a2;
  *(uint32_t *)(v11 + 92) = a3;
  *(uint8_t *)(v11 + 28) = v21;
  *(uint8_t *)(v11 + 29) = a1;
  tx_path_status(v11, 5);
  return 0;
}

