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

extern uint32_t off_1258BC;

// co_list_remove @ 0x1258a4, size 22 bytes
int  co_list_remove(uint16_t *a1)
{
  if ( *((uint32_t *)off_1258BC + 1) )
    return cmd_handler_a((char *)off_1258BC + 12);
  else
    return hci_acl_header_parse(a1);
}

