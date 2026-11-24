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


extern uint32_t dword_12D7B8;
extern uint32_t dword_12D7C4;
extern uint32_t dword_12D7C8;
extern uint32_t off_12D7C0;

// sub_12D748 @ 0x12d748, size 110 bytes
int  sub_12D748(int a1)
{
  int *v1; // r5
  uint64_t v3; // r0
  uint64_t v4; // r0
  uint64_t v5; // r2
  uint64_t v6; // r0
  uint64_t v7; // r2
  uint64_t v8; // r0
  unsigned int v9; // r0
  uint32_t v11[32]; // [sp+0h] [bp-104h] BYREF
  char v12[132]; // [sp+80h] [bp-84h] BYREF

  v1 = (int *)off_12D7C0;
  sub_14380C((char *)v11, (char *)off_12D7C0, 0x80u);
  sub_14380C(v12, (char *)v1 + 128, 0x80u);
  v3 = sub_142A94(a1);
  v4 = sub_142B44(v3, *(uint64_t *)&dword_12D7B8);
  HIDWORD(v5) = dword_12D7C4;
  LODWORD(v5) = 0;
  v6 = sub_142B44(v4, v5);
  HIDWORD(v7) = dword_12D7C8;
  LODWORD(v7) = 0;
  v8 = sub_1427D8(v6, v7);
  v9 = sub_143078(v8);
  return v9 & 0x7F800000
       | ((((v9 & 0x7FFFFF) * (uint64_t)(int)v11[(v9 >> 18) & 0x1F]) >> 23) + *(uint32_t *)&v12[4 * ((v9 >> 18) & 0x1F)]);
}
