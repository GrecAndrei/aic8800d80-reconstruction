// fwstruct annotate: 11a090_sub_11A090.c
// sub_11A090 @ 0x11a090, size 566 bytes
int __fastcall sub_11A090(int a1, int a2)
{
  int v2; // r7
  int v3; // r8
  int v4; // r5
  int v5; // r2
  int v8; // r9
  int v9; // r3
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // lr
  unsigned int v13; // r12
  unsigned int v14; // r10
  unsigned int v15; // r0
  unsigned int v16; // r11
  unsigned int v17; // r1
  int v18; // r0
  int v19; // r7
  unsigned int v20; // r5
  char v21; // r0
  unsigned int v22; // r3
  unsigned int v23; // r0
  int v25; // r0
  int v26; // r10
  _DWORD *v27; // r5
  unsigned int v28; // r2
  unsigned int v29; // r0
  int v30; // r2
  int v31; // r1
  unsigned int v32; // r1
  int v33; // r3
  unsigned int v34; // r0
  int v35; // r6
  unsigned int v36; // r3
  int v37; // r12
  int v38; // r0
  int v39; // r3
  int v40; // [sp+0h] [bp-1Ch]
  int v41; // [sp+4h] [bp-18h]
  char v42; // [sp+8h] [bp-14h]
  char v43; // [sp+Ch] [bp-10h]
  int v44; // [sp+10h] [bp-Ch]
  int v45; // [sp+14h] [bp-8h]

  v2 = dword_11A2C8;
  v3 = *(_DWORD *)(a1 + 76);
  v4 = dword_11A2C8 + 84 * a2;
  v5 = *(_DWORD *)(v4 + 44);
  v42 = *(_BYTE *)(a1 + 27);
  v43 = *(_BYTE *)(a1 + 29);
  v8 = v3 + 12;
  if ( v5 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(a1 + 36);
      if ( (v9 & 0x200000) != 0
        && (v9 & 0x380000) != 0x280000
        && *(unsigned __int8 *)(v5 + 12) == *(unsigned __int8 *)(a1 + 29)
        && *(unsigned __int8 *)(v5 + 13) == *(unsigned __int8 *)(a1 + 27) )
      {
        v10 = *(unsigned __int16 *)(v4 + 72);
        v11 = (unsigned __int16)(((*(_DWORD *)(v3 + 36) + 3) & 0xFFFC) + 4);
        if ( v10 > v11 )
        {
          v37 = (unsigned __int16)(v10 - v11) + 3;
          v45 = v37 >> 2;
          v13 = (unsigned int)v37 >> 2;
          v12 = 4 * v45;
        }
        else
        {
          v12 = 0;
          v45 = 0;
          LOWORD(v13) = 0;
        }
        v41 = *(_DWORD *)(v5 + 40);
        v40 = *(_DWORD *)(v4 + 52);
        v14 = *(unsigned __int8 *)(v4 + 79);
        v15 = 21 * a2 + v14;
        v44 = *(_DWORD *)(v40 + 76);
        v16 = *(_DWORD *)(v2 + 4 * v15 + 56);
        *(_WORD *)(v4 + 74) = v13;
        v17 = v41 + v12 + v11;
        if ( v17 <= v16 )
          goto LABEL_15;
        if ( *(unsigned __int8 *)(v4 + 78) > v14 && *(_BYTE *)(v4 + 77) != 1 && v17 <= *(_DWORD *)(v2 + 4 * v15 + 60) )
          break;
      }
      sub_119EC8(a2);
      v5 = *(_DWORD *)(v4 + 44);
      if ( !v5 )
        goto LABEL_17;
    }
    v18 = v5 + 4 * v14;
    *(_DWORD *)(v18 + 328) = v40;
    *(_DWORD *)(v18 + 56) = v41;
    *(_BYTE *)(v4 + 79) = v14 + 1;
LABEL_15:
    v19 = v2 + 84 * a2;
    v20 = *(unsigned __int8 *)(v19 + 76);
    v21 = *(_BYTE *)(v19 + 77);
    *(_DWORD *)(a1 + 68) = v5;
    v22 = (v9 | (v45 << 9)) & 0xFF87FFFF | 0x700000;
    *(_DWORD *)(a1 + 36) = v22;
    v23 = (unsigned __int8)(v21 + 1);
    *(_DWORD *)(v3 + 68) = v22;
    *(_DWORD *)(v44 + 20) = v8;
    *(_DWORD *)(v5 + 40) = v17;
    *(_DWORD *)(v19 + 52) = a1;
    *(_BYTE *)(v19 + 77) = v23;
    if ( v20 <= v23 )
      sub_119EC8(a2);
  }
  else
  {
LABEL_17:
    if ( (*(_DWORD *)(a1 + 36) & 0x200000) != 0 && ((*(_DWORD *)(a1 + 40) >> 11) & 6) != 0 )
    {
      v25 = rf_bus_mark_n100_d2d0(dword_11A2CC + 8 * a2);
      v26 = v2 + 84 * a2;
      v27 = (_DWORD *)v25;
      *(_DWORD *)(v26 + 44) = v25;
      if ( v25 )
      {
        *(_BYTE *)(v25 + 12) = v43;
        *(_BYTE *)(v25 + 13) = v42;
        *(_BYTE *)(v25 + 14) = 1;
        v28 = *(_DWORD *)(a1 + 40);
        *(_DWORD *)(v25 + 268) = a1;
        *(_QWORD *)(v25 + 4) = v28;
        *(_DWORD *)(v25 + 264) = 0;
        *(_BYTE *)(v25 + 344) = *(_BYTE *)(a1 + 54);
        sub_1194A8(v25, a2, v2 + 84 * a2 + 44);
        v29 = *(unsigned __int16 *)(v26 + 72);
        v30 = (unsigned __int16)(((*(_DWORD *)(v3 + 36) + 3) & 0xFFFC) + 4);
        v27[10] = v30;
        v31 = *(_DWORD *)(v3 + 36);
        v27[6] = v8;
        v32 = (unsigned __int16)(((v31 + 3) & 0xFFFC) + 4);
        v33 = 0;
        v27[14] = 0;
        v27[15] = 0;
        v27[19] = 0;
        v27[7] = 0;
        v27[16] = 0;
        *(_BYTE *)(v26 + 77) = 1;
        if ( v29 > v32 )
        {
          v38 = (unsigned __int16)(v29 - v32) + 3;
          v39 = v38 >> 2;
          v30 += 4 * (v38 >> 2);
          v34 = (unsigned int)v38 >> 2;
          v33 = v39 << 9;
        }
        else
        {
          LOWORD(v34) = 0;
        }
        v35 = v2 + 84 * a2;
        v36 = (v33 | *(_DWORD *)(a1 + 36)) & 0xFF87FFFF | 0x680000;
        *(_WORD *)(v35 + 74) = v34;
        v27[10] = v30;
        *(_DWORD *)(v35 + 48) = a1;
        *(_DWORD *)(v35 + 52) = a1;
        *(_DWORD *)(a1 + 36) = v36;
        *(_DWORD *)(a1 + 68) = v27;
        *(_DWORD *)(v3 + 68) = v36;
      }
      else
      {
        *(_DWORD *)(a1 + 36) = 0;
        ++*(_BYTE *)(v26 + 80);
      }
    }
    else
    {
      ++*(_BYTE *)(v2 + 84 * a2 + 80);
    }
  }
  return 0;
}

