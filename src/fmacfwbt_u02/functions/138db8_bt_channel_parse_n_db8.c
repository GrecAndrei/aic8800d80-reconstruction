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

extern uint32_t off_138E14;
extern uint32_t off_138E18;

// rf_cal_freq_from_channel @ 0x138db8, size 92 bytes
// Doc: rf_cal_freq_from_channel [bt]: Parses channel/band info from BT config block into output
// rf_cal_freq_from_channel [bt]: Parses channel/band info from BT config block into output
uint32_t * rf_cal_freq_from_channel(int a1, int16_t a2)
{
  uint32_t *v2; // r6
  int16_t v4; // r5
  unsigned int v5; // r3
  unsigned int v6; // r3

  v2 = off_138E14;
  v4 = a2;
  if ( *((uint8_t *)off_138E18 + 16) != 255 )
  {
    v4 = a2 | 0x80;
LABEL_3:
    v5 = (*((uint8_t *)off_138E14 + 10) << 8)
       | (*((uint8_t *)off_138E14 + 9) << 16)
       | (*((uint8_t *)off_138E14 + 11) << 24)
       | *(uint32_t *)(a1 + 96)
       | 0x80;
    goto LABEL_4;
  }
  if ( (a2 & 0x80) != 0 )
    goto LABEL_3;
  v5 = (*((uint8_t *)off_138E14 + 10) << 8)
     | (*((uint8_t *)off_138E14 + 9) << 16)
     | (*((uint8_t *)off_138E14 + 11) << 24)
     | *(uint32_t *)(a1 + 96) & 0xFFFFFF7F;
LABEL_4:
  if ( (v4 & 1) != 0 )
    v6 = v5 | 0x40;
  else
    v6 = v5 & 0xFFFFFFBF;
  *(uint32_t *)(a1 + 96) = v6;
  rx_packet_setup(a1);
  return tx_power_cal_read(a1, v4, v2[16]);
}

