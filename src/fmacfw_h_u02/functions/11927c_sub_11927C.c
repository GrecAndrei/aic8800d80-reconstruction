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

extern uint32_t off_119304;
extern uint32_t dword_1192FC;
extern uint32_t dword_119300;

// btm_acl_update @ 0x11927c, size 126 bytes
int  btm_acl_update(int a1, int16_t a2, int a3, int16_t a4, uint8_t a5)
{
  int *v5; // r7
  int v6; // r6
  int v7; // r4
  int v8; // t1
  int16_t v9; // r12
  int v11; // r0
  int v12; // r4
  int v13; // r6
  int result; // r0

  v5 = (int *)off_119304;
  v6 = dword_1192FC + 696 * a3;
  v7 = dword_119300 + 1320 * *(uint8_t *)(v6 + 34);
  v8 = *(uint32_t *)(v6 + 38);
  v9 = *(uint16_t *)(v7 + 104);
  v11 = *(uint32_t *)(v7 + 100);
  *(uint16_t *)(a1 + 160) = *(uint16_t *)(v6 + 42);
  *(uint32_t *)(a1 + 120) = a1 + 172;
  *(uint32_t *)(a1 + 88) = 0;
  *(uint32_t *)(a1 + 144) = 0;
  v12 = *v5;
  v13 = *v5;
  *(uint32_t *)(a1 + 162) = v11;
  result = (a5 << 7) | 0x808;
  *(uint32_t *)(a1 + 156) = v8;
  *(uint32_t *)(a1 + 208) = (uint16_t)((uint16_t)v12 << 8) | (uint8_t)v13;
  *(uint16_t *)(a1 + 166) = v9;
  *(uint16_t *)(a1 + 168) = (a4 << 12) | 4;
  *(uint16_t *)(a1 + 170) = 16 * a2;
  *(uint32_t *)(a1 + 192) = result;
  return result;
}

