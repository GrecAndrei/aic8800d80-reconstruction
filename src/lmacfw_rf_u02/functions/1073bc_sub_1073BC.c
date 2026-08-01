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

extern uint32_t dword_10746C;
extern uint32_t dword_107470;
extern uint32_t dword_107478;
extern uint32_t dword_107474;

// timer_delta_compare @ 0x1073bc, size 174 bytes
int  timer_delta_compare(unsigned int *a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r5
  int v5; // r7
  int v6; // s15
  int v7; // r3
  int v8; // r3

  v2 = *a1;
  if ( *a1 < a1[1] )
    v2 = a1[1];
  v3 = a1[3];
  if ( !v2 )
    v2 = 1;
  if ( v2 < a1[2] )
    v2 = a1[2];
  if ( v3 < v2 )
    v3 = v2;
  v5 = *(uint32_t *)(a2 + 8);
  check_interrupt_flag(1, dword_10746C, v3, v2);
  v6 = (int)(float)(COERCE_FLOAT(((int ( *)(uint32_t))float_to_double)(vcvts_n_f32_u32(v3, 0xFu))) * 10.0);
  check_interrupt_flag(1, dword_107470, v6, v7);
  v8 = v6 + 1;
  if ( v6 >= -1 )
  {
    check_interrupt_flag(1, dword_107478, -2, v8);
  }
  else if ( v6 < -30 )
  {
    check_interrupt_flag(1, dword_107474, -30, v8);
  }
  *(uint32_t *)(a2 + 8) = (int)((float ( *)(uint32_t))branch_to_127228)((float)(~v6 + v5));
  return load_patch_bundle(a2);
}

