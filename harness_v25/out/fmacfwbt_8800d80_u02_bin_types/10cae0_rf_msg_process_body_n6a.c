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

extern uint32_t off_10CAE8;

// rf_msg_process_body_n6a @ 0x10cae0, size 8 bytes
// Doc: rf_msg_process_body_n6a [rf]: Process RF message body payload
// rf_msg_process_body_n6a [rf]: Process RF message body payload
void rf_msg_process_body_n6a()
{
  *(uint32_t *)off_10CAE8 = 8;
}

