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


extern uint32_t dword_122A48;
extern uint32_t dword_122A58;
extern uint32_t dword_122C5C;
extern uint32_t dword_122C70;
extern uint32_t off_122A40;
extern uint32_t off_122A50;
extern uint32_t off_122A5C;
extern uint32_t off_122A64;
extern uint32_t off_122A74;
extern uint32_t off_122C50;
extern uint32_t off_122C60;
extern uint32_t off_122C6C;

// init_system @ 0x122728, size 1314 bytes
int  init_system(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  uint32_t *v6; // r6
  int v7; // r10
  uint8_t *v8; // r8
  int v9; // r7
  int v10; // r4
  int v11; // r1
  uint32_t *v12; // r6
  int k; // r8
  int v14; // r11
  uint8_t *v15; // r7
  int v16; // r5
  int v17; // r4
  int v18; // r1
  int v23; // r0
  char v24; // r4
  int v25; // r0
  unsigned int v26; // r9
  unsigned int v27; // r1
  int v28; // r3
  int v29; // r10
  int *v30; // r6
  char *v31; // r7
  uint8_t *v32; // r11
  int j; // r5
  char v34; // t1
  int v35; // r3
  int v36; // r3
  unsigned int v37; // r6
  unsigned int v38; // r3
  uint8_t *v39; // r6
  int v40; // r1
  unsigned int v41; // r1
  int v42; // r3
  unsigned int v43; // r6
  int v44; // r3
  uint8_t *v45; // r6
  int v46; // r1
  int v47; // r5
  uint32_t *v48; // r6
  int v49; // r8
  uint8_t *v50; // r11
  char *v51; // r7
  uint8_t *v52; // r9
  int i; // r5
  char v54; // t1
  int v55; // r3
  int v56; // r0
  char v57; // r4
  int v58; // r0
  unsigned int v59; // r9
  int v60; // [sp+0h] [bp-2Ch]
  int v61; // [sp+0h] [bp-2Ch]
  int v62; // [sp+0h] [bp-2Ch]
  uint32_t *v63; // [sp+0h] [bp-2Ch]
  int *p_a3a; // [sp+4h] [bp-28h]
  uint32_t v65[3]; // [sp+8h] [bp-24h] BYREF
  int a3a; // [sp+14h] [bp-18h] BYREF
  int v67; // [sp+18h] [bp-14h]
  int v68; // [sp+1Ch] [bp-10h]
  int v69; // [sp+20h] [bp-Ch]
  int v70; // [sp+24h] [bp-8h]
  uint8_t v71[4]; // [sp+28h] [bp-4h] BYREF

  v4 = HIBYTE(*(uint32_t *)off_122A40) & 2;
  v5 = a1;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      if ( a2 <= 2 && a3 <= 2 )
      {
        if ( (uint8_t)(a4 + 7) <= 0xEu )
        {
          if ( v4 )
          {
            v56 = tx_packet_prepare(a2, a3, a4);
            v57 = v56;
            if ( v56 < 0 )
            {
              dispatch_event_handler_1(aNoRoom);
              v59 = 2 * a2;
            }
            else
            {
              dispatch_event_handler_1("set ef_pwrofst2x_2.4g:\n  [%d][%d]=%d\n", a2, a3, a4);
              *(uint8_t *)(*(uint32_t *)off_122C60 + 3 * a2 + a3) = a4;
              v58 = tx_desc_build(a2, a3, &a3a);
              v57 = v58;
              v59 = 2 * a2;
              if ( (char)a3a == a4 )
                mmio_reg_write_1b(v5);
              else
                dispatch_event_handler_1("failed to set, rd=%d(rem:%d)\n", (char)a3a, v58);
            }
            *(uint8_t *)(dword_122C5C + a2 + v59 + a3) = v57;
          }
          else
          {
            a3a = 0;
            v67 = 0;
            v68 = 0;
            bus_read_12((int)&a3a);
            dispatch_event_handler_1("set fl_pwrofst2x_2.4g:\n  [%d][%d]=%d\n", a2, a3, a4);
            v37 = 3 * a2;
            v38 = *(uint32_t *)off_122A50 + v37;
            v39 = &v71[v37 + a3];
            *(uint8_t *)(v38 + a3) = a4;
            *(v39 - 20) = a4;
            mmio_write_2((int)&a3a);
            bus_read_12((int)&a3a);
            v40 = (char)*(v39 - 20);
            if ( v40 == a4 )
            {
              v65[0] = 0;
              mmio_write_128((int)v65);
            }
            else
            {
              dispatch_event_handler_1("failed to set, rd=%d\n", v40);
            }
          }
          v41 = *((uint16_t *)off_122A74 + 20);
          if ( v41 <= 0x97B )
          {
            v42 = 0;
          }
          else if ( v41 > 0x994 )
          {
            v42 = 2;
          }
          else
          {
            v42 = 1;
          }
          if ( !*((uint8_t *)off_122A74 + 36) && v42 == a3 )
          {
            rf_ctrl_set(*((uint8_t *)off_122A74 + 36), v41);
            return 0;
          }
          return 0;
        }
LABEL_78:
        dispatch_event_handler_1(aWrongOfstVal);
        return -11;
      }
    }
    else
    {
      if ( a1 != 2 )
      {
        dispatch_event_handler_1(aWrongFunc_0);
        return -21;
      }
      if ( a2 <= 2 && a3 <= 5 )
      {
        if ( (uint8_t)(a4 + 7) <= 0xEu )
        {
          if ( v4 )
          {
            v23 = rx_packet_prepare(a2, a3, a4);
            v24 = v23;
            if ( v23 < 0 )
            {
              dispatch_event_handler_1(aNoRoom);
              v26 = 2 * a2;
            }
            else
            {
              dispatch_event_handler_1("set ef_pwrofst2x_5g:\n  [%d][%d]=%d\n", a2, a3, a4);
              *(uint8_t *)(*(uint32_t *)off_122A64 + 6 * a2 + a3) = a4;
              v25 = rx_desc_build(a2, a3, &a3a);
              v24 = v25;
              v26 = 2 * a2;
              if ( (char)a3a == a4 )
                mmio_reg_write_1b(1);
              else
                dispatch_event_handler_1("failed to set, rd=%d(rem:%d)\n", (char)a3a, v25);
            }
            *(uint8_t *)(dword_122A58 + 2 * (a2 + v26) + a3) = v24;
          }
          else
          {
            a3a = 0;
            v67 = 0;
            v68 = 0;
            v69 = 0;
            v70 = 0;
            mmio_read_4((int)&a3a);
            dispatch_event_handler_1("set fl_pwrofst2x_5g:\n  [%d][%d]=%d\n", a2, a3, a4);
            v43 = 3 * a2;
            v44 = *(uint32_t *)off_122C50 + 2 * v43;
            v45 = &v71[2 * v43 + a3];
            *(uint8_t *)(v44 + a3) = a4;
            *(v45 - 20) = a4;
            mmio_write_4((int)&a3a);
            mmio_read_4((int)&a3a);
            v46 = (char)*(v45 - 20);
            if ( v46 == a4 )
            {
              v65[0] = 0;
              mmio_write_128((int)v65);
            }
            else
            {
              dispatch_event_handler_1("failed to set, rd=%d\n", v46);
            }
          }
          v27 = *((uint16_t *)off_122A74 + 20);
          if ( v27 > 0x1666 )
          {
            v28 = 5;
          }
          else if ( v27 > 0x1616 )
          {
            v28 = 4;
          }
          else if ( v27 > 0x15C6 )
          {
            v28 = 3;
          }
          else if ( v27 > 0x1571 )
          {
            v28 = 2;
          }
          else
          {
            v28 = v27 > 0x1486;
          }
          if ( *((uint8_t *)off_122A74 + 36) == 1 && v28 == a3 )
            rf_ctrl_set(1, v27);
          return 0;
        }
        goto LABEL_78;
      }
    }
    dispatch_event_handler_1(aWrongTypeChgrp);
    return -12;
  }
  if ( !v4 )
  {
    memset(v65, 0, sizeof(v65));
    v67 = 0;
    v68 = 0;
    v69 = 0;
    v70 = 0;
    a3a = 0;
    dispatch_event_handler_1(aFlPwrofst2x24g, a2, a3, a4);
    if ( bus_read_12((int)v65) )
    {
      memset_thunk((int *)dword_122A48, 0xFu, 9u);
      dispatch_event_handler_1(aEmpty);
    }
    else
    {
      v47 = dword_122C5C;
      v48 = off_122C60;
      dispatch_event_handler_1(a011b1OfdmHighr);
      dispatch_event_handler_1(aChan14591013);
      v49 = 0;
      v63 = v65;
      v50 = (uint8_t *)v47;
      do
      {
        dispatch_event_handler_1("\n  [%d] =", v49);
        v51 = (char *)v63;
        v52 = v50;
        for ( i = 0; i != 3; ++i )
        {
          v54 = *v51++;
          *(uint8_t *)(*v48 + i + 3 * v49) = v54;
          v55 = *v48 + i;
          *v52++ = 15;
          dispatch_event_handler_1("\t%d", *(char *)(v55 + 3 * v49));
        }
        ++v49;
        v63 = (uint32_t *)((char *)v63 + 3);
        v50 += 3;
      }
      while ( v49 != 3 );
      dispatch_event_handler_1((const char *)off_122C6C);
    }
    dispatch_event_handler_1(aFlPwrofst2x5g);
    v29 = mmio_read_4((int)&a3a);
    if ( v29 )
    {
      memset_thunk((int *)dword_122C70, 0xFu, 0x12u);
      dispatch_event_handler_1(aEmpty);
    }
    else
    {
      v62 = dword_122A58;
      dispatch_event_handler_1(a0OfdmLowrate1O);
      v30 = (int *)off_122A64;
      dispatch_event_handler_1(aChan3650516498);
      p_a3a = &a3a;
      do
      {
        dispatch_event_handler_1("\n  [%d] =", v29);
        v32 = (uint8_t *)v62;
        v31 = (char *)p_a3a;
        for ( j = 0; j != 6; ++j )
        {
          v34 = *v31++;
          *(uint8_t *)(*v30 + j + v4) = v34;
          v35 = *v30;
          *v32++ = 15;
          v36 = v35 + j;
          dispatch_event_handler_1("\t%d", *(char *)(v36 + v4));
        }
        p_a3a = (int *)((char *)p_a3a + 6);
        v4 += 6;
        ++v29;
        v62 += 6;
      }
      while ( v4 != 18 );
      dispatch_event_handler_1((const char *)off_122A5C);
    }
    return 0;
  }
  v60 = dword_122A48;
  dispatch_event_handler_1(aEfPwrofst2x24g, a2, a3);
  v6 = off_122A50;
  dispatch_event_handler_1(aChan14591013);
  do
  {
    v7 = tx_desc_init(v5, *v6 + 3 * v5);
    dispatch_event_handler_1("\n  [%d] =", v5);
    v8 = (uint8_t *)v60;
    v9 = 0;
    do
    {
      v10 = (v7 >> (4 * v9)) & 0xF;
      v11 = *(char *)(*v6 + v9++ + 3 * v5);
      dispatch_event_handler_1("\t%d(r%x)", v11, v10);
      *v8++ = v10;
    }
    while ( v9 != 3 );
    ++v5;
    v60 += 3;
  }
  while ( v5 != 3 );
  v61 = dword_122A58;
  dispatch_event_handler_1((const char *)off_122A5C);
  v12 = off_122A64;
  dispatch_event_handler_1("ef_pwrofst2x_5g: [0]:ofdm_lowrate, [1]:ofdm_highrate, [2]:ofdm_midrate");
  dispatch_event_handler_1(aChan3650516498);
  for ( k = 0; k != 3; ++k )
  {
    v14 = rx_desc_init(k, *v12 + 6 * k);
    dispatch_event_handler_1("\n  [%d] =", k);
    v15 = (uint8_t *)v61;
    v16 = 0;
    do
    {
      v17 = (v14 >> (4 * v16)) & 0xF;
      v18 = *(char *)(*v12 + v16++ + 6 * k);
      dispatch_event_handler_1("\t%d(r%x)", v18, v17);
      *v15++ = v17;
    }
    while ( v16 != 6 );
    v61 += 6;
  }
  dispatch_event_handler_1((const char *)off_122A5C);
  return 0;
}
