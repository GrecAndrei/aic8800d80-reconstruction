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

extern uint32_t dword_114B20;
extern uint32_t dword_114B24;
extern uint32_t dword_114B28;
extern uint32_t dword_114B2C;
extern uint32_t off_114B30;
extern uint32_t off_114B34;
extern uint32_t dword_114B38;
extern uint32_t off_114B3C;
extern uint32_t off_114B40;
extern uint32_t off_114B44;
extern uint32_t off_114B4C;
extern uint32_t off_114B48;
extern uint32_t dword_114B50;
extern uint32_t off_114B54;
extern uint32_t off_114B58;

// get_free_heap_size @ 0x114a68, size 180 bytes
void __noreturn get_free_heap_size()
{
  uint32_t *v0; // r2
  unsigned int v1; // r3
  int v2; // r1
  char *v3; // r2
  char *v4; // r3
  uint32_t *v5; // r0
  int v6; // t1
  uint32_t *v7; // r2
  int v8; // r0
  int i; // r3
  int v10; // r2
  int v11; // r3
  uint8_t *v12; // r2

  v0 = (uint32_t *)dword_114B20;
  if ( dword_114B20 < (unsigned int)dword_114B24 )
  {
    v1 = ((dword_114B24 - 1 - dword_114B20) & 0xFFFFFFFC) + 4 + dword_114B20;
    do
      *v0++ = 0;
    while ( v0 != (uint32_t *)v1 );
  }
  v2 = dword_114B28;
  if ( dword_114B28 < (unsigned int)dword_114B2C )
  {
    v3 = (char *)off_114B30;
    v4 = (char *)off_114B30 + ((dword_114B2C - 1 - dword_114B28) & 0xFFFFFFFC) + 4;
    v5 = (uint32_t *)dword_114B28;
    do
    {
      v6 = *(uint32_t *)v3;
      v3 += 4;
      *v5++ = v6;
    }
    while ( v3 != v4 );
  }
  v7 = off_114B34;
  v8 = dword_114B38;
  *((uint32_t *)off_114B34 + 34) |= 0xF00000u;
  v7[2] = v2;
  for ( i = 0; i != 86; ++i )
  {
    v10 = v8 + i;
    *(uint8_t *)(v10 + 768) = -1;
  }
  if ( (uint16_t)*(uint32_t *)off_114B34 == 49729 )
    *(uint32_t *)off_114B3C = 1;
  v11 = HIBYTE(*(uint32_t *)off_114B40);
  *(uint8_t *)off_114B44 = v11;
  if ( (v11 & 4) != 0 )
  {
    v12 = off_114B4C;
    *(uint32_t *)off_114B48 = dword_114B50;
    *v12 = 26;
  }
  if ( (v11 & 0x10) == 0 )
    *(uint32_t *)off_114B54 &= ~0x4000u;
  *(uint8_t *)off_114B58 = BYTE2(*(uint32_t *)off_114B40);
  save_rf_context();
  init_buffer_list();
}

