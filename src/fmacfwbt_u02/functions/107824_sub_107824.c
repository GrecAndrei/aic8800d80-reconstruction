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

extern uint32_t dword_1078D4;
extern uint32_t dword_1078D8;
extern uint32_t dword_1078E0;
extern uint32_t dword_1078DC;

// util_min_max @ 0x107824, size 174 bytes
int  util_min_max(unsigned int *a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r5
  int v5; // r7
  int v6; // s15

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
  state_check_feature(1, dword_1078D4);
  v6 = (int)(float)(COERCE_FLOAT(((int ( *)(uint32_t))system_init_sequence)(vcvts_n_f32_u32(v3, 0xFu))) * 10.0);
  state_check_feature(1, dword_1078D8);
  if ( v6 >= -1 )
  {
    state_check_feature(1, dword_1078E0);
  }
  else if ( v6 < -30 )
  {
    state_check_feature(1, dword_1078DC);
  }
  *(uint32_t *)(a2 + 8) = (int)((float ( *)(uint32_t))tail_call_14274c)((float)(~v6 + v5));
  return rf_load_tx_config(a2);
}

