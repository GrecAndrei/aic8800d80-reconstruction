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

extern uint32_t off_10C3DC;
extern uint32_t off_10C3D8;
extern uint32_t off_10C3E0;
extern uint32_t off_10C3E4;
extern uint32_t dword_10C3E8;
extern uint32_t off_10C3F8;
extern uint32_t off_10CA80;
extern uint32_t off_10CA7C;
extern uint32_t off_10C3EC;
extern uint32_t off_10C3F0;
extern uint32_t off_10CAA4;
extern uint32_t off_10CAA8;
extern uint32_t off_10C3F4;
extern uint32_t off_10C71C;
extern uint32_t off_10C720;
extern uint32_t off_10C724;
extern uint32_t dword_10C728;
extern uint32_t off_10C72C;
extern uint32_t dword_10C730;
extern uint32_t off_10C734;
extern uint32_t dword_10CA8C;
extern uint32_t dword_10C790;
extern uint32_t off_10C794;
extern uint32_t off_10C738;
extern uint32_t dword_10C798;
extern uint32_t off_10C79C;
extern uint32_t dword_10C73C;
extern uint32_t off_10CA90;
extern uint32_t dword_10CBCC;
extern uint32_t off_10CBDC;
extern uint32_t dword_10CBD0;
extern uint32_t dword_10CBC0;
extern uint32_t dword_10CBC4;
extern uint32_t off_10CBD4;
extern uint32_t dword_10CBC8;
extern uint32_t off_10CBD8;
extern uint32_t dword_10CBB8;
extern uint32_t dword_10CBBC;
extern uint32_t dword_10C740;
extern uint32_t dword_10CA84;
extern uint32_t off_10CA88;
extern uint32_t off_10C744;
extern uint32_t off_10C748;
extern uint32_t off_10C750;
extern uint32_t off_10C74C;
extern uint32_t dword_10C754;
extern uint32_t off_10C758;
extern uint32_t dword_10C75C;
extern uint32_t dword_10C760;
extern uint32_t off_10C764;
extern uint32_t off_10C768;
extern uint32_t dword_10C76C;
extern uint32_t dword_10C770;
extern uint32_t dword_10C774;
extern uint32_t off_10CA94;
extern uint32_t off_10CA98;
extern uint32_t off_10CA9C;

// configure_dma_engine @ 0x10c2e4, size 2260 bytes
void __noreturn configure_dma_engine()
{
  uint8_t *v0; // r0
  int *v1; // r2
  uint32_t *v2; // r3
  int v3; // r5
  uint32_t *v4; // r4
  uint32_t *v5; // r10
  int v6; // r1
  uint32_t *v7; // r3
  uint32_t *v8; // r1
  int v9; // r0
  int v10; // r0
  int v11; // r0
  int inited; // r0
  uint32_t *v13; // r3
  uint32_t *v14; // r1
  uint32_t *v15; // r4
  unsigned int v16; // r0
  int v17; // r2
  int v18; // r0
  int v19; // r1
  int v20; // r4
  void *v21; // r2
  int v22; // r0
  int v23; // r3
  int v24; // r4
  uint8_t *v25; // r8
  uint32_t *v26; // r9
  uint8_t *v27; // r7
  int v28; // r5
  int v29; // r0
  int v30; // r8
  uint32_t *v31; // r9
  int v32; // r4
  int i; // r5
  int v34; // r0
  uint8_t *v35; // r1
  int j; // r3
  int v37; // r2
  unsigned int v38; // r1
  int v39; // r2
  int v40; // r0
  int v41; // r0
  uint32_t *v42; // r4
  uint32_t *v43; // r3
  uint32_t *v44; // r2
  int v45; // r3
  int *v46; // r1
  uint32_t *v47; // r2
  int *v48; // r2
  int v49; // r3
  int v50; // r0
  int v51; // r5
  uint8_t *v52; // r4
  int v53; // r0
  int v54; // r2
  int v55; // r1
  int v56; // r2
  uint8_t *v57; // r7
  int v58; // r1
  int v59; // r2
  unsigned int v60; // r3
  int *v61; // r7
  uint32_t *v62; // r3
  uint32_t *v63; // r1
  uint8_t *v64; // r3
  char v65; // r1
  char v66; // r2
  uint32_t *v67; // r9
  int v68; // r2
  int v69; // r7
  uint32_t *v70; // r6
  int v71; // r9
  char *v72; // r11
  uint8_t *v73; // r8
  int v74; // r5
  int v75; // t1
  int v76; // r0
  int v77; // r1
  int v78; // r1
  int v79; // r5
  uint32_t *v80; // r9
  int v81; // r2
  int v82; // r11
  uint8_t *v83; // r6
  uint32_t *v84; // r4
  char *v85; // r7
  uint8_t *v86; // r9
  int v87; // r5
  int v88; // t1
  int v89; // r0
  int v90; // r3
  int v91; // r1
  uint8_t *v92; // [sp+8h] [bp-A4h]
  uint32_t *v93; // [sp+8h] [bp-A4h]
  uint8_t *v94; // [sp+Ch] [bp-A0h]
  int16_t v95; // [sp+12h] [bp-9Ah] BYREF
  int v96; // [sp+14h] [bp-98h] BYREF
  uint32_t v97[3]; // [sp+18h] [bp-94h] BYREF
  uint8_t v98[136]; // [sp+24h] [bp-88h] BYREF

  v0 = off_10C3DC;
  *((uint32_t *)off_10C3D8 + 64) = 8;
  if ( !v0[2] )
    *((uint32_t *)off_10C3E0 + 2) = *((uint32_t *)off_10C3E0 + 2) & 0xFFF9FFFF | 0x20000;
  v1 = (int *)off_10C3E0;
  while ( (*((uint32_t *)off_10C3E0 + 12) & 0x22) != 2 )
    ;
  v2 = off_10C3E4;
  v3 = dword_10C3E8;
  v4 = off_10C3D8;
  v5 = off_10C3F8;
  *((uint32_t *)off_10C3E0 + 2) = *((uint32_t *)off_10C3E0 + 2) & 0xFFFE73FE | 0x18401;
  *v2 = 6;
  v1[21] = v1[21] & 0x37F | 0x80 | v1[21] & v3;
  v4[81] = 16;
  v6 = *((uint8_t *)v5 + 177);
  *v1 = *v1 & 0x37F | 0x80 | v3 & *v1;
  if ( v6 && (v1[12] & 0x40) == 0 && (v1[12] & 4) != 0 )
  {
    v48 = (int *)off_10CA80;
    v49 = v5[42] | 0x2000000;
    *(uint8_t *)off_10CA7C = 1;
    *v48 = v49;
    v4[14] |= 0x10u;
  }
  else
  {
    *(uint32_t *)off_10C3EC = v5[42];
  }
  if ( v0[2] )
  {
    if ( **(uint8_t **)off_10C3F0 == 2 )
    {
      v62 = off_10CAA4;
      v63 = off_10CAA8;
      *((uint32_t *)off_10CAA4 + 20) |= 0x40000u;
      v63[7] &= ~0x100u;
      v62[9] = v62[9] & 0xFFFFFF00 | 0x60;
      v62[9] = v62[9] & 0xFFFF00FF | 0xDF00;
LABEL_11:
      v10 = panic_fatal();
      if ( !*(uint32_t *)off_10C3F4 )
        goto LABEL_15;
      goto LABEL_12;
    }
    v7 = off_10C3E0;
    **(uint8_t **)off_10C3F0 = 2;
    v8 = off_10C3D8;
    v9 = (uint8_t)v0[2];
    v7[20] |= 0x40000u;
    v8[7] &= ~0x100u;
    v7[9] = v7[9] & 0xFFFFFF00 | 0x60;
    v7[9] = v7[9] & 0xFFFF00FF | 0xDF00;
    if ( v9 )
      goto LABEL_11;
  }
  else
  {
    v13 = off_10C71C;
    v14 = off_10C720;
    *((uint32_t *)off_10C71C + 20) |= 0x40000u;
    v14[7] &= ~0x100u;
    v13[9] = v13[9] & 0xFFFFFF00 | 0x60;
    v13[9] = v13[9] & 0xFFFF00FF | 0xDF00;
  }
  v10 = rf_phy_init();
  if ( !*(uint32_t *)off_10C724 )
  {
LABEL_15:
    v15 = off_10C720;
    check_chip_flag();
    v15[4] |= 2u;
    save_rf_context();
    v95 = 0;
    if ( (*v15 & 0x2000000) != 0 )
    {
      mmio_read_status(&v95);
      mmio_read_byte((char *)&v95 + 1);
      v16 = (uint8_t)v95;
      if ( (uint8_t)v95 )
      {
LABEL_19:
        if ( v16 > 0x1F )
        {
          v16 = 31;
          LOBYTE(v95) = 31;
        }
        set_xtal_ftune(v16);
        v18 = log_printf(dword_10C728, (uint8_t)v95, v17);
LABEL_22:
        v19 = HIBYTE(v95);
        if ( HIBYTE(v95) )
        {
          if ( HIBYTE(v95) <= 0x3Fu )
          {
            v20 = (HIBYTE(v95) << 18) & 0xFC0000;
          }
          else
          {
            v19 = 63;
            HIBYTE(v95) = 63;
            v20 = 16515072;
          }
          v21 = off_10C72C;
          v22 = dword_10C730;
          *(uint32_t *)off_10C72C = *(uint32_t *)off_10C72C & 0xFF03FFFF | v20;
          v18 = log_printf(v22, v19, v21);
        }
        v23 = *(uint8_t *)off_10C734;
        if ( (v23 == 7 || v23 == 193) && !rf_get_reg1_bits13_16(v18) )
        {
          v53 = mmio_rmw_field(3);
          if ( v53 != 3 )
            log_printf(dword_10CA8C, v53, v54);
        }
        v24 = HIBYTE(*(uint32_t *)off_10C720) & 2;
        if ( v24 )
        {
          v25 = (uint8_t *)dword_10C790;
          v26 = off_10C794;
          v27 = off_10C738;
          v28 = 0;
          do
          {
            v29 = tx_desc_init(v28, *v26 + 3 * v28);
            ++v28;
            if ( v29 != 546 )
              v27[1] |= 1u;
            *v25 = v29 & 0xF;
            v25[1] = (uint8_t)v29 >> 4;
            v25[2] = BYTE1(v29) & 0xF;
            v25 += 3;
          }
          while ( v28 != 3 );
          v30 = dword_10C798;
          v31 = off_10C79C;
          v32 = dword_10C73C;
          for ( i = 0; i != 3; ++i )
          {
            v34 = rx_desc_init(i, *v31 + 6 * i);
            if ( v34 != v32 )
              v27[1] |= 1u;
            v35 = (uint8_t *)v30;
            for ( j = 0; j != 24; j += 4 )
            {
              v37 = v34 >> j;
              *v35++ = v37 & 0xF;
            }
            v30 += 6;
          }
          v38 = 31 - __clz(rf_get_reg0x1b());
          *v27 = v38;
        }
        else
        {
          memset(v97, 0, sizeof(v97));
          if ( bus_read_12(v97) )
          {
            v57 = off_10CA90;
          }
          else
          {
            v79 = dword_10CBCC;
            v80 = off_10CBDC;
            log_printf(dword_10CBD0, v55, v56);
            v82 = 0;
            v93 = v97;
            v83 = (uint8_t *)v79;
            v84 = v80;
            do
            {
              log_printf(dword_10CBC0, v82, v81);
              v85 = (char *)v93;
              v86 = v83;
              v87 = 0;
              do
              {
                v88 = *v85++;
                v89 = dword_10CBC4;
                *(uint8_t *)(*v84 + v87 + 3 * v82) = v88;
                v90 = *v84 + v87++;
                log_printf(v89, *(char *)(v90 + 3 * v82), v88);
                *v86++ = 15;
              }
              while ( v87 != 3 );
              ++v82;
              v93 = (uint32_t *)((char *)v93 + 3);
              v83 += 3;
            }
            while ( v82 != 3 );
            v57 = off_10CBD4;
            v24 = 0;
            log_printf(dword_10CBC8, v91, v81);
            v57[1] |= 1u;
          }
          memset(v98, 0, 20);
          if ( !mmio_read_4(v98) )
          {
            v67 = off_10CBD8;
            log_printf(dword_10CBB8, v58, v59);
            v94 = v57;
            v69 = dword_10CBBC;
            v92 = v98;
            v70 = v67;
            v71 = 0;
            do
            {
              log_printf(dword_10CBC0, v71, v68);
              v72 = (char *)v92;
              v73 = (uint8_t *)v69;
              v74 = 0;
              do
              {
                v75 = *v72++;
                v76 = dword_10CBC4;
                *(uint8_t *)(*v70 + v24 + v74) = v75;
                v77 = *(char *)(*v70 + v24 + v74++);
                log_printf(v76, v77, v75);
                *v73++ = 15;
              }
              while ( v74 != 6 );
              v24 += 6;
              ++v71;
              v92 += 6;
              v69 += 6;
            }
            while ( v24 != 18 );
            v57 = v94;
            log_printf(dword_10CBC8, v78, v68);
            v94[1] |= 1u;
          }
          if ( mmio_read_128(&v96) )
          {
            v38 = -1;
            *v57 = -1;
          }
          else
          {
            v60 = (char)v96;
            *v57 = v96;
            v38 = v60;
          }
        }
        v40 = log_printf(dword_10C740, v38, v39);
        if ( *((uint8_t *)v5 + 372) )
        {
          if ( (*(uint32_t *)off_10C720 & 0x2000000) != 0 )
          {
            v40 = rf_get_reg0xf_bit18(v40);
            if ( v40 )
            {
              v50 = rf_get_reg0x11_bits0_2();
              v51 = dword_10CA84;
              v52 = off_10CA88;
              *(uint8_t *)off_10CA88 = *(uint8_t *)(dword_10CA84 + v50);
              v52[1] = *(uint8_t *)(v51 + rf_get_reg0x11_bits3_5());
              v40 = rf_get_reg0x11_bits6_8();
              v52[2] = *(uint8_t *)(v51 + v40);
            }
          }
          else
          {
            *(uint32_t *)v98 = 0;
            v40 = mmio_read_32(v98);
            if ( !v40 )
            {
              v64 = off_10CA88;
              v40 = *(uint8_t *)(dword_10CA84 + v98[0]);
              v65 = *(uint8_t *)(dword_10CA84 + v98[1]);
              v66 = *(uint8_t *)(dword_10CA84 + v98[2]);
              *(uint8_t *)off_10CA88 = v40;
              v64[1] = v65;
              v64[2] = v66;
            }
          }
        }
        v41 = rf_get_reg0xf_bit19(v40);
        v42 = off_10C744;
        if ( v41 )
          *(uint32_t *)off_10C744 |= 1u;
        if ( rf_get_reg0xf_bit20() )
          *v42 |= 2u;
        *(uint32_t *)off_10C748 &= 0xFFFFFFC7;
        if ( (*(uint8_t *)off_10C734 & 0xC0) == 0xC0 )
        {
          v43 = off_10C750;
          *(uint32_t *)off_10C74C = dword_10C754;
          v44 = off_10C758;
          *v43 = dword_10C75C;
          v45 = dword_10C760;
          v46 = (int *)off_10C764;
          *v44 = dword_10C760;
          v47 = off_10C768;
          *v46 = v45;
          *v47 = dword_10C76C;
        }
        memcpy_advance(0, 0, 0x10u, dword_10C770);
        memcpy_advance(0, 16, 0x10u, dword_10C774);
        if ( (*v42 & 2) == 0 )
        {
          v61 = (int *)off_10CA94;
          memcpy_advance(0, 32, 0x10u, *((uint32_t *)off_10CA94 + 2));
          memcpy_advance(0, 48, 0x10u, v61[1]);
          memcpy_advance(0, 64, 0x10u, *v61);
          memcpy_advance(1, 0, 0x10u, *(uint32_t *)off_10CA98);
          memcpy_advance(1, 16, 0x10u, *(uint32_t *)off_10CA9C);
        }
        rf_cal_read_1();
        rf_init_regs();
      }
    }
    else
    {
      *(uint32_t *)v98 = 0;
      if ( bus_read32(v98) )
      {
        v16 = (uint8_t)v95;
      }
      else
      {
        v16 = v98[0];
        v95 = *(uint16_t *)v98;
      }
      if ( v16 )
        goto LABEL_19;
    }
    v18 = set_xtal_ftune(15);
    goto LABEL_22;
  }
LABEL_12:
  v11 = chip_common_write(v10);
  inited = periph_cmd_poll(v11);
  periph_cmd_write(inited);
  goto LABEL_15;
}

