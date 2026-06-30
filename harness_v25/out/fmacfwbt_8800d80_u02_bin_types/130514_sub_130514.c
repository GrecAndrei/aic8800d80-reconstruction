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

extern uint32_t off_130580;
extern uint32_t dword_130588;
extern uint32_t dword_130584;

// sub_130514 @ 0x130514, size 108 bytes
int  sub_130514(int a1)
{
  uint8_t *v1; // r3
  int v2; // r2
  int v3; // r0
  char v4; // lr
  char v5; // r9
  char v6; // r8
  char v7; // r5
  int v8; // r7
  int v9; // r6
  char v10; // r4
  char v11; // r12
  char v12; // r1

  v1 = off_130580;
  v2 = *((char *)off_130580 + 2) + 7;
  v3 = a1 + 7;
  v4 = *(uint8_t *)(dword_130588 + v2);
  v5 = *(uint8_t *)(dword_130584 + v2 + 16);
  v6 = *(uint8_t *)(dword_130584 + v2 + 32);
  v7 = *(uint8_t *)(dword_130584 + v3 + 16);
  v8 = dword_130588 + v2;
  LOBYTE(v2) = *(uint8_t *)(dword_130584 + v3) - *(uint8_t *)(dword_130584 + v2);
  v9 = dword_130588 + v3;
  v10 = *(uint8_t *)(dword_130584 + v3 + 32);
  LOBYTE(v3) = *(uint8_t *)(dword_130588 + v3);
  v11 = *(uint8_t *)(v8 + 16);
  v12 = *(uint8_t *)(v9 + 16);
  LOBYTE(v8) = *(uint8_t *)(v8 + 32);
  *((uint8_t *)off_130580 + 8) = v2;
  LOBYTE(v2) = *(uint8_t *)(v9 + 32) - v8;
  v1[9] = v7 - v5;
  v1[10] = v10 - v6;
  v1[11] = v3 - v4;
  v1[12] = v12 - v11;
  v1[13] = v2;
  return rf_msg_handler_n_13a();
}

