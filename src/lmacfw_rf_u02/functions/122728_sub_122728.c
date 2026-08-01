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

extern uint32_t off_122A40;
extern uint32_t dword_122C80;
extern uint32_t dword_122C78;
extern uint32_t off_122C60;
extern uint32_t dword_122C7C;
extern uint32_t dword_122C5C;
extern uint32_t dword_122A88;
extern uint32_t off_122A50;
extern uint32_t dword_122A8C;
extern uint32_t off_122A74;
extern uint32_t dword_122C8C;
extern uint32_t dword_122C88;
extern uint32_t dword_122A6C;
extern uint32_t off_122A64;
extern uint32_t dword_122A70;
extern uint32_t dword_122A58;
extern uint32_t dword_122C4C;
extern uint32_t off_122C50;
extern uint32_t dword_122C54;
extern uint32_t dword_122C84;
extern uint32_t dword_122A78;
extern uint32_t dword_122A48;
extern uint32_t dword_122A7C;
extern uint32_t dword_122C90;
extern uint32_t dword_122C58;
extern uint32_t dword_122C64;
extern uint32_t dword_122C68;
extern uint32_t dword_122C6C;
extern uint32_t dword_122A80;
extern uint32_t dword_122C70;
extern uint32_t dword_122C74;
extern uint32_t dword_122A84;
extern uint32_t dword_122A94;
extern uint32_t dword_122A68;
extern uint32_t dword_122A54;
extern uint32_t dword_122A5C;
extern uint32_t dword_122A44;
extern uint32_t dword_122A90;
extern uint32_t dword_122A4C;
extern uint32_t dword_122A60;

// init_system @ 0x122728, size 1314 bytes
int  init_system(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int v4; // r4
  int v5; // r5
  uint32_t *v6; // r6
  int v7; // r9
  int v8; // r10
  uint8_t *v9; // r8
  int v10; // r7
  int v11; // r4
  int v12; // r1
  uint32_t *v13; // r6
  int v14; // r9
  int k; // r8
  int v16; // r11
  uint8_t *v17; // r7
  int v18; // r5
  int v19; // r4
  int v20; // r1
  int v25; // r0
  char v26; // r4
  int v27; // r0
  int v28; // r9
  unsigned int v29; // r1
  int v30; // r3
  int v31; // r10
  int *v32; // r6
  int v33; // r9
  char *v34; // r7
  uint8_t *v35; // r11
  int j; // r5
  char v37; // t1
  int v38; // r3
  int v39; // r3
  int v40; // r6
  int v41; // r3
  uint8_t *v42; // r6
  unsigned int v43; // r1
  int v44; // r3
  int v45; // r6
  int v46; // r3
  uint8_t *v47; // r6
  int v48; // r5
  uint32_t *v49; // r6
  int v50; // r10
  int v51; // r8
  uint8_t *v52; // r11
  char *v53; // r7
  uint8_t *v54; // r9
  int i; // r5
  char v56; // t1
  int v57; // r3
  int v58; // r0
  char v59; // r4
  int v60; // r0
  int v61; // r9
  int v62; // [sp+0h] [bp-2Ch]
  int v63; // [sp+0h] [bp-2Ch]
  int v64; // [sp+0h] [bp-2Ch]
  uint32_t *v65; // [sp+0h] [bp-2Ch]
  int *v66; // [sp+4h] [bp-28h]
  uint32_t v67[3]; // [sp+8h] [bp-24h] BYREF
  int v68; // [sp+14h] [bp-18h] BYREF
  int v69; // [sp+18h] [bp-14h]
  int v70; // [sp+1Ch] [bp-10h]
  int v71; // [sp+20h] [bp-Ch]
  int v72; // [sp+24h] [bp-8h]
  uint8_t v73[4]; // [sp+28h] [bp-4h] BYREF

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
            v58 = tx_packet_prepare(a2, a3, a4);
            v59 = v58;
            if ( v58 < 0 )
            {
              dispatch_event_handler(dword_122C80);
              v61 = 2 * a2;
            }
            else
            {
              dispatch_event_handler(dword_122C78, a2, a3, a4);
              *(uint8_t *)(*(uint32_t *)off_122C60 + 3 * a2 + a3) = a4;
              v60 = tx_desc_build(a2, a3, &v68);
              v59 = v60;
              v61 = 2 * a2;
              if ( (char)v68 == a4 )
                mmio_reg_write_1b(v5);
              else
                dispatch_event_handler(dword_122C7C, (char)v68, v60);
            }
            *(uint8_t *)(dword_122C5C + a2 + v61 + a3) = v59;
          }
          else
          {
            v68 = 0;
            v69 = 0;
            v70 = 0;
            bus_read_12((int)&v68);
            dispatch_event_handler(dword_122A88, a2, a3, a4);
            v40 = 3 * a2;
            v41 = *(uint32_t *)off_122A50 + v40;
            v42 = &v73[v40 + a3];
            *(uint8_t *)(v41 + a3) = a4;
            *(v42 - 20) = a4;
            mmio_write_2((int)&v68);
            bus_read_12((int)&v68);
            if ( (char)*(v42 - 20) == a4 )
            {
              v67[0] = 0;
              mmio_write_128((int)v67);
            }
            else
            {
              dispatch_event_handler(dword_122A8C);
            }
          }
          v43 = *((uint16_t *)off_122A74 + 20);
          if ( v43 <= 0x97B )
          {
            v44 = 0;
          }
          else if ( v43 > 0x994 )
          {
            v44 = 2;
          }
          else
          {
            v44 = 1;
          }
          if ( !*((uint8_t *)off_122A74 + 36) && v44 == a3 )
          {
            rf_ctrl_set(*((uint8_t *)off_122A74 + 36), v43);
            return 0;
          }
          return 0;
        }
LABEL_78:
        dispatch_event_handler(dword_122C8C);
        return -11;
      }
    }
    else
    {
      if ( a1 != 2 )
      {
        dispatch_event_handler(dword_122C88);
        return -21;
      }
      if ( a2 <= 2 && a3 <= 5 )
      {
        if ( (uint8_t)(a4 + 7) <= 0xEu )
        {
          if ( v4 )
          {
            v25 = rx_packet_prepare(a2, a3, a4);
            v26 = v25;
            if ( v25 < 0 )
            {
              dispatch_event_handler(dword_122C80);
              v28 = 2 * a2;
            }
            else
            {
              dispatch_event_handler(dword_122A6C, a2, a3, a4);
              *(uint8_t *)(*(uint32_t *)off_122A64 + 6 * a2 + a3) = a4;
              v27 = rx_desc_build(a2, a3, &v68);
              v26 = v27;
              v28 = 2 * a2;
              if ( (char)v68 == a4 )
                mmio_reg_write_1b(1);
              else
                dispatch_event_handler(dword_122A70, (char)v68, v27);
            }
            *(uint8_t *)(dword_122A58 + 2 * (a2 + v28) + a3) = v26;
          }
          else
          {
            v68 = 0;
            v69 = 0;
            v70 = 0;
            v71 = 0;
            v72 = 0;
            mmio_read_4((int)&v68);
            dispatch_event_handler(dword_122C4C, a2, a3, a4);
            v45 = 3 * a2;
            v46 = *(uint32_t *)off_122C50 + 2 * v45;
            v47 = &v73[2 * v45 + a3];
            *(uint8_t *)(v46 + a3) = a4;
            *(v47 - 20) = a4;
            mmio_write_4((int)&v68);
            mmio_read_4((int)&v68);
            if ( (char)*(v47 - 20) == a4 )
            {
              v67[0] = 0;
              mmio_write_128((int)v67);
            }
            else
            {
              dispatch_event_handler(dword_122C54);
            }
          }
          v29 = *((uint16_t *)off_122A74 + 20);
          if ( v29 > 0x1666 )
          {
            v30 = 5;
          }
          else if ( v29 > 0x1616 )
          {
            v30 = 4;
          }
          else if ( v29 > 0x15C6 )
          {
            v30 = 3;
          }
          else if ( v29 > 0x1571 )
          {
            v30 = 2;
          }
          else
          {
            v30 = v29 > 0x1486;
          }
          if ( *((uint8_t *)off_122A74 + 36) == 1 && v30 == a3 )
            rf_ctrl_set(1, v29);
          return 0;
        }
        goto LABEL_78;
      }
    }
    dispatch_event_handler(dword_122C84);
    return -12;
  }
  if ( !v4 )
  {
    memset(v67, 0, sizeof(v67));
    v69 = 0;
    v70 = 0;
    v71 = 0;
    v72 = 0;
    v68 = 0;
    dispatch_event_handler(dword_122A78);
    if ( bus_read_12((int)v67) )
    {
      sub_100200((int *)dword_122A48, 0xFu, 9u);
      dispatch_event_handler(dword_122A7C);
    }
    else
    {
      v48 = dword_122C5C;
      v49 = off_122C60;
      v50 = dword_122C90;
      dispatch_event_handler(dword_122C58);
      dispatch_event_handler(dword_122C64);
      v51 = 0;
      v65 = v67;
      v52 = (uint8_t *)v48;
      do
      {
        dispatch_event_handler(dword_122C68, v51);
        v53 = (char *)v65;
        v54 = v52;
        for ( i = 0; i != 3; ++i )
        {
          v56 = *v53++;
          *(uint8_t *)(*v49 + i + 3 * v51) = v56;
          v57 = *v49 + i;
          *v54++ = 15;
          dispatch_event_handler(v50, *(char *)(v57 + 3 * v51));
        }
        ++v51;
        v65 = (uint32_t *)((char *)v65 + 3);
        v52 += 3;
      }
      while ( v51 != 3 );
      dispatch_event_handler(dword_122C6C);
    }
    dispatch_event_handler(dword_122A80);
    v31 = mmio_read_4((int)&v68);
    if ( v31 )
    {
      sub_100200((int *)dword_122C70, 0xFu, 0x12u);
      dispatch_event_handler(dword_122C74);
    }
    else
    {
      v64 = dword_122A58;
      dispatch_event_handler(dword_122A84);
      v32 = (int *)off_122A64;
      v33 = dword_122A94;
      dispatch_event_handler(dword_122A68);
      v66 = &v68;
      do
      {
        dispatch_event_handler(dword_122A54, v31);
        v35 = (uint8_t *)v64;
        v34 = (char *)v66;
        for ( j = 0; j != 6; ++j )
        {
          v37 = *v34++;
          *(uint8_t *)(*v32 + j + v4) = v37;
          v38 = *v32;
          *v35++ = 15;
          v39 = v38 + j;
          dispatch_event_handler(v33, *(char *)(v39 + v4));
        }
        v66 = (int *)((char *)v66 + 6);
        v4 += 6;
        ++v31;
        v64 += 6;
      }
      while ( v4 != 18 );
      dispatch_event_handler(dword_122A5C);
    }
    return 0;
  }
  v62 = dword_122A48;
  dispatch_event_handler(dword_122A44);
  v6 = off_122A50;
  v7 = dword_122A90;
  dispatch_event_handler(dword_122A4C);
  do
  {
    v8 = tx_desc_init(v5, *v6 + 3 * v5);
    dispatch_event_handler(dword_122A54, v5);
    v9 = (uint8_t *)v62;
    v10 = 0;
    do
    {
      v11 = (v8 >> (4 * v10)) & 0xF;
      v12 = *(char *)(*v6 + v10++ + 3 * v5);
      dispatch_event_handler(v7, v12, v11);
      *v9++ = v11;
    }
    while ( v10 != 3 );
    ++v5;
    v62 += 3;
  }
  while ( v5 != 3 );
  v63 = dword_122A58;
  dispatch_event_handler(dword_122A5C);
  v13 = off_122A64;
  v14 = dword_122A90;
  dispatch_event_handler(dword_122A60);
  dispatch_event_handler(dword_122A68);
  for ( k = 0; k != 3; ++k )
  {
    v16 = rx_desc_init(k, *v13 + 6 * k);
    dispatch_event_handler(dword_122A54, k);
    v17 = (uint8_t *)v63;
    v18 = 0;
    do
    {
      v19 = (v16 >> (4 * v18)) & 0xF;
      v20 = *(char *)(*v13 + v18++ + 6 * k);
      dispatch_event_handler(v14, v20, v19);
      *v17++ = v19;
    }
    while ( v18 != 6 );
    v63 += 6;
  }
  dispatch_event_handler(dword_122A5C);
  return 0;
}

