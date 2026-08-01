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

extern uint32_t off_13BFAC;
extern uint32_t dword_13BFB0;

// read_global_state_byte @ 0x13bf78, size 52 bytes
// Doc: sub_123BF78 [unknown]: Helper loading state struct pointer
// sub_123BF78 [unknown]: Helper loading state struct pointer
int read_global_state_byte()
{
  uint32_t *v0; // r4
  int result; // r0
  unsigned int v2; // r0

  v0 = off_13BFAC;
  if ( !*((uint32_t *)off_13BFAC + 6)
    || (result = *((uint8_t *)mem_word_load((int)off_13BFAC + 24) + 26), result == 33) )
  {
    if ( v0[8] )
      return 33;
    v2 = (uint8_t)tx_done_queue((int **)dword_13BFB0);
    if ( (uint8_t)v2 == 33 )
    {
      return 33;
    }
    else
    {
      rf_get_chan_param(v2);
      return 33;
    }
  }
  return result;
}

