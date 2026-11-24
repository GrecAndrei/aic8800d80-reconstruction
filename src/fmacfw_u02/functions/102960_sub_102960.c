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


extern uint32_t dword_1029CC;
extern uint32_t dword_1029D0;
extern uint32_t dword_1029D4;
extern uint32_t dword_1029E0;
extern uint32_t off_1029C8;
extern uint32_t off_1029D8;
extern uint32_t off_1029DC;

// mmio_write_40580020 @ 0x102960, size 102 bytes
int mmio_write_40580020()
{
  int *v0; // r3
  int *v1; // r2
  int *v2; // r1
  int *v3; // r3
  int v4; // r2

  event_queue_check();
  v0 = (int *)off_1029C8;
  *(uint32_t *)off_1029C8 = dword_1029CC;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_1029D0;
  v1 = (int *)off_1029C8;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_1029D4;
  v2 = (int *)off_1029C8;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  tx_packet_handler((unsigned int)*v2 >> 31, 2437, 0x985u, (unsigned int)*v2 >> 31, *v2 < 0, *v2 < 0);
  v3 = (int *)off_1029DC;
  v4 = dword_1029E0;
  *(uint32_t *)off_1029D8 = 12;
  *v3 = v4;
  return 12;
}
