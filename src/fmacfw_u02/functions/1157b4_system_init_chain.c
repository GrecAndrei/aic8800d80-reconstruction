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

// system_init @ 0x1157b4, size 32 bytes
// Doc: system_init [util]: System initialization chain calling subs
// system_init [util]: System initialization chain calling subs
int system_init()
{
  int inited; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((uint8_t *)ipc_doorbell_handler_n_1a8 + 1) = 0;
  inited = reset_global_0x18274c();
  v1 = ke_task_reset(inited);
  v2 = get_bt_state(v1);
  v3 = assert_fail_record(v2);
  return init_global_0x1922d4(v3);
}

