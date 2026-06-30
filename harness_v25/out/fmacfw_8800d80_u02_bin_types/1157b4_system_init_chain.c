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

// system_init_chain @ 0x1157b4, size 32 bytes
// Doc: system_init_chain [util]: System initialization chain calling subs
// system_init_chain [util]: System initialization chain calling subs
int system_init_chain()
{
  int inited; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((uint8_t *)ipc_doorbell_handler_n_1a8 + 1) = 0;
  inited = ipc_init_buf();
  v1 = sub_1321C8(inited);
  v2 = mac_phy_init(v1);
  v3 = sub_12D210(v2);
  return sub_12F508(v3);
}

