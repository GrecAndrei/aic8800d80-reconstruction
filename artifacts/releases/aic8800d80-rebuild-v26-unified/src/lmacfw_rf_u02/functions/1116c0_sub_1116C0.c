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

extern uint32_t dword_1117C8;
extern uint32_t off_1117CC;
extern uint32_t off_1117D0;
extern uint32_t off_1117D4;
extern uint32_t dword_111800;
extern uint32_t off_1117D8;
extern uint32_t off_1117F0;
extern uint32_t off_1117F4;
extern uint32_t off_1117F8;
extern uint32_t dword_1117FC;
extern uint32_t dword_1117DC;
extern uint32_t dword_1117E4;
extern uint32_t off_1117E8;
extern uint32_t off_1117E0;
extern uint32_t dword_1117EC;

// sub_1116C0 @ 0x1116c0, size 262 bytes
int  sub_1116C0(uint32_t *a1, int a2)
{
  uint8_t *v4; // r6
  uint32_t *v5; // r7
  void *v6; // r0
  int v7; // r1
  uint32_t *v8; // r4
  int v9; // r1
  int v10; // r1
  uint32_t *v11; // r3
  uint8_t *v13; // r7
  int v14; // r0
  int v15; // r1
  uint32_t *v16; // r3
  void ( *v17)(int); // r2

  sub_11F504(dword_1117C8, 0);
  if ( !a1 )
    return 1;
  if ( !*a1 || !a1[1] || !a1[2] || !a1[5] )
    return 2;
  v4 = off_1117CC;
  if ( *(uint8_t *)off_1117CC )
    return 3;
  v5 = off_1117D0;
  v6 = off_1117D4;
  *(uint8_t *)off_1117CC = 1;
  sub_1282E8(v6, a1, 80);
  v7 = v5[97];
  if ( v7 )
  {
    sub_11F504(dword_111800, v7);
    sub_100560(v5[97]);
  }
  v8 = off_1117D8;
  if ( (*((uint32_t *)off_1117D8 + 512) & 0x7F0) != 0 )
  {
    v13 = off_1117F0;
    *((uint32_t *)off_1117F0 + 1) = 0;
    *((uint32_t *)v13 + 2) = 0;
    *v13 = 0;
    *v4 = 4;
    v14 = sub_11118C();
    v15 = *(uint32_t *)off_1117F4;
    v16 = *(uint32_t **)off_1117F8;
    *v16 = dword_1117FC;
    v16[1] = v15;
    v8[709] = v16;
    v8[706] = v8[706];
    v17 = *((void ( **)(int))off_1117D4 + 19);
    v9 = 1;
    v8[704] |= 0x84000000;
    *v13 = 1;
    if ( v17 )
      v17(v14);
  }
  else
  {
    if ( (*((uint32_t *)off_1117D8 + 2) & 1) != 0 )
    {
      *((uint32_t *)off_1117D8 + 2) &= ~1u;
      v8[513] |= 2u;
    }
    sub_111304();
  }
  sub_11F504(dword_1117DC, v9);
  v10 = dword_1117E4;
  v11 = off_1117E8;
  *(uint32_t *)(*((uint32_t *)off_1117E0 + 2) + 320) = dword_1117E4;
  v11[2] = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  sub_11F504(dword_1117EC, v10);
  return 0;
}

