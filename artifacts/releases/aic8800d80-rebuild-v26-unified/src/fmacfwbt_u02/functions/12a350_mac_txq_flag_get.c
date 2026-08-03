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

extern uint32_t dword_12A360;

// mac_txq_flag_get @ 0x12a350, size 14 bytes
// Doc: mac_txq_flag_get [mac]: Read flag byte from per-TID tx queue entry table
// mac_txq_flag_get [mac]: Read flag byte from per-TID tx queue entry table
int  mac_txq_flag_get(int a1)
{
  return *(uint8_t *)(dword_12A360 + 140 * a1 + 133);
}

