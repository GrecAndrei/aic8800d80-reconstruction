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

extern uint32_t dword_102BEC;
extern uint32_t dword_102BE8;
extern uint32_t off_102BF0;
extern uint32_t dword_102BF8;
extern uint32_t dword_102BF4;

// fw_init_or_status_check @ 0x102bc0, size 38 bytes
// Doc: fw_init_or_status_check [util]: Initialize FW state and poll sign halfword status
// fw_init_or_status_check [util]: Initialize FW state and poll sign halfword status
int  fw_init_or_status_check(int a1, int a2, int a3)
{
  int result; // r0

  result = msg_parse(dword_102BEC, dword_102BE8, a3);
  if ( **(int16_t **)off_102BF0 < 0 )
    return sub_12F46C(dword_102BF8, dword_102BF4, 61);
  return result;
}

