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

extern uint32_t off_11CB74;
extern uint32_t off_11CB78;
extern uint32_t dword_11CB7C;
extern uint32_t dword_11CB80;

// queue_remove @ 0x11cac8, size 170 bytes
int queue_remove()
{
  uint32_t *v0; // r6
  int v1; // r7
  int v2; // r5
  int v3; // r4
  int v4; // r1
  int v5; // r3
  int v6; // r2
  int v7; // r1
  int v9; // r0
  int v10; // r1

  v0 = off_11CB74;
  v1 = *(uint32_t *)off_11CB74;
  v2 = *(uint32_t *)off_11CB74 + 6 * *((uint8_t *)off_11CB74 + 10);
  v3 = 6 * *((uint8_t *)off_11CB74 + 10);
  if ( (*(uint8_t *)(v2 + 3) & 5) != 0 )
  {
    v4 = *(uint32_t *)(*(uint32_t *)off_11CB78 + 20);
    if ( !v4 )
      v4 = dword_11CB7C;
  }
  else
  {
    v9 = rf_channel_compare((uint16_t *)(*(uint32_t *)off_11CB74 + 6 * *((uint8_t *)off_11CB74 + 10)));
    v4 = 30000;
    if ( v9 )
      v4 = v9;
  }
  rf_status_read((int16_t *)v2, v4, *(uint8_t *)(v1 + 366));
  v5 = v0[1];
  if ( v5 )
  {
    v6 = *(uint8_t *)(v2 + 2);
    v7 = *(uint16_t *)(v1 + v3);
    if ( *(uint8_t *)(v2 + 2) )
    {
      if ( v6 == 1 && (v10 = v7 - 4992, (uint16_t)(v10 - 13) <= 0x370u) )
        *(uint8_t *)(v5 + 2) = (unsigned int)(((unsigned int)dword_11CB80 * (unsigned uint64_t)(unsigned int)(v10 - 8)) >> 32) >> 2;
      else
        *(uint8_t *)(v5 + 2) = 0;
    }
    else
    {
      if ( (unsigned int)(v7 - 2412) <= 0x48 )
      {
        if ( v7 == 2484 )
        {
          *(uint8_t *)(v5 + 2) = 14;
          return flash_erase_sector(2);
        }
        LOBYTE(v6) = (unsigned int)(((unsigned int)dword_11CB80 * (unsigned uint64_t)(unsigned int)(v7 - 2407)) >> 32) >> 2;
      }
      *(uint8_t *)(v5 + 2) = v6;
    }
  }
  return flash_erase_sector(2);
}

