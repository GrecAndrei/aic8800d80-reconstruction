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


extern uint32_t dword_101844;
extern uint32_t dword_101870;
extern uint32_t dword_101874;
extern uint32_t off_101830;
extern uint32_t off_101834;
extern uint32_t off_101838;
extern uint32_t off_10183C;
extern uint32_t off_101840;
extern uint32_t off_101848;
extern uint32_t off_10184C;
extern uint32_t off_101850;
extern uint32_t off_101854;
extern uint32_t off_101858;
extern uint32_t off_10185C;
extern uint32_t off_101860;
extern uint32_t off_101864;
extern uint32_t off_101868;
extern uint32_t off_10186C;
extern uint32_t off_101878;
extern uint32_t off_10187C;

// is_scan_active @ 0x1016a8, size 390 bytes
int is_scan_active()
{
  uint32_t *v0; // r2
  uint32_t *v1; // r0
  uint32_t *v2; // r5
  unsigned int *v3; // r1
  unsigned int *v4; // r4
  uint32_t *v5; // r3
  uint32_t *v6; // r0
  uint32_t *v7; // r6
  uint32_t *v8; // r4
  unsigned int *v9; // r3
  unsigned int *v10; // r2
  uint32_t *v11; // r3
  uint32_t *v12; // r2
  int result; // r0
  int v14; // r1

  if ( **(uint16_t **)off_101830 < 0
    && (uint8_t)BYTE2(*(uint32_t *)off_10187C) + 10 * (HIBYTE(*(uint32_t *)off_10187C) + 2) != 32 )
  {
    irq_disable_mmio_write((int)aMdmMajorVersio, (int)aMdmInit, 6119);
  }
  mmio_write_cmd();
  v0 = off_101838;
  v1 = off_10183C;
  *(uint32_t *)off_101834 |= 0x8000000u;
  *v0 |= 8u;
  if ( ((*v1 >> 8) & 0xF) == 2 )
    *(v0 - 4897) |= 3u;
  if ( (uint8_t)*(uint32_t *)off_10183C >> 4 == 2 )
    *(uint32_t *)off_101840 = dword_101844;
  v2 = off_101848;
  v3 = (unsigned int *)off_10184C;
  v4 = (unsigned int *)off_101850;
  v5 = off_101854;
  v6 = off_101858;
  v7 = off_101834;
  *(uint32_t *)off_101848 = *(uint32_t *)off_101848 & 0xFFFFF800 | 0x700;
  *v3 = 256;
  *v4 = *v4 & 0xFFFFE000 | 0x580;
  *v5 |= 0x10000u;
  *v5 |= 0x10000000u;
  *v5 |= 2u;
  v2 -= 236;
  *v6 |= 2u;
  *v2 = 1;
  v8 = v4 + 16846;
  *v5 &= 0xFFFFFF8F;
  *v8 = 1;
  *v3 = *v3 & 0xFFFFFCFF | 0x100;
  v2 -= 10753;
  *v7 |= 0x8000000u;
  v9 = (unsigned int *)off_10185C;
  *v2 &= 0xFFFFF0FF;
  *v9 |= 0x800000u;
  *v9 |= 0x400000u;
  *v9 |= 1u;
  *v9 = *v9 & 0xFFFFFF3F | 0x80;
  if ( v2[17161] > 1u )
  {
    v10 = (unsigned int *)off_101860;
    *v8 = 1;
    *v10 = *v10 & 0xFFFFFF | 0xA0000000;
    *v3 = *v3 & 0xFFFFFCFF | 0x100;
  }
  v11 = off_101868;
  v12 = off_10186C;
  result = dword_101874;
  *(uint32_t *)off_101864 = dword_101870;
  *v11 = result;
  v14 = BYTE2(((uint32_t *)(uintptr_t)off_101878)[101]);
  *v12 |= 0x10u;
  if ( !v14 )
    *(v12 - 10802) &= ~0x40u;
  return result;
}
