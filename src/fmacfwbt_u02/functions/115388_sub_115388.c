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

// ioctl_cmd_4 @ 0x115388, size 10 bytes
// Doc: patch_apply_n_15c [patch]: Apply BT firmware patch nop-stub n_15c
// patch_apply_n_15c [patch]: Apply BT firmware patch nop-stub n_15c
int  ioctl_cmd_4(int a1)
{
  return ioctl_dispatch(4, a1, 0x14u);
}

