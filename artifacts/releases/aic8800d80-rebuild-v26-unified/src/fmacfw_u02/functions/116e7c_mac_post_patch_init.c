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

extern uint32_t off_116EF8;

// mac_post_patch_init @ 0x116e7c, size 124 bytes
// Doc: mac_post_patch_init [mac]: Run post-patch initialization sequence
// mac_post_patch_init [mac]: Run post-patch initialization sequence
int mac_post_patch_init()
{
  int v0; // r0
  int inited; // r0
  char *v2; // r5
  char *v3; // r6
  char *v4; // r0
  uint32_t *v5; // r5
  int result; // r0

  sub_119D4C();
  rf_fault_status_get_n_xxx();
  v0 = sub_1161D4();
  subsys_init(v0);
  inited = crypto_init_n_cf(0);
  sub_11BD88(inited);
  v2 = (char *)off_116EF8 + 12;
  memset_thunk((int *)off_116EF8, 0, 0x204u);
  v3 = v2 + 420;
  do
  {
    sub_12D240(v2);
    *((uint32_t *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((uint32_t *)v2 + 6) = 0;
    *((uint32_t *)v2 + 7) = 0;
    v4 = v2 + 16;
    v2 += 84;
    sub_12D240(v4);
  }
  while ( v2 != v3 );
  v5 = off_116EF8;
  sub_12D240((char *)off_116EF8 + 432);
  v5[114] = 0;
  v5[115] = 0;
  v5[105] = 0;
  *((uint8_t *)v5 + 446) = 0;
  *((uint8_t *)v5 + 500) = 0;
  result = sub_12D240(v5 + 112);
  *((uint16_t *)v5 + 254) = 0;
  return result;
}

