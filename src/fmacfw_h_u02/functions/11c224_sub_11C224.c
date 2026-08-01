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

extern uint32_t off_11C250;

// get_frame_info @ 0x11c224, size 44 bytes
int  get_frame_info(int a1, int a2)
{
  int v2; // r3

  v2 = *(uint32_t *)(a1 + 68);
  if ( v2 && (*(uint16_t *)(v2 + 8) & 0x200) != 0 )
    return *((uint32_t *)off_11C250 + 43);
  if ( *(int *)(*(uint32_t *)(a1 + 44) + 60) >= 0 )
    return *(uint32_t *)(a2 + 580);
  return (*(uint8_t *)(a2 + 309) << 9) | 0x8007;
}

