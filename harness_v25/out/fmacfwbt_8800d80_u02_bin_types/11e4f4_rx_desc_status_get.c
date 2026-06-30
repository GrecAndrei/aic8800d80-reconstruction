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

extern uint32_t off_11E53C;
extern uint32_t off_11E538;

// rx_desc_status_get @ 0x11e4f4, size 66 bytes
// Doc: rx_desc_status_get [rx]: Reads descriptor status/control fields at offset 0x98/0x9c
// rx_desc_status_get [rx]: Reads descriptor status/control fields at offset 0x98/0x9c
int  rx_desc_status_get(int result)
{
  unsigned int v1; // r3
  unsigned int v2; // r2
  unsigned int v3; // r2

  v1 = *(uint32_t *)(result + 152);
  if ( *(uint8_t *)(result + 156) )
  {
    v3 = *(uint32_t *)off_11E53C & 0x80000000;
    if ( v1 < (*(uint32_t *)off_11E53C & 0x7FFFFFFFu) )
      v3 += 0x80000000;
    *(uint32_t *)off_11E53C = v1 | v3;
  }
  else
  {
    v2 = *(uint32_t *)off_11E538 & 0x80000000;
    if ( v1 < (*(uint32_t *)off_11E538 & 0x7FFFFFFFu) )
      v2 += 0x80000000;
    *(uint32_t *)off_11E538 = v1 | v2;
  }
  return result;
}

