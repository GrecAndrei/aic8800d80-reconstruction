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

extern uint32_t off_11EB40;
extern uint32_t off_11EB44;
extern uint32_t dword_11EB48;
extern uint32_t dword_11EB4C;

// check_hw_fw_status @ 0x11eabc, size 132 bytes
void check_hw_fw_status()
{
  uint32_t *v0; // r5
  uint32_t *v1; // r6
  int v2; // r3
  int v3; // r7
  int v4; // r3
  int v5; // r4
  int v6; // r2
  unsigned int v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r3
  unsigned int v10; // r2

  v0 = off_11EB40;
  v1 = off_11EB44;
  v2 = *((uint32_t *)off_11EB40 + 5);
  if ( v2 != *(uint32_t *)off_11EB44 )
  {
    v3 = dword_11EB48;
    do
    {
      v7 = v2 & 0x7FFFFFFF;
      v8 = v0[4] - (v2 & 0x7FFFFFFF);
      v9 = v2 & 0x80000000;
      if ( v8 > 0x9F )
      {
        v4 = v0[5];
      }
      else
      {
        v10 = v0[3];
        if ( v7 > v10 )
          v9 += 0x80000000;
        v4 = v9 | v10;
        v0[5] = v4;
      }
      v5 = v4 & 0x7FFFFFFF;
      v6 = *(uint32_t *)((v4 & 0x7FFFFFFF) + 0x14);
      if ( v6 != v3 )
        alloc_tx_event(dword_11EB4C, v4 & 0x7FFFFFFF, v6);
      read_chip_revision(v5);
      *(uint8_t *)(v5 + 156) = 1;
      capability_get(v5);
      v2 = v0[5];
    }
    while ( v2 != *v1 );
  }
}

