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

extern uint32_t off_103AE4;
extern uint32_t off_103AE0;
extern uint32_t off_103AE8;
extern uint32_t off_103AF0;
extern uint32_t off_103AF4;
extern uint32_t dword_103AF8;
extern uint32_t off_103AEC;

// rf_set_control_bit @ 0x103a54, size 138 bytes
int rf_set_control_bit()
{
  uint32_t *v0; // r2
  int v1; // r3
  uint32_t *v2; // r3
  uint32_t *v3; // r2
  int v4; // r3
  uint32_t *v5; // r3
  uint32_t *v6; // r0
  int v7; // r1

  v0 = off_103AE4;
  *(uint32_t *)off_103AE0 |= 1u;
  while ( (*v0 & 0x10) == 0 )
  {
    LOWORD(v1) = 50;
    do
      v1 = (uint16_t)(v1 - 1);
    while ( v1 );
  }
  v2 = off_103AE8;
  v3 = off_103AE4;
  *(uint32_t *)off_103AE8 |= 0x80000u;
  *v2 |= 0x100000u;
  while ( (*v3 & 8) == 0 )
  {
    LOWORD(v4) = 50;
    do
      v4 = (uint16_t)(v4 - 1);
    while ( v4 );
  }
  v5 = off_103AF0;
  v6 = off_103AF4;
  v7 = dword_103AF8;
  *(uint32_t *)off_103AEC |= 0x20000u;
  *v5 |= 0x1000000u;
  *v5 |= 0x8000000u;
  *v6 |= 0x524u;
  return check_feature_flag(0x2000, v7);
}

