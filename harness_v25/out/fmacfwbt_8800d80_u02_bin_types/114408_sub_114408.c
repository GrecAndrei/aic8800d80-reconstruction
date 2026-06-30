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

extern uint32_t off_114478;
extern uint32_t off_11447C;
extern uint32_t off_114480;
extern uint32_t dword_114490;
extern uint32_t off_114484;
extern uint32_t off_114488;
extern uint32_t off_11448C;
extern uint32_t dword_114494;

// sub_114408 @ 0x114408, size 110 bytes
// Doc: sub_1214408 [ipc]: Unidentified helper, possibly IPC/mailbox glue
// sub_1214408 [ipc]: Unidentified helper, possibly IPC/mailbox glue
int  sub_114408(int result)
{
  if ( !result )
  {
    if ( *(uint32_t *)off_114478
      && (result = *((uint32_t *)off_11447C + 4),
          *(uint32_t *)(*(uint32_t *)off_114478 + 12) - result - *((uint16_t *)off_114480 + 92) - 2000 < 0) )
    {
      result = feature_guard_sdio(2, dword_114490);
    }
    else
    {
      if ( !*(uint8_t *)off_114484
        || (result = *((uint32_t *)off_11447C + 4),
            *((uint32_t *)off_114484 + 1)
          + *((uint32_t *)off_114484 + 2)
          - result
          - *((uint16_t *)off_114480 + 92)
          - *(uint16_t *)(*(uint32_t *)off_114488 + 52) >= 0) )
      {
        *(uint32_t *)off_11448C = 0x40000000;
        return result;
      }
      result = feature_guard_sdio(2, dword_114494);
    }
  }
  *(uint32_t *)off_11448C = 0x80000000;
  return result;
}

