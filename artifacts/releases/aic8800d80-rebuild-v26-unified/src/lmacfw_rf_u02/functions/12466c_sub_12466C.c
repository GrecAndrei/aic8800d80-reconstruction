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

extern uint32_t off_1246DC;
extern uint32_t off_1246EC;
extern uint32_t off_1246E0;
extern uint32_t off_1246E8;
extern uint32_t off_1246E4;

// sub_12466C @ 0x12466c, size 112 bytes
void sub_12466C()
{
  int v0; // r0

  v0 = sub_11E628(0x2000);
  if ( is_flag_set_n645c(v0) )
  {
    switch ( *(uint8_t *)off_1246DC )
    {
      case 1:
        sub_124520();
        break;
      case 2:
        sub_124594();
        break;
      case 3:
        sub_124638();
        break;
      case 4:
        if ( *(uint8_t *)off_1246EC != 1 )
          log_free_dispatch_n2f2();
        break;
      case 5:
        rf_init_or_reset_sub_12245f0();
        break;
      default:
        return;
    }
  }
  else if ( *(uint32_t *)off_1246E0 )
  {
    if ( !*(uint8_t *)off_1246E8 )
      rf_sub_3bbc();
  }
  else
  {
    *(uint32_t *)off_1246E4 = 0;
  }
}

