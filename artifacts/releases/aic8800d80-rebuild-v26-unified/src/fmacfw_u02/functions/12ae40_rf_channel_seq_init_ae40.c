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

extern uint32_t dword_12AE70;

// rf_channel_seq_init_ae40 @ 0x12ae40, size 48 bytes
// Doc: rf_channel_seq_init_ae40 [rf]: Sequential init calls with args 0..3 to sub
// rf_channel_seq_init_ae40 [rf]: Sequential init calls with args 0..3 to sub
int *rf_channel_seq_init_ae40()
{
  int *result; // r0
  uint8_t *v1; // r3
  int v2; // r1

  fmac_table_lookup(0);
  fmac_table_lookup(1);
  fmac_table_lookup(2);
  result = fmac_table_lookup(3);
  v1 = (uint8_t *)dword_12AE70;
  v2 = dword_12AE70 + 96;
  do
  {
    v1[1] = 0;
    v1[2] = 0;
    *v1 = 0;
    v1 += 3;
  }
  while ( v1 != (uint8_t *)v2 );
  return result;
}

