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

extern uint32_t dword_134678;
extern uint32_t off_134674;

// get_acl_conn_slot @ 0x13465c, size 24 bytes
int  get_acl_conn_slot(uint8_t *a1)
{
  return cfm_radio_check(
           (uint8_t *)(dword_134678 + 1320 * *(uint8_t *)(*((uint32_t *)off_134674 + 4) + 61)),
           a1);
}

