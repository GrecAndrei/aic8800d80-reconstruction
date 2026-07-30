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

extern uint32_t dword_11C03C;
extern uint32_t off_11C038;

// bt_xx_table_lookup_n_be @ 0x11bff4, size 68 bytes
// Doc: bt_xx_table_lookup_n_be [bt]: Looks up table entry indexed by [base+0xbe] scaled by 0x54
// bt_xx_table_lookup_n_be [bt]: Looks up table entry indexed by [base+0xbe] scaled by 0x54
int  bt_xx_table_lookup_n_be(int a1, int a2)
{
  int v2; // r6
  int v3; // r5
  int result; // r0
  int v6; // r5

  v2 = dword_11C03C;
  v3 = *((uint8_t *)off_11C038 + 190);
  sub_12D4F8(dword_11C03C + 84 * v3 + 12);
  result = sub_118358(a1, a2, v3);
  if ( (*(uint32_t *)(a1 + 36) & 0x380000) == 0x380000 )
  {
    v6 = v2 + 84 * v3;
    *(uint32_t *)(v6 + 36) = *(uint32_t *)(a1 + 68);
    *(uint8_t *)(v6 + 26) = 2;
  }
  return result;
}

