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

// hci_send_vendor_command @ 0x135930, size 46 bytes
int  hci_send_vendor_command(int a1)
{
  ke_int_lock((char *)0x180A, 6);
  if ( !a1 )
    return init_rf_tables();
  check_status_bits(256, "ext auth st %x\n", a1);
  return bt_setup_conn_profile(a1);
}
