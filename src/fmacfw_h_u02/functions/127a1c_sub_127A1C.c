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

extern uint32_t off_127BDC;
extern uint32_t dword_127BE0;
extern uint32_t off_127BF0;
extern uint32_t dword_127BE4;
extern uint32_t dword_127BEC;
extern uint32_t off_127BE8;

// cfm_event_handler @ 0x127a1c, size 446 bytes
int  cfm_event_handler(uint8_t *a1, int a2)
{
  uint8_t *v2; // r7
  int v5; // r5
  unsigned int v6; // r3
  uint32_t *v7; // r8
  char v8; // r3
  uint8_t *v10; // r8
  char v11; // r3
  int v12; // r0
  uint8_t *v13; // r2
  int16_t v14; // r1
  unsigned int v15; // r1
  int v16; // r2
  int v17; // r0
  int v18; // r0

  v2 = off_127BDC;
  check_feature_flag(8, dword_127BE0);
  v5 = *a1;
  if ( *a1 )
  {
    if ( v5 == 1 )
    {
      if ( (uint8_t)v2[136] == 255 )
        return 0;
      v6 = (uint8_t)v2[128];
      v7 = off_127BF0;
      if ( v6 > 3 )
      {
        if ( v6 == 4 )
        {
          mem_set_util((int)off_127BF0 + 64);
          v12 = v7[8];
          v7[18] = 0;
          llc_version_read(v12);
        }
      }
      else if ( v6 > 1 )
      {
        v13 = *((uint8_t **)off_127BF0 + 11);
        *((uint8_t *)off_127BF0 + 88) &= ~4u;
        if ( v13 )
        {
          if ( v13 == v2 + 112 && (uint8_t *)v7[20] == v13 )
          {
            mem_set_util((int)(v7 + 16));
            v7[18] = 0;
          }
          v7[11] = 0;
        }
        ipc_post_msg(dword_127BE4);
      }
      else if ( v6 == 1 )
      {
        *((uint8_t *)off_127BF0 + 88) &= 0xFAu;
        ipc_post_msg((int)(v2 + 112));
      }
      v8 = *((uint8_t *)v7 + 88);
      v2[136] = -1;
      if ( (v8 & 0x12) != 0x10 )
        return 0;
      v18 = dword_127BEC;
      *((uint8_t *)v7 + 88) = v8 & 0xEF;
      v5 = 0;
      mem_set_util(v18);
      return v5;
    }
    return 1;
  }
  if ( (uint8_t)v2[136] != 255 || v2[128] == 4 || hci_cmd_handler(4) == 1 )
  {
    v10 = off_127BF0;
    v11 = *((uint8_t *)off_127BF0 + 88);
    if ( (v11 & 0x20) == 0 )
      return 1;
  }
  else
  {
    v10 = off_127BF0;
    if ( !*((uint8_t *)off_127BF0 + 91) )
    {
      v11 = *((uint8_t *)off_127BF0 + 88);
      goto LABEL_25;
    }
    v11 = *((uint8_t *)off_127BF0 + 88);
    if ( (v11 & 0x20) == 0 )
    {
LABEL_25:
      v2[136] = 4;
      v2[116] = a1[2];
      v2[117] = a1[3];
      v14 = *((uint16_t *)a1 + 3);
      *((uint16_t *)v2 + 59) = *((uint16_t *)a1 + 2);
      *((uint16_t *)v2 + 61) = *((uint16_t *)a1 + 4);
      *((uint16_t *)v2 + 60) = v14;
      v2[124] = a1[16];
      v2[128] = 1;
      v2[125] = 0;
      v15 = *((uint32_t *)a1 + 3);
      *((uint16_t *)v2 + 63) = a2;
      v16 = 1000 * v15;
      if ( v15 > 0x23 )
        v16 -= 35000;
      *((uint32_t *)v2 + 33) = v16;
      v2[138] = a1[1];
      if ( a2 )
      {
        v10[88] = v11 | 1;
        llc_flag_test_bit4();
      }
      else
      {
        v17 = dword_127BE4;
        v10[88] = v11 | 4;
        llc_hw_reg_sync(v17);
      }
      *(uint32_t *)off_127BE8 |= 4u;
      return v5;
    }
  }
  v10[88] = v11 & 0xDF;
  return 1;
}

