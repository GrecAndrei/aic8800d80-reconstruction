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

extern uint32_t dword_11941C;

// trace_record_event @ 0x119400, size 28 bytes
int  trace_record_event(int a1, uint32_t *a2, int a3, int a4)
{
  int v4; // r0
  uint32_t *v5; // r5
  int v6; // r4
  int v7; // r1

  v4 = *a2;
  v5 = a2;
  v6 = dword_11941C;
  v7 = a2[1];
  LOWORD(v5) = *((uint16_t *)v5 + 4);
  *(uint32_t *)dword_11941C = v4;
  *(uint32_t *)(v6 + 4) = v7;
  *(uint16_t *)(v6 + 8) = (uint16_t)v5;
  ke_evt_handler(138, a4, a3);
  return 0;
}

