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

// patch_apply_n_28 @ 0x1154c0, size 28 bytes
// Doc: patch_apply_n_28 [patch]: Apply firmware patch from symbol table
// patch_apply_n_28 [patch]: Apply firmware patch from symbol table
void __noreturn patch_apply_n_28()
{
  if ( **(int16_t **)off_1154DC < 0 )
    sub_12F694(patch_apply_n_4, dword_1154E0, 242);
  while ( 1 )
    ;
}

