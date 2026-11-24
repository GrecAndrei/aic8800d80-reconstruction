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


extern uint32_t dword_102844;
extern uint32_t dword_102848;
extern uint32_t dword_10284C;
extern uint32_t dword_102858;
extern uint32_t off_102840;
extern uint32_t off_102850;
extern uint32_t off_102854;

// flash_cr_unlock @ 0x1027d8, size 102 bytes
int flash_cr_unlock()
{
  int *v0; // r3
  int *v1; // r2
  int *v2; // r1
  int *v3; // r3
  int v4; // r2

  llc_event_loop();
  v0 = (int *)off_102840;
  *(uint32_t *)off_102840 = dword_102844;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_102848;
  v1 = (int *)off_102840;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_10284C;
  v2 = (int *)off_102840;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  format_log_message((unsigned int)*v2 >> 31, 2437, 0x985u, (unsigned int)*v2 >> 31, *v2 < 0, *v2 < 0);
  v3 = (int *)off_102854;
  v4 = dword_102858;
  *(uint32_t *)off_102850 = 12;
  *v3 = v4;
  return 12;
}
