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

extern uint32_t dword_122438;
extern uint32_t off_122440;
extern uint32_t off_122444;
extern uint32_t off_12246C;
extern uint32_t off_122470;
extern uint32_t off_122448;
extern uint32_t off_12243C;
extern uint32_t dword_12244C;
extern uint32_t off_122474;
extern uint32_t off_122478;
extern uint32_t off_122454;
extern uint32_t dword_122450;
extern uint32_t off_12247C;
extern uint32_t off_122458;
extern uint32_t off_12245C;
extern uint32_t off_122460;
extern uint32_t off_122480;
extern uint32_t off_122464;
extern uint32_t dword_122468;

// rf_cmd_dispatch_n388 @ 0x1222cc, size 362 bytes
// Doc: rf_cmd_dispatch [rf]: Dispatches RF control commands to RF hardware
// rf_cmd_dispatch [rf]: Dispatches RF control commands to RF hardware
int  rf_cmd_dispatch_n388(int a1, int a2)
{
  uint8_t *v3; // r6
  unsigned int v4; // r6
  uint16_t v5; // r0
  uint8_t *v6; // r5
  uint16_t v7; // r7
  unsigned int v8; // r8
  uint32_t *v9; // r0
  uint32_t *v10; // r1
  uint32_t *v11; // r12
  uint32_t *v12; // lr
  uint32_t *v13; // r3
  uint32_t *v14; // r9
  uint32_t *v15; // lr
  uint32_t *v16; // r0
  uint32_t *v17; // r12
  unsigned int *v18; // r1
  unsigned int v19; // r3
  char *v20; // r0
  int *v21; // r12
  int v22; // lr
  int v23; // r9
  int v24; // r0
  uint8_t v26[4]; // [sp+8h] [bp-Ch] BYREF
  char v27; // [sp+Ch] [bp-8h]

  if ( sub_1288C0(*(uint32_t *)(a2 + 4)) != 12 || sub_1288C0(*(uint32_t *)(a2 + 8)) != 12 )
    return -2;
  v3 = *(uint8_t **)(a2 + 4);
  sub_1282E8(v26, v3 + 8, 4);
  v3[8] = 0;
  v27 = 0;
  v4 = parse_int(v3, 0, 0x10u);
  v5 = parse_int(v26, 0, 0x10u);
  v6 = *(uint8_t **)(a2 + 8);
  v7 = v5;
  sub_1282E8(v26, v6 + 8, 4);
  v6[8] = 0;
  v27 = 0;
  v8 = parse_int(v6, 0, 0x10u);
  LOWORD(v6) = parse_int(v26, 0, 0x10u);
  msg_parse(dword_122438);
  v9 = off_122440;
  v10 = off_122444;
  v11 = off_12246C;
  v12 = off_122470;
  v13 = off_122448;
  *(uint32_t *)off_12243C = 512;
  *v12 = 7;
  *v9 = 7;
  *v10 = 7;
  *v11 = 7;
  *v13 = 7;
  v9[4] = 7;
  v13 -= 495296;
  v10[4] = 7;
  v11[4] = 7;
  *v13 = 9816;
  *(v9 - 457703) = 50529027;
  *(v10 - 457698) = dword_12244C;
  v14 = off_122474;
  v15 = off_122478;
  v16 = off_122454;
  v13[37597] = dword_122450;
  v17 = off_12247C;
  v18 = (unsigned int *)off_122458;
  *v14 = -1;
  *v15 = -1;
  *v16 = -1;
  *v17 = -1;
  *v18 = bswap32(v4);
  v18 += 4;
  *(uint32_t *)off_12245C = __rev16(v7);
  v19 = bswap32(v8);
  *v18 = v19;
  v20 = (char *)off_122460;
  *(uint32_t *)off_122460 = __rev16((uint16_t)v6);
  *(v18 - 380) = v19;
  v21 = (int *)off_122480;
  v22 = rf_mem_write_n458;
  v23 = rf_mem_write_word_2488;
  *(uint32_t *)off_122464 = __rev16((uint16_t)v6);
  *(uint32_t *)&v20[-148] = 7;
  *(uint32_t *)&v20[-148] = v23;
  v24 = dword_122468;
  *v21 = v22;
  msg_parse(v24, v4, v7, v8, (uint16_t)v6);
  return 0;
}

