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

extern uint32_t dword_140E94;

// send_scan_report_event @ 0x140e60, size 52 bytes
int  send_scan_report_event(char a1, char a2, char a3, int a4, char a5)
{
  int v5; // r4
  int16_t v6; // r6
  int result; // r0
  uint8_t v8[140]; // [sp+0h] [bp-8Ch] BYREF

  v5 = dword_140E94;
  v8[2] = a5;
  v6 = *(uint16_t *)(dword_140E94 + 6488);
  *(uint8_t *)(dword_140E94 + 6488) = a2;
  *(uint8_t *)(v5 + 6489) = a1;
  v8[0] = a3;
  result = check_scan_enable((int)v8, a4);
  *(uint16_t *)(v5 + 6488) = v6;
  return result;
}

