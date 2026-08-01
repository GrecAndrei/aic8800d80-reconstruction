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

extern uint32_t off_113C3C;

// update_config_bytes @ 0x113c20, size 28 bytes
// Doc: rf_msg_process_body_c22 [rf]: Process RF message body handler
// rf_msg_process_body_c22 [rf]: Process RF message body handler
int  update_config_bytes(int a1)
{
  uint8_t *v1; // r2
  char v2; // r3

  save_task_ptr(a1);
  v1 = rf_msg_process_body_n_4;
  v2 = *((uint8_t *)off_113C3C + 352);
  *(uint8_t *)rf_msg_process_body_n_8 = *((uint8_t *)off_113C3C + 326);
  *v1 = v2;
  return 1;
}

