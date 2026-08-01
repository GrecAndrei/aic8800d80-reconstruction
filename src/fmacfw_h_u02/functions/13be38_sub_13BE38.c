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

extern uint32_t off_13BE6C;
extern uint32_t dword_13BE70;

// ke_get_state @ 0x13be38, size 52 bytes
int ke_get_state()
{
  uint32_t *v0; // r4
  int result; // r0
  unsigned int v2; // r0

  v0 = off_13BE6C;
  if ( !*((uint32_t *)off_13BE6C + 6)
    || (result = *((uint8_t *)list_pop((int)off_13BE6C + 24) + 26), result == 33) )
  {
    if ( v0[8] )
      return 33;
    v2 = (uint8_t)load_global_pointer((int **)dword_13BE70);
    if ( (uint8_t)v2 == 33 )
    {
      return 33;
    }
    else
    {
      ke_task_get(v2);
      return 33;
    }
  }
  return result;
}

