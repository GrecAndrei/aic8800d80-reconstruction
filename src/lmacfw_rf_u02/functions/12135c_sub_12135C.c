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

// patch_ram_download @ 0x12135c, size 68 bytes
int  patch_ram_download(int a1, char **a2, int a3, int a4)
{
  int v5; // r0
  char *v6; // r1
  unsigned int v7; // r2
  int v8; // r4

  v5 = ke_msg_send_1(1060, a4, a3, 1032);
  v7 = (unsigned int)a2[1];
  v6 = *a2;
  if ( v7 >= 0x400 )
    v7 = 1024;
  *(uint32_t *)v5 = v6;
  *(uint32_t *)(v5 + 4) = v7;
  v8 = v5;
  memcpy_large((char *)(v5 + 8), v6, v7);
  dispatch_event_handler_1(asc_12E8F8, *a2, &(*a2)[*(uint32_t *)(v8 + 4)], *(uint32_t *)(v8 + 8));
  rx_irq_handler_1(v8);
  return 0;
}
