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


extern uint32_t dword_101968;
extern uint32_t dword_10198C;
extern uint32_t dword_10199C;
extern uint32_t dword_1019A0;
extern uint32_t off_101954;
extern uint32_t off_101958;
extern uint32_t off_10195C;
extern uint32_t off_101960;
extern uint32_t off_101964;
extern uint32_t off_10196C;
extern uint32_t off_101970;
extern uint32_t off_101974;
extern uint32_t off_101978;
extern uint32_t off_10197C;
extern uint32_t off_101980;
extern uint32_t off_101984;
extern uint32_t off_101988;
extern uint32_t off_101990;
extern uint32_t off_101994;
extern uint32_t off_101998;
extern uint32_t off_1019A4;
extern uint32_t off_1019A8;

// tx_path_check @ 0x1017c0, size 404 bytes
int tx_path_check()
{
  uint32_t *v0; // r2
  uint32_t *v1; // r0
  uint32_t *v2; // r5
  unsigned int *v3; // r1
  unsigned int *v4; // r4
  uint32_t *v5; // r3
  uint32_t *v6; // r0
  uint32_t *v7; // r6
  int result; // r0
  uint32_t *v9; // r4
  unsigned int *v10; // r3
  unsigned int *v11; // r2
  uint8_t *v12; // r3
  int *v13; // r1
  int v14; // r2
  uint32_t *v15; // r2
  int v16; // r1

  if ( **(uint16_t **)off_101954 < 0
    && (uint8_t)BYTE2(*(uint32_t *)off_1019A8) + 10 * (HIBYTE(*(uint32_t *)off_1019A8) + 2) != 32 )
  {
    flash_ctrl_init((int)aMdmMajorVersio, (int)aMdmInit, 6119);
  }
  periph_write_read();
  v0 = off_10195C;
  v1 = off_101960;
  *(uint32_t *)off_101958 |= 0x8000000u;
  *v0 |= 8u;
  if ( ((*v1 >> 8) & 0xF) == 2 )
    *(v0 - 4897) |= 3u;
  if ( (uint8_t)*(uint32_t *)off_101960 >> 4 == 2 )
    *(uint32_t *)off_101964 = dword_101968;
  v2 = off_10196C;
  v3 = (unsigned int *)off_101970;
  v4 = (unsigned int *)off_101974;
  v5 = off_101978;
  v6 = off_10197C;
  v7 = off_101958;
  *(uint32_t *)off_10196C = *(uint32_t *)off_10196C & 0xFFFFF800 | 0x700;
  *v3 = 256;
  *v4 = *v4 & 0xFFFFE000 | 0x580;
  *v5 |= 0x10000u;
  *v5 |= 0x10000000u;
  *v5 |= 2u;
  v2 -= 236;
  *v6 |= 2u;
  result = 1;
  *v2 = 1;
  v9 = v4 + 16846;
  *v5 &= 0xFFFFFF8F;
  *v9 = 1;
  *v3 = *v3 & 0xFFFFFCFF | 0x100;
  v2 -= 10753;
  *v7 |= 0x8000000u;
  v10 = (unsigned int *)off_101980;
  *v2 &= 0xFFFFF0FF;
  *v10 |= 0x800000u;
  *v10 |= 0x400000u;
  *v10 |= 1u;
  *v10 = *v10 & 0xFFFFFF3F | 0x80;
  if ( v2[17161] > 1u )
  {
    v11 = (unsigned int *)off_101984;
    *v9 = 1;
    *v11 = *v11 & 0xFFFFFF | 0xA0000000;
    *v3 = *v3 & 0xFFFFFCFF | 0x100;
  }
  v12 = off_101990;
  *(uint32_t *)off_101988 = dword_10198C;
  v13 = off_101994;
  if ( (*v12 & 0xC0) == 0xC0 )
    v14 = dword_10199C;
  else
    v14 = dword_1019A0;
  *(uint32_t *)off_101998 = v14;
  v15 = off_1019A4;
  v16 = *((uint8_t *)v13 + 406);
  *(uint32_t *)off_1019A4 |= 0x10u;
  if ( !v16 )
    *(v15 - 10802) &= ~0x40u;
  return result;
}
