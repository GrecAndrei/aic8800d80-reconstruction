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

extern uint32_t off_116430;
extern uint32_t dword_11642C;
extern uint32_t off_116434;
extern uint32_t off_116438;
extern uint32_t dword_11643C;
extern uint32_t dword_116440;
extern uint32_t off_116444;

// sub_1163A8 @ 0x1163a8, size 132 bytes
int sub_1163A8()
{
  int **v0; // r5
  uint32_t *v1; // r6
  int *v2; // r0
  void *v3; // r8
  int v4; // r7
  uint16_t v5; // r9
  int result; // r0

  v0 = (int **)off_116430;
  sub_12D468(dword_11642C);
  if ( **(int16_t **)off_116434 < 0 )
  {
    v2 = *v0;
    v1 = off_116438;
    if ( !*v0 || !*(uint32_t *)off_116438 )
    {
      sub_12F694(dword_11643C, dword_116440, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = off_116438;
    v2 = *v0;
  }
  v3 = off_116444;
  v4 = dword_11642C;
  sub_100200(v2, 0, 88 * *(uint16_t *)(*(uint32_t *)off_116444 + 8) + 88);
  v5 = 0;
  do
  {
    (*v0)[22 * v5 + 19] = *v1 + 80 * v5;
    result = sub_12D470(v4);
    ++v5;
  }
  while ( *(uint16_t *)(*(uint32_t *)v3 + 8) >= (unsigned int)v5 );
  return result;
}

