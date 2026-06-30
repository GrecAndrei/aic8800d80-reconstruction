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

extern uint32_t off_14157C;
extern uint32_t dword_141568;
extern uint32_t dword_141578;
extern uint32_t dword_14156C;
extern uint32_t dword_141574;
extern uint32_t dword_141570;

// sub_1414AC @ 0x1414ac, size 186 bytes
int sub_1414AC()
{
  int16_t **v0; // r8
  int v1; // r5
  int v2; // r4
  int v3; // r6
  int v4; // r7
  int result; // r0

  v0 = (int16_t **)off_14157C;
  v1 = dword_141568;
  v2 = *(uint32_t *)(dword_141568 + 6480);
  if ( **(int16_t **)off_14157C >= 0 || v2 < 0 && (result = sub_12F32C(dword_141578, dword_14156C, 1734), **v0 >= 0) )
  {
    v3 = 16 * v2;
    if ( *(uint8_t *)(v1 + 136 * v2 + 6339) > 1u )
      return result;
    return sub_140AAC(v1 + 8 * (v2 + v3) + 6336, 0);
  }
  v4 = v1 + 136 * v2;
  v3 = 16 * v2;
  if ( *(uint8_t *)(v4 + 6338) == 5 )
  {
    if ( *(uint8_t *)(v4 + 6339) <= 1u )
      return sub_140AAC(v1 + 8 * (v2 + v3) + 6336, 0);
    return sub_12F32C(dword_141574, dword_14156C, 1744);
  }
  result = sub_12F32C(dword_141570, dword_14156C, 1735);
  if ( *(uint8_t *)(v4 + 6339) <= 1u )
    return sub_140AAC(v1 + 8 * (v2 + v3) + 6336, 0);
  if ( **v0 < 0 )
    return sub_12F32C(dword_141574, dword_14156C, 1744);
  return result;
}

