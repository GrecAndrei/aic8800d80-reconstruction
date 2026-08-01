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

extern uint32_t off_11BE50;
extern uint32_t dword_11BE54;
extern uint32_t dword_11BE58;
extern uint32_t dword_11BE5C;
extern uint32_t dword_11BE60;
extern uint32_t dword_11BE68;
extern uint32_t off_11BE64;

// rx_queue_process @ 0x11bda0, size 174 bytes
int rx_queue_process()
{
  uint32_t *v0; // r4
  int v1; // r6
  int v2; // r7
  int v3; // r5
  char v4; // r8
  char *v5; // r3
  uint32_t *v6; // r2
  int result; // r0
  char v8; // r1
  int v9; // r3
  int v10; // r1
  void *v11; // r0
  uint32_t v12[28]; // [sp+0h] [bp-90h] BYREF
  char v13; // [sp+70h] [bp-20h] BYREF

  v0 = off_11BE50;
  v1 = *((uint32_t *)off_11BE50 + 1);
  if ( v1 )
  {
    v2 = *((uint32_t *)off_11BE50 + 2);
    mem_set_util(off_11BE50);
    v3 = v0[4];
    if ( v3 )
      goto LABEL_3;
  }
  else
  {
    v3 = *((uint32_t *)off_11BE50 + 4);
    v2 = 0;
    if ( v3 )
    {
LABEL_3:
      memcpy(v12, dword_11BE54, 144);
      v4 = *((uint8_t *)v0 + 160);
      if ( v12[1] )
        mem_set_util(dword_11BE54);
      if ( v12[8] )
        mem_set_util(dword_11BE58);
      if ( v12[15] )
        mem_set_util(dword_11BE5C);
      if ( v12[22] )
        mem_set_util(dword_11BE60);
      wifi_core_init();
      v0[4] = v3;
      *((uint8_t *)v0 + 160) = v4;
      v0 = off_11BE50;
      v5 = (char *)v12;
      v6 = off_11BE50;
      do
      {
        result = *((uint32_t *)v5 + 5);
        v8 = v5[24];
        v6[10] = result;
        v5 += 28;
        *((uint8_t *)v6 + 44) = v8;
        v6 += 7;
      }
      while ( &v13 != v5 );
      if ( v1 )
        goto LABEL_14;
      return result;
    }
  }
  result = wifi_core_init();
  v0[4] = v3;
  if ( v1 )
  {
LABEL_14:
    v9 = dword_11BE68;
    v10 = *((uint32_t *)off_11BE64 + 4);
    v11 = off_11BE50;
    v0[2] = v2;
    v0[1] = v9;
    return mem_copy_util(v11, v10 + 5000);
  }
  return result;
}

