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

extern uint32_t off_132B14;
extern uint32_t dword_132B18;
extern uint32_t dword_132B1C;

// bt_get_local_addr_type @ 0x132ab8, size 92 bytes
// Doc: bt_get_local_addr_type [bt]: Check Bluetooth link state and 0xC0 flag
// bt_get_local_addr_type [bt]: Check Bluetooth link state and 0xC0 flag
int  bt_get_local_addr_type(int a1)
{
  int v2; // r0
  int v3; // r3
  int v4; // r4
  char v5; // r2
  int v6; // t1
  int v7; // r0
  int result; // r0

  v2 = *(uint8_t *)(a1 + 192);
  if ( **(int16_t **)off_132B14 >= 0 )
  {
LABEL_2:
    if ( !v2 )
      goto LABEL_7;
    goto LABEL_3;
  }
  if ( !v2 )
  {
    mmio_irq_clear(dword_132B18, dword_132B1C, 707);
    v2 = *(uint8_t *)(a1 + 192);
    goto LABEL_2;
  }
LABEL_3:
  v3 = a1 + 192;
  v4 = a1 + 192 + v2;
  v2 = 0;
  do
  {
    v6 = *(uint8_t *)++v3;
    v5 = v6;
    if ( (int)(v6 & 0xFFFFFF7F) > v2 )
      v2 = v5 & 0x7F;
  }
  while ( v3 != v4 );
LABEL_7:
  v7 = util_validate_name_char(v2);
  result = set_flow_control_mode(a1, v7);
  *(uint8_t *)(a1 + 350) = 0;
  return result;
}

