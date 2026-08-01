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

extern uint32_t off_11830C;

// find_link_in_list @ 0x1182f4, size 22 bytes
// Doc: find_link_in_list [rf]: Get pointer to RF state structure
// find_link_in_list [rf]: Get pointer to RF state structure
int find_link_in_list()
{
  uint32_t *i; // r4
  int result; // r0

  for ( i = *((uint32_t **)off_11830C + 2); i; i = (uint32_t *)*i )
    result = check_link_id((int)i);
  return result;
}

