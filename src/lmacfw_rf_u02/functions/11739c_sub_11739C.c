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

extern uint32_t off_11740C;
extern uint32_t off_117400;
extern uint32_t dword_117408;
extern uint32_t dword_117404;

// ll_timer_offset_get @ 0x11739c, size 98 bytes
int  ll_timer_offset_get(int a1, int a2)
{
  int v2; // r3
  int result; // r0
  unsigned int v4; // r3
  uint32_t *v5; // r1
  int v6; // r2
  int v7; // cf
  unsigned int v8; // r2

  if ( !a2 )
  {
    v4 = a1 + 156;
    goto LABEL_9;
  }
  if ( (*(uint16_t *)(a2 + 16) & 1) != 0 )
  {
LABEL_8:
    v4 = (*(uint32_t *)(a2 + 12) & 0xFFFFFFFC) + 4;
LABEL_9:
    v5 = off_11740C;
    v6 = *((uint32_t *)off_11740C + 2);
    if ( *((uint32_t *)off_11740C + 1) == v4 )
      v4 = *(uint32_t *)off_11740C;
    *(uint32_t *)(a1 + 148) = v4;
    result = v6 & 0x7FFFFFFF;
    v7 = v4 >= (v6 & 0x7FFFFFFFu);
    v8 = v6 & 0x80000000;
    if ( !v7 )
      v8 += 0x80000000;
    v5[2] = v4 | v8;
    return result;
  }
  v2 = *(uint32_t *)off_117400;
  while ( 1 )
  {
    a2 = *(uint32_t *)(a2 + 4);
    if ( **(int16_t **)off_117400 < 0 && !a2 )
      return ke_int_lock(dword_117408, dword_117404, 1119, v2);
    v2 = *(uint16_t *)(a2 + 16) << 31;
    if ( (*(uint16_t *)(a2 + 16) & 1) != 0 )
      goto LABEL_8;
  }
}

