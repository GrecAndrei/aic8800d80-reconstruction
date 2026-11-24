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


extern uint32_t dword_138964;

// rf_set_tx_power @ 0x138934, size 46 bytes
int  rf_set_tx_power(int a1)
{
  int v1; // r5
  int v3; // r1

  v1 = dword_138964;
  rf_lookup_tx_power(0, 4, *(uint32_t *)(a1 + 20));
  wlan_ioctl_handler_3(v1, (uint32_t *)a1);
  wlan_ioctl_handler_1(v1 - 8, (uint32_t *)a1);
  return (int)deref_and_check((int *)(v1 - 32), v3);
}
