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

extern uint32_t off_13BE04;
extern uint32_t dword_13BE10;
extern uint32_t dword_13BE0C;
extern uint32_t dword_13BE08;

// tx_build_frame_header @ 0x13bda4, size 96 bytes
// Doc: tx_build_frame_header [tx]: Builds transmit frame header with shifted control fields and length
// tx_build_frame_header [tx]: Builds transmit frame header with shifted control fields and length
int  tx_build_frame_header(int a1, int a2)
{
  unsigned int v2; // r5
  int *v5; // r4
  int v6; // r1
  int v7; // r3

  v2 = (uint16_t)((uint16_t)a2 << 8) | 8;
  v5 = (int *)sub_12C92C(42, 0, ((uint16_t)a2 << 8) | 8, 3u);
  if ( **(int16_t **)off_13BE04 < 0 && msg_get_value(v2) != 4 )
    sub_12F46C(dword_13BE10, dword_13BE0C, 891);
  v6 = dword_13BE08 + 32 * a2;
  v7 = *(uint8_t *)(v6 + 17);
  v5[1] = a1;
  *v5 = v7 != 1;
  v5[2] = *(uint8_t *)(v6 + 22);
  return sdio_buffer_prepare_n_4e8((int)v5);
}

