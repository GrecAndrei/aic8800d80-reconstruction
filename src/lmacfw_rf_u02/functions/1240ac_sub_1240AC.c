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


extern uint32_t off_124130;
extern uint32_t off_124134;

// rf_disable_1 @ 0x1240ac, size 130 bytes
int  rf_disable_1(int a1)
{
  unsigned int *v1; // r1
  unsigned int *v2; // r4
  unsigned int v3; // r3
  unsigned int v4; // r2
  int result; // r0

  v1 = (unsigned int *)off_124130;
  v2 = (unsigned int *)off_124134;
  v3 = *(uint32_t *)off_124130 & 0xFFFCFFFF;
  v4 = *(uint32_t *)off_124134 & 0xFFFFF9FF;
  *(uint32_t *)off_124134 = v4;
  *v1 = v3;
  switch ( a1 )
  {
    case 0:
      dispatch_event_handler_1(aGi08us1xHeLtf3);
      result = 0;
      break;
    case 1:
      *v1 = v3 | 0x10000;
      dispatch_event_handler_1(aGi08us2xHeLtf6);
      result = 0;
      break;
    case 2:
      *v1 = v3 | 0x10000;
      *v2 = v4 | 0x200;
      dispatch_event_handler_1(aGi16us2xHeLtf6);
      result = 0;
      break;
    case 3:
      *v1 = v3 | 0x20000;
      dispatch_event_handler_1(aGi08us4xHeLtf1);
      result = 0;
      break;
    case 4:
      *v1 = v3 | 0x20000;
      *v2 = v4 | 0x400;
      dispatch_event_handler_1(aGi32us4xHeLtf1);
      goto LABEL_3;
    default:
      dispatch_event_handler_1(aUnsupportValue);
LABEL_3:
      result = 0;
      break;
  }
  return result;
}
