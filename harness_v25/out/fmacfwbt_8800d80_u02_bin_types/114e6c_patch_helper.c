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

extern uint32_t off_114E78;

// patch_helper @ 0x114e6c, size 12 bytes
// Doc: patch_helper [patch]: Patch application helper
// patch_helper [patch]: Patch application helper
int  patch_helper(int result)
{
  if ( !result )
    *(uint32_t *)off_114E78 = 0x20000;
  return result;
}

