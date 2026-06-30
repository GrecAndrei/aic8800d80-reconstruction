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

extern uint32_t dword_12D928;
extern uint32_t dword_12D92C;

// rf_state_check_n3ea_d908 @ 0x12d908, size 26 bytes
// Doc: rf_state_check_n3ea_d908 [rf]: Check RF state via magic values
// rf_state_check_n3ea_d908 [rf]: Check RF state via magic values
float  rf_state_check_n3ea_d908(unsigned int a1)
{
  float v1; // r0
  uint64_t v2; // r0
  int v3; // r0

  v1 = sub_12D7CC(a1);
  v2 = sub_142A94(LODWORD(v1));
  v3 = sub_142B44(v2, HIDWORD(v2), dword_12D928, dword_12D92C);
  return sub_143108(v3);
}

