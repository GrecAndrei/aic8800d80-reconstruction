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

extern uint32_t dword_1219EC;
extern uint32_t off_1219E8;
extern uint32_t off_1219F0;

// rf_cmd_send_n264 @ 0x1219c4, size 36 bytes
// Doc: rf_cmd_send_n264 [rf]: Send RF command (n264 variant) via MMIO
// rf_cmd_send_n264 [rf]: Send RF command (n264 variant) via MMIO
int  rf_cmd_send_n264(int a1, int a2, int a3)
{
  int v4; // r0
  int result; // r0

  __disable_irq();
  v4 = dword_1219EC;
  *(uint32_t *)off_1219E8 = 0;
  result = msg_parse(v4, a1, a2, a3 & 0xFFFFF);
  while ( *(uint32_t *)off_1219F0 )
    ;
  return result;
}

