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

extern uint32_t off_133970;
extern uint32_t dword_133978;
extern uint32_t dword_133974;

// sub_133914 @ 0x133914, size 90 bytes
int sub_133914()
{
  int v0; // r2
  int v2; // [sp+0h] [bp-Ch] BYREF
  int v3; // [sp+4h] [bp-8h] BYREF

  v0 = **(int16_t **)off_133970;
  v2 = 0;
  v3 = 0;
  if ( v0 < 0 && sub_12CD48(6u) != 1 )
    sub_12F32C(dword_133978, dword_133974, 303);
  sub_134334(&v2, &v3);
  if ( v2 && v3 )
  {
    sub_134480();
    return 0;
  }
  else
  {
    sub_134CC4(1);
    return 0;
  }
}

