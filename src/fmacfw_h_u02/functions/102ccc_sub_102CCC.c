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


extern uint32_t dword_102DEC;
extern uint32_t dword_102DF8;
extern uint32_t off_102DE8;
extern uint32_t off_151B28;
extern uint64_t qword_102DFC;

// uart_driver_send @ 0x102ccc, size 282 bytes
int  uart_driver_send(int a1, uint16_t *a2)
{
  unsigned int v4; // r11
  int v5; // r8
  int v6; // r10
  unsigned int *v7; // r6
  int v8; // r5
  uint16_t *v9; // r7
  unsigned int v10; // r4
  int v11; // t1
  unsigned int v12; // r4
  int v13; // r3
  int result; // r0
  int v15; // r4
  uint16_t v16; // r12
  char *v17; // r7
  int v18; // r6
  char *v19; // r12
  int v20; // r3
  uint16_t *v21; // r1
  int v22; // t1
  int v23; // [sp+8h] [bp-24h]
  uint16_t *v24; // [sp+Ch] [bp-20h]
  uint64_t v25; // [sp+14h] [bp-18h] BYREF
  int *v26; // [sp+1Ch] [bp-10h]

  while ( !*(uint32_t *)off_102DE8 )
    ;
  v4 = 0;
  rf_clear_control_bit_a(0);
  v5 = dword_102DF8;
  v23 = 0;
  v24 = a2;
  v6 = a1;
  while ( ((1 << v4) & v6) == 0 )
  {
    if ( (uint16_t)v4 == 5 )
      goto LABEL_10;
LABEL_4:
    ++v4;
  }
  v7 = (unsigned int *)(dword_102DEC + (v4 << 9));
  v8 = 0;
  v9 = v24 - 1;
  do
  {
    v10 = *v7;
    check_feature_flag(0x2000, "before %d,%d: dcq/i=%4x\r\n", v4, v8, (uint16_t)(*v7 >> 11));
    v11 = v9[1];
    ++v9;
    v12 = v10 & v5 | (v11 << 11);
    *v7 = v12;
    v7 += 8;
    v13 = v8++;
    check_feature_flag(0x2000, "after  %d,%d: dcq/i=%4x\r\n", v4, v13, (uint16_t)(v12 >> 11));
  }
  while ( v8 != 16 );
  if ( v4 <= 1 )
    goto LABEL_4;
  v23 = 1;
  if ( (uint16_t)v4 != 5 )
    goto LABEL_4;
LABEL_10:
  result = rf_clear_control_bit_b(0);
  *(uint32_t *)off_102DE8 = 1;
  if ( v23 )
  {
    v15 = *(uint32_t *)aT;
    v25 = *(uint64_t *)aT;
    v26 = (int *)off_151B28;
    v16 = 3;
  }
  else
  {
    v15 = qword_102DFC;
    v26 = nullptr;
    v25 = qword_102DFC;
    v16 = 2;
  }
  v17 = (char *)&v25 + 4;
  v18 = dword_102DF8;
  v19 = (char *)&v25 + 4 * (uint16_t)(v16 - 1) + 4;
  while ( 1 )
  {
    v20 = v15;
    v21 = v24;
    do
    {
      if ( v15 )
      {
        result = *v21;
        *(uint32_t *)(v20 + 16) = *(uint32_t *)(v20 + 16) & v18 | (result << 11);
      }
      v20 += 20;
      ++v21;
    }
    while ( v15 + 320 != v20 );
    if ( v19 == v17 )
      break;
    v22 = *(uint32_t *)v17;
    v17 += 4;
    v15 = v22;
  }
  return result;
}
