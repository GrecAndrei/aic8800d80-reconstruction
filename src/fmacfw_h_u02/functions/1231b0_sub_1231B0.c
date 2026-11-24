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


extern uint32_t off_123414;

// bt_patch_apply @ 0x1231b0, size 612 bytes
int  bt_patch_apply(int a1, int a2, int a3, int a4)
{
  int v6; // r8
  int v7; // r9
  unsigned int v8; // r4
  unsigned int v9; // t1
  int v11; // r3
  unsigned int v12; // r5
  int v13; // r6
  void ( *v14)(unsigned int, int, unsigned int, int); // r0
  void ( *v15)(unsigned int, int, unsigned int, int); // r10
  int v16; // [sp+40h] [bp-2Ch]
  int v17; // [sp+4Ch] [bp-20h]
  char v18[5]; // [sp+67h] [bp-5h] BYREF

  *(uint8_t *)off_123414 = 1;
  alloc_tx_event("%s: %d\n", aMmSetResumeRes, 708);
  alloc_tx_event(
    "offset: %d %d %d %d | %d %d %d %d | %d %d %d %d | %d %d %d %d\n",
    0,
    4,
    73,
    83,
    112,
    136,
    248,
    504,
    520,
    592,
    640,
    660,
    670,
    702,
    703,
    704);
  alloc_tx_event("sizeof %d, %d, %d, %d\n", 32, 44, 108, 112);
  if ( *(uint8_t *)(a2 + 702) )
  {
    v6 = 0;
    v17 = 0;
    v7 = a2 + 668;
    while ( 1 )
    {
      while ( 1 )
      {
        v9 = *(uint16_t *)(v7 + 2);
        v7 += 2;
        v8 = v9;
        alloc_tx_event("sub_msg_id: 0x%x\n", v9);
        if ( v9 <= 0x89 )
          break;
        if ( v8 == 5120 )
        {
          v11 = 5;
          v13 = a2 + 136;
          v12 = 5;
          goto LABEL_12;
        }
        if ( v8 == 5122 )
        {
          v11 = 5;
          v13 = a2 + 248;
          v12 = 5;
          goto LABEL_12;
        }
LABEL_16:
        alloc_tx_event("skip sub_msg_id: 0x%x\n", v8);
        if ( *(uint8_t *)(a2 + 702) <= ++v6 )
          goto LABEL_9;
      }
      if ( v8 > 0x64 )
      {
        switch ( v8 )
        {
          case 0x65u:
            v11 = 0;
            v13 = a2 + 504;
            v12 = 0;
            goto LABEL_12;
          case 0x69u:
            v11 = 0;
            v13 = a2 + 112;
            v12 = 0;
            goto LABEL_12;
          case 0x77u:
            v11 = 0;
            v13 = a2 + 4;
            v12 = 0;
            goto LABEL_12;
          case 0x79u:
            v11 = 0;
            v13 = a2 + 83;
            v12 = 0;
            goto LABEL_12;
          case 0x7Bu:
            v11 = 0;
            v12 = 0;
            v13 = a2;
            goto LABEL_12;
          case 0x87u:
            v11 = 0;
            v13 = a2 + 12 * v17 + 592;
            v17 = (uint8_t)(v17 + 1);
            v12 = 0;
            goto LABEL_12;
          case 0x89u:
            v11 = 0;
            v13 = a2 + 73;
            v12 = 0;
            goto LABEL_12;
          default:
            goto LABEL_16;
        }
      }
      if ( v8 == 2 )
      {
        v11 = 0;
        v13 = a2 + 520;
        v12 = 0;
        goto LABEL_12;
      }
      if ( v8 == 6 )
      {
        alloc_tx_event(
          "add vif req:cnt=%d, p2p=%d, macaddr=%x,%x,%x\n",
          *(uint32_t *)(a2 + 704),
          *(uint8_t *)(a2 + 668),
          *(uint16_t *)(a2 + 662),
          *(uint16_t *)(a2 + 664),
          *(uint16_t *)(a2 + 666));
        if ( *(uint32_t *)(a2 + 704) )
        {
          transmit_radio_packet(
            a2 + 662,
            *(uint8_t *)(a2 + 660),
            *(uint8_t *)(a2 + 668),
            (uint8_t *)v18);
          if ( *(uint8_t *)(a2 + 702) <= ++v6 )
            break;
        }
        else if ( *(uint8_t *)(a2 + 702) <= ++v6 )
        {
          break;
        }
      }
      else
      {
        if ( v8 )
          goto LABEL_16;
        v12 = 0;
        v11 = 0;
        v13 = 0;
LABEL_12:
        v16 = v11;
        v14 = (void ( *)(unsigned int, int, unsigned int, int))hci_event_handler(v8, v12);
        v15 = v14;
        if ( v14 )
        {
          alloc_tx_event("func %p for msg_id:0x%x dest_id:0x%x\n", v14, v8, v16);
          v15(v8, v13, v12, a4);
          if ( *(uint8_t *)(a2 + 702) <= ++v6 )
            break;
        }
        else
        {
          alloc_tx_event("func not found for msg_id:0x%x dest_id:0x%x\n", v8, v16);
          if ( *(uint8_t *)(a2 + 702) <= ++v6 )
            break;
        }
      }
    }
  }
LABEL_9:
  *(uint8_t *)off_123414 = 0;
  return 0;
}
