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


extern uint32_t dword_10289C;
extern uint32_t dword_1028A0;
extern uint32_t dword_1028A4;
extern uint32_t dword_1028B4;
extern uint32_t off_102898;
extern uint32_t off_1028A8;
extern uint32_t off_1028AC;
extern uint32_t off_1028B0;

// pmu_write_ctrl @ 0x102828, size 110 bytes
int pmu_write_ctrl()
{
  int *v0; // r3
  int *v1; // r2
  int *v2; // r1
  uint32_t *v3; // r4
  uint32_t *v4; // r1
  int result; // r0

  tx_path_check();
  v0 = (int *)off_102898;
  *(uint32_t *)off_102898 = dword_10289C;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_1028A0;
  v1 = (int *)off_102898;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_1028A4;
  v2 = (int *)off_102898;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  rf_calibrate((unsigned int)*v2 >> 31, 2412, 0x96Cu, (unsigned int)*v2 >> 31, *v2 < 0, *v2 < 0);
  v3 = off_1028AC;
  v4 = off_1028B0;
  result = dword_1028B4;
  *(uint32_t *)off_1028A8 &= ~0x200u;
  *v3 = 12;
  *v4 = result;
  return result;
}
