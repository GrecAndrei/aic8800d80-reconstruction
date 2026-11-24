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


extern uint32_t off_12FC40;

// sub_12FC20 @ 0x12fc20, size 32 bytes
int sub_12FC20()
{
  unsigned int v0; // r4
  unsigned int v1; // r5
  const char *v2; // r2

  v0 = off_12FC40;
  v1 = off_12FC40 + 112;
  do
  {
    v2 = *(const char **)(v0 + 4);
    if ( v2 )
      sub_10DA7C("%s %s\r\n", *(const char **)v0, v2);
    v0 += 16;
  }
  while ( v0 != v1 );
  return 0;
}
