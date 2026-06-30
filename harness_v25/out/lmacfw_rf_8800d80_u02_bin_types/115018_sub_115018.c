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

extern uint32_t off_115098;
extern uint32_t dword_115094;
extern uint32_t dword_115090;
extern uint32_t off_11509C;
extern uint32_t off_1150A0;
extern uint32_t off_1150A4;

// sub_115018 @ 0x115018, size 116 bytes
void __noreturn sub_115018()
{
  int *v0; // r4
  int v1; // r3
  int inited; // r0
  uint8_t *v3; // r5

  v0 = (int *)off_115098;
  msg_parse(dword_115094, dword_115090);
  if ( *(uint32_t *)off_11509C )
  {
    rf_byte_extract_save();
    if ( *(uint16_t *)(*v0 + 8) )
      sub_10F110(*(uint16_t *)(*v0 + 8));
  }
  if ( **(uint8_t **)off_1150A0 == 2 )
  {
    v1 = *v0;
    *(uint8_t *)(v1 + 6) = 2;
    *(uint8_t *)(v1 + 3) = 1;
  }
  inited = sub_113854(*(uint16_t *)(*v0 + 4));
  if ( !*(uint8_t *)(*v0 + 3) )
    rf_clear_flag_bit1();
  __enable_irq();
  __dsb(0xFu);
  __isb(0xFu);
  v3 = off_1150A4;
  while ( 1 )
  {
    if ( *(uint8_t *)(*v0 + 3) )
      sub_1138D0();
    if ( !*v3 )
      inited = rf_init_handler_1(inited);
    inited = sub_123240(inited);
  }
}

