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

extern uint32_t off_10CDC4;
extern uint32_t off_10CDC8;
extern uint32_t off_10CDCC;
extern uint32_t off_10CDD0;

// interrupt_wait @ 0x10cd94, size 48 bytes
// Doc: interrupt_wait [mac]: Checks MAC status register 0x40035104 bit shift
// interrupt_wait [mac]: Checks MAC status register 0x40035104 bit shift
int interrupt_wait()
{
  uint32_t *v0; // r4
  int *v1; // r7
  uint32_t *v2; // r6
  int v3; // r0
  int result; // r0

  v0 = off_10CDC4;
  if ( (*(uint32_t *)off_10CDC4 & 2) != 0 )
  {
    v1 = (int *)off_10CDC8;
    v2 = off_10CDCC;
    do
    {
      v3 = *v1;
      *v2 = 2;
      scan_report_alloc((uint16_t *)(v3 + 4));
    }
    while ( (*v0 & 2) != 0 );
  }
  result = unknown_func_12d14c(0x8000000);
  *(uint32_t *)off_10CDD0 = 2;
  return result;
}

