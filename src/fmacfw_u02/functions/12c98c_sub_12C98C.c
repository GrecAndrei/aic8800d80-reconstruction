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


extern uint32_t dword_12C9FC;
extern uint32_t off_12C9F8;
extern uint32_t off_12CA0C;

// sub_12C98C @ 0x12c98c, size 106 bytes
uint32_t * sub_12C98C(int a1)
{
  int v1; // r3
  char *v4; // r0

  v1 = *(uint16_t *)(a1 - 6);
  if ( **(int16_t **)off_12C9F8 >= 0 || (uint8_t)v1 <= 0xEu )
  {
    if ( (uint8_t)v1 <= 0xCu )
    {
      sub_12D248(dword_12C9FC, (uint32_t *)(a1 - 12));
      return (uint32_t *)sub_12D104(0x4000000);
    }
  }
  else
  {
    sub_12F46C((int)aIdTaskMax, (int)aKeTaskLocal, 183);
    v1 = *(uint16_t *)(a1 - 6);
  }
  sub_12EA88(
    "\x9D\x80Dispatching msg:%x from tsk:%x to tsk:%x\n",
    *(uint16_t *)(a1 - 8),
    *(uint16_t *)(a1 - 4),
    v1);
  v4 = (char *)(a1 - 12);
  if ( *(uint8_t *)off_12CA0C )
    return sub_12CBC8(v4);
  else
    return (uint32_t *)sub_12F52C(v4);
}
