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

// rf_msg_process_body_n410 @ 0x114058, size 56 bytes
// Doc: rf_msg_process_body_n43e [rx]: Process RF message body 0x60 bytes
// rf_msg_process_body_n43e [rx]: Process RF message body 0x60 bytes
int rf_msg_process_body_n410()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  mem_buf_alloc_n_c30();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)rf_msg_process_body_n448 = 1;
  }
  v0 = (int *)rf_msg_process_body_n44c;
  ++*(uint32_t *)rf_msg_process_body_n44c;
  result = clear_flags(128);
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(uint32_t *)rf_msg_process_body_n448;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

