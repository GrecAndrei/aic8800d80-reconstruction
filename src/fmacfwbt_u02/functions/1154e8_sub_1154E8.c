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

extern uint32_t off_115558;

// check_patch_magic @ 0x1154e8, size 112 bytes
// Doc: patch_apply_ne_54f6 [patch]: Apply patch with aligned check (ands r1, r2, 3)
// patch_apply_ne_54f6 [patch]: Apply patch with aligned check (ands r1, r2, 3)
void check_patch_magic()
{
  uint32_t *v0; // r3
  int v1; // r2
  unsigned int v2; // r1
  int v3; // r4
  uint32_t *v4; // t1
  int *v5; // r2
  int v6; // r5
  int v7; // r0
  int v8; // t1
  uint32_t *v9; // r3
  unsigned int v10; // r1
  int v11; // r0

  v0 = off_115558;
  if ( *(uint32_t *)off_115558 == patch_apply_n74_555c && *((uint32_t *)off_115558 + 2) == patch_apply_n74_555c + 135327480 )
  {
    v1 = *((uint32_t *)off_115558 + 1);
    v2 = v1 & 3;
    if ( (v1 & 3) == 0 )
    {
      if ( *((uint32_t *)off_115558 + 3) )
      {
        do
        {
          v3 = *(uint32_t *)(v1 + 4);
          v4 = *(uint32_t **)v1;
          v1 += 8;
          *v4 = v3;
          ++v2;
        }
        while ( v0[3] > v2 );
      }
      v5 = (int *)patch_apply_entry_560;
      v6 = patch_apply_entry_560 + 16;
      do
      {
        v8 = *v5++;
        v7 = v8;
        if ( !(v8 << 30) )
        {
          v9 = (uint32_t *)v5[3];
          v10 = (uint8_t)v9 & 3;
          if ( ((uint8_t)v9 & 3) == 0 )
          {
            if ( v5[7] )
            {
              v11 = v7 - (uint32_t)v9;
              do
              {
                *(uint32_t *)((char *)v9 + v11) = *v9;
                ++v10;
                ++v9;
              }
              while ( v10 < v5[7] );
            }
          }
        }
      }
      while ( v5 != (int *)v6 );
    }
  }
}

