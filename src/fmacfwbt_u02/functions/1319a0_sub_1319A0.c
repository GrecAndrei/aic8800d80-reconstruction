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

extern uint32_t dword_131A34;
extern uint32_t off_131A30;
extern uint32_t dword_131A3C;
extern uint32_t dword_131A38;

// llc_conn_env_get_by_handle @ 0x1319a0, size 142 bytes
int  llc_conn_env_get_by_handle(int a1, uint8_t *a2)
{
  int v3; // r5
  int v4; // r6
  char v5; // r3
  char v7; // r3

  v3 = *(uint32_t *)(dword_131A34 + 696 * *a2 + 340);
  if ( **(int16_t **)off_131A30 < 0 && !v3 )
    mmio_irq_clear(dword_131A3C, dword_131A38, 1031);
  v4 = *((uint16_t *)a2 + 1);
  if ( v4 == 0xFFFF )
  {
    v5 = *(uint8_t *)(v3 + 166);
    *(uint16_t *)(v3 + 190) = -1;
    v5 &= 0xCFu;
    *(uint8_t *)(v3 + 166) = v5;
    if ( (v5 & 0x80) == 0 )
      return 0;
    is_connection_active(*a2);
    *(uint8_t *)(v3 + 166) &= ~0x80u;
    return 0;
  }
  else
  {
    if ( !validate_channel_map(v3, *((uint16_t *)a2 + 1)) )
      return 0;
    v7 = *(uint8_t *)(v3 + 166);
    *(uint16_t *)(v3 + 190) = v4;
    *(uint8_t *)(v3 + 166) = v7 & 0xCF | 0x10;
    return 0;
  }
}

