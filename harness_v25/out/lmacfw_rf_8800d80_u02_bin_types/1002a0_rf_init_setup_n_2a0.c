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

extern uint32_t off_10038C;
extern uint32_t dword_100390;
extern uint32_t dword_100398;
extern uint32_t off_10039C;
extern uint32_t off_100394;
extern uint32_t off_1003A0;
extern uint32_t dword_1003A4;
extern uint32_t dword_1003D0;
extern uint32_t dword_1003C8;
extern uint32_t off_1003A8;
extern uint32_t dword_1003AC;
extern uint32_t off_1003B0;
extern uint32_t dword_1003B4;
extern uint32_t dword_1003B8;
extern uint32_t dword_1003CC;
extern uint32_t off_1003BC;
extern uint32_t dword_1003C0;
extern uint32_t dword_1003C4;

// rf_init_setup_n_2a0 @ 0x1002a0, size 234 bytes
// Doc: rf_init_setup_n_2a0 [rf]: Initialize RF subsystem loading config constants
// rf_init_setup_n_2a0 [rf]: Initialize RF subsystem loading config constants
int rf_init_setup_n_2a0()
{
  uint8_t **v0; // r5
  int v1; // r0
  unsigned int v2; // r7
  uint64_t v3; // kr00_8
  uint64_t v4; // kr08_8
  int v5; // r2
  uint32_t *v6; // r3
  unsigned int v7; // r4
  int16_t **v8; // r6
  int v9; // r0
  uint32_t *v10; // r2
  int v11; // r1
  int v12; // r4
  int v13; // r3
  unsigned int v14; // r4
  unsigned int v15; // r3
  unsigned int v16; // r3
  unsigned int v17; // r7
  int result; // r0
  uint8_t *v19; // r3
  int v20; // r2
  unsigned int v21; // r2

  v0 = (uint8_t **)off_10038C;
  v1 = dword_100390;
  v2 = dword_100398;
  v3 = *(uint64_t *)(*(uint32_t *)off_10038C + 36);
  v4 = *(uint64_t *)(*(uint32_t *)off_10038C + 44);
  v5 = 44 * *(uint16_t *)(*(uint32_t *)off_10038C + 8) + 44;
  v6 = off_10039C;
  *(uint32_t *)off_100394 = dword_100390;
  v7 = v5 + v1;
  v8 = (int16_t **)off_1003A0;
  v6[1] = HIDWORD(v3);
  v9 = dword_1003A4;
  *v6 = v3;
  v6[2] = v4;
  v6[3] = HIDWORD(v4);
  sub_10DA6C(v9, v2, v7);
  if ( **v8 < 0 && v7 >= v2 )
    rf_cmd_send_n264(dword_1003D0, dword_1003C8, 120);
  v10 = *(uint32_t **)off_1003A8;
  v11 = dword_1003AC;
  v12 = 76 * *((uint16_t *)*v0 + 4) + 76;
  v13 = **(uint32_t **)off_1003A8;
  *(uint32_t *)off_1003B0 = dword_1003AC;
  v14 = v12 + v11;
  if ( !v13 )
  {
    v15 = (v10[1] + 4) & 0xFFFFFFFC;
    *v10 = v14 + 4;
    v14 += v15;
  }
  if ( !v10[2] )
  {
    v16 = (v10[3] + 4) & 0xFFFFFFFC;
    v10[2] = v14 + 4;
    v14 += v16;
  }
  v17 = dword_1003B4;
  result = sub_10DA6C(dword_1003B8, dword_1003AC, dword_1003B4);
  if ( **v8 < 0 && v14 >= v17 )
    result = rf_cmd_send_n264(dword_1003CC, dword_1003C8, 156);
  v19 = *v0;
  *(uint32_t *)off_1003BC = *((uint32_t *)*v0 + 3);
  v20 = *v19;
  if ( v20 == 2 )
  {
    v21 = *((uint32_t *)v19 + 4);
  }
  else
  {
    if ( v20 != 1 )
      return result;
    v21 = *((uint32_t *)v19 + 5);
  }
  if ( v21 )
  {
    if ( dword_1003C0 > v21 )
      return sub_10DA6C(dword_1003C4, dword_1003C0, v21);
  }
  return result;
}

