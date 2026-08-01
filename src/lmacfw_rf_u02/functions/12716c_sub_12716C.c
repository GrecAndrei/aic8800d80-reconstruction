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

extern uint32_t off_127190;

// rf_disable @ 0x12716c, size 36 bytes
int rf_disable()
{
  int result; // r0

  *((uint8_t *)off_127190 + 1) = 0;
  result = ke_task_retrieve(1070, 1);
  if ( result )
    return ke_int_lock(1070, 1);
  return result;
}

