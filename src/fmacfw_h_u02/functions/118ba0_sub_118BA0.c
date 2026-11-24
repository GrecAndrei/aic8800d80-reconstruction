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


extern uint32_t dword_118BB8;

// set_string_0x1882c0 @ 0x118ba0, size 22 bytes
int  set_string_0x1882c0(uint32_t *a1)
{
  wlan_ioctl_handler_1(dword_118BB8, a1);
  return irq_disable_global_2(0x20000);
}
