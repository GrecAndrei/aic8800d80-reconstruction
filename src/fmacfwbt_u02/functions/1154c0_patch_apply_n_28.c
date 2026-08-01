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

extern uint32_t off_1154DC;
extern uint32_t dword_1154E0;

// check_signed_status @ 0x1154c0, size 28 bytes
// Doc: check_signed_status [patch]: Apply firmware patch from symbol table
// check_signed_status [patch]: Apply firmware patch from symbol table
void __noreturn check_signed_status()
{
  if ( **(int16_t **)off_1154DC < 0 )
    mmio_irq_clear(patch_apply_n_4, dword_1154E0, 242);
  while ( 1 )
    ;
}

