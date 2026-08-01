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

// init_bt_global @ 0x1142f8, size 24 bytes
// Doc: init_bt_global [rf]: RF fault dump handler clearing fault structure fields
// init_bt_global [rf]: RF fault dump handler clearing fault structure fields
int  init_bt_global(int a1)
{
  uint32_t *v1; // r2
  uint16_t *v2; // r1

  v1 = rf_fault_dump_n_438;
  v2 = rf_fault_dump_n_434;
  *((uint32_t *)rf_fault_dump_n_438 + 2) = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v1 = 0;
  v1[1] = 0;
  v2[6] = 0;
  return 1;
}

