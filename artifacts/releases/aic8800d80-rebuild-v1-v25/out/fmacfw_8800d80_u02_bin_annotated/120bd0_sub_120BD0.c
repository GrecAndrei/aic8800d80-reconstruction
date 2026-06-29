// fwstruct annotate: 120bd0_sub_120BD0.c
// sub_120BD0 @ 0x120bd0, size 1192 bytes
int sub_120BD0()
{
  _BYTE *v0; // r10
  int v1; // r8
  int result; // r0
  void *v3; // r4
  _DWORD *v4; // r11
  int v5; // r1
  _DWORD *v6; // r7
  _DWORD *v7; // r5
  _DWORD *v8; // r9
  int v9; // r3
  int v10; // r2
  int v11; // r1
  int v12; // r1
  int v13; // r3
  int v14; // r6
  unsigned int v15; // r5
  unsigned int v16; // r6
  int v17; // r1
  int v18; // r3
  char v19; // r5
  unsigned __int8 **v20; // r7
  unsigned __int8 *v21; // r1
  _DWORD *v22; // r3
  int v23; // r3
  __int16 **v24; // r1
  int v25; // r3
  int v26; // r2
  int v27; // r3
  void *v28; // r1
  char v29; // r1
  _DWORD *v30; // r2
  _DWORD *v31; // r7
  int v32; // r1
  int v33; // r1
  _DWORD *v34; // r1
  int *v35; // r9
  _DWORD *v36; // r5
  int v37; // r2
  int v38; // r6
  int v39; // r2
  _DWORD *v40; // r6
  int v41; // r3
  int v42; // r2
  _DWORD *v43; // r2
  int v44; // r8
  int v45; // r5
  int v46[3]; // [sp+0h] [bp-Ch]
  int v47; // [sp+0h] [bp-Ch]
  int v48; // [sp+0h] [bp-Ch]

  v0 = off_120F54;
  v1 = *((_DWORD *)off_120F54 + 8);
  result = clear_flags(0x40000);
  if ( v1 )
  {
    v3 = off_120EDC;
    v4 = off_120F58;
    v5 = *((unsigned __int8 *)off_120EDC + 30);
LABEL_3:
    v6 = off_120EE0;
    v7 = off_120EE4;
    v8 = off_120F5C;
    while ( 1 )
    {
      if ( !v5 )
        return result;
      if ( (v5 & 8) != 0 )
      {
        v9 = *(_DWORD *)off_120EE8;
        *(_DWORD *)off_120EEC = 0x80000000;
        if ( *(_DWORD *)(v9 + 4) + *(_DWORD *)(v1 + 120) - v4[4] < 0
          && !sub_118DC4(*(unsigned __int8 *)(v1 + 116), 0, 0) )
        {
          *(_DWORD *)(v1 + 120) = v4[4];
        }
        v5 = *((_BYTE *)v3 + 30) & 0xF7;
        *((_BYTE *)v3 + 30) = v5;
      }
      if ( (v5 & 4) != 0 )
      {
        feature_guard_check(2, dword_120F14);
        v24 = (__int16 **)off_120EF8;
        v25 = *((_DWORD *)v3 + 1);
        *v6 &= ~4u;
        v26 = **v24;
        v27 = v25 | 0x200;
        *((_DWORD *)v3 + 1) = v27;
        if ( v26 < 0 && *(_DWORD *)off_120F24 << 28 )
        {
          sub_12F49C(dword_120F2C, dword_120F28, 472);
          v27 = *((_DWORD *)v3 + 1);
        }
        v28 = off_120F18;
        *(_DWORD *)off_120F1C = v27 | *(_DWORD *)v3;
        sub_12B2B0(*(unsigned __int8 *)(v1 + 107), v28, v1);
        v29 = *((_BYTE *)v3 + 30);
        *v7 &= 0xFC0FFFFF;
        v5 = v29 & 0xFB;
        *v8 |= 0x400000u;
        *((_BYTE *)v3 + 30) = v5;
      }
      if ( (v5 & 2) != 0 )
      {
        *(_DWORD *)(v1 + 4) &= ~2u;
        if ( v0[29] == 5 )
        {
          timestamp_remove(dword_120F34);
          LOBYTE(v5) = *((_BYTE *)v3 + 30);
          v0[29] = 0;
        }
        v5 &= 0xFDu;
        *((_BYTE *)v3 + 30) = v5;
      }
      result = v5 << 31;
      if ( (v5 & 1) != 0 )
        break;
LABEL_20:
      if ( (v5 & 0x20) != 0 )
      {
        v15 = *(_DWORD *)off_120F00;
        v16 = (*(_DWORD *)off_120F00 >> 5) & 3;
        feature_guard_check(2, dword_120F04);
        v17 = *(_DWORD *)(v1 + 120);
        v18 = *(_DWORD *)(*(_DWORD *)off_120EE8 + 4);
        *(_BYTE *)(v1 + 128) = 0;
        v19 = v15 >> 5;
        if ( v18 + v17 - v4[4] < 0 )
        {
          v32 = dword_120F50;
          *((_BYTE *)v3 + 30) |= 8u;
          feature_guard_check(2, v32);
        }
        if ( v16 )
        {
          while ( (*(_DWORD *)off_120F00 & 8) == 0 )
            ;
          v31 = off_120F00;
          *(_DWORD *)off_120F00 &= ~8u;
          if ( (*v31 & 0x10) != 0 )
          {
            feature_guard_check(2, dword_120F48);
            *(_BYTE *)off_120F08 = BYTE2(*(_DWORD *)off_120F4C);
            sub_12917C(v16 >> 1, v19 & 1, v1);
            *v31 &= ~0x10u;
          }
          else
          {
            v33 = dword_12107C;
            *(_DWORD *)off_121078 = 1;
            feature_guard_check(2, v33);
            v34 = off_121084;
            *(_BYTE *)off_121080 = *((unsigned __int8 *)off_121080 + 1) > 1u;
            *v34 = 1;
          }
        }
        else
        {
          *(_BYTE *)off_120F08 = *((_BYTE *)off_120F08 + 1);
        }
        v20 = (unsigned __int8 **)off_120F10;
        *(_DWORD *)off_120F0C &= ~0x200u;
        *(_DWORD *)(v1 + 4) &= ~1u;
        result = timestamp_remove(v1 + 48);
        v21 = *v20;
        if ( **v20 == 2 )
        {
          if ( (__get_CPSR() & 1) == 0 )
          {
            __disable_irq();
            *(_DWORD *)off_121094 = 1;
          }
          v35 = (int *)off_1210B0;
          v36 = off_121088;
          v37 = *(_DWORD *)off_121088;
          ++*(_DWORD *)off_1210B0;
          *v36 = 0;
          v38 = v4[4];
          v39 = v37 & 0xF;
          while ( *v36 << 28 )
          {
            if ( (unsigned int)(v4[4] - v38) > 0x7530 )
            {
              v47 = v39;
              feature_guard_check(2, dword_1210A4);
              v39 = v47;
            }
          }
          v40 = off_12109C;
          result = *(_DWORD *)off_12109C;
          if ( v39 )
          {
            result &= *(_DWORD *)off_121098;
            if ( (result & 4) == 0 )
            {
              v48 = v1;
              v43 = off_121098;
              v44 = v4[4];
              do
              {
                result = 30000;
                v45 = *v43 & *v40;
                if ( (unsigned int)(v4[4] - v44) > 0x7530 )
                {
                  result = feature_guard_check(2, dword_1210AC);
                  v43 = off_121098;
                }
              }
              while ( (v45 & 4) == 0 );
              v1 = v48;
            }
          }
          *(_DWORD *)off_1210A0 = 4;
          if ( *v35 )
          {
            v41 = *v35 - 1;
            v42 = *(_DWORD *)off_121094;
            *v35 = v41;
            if ( !v41 )
            {
              if ( v42 )
                __enable_irq();
            }
          }
          v21 = *v20;
        }
        v22 = off_120F00;
        *(_DWORD *)off_120F00 &= ~1u;
        *v22 &= ~0x80u;
        v23 = *v21;
        if ( v23 == 1 )
        {
          result = timestamp_update(
                     v1 + 24,
                     v4[4] + 32 * *(_DWORD *)off_12108C - *((unsigned __int16 *)off_121090 + 93));
          v23 = **v20;
        }
        if ( v23 == 2 )
        {
          *(_DWORD *)off_121088 = 48;
          result = sub_117AB8();
        }
        v5 = *((_BYTE *)v3 + 30) & 0xDF;
        *((_BYTE *)v3 + 30) = v5;
        goto LABEL_3;
      }
    }
    v10 = 32 * *(_DWORD *)off_120EF0;
    if ( (*(_DWORD *)off_120EF0 & 0x4000000) != 0 )
    {
      v11 = HIWORD(*(_DWORD *)off_120EF0);
      if ( (v11 & 0x3F0) != 0 )
      {
        v12 = (unsigned __int8)(v11 - 16);
        v13 = dword_120EF4 + 696 * v12;
        if ( *(_BYTE *)(v13 + 37) )
        {
          result = 1320;
          v14 = dword_120EFC + 1320 * *(unsigned __int8 *)(v13 + 34);
          if ( **(__int16 **)off_120EF8 >= 0 || v1 == v14 )
          {
            if ( (*v7 & 0x70000) == 0 )
              goto LABEL_43;
          }
          else
          {
            result = sub_12F46C(dword_120F40, dword_120F3C, 864);
            if ( (*v7 & 0x70000) == 0 )
            {
LABEL_43:
              v46[0] = *(_DWORD *)off_120EF0 >> 31;
              v46[1] = (*(_DWORD *)off_120EF0 >> 30) & 1;
              feature_guard_check(2, dword_120F44);
              result = v46[0];
              if ( *(_QWORD *)v46 )
              {
                result = sub_12917C(v46[0], v46[1], v14);
                v30 = off_120EF0;
                *(_DWORD *)off_120EF0 &= ~0x80000000;
                *v30 &= ~0x40000000u;
              }
            }
          }
        }
        else
        {
          result = msg_parse(dword_120F38, v12, *(unsigned __int8 *)(v13 + 37));
        }
      }
      else
      {
        result = msg_parse(dword_120F30, v11, v10);
      }
    }
    else
    {
      result = msg_parse(dword_120F20, v5, v10);
    }
    v5 = *((_BYTE *)v3 + 30) & 0xFE;
    *((_BYTE *)v3 + 30) = v5;
    goto LABEL_20;
  }
  return result;
}

