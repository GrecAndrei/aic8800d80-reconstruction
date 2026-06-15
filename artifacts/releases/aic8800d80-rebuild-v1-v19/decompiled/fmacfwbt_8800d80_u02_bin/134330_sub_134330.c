// sub_134330 @ 0x134330, size 570 bytes
int __fastcall sub_134330(int a1, unsigned __int8 *a2)
{
  int v3; // r5
  int v4; // r8
  int v5; // r11
  int v6; // r6
  int v7; // r9
  _DWORD *v8; // r12
  int v9; // r0
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // lr
  _DWORD *v14; // r3
  int *v15; // r12
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  _DWORD *v20; // r10
  int v21; // r0
  int v22; // r1
  int v23; // r2
  int v24; // r3
  int v25; // r1
  int v26; // r2
  int v27; // r3
  int v28; // r1
  int v29; // r2
  int v30; // r3
  int v31; // r1
  int v32; // r2
  int v33; // r3
  int v34; // r1
  int v35; // r1
  int v36; // r2
  _DWORD *v37; // r3
  int v38; // r2
  _BYTE *v39; // r7
  unsigned __int8 *v40; // r12
  char *v41; // r10
  int v42; // r4
  char *v43; // r1
  _BYTE *v44; // r2
  char v45; // r0
  char v46; // t1
  unsigned int v47; // r3
  _DWORD *i; // r3
  int v49; // r2
  int v51; // [sp+0h] [bp-2Ch]
  int v52; // [sp+8h] [bp-24h]
  int v53; // [sp+8h] [bp-24h]
  _DWORD *v54; // [sp+Ch] [bp-20h]
  _DWORD v55[3]; // [sp+10h] [bp-1Ch] BYREF
  _DWORD v56[4]; // [sp+1Ch] [bp-10h] BYREF

  if ( **(__int16 **)off_13456C < 0 && msg_get_value(6u) != 3 )
    sub_12F694(dword_134578, dword_134574, 481);
  v3 = *a2;
  if ( *a2 )
  {
    sub_135020(1);
    return 0;
  }
  else
  {
    v4 = dword_13457C;
    v5 = dword_134580;
    v51 = a2[1];
    v6 = dword_13457C + 696 * v51;
    v7 = *(unsigned __int8 *)(v6 + 34);
    v8 = (_DWORD *)(dword_134580 + 1320 * v7);
    v9 = v8[106];
    v10 = v8[107];
    v11 = v8[108];
    v12 = v8[109];
    *(_DWORD *)(v6 + 192) = v9;
    *(_DWORD *)(v6 + 196) = v10;
    *(_DWORD *)(v6 + 200) = v11;
    v13 = v8[118];
    *(_BYTE *)(v6 + 204) = v12;
    if ( (v13 & 0x10) != 0 )
      *(_DWORD *)(v6 + 4) |= 0x40u;
    if ( (v13 & 1) != 0 )
      *(_DWORD *)(v4 + 696 * v51 + 4) |= 1u;
    if ( (v13 & 2) != 0 )
    {
      v14 = (_DWORD *)(v5 + 1320 * v7);
      v15 = v14 + 62;
      v54 = v14;
      v16 = v14[62];
      v17 = v14[63];
      v18 = v14[64];
      v19 = v14[65];
      v15 += 4;
      v20 = (_DWORD *)(v4 + 696 * v51);
      v20[52] = v16;
      v20[53] = v17;
      v20[54] = v18;
      v20[55] = v19;
      v21 = *v15;
      v22 = v15[1];
      v23 = v15[2];
      v24 = v15[3];
      v52 = v20[1];
      v20[1] = v52 | 2;
      v20[56] = v21;
      v20[57] = v22;
      v20[58] = v23;
      v20[59] = v24;
      if ( (v13 & 8) != 0 )
      {
        v25 = v54[74];
        v26 = v54[75];
        v27 = v54[76];
        v20[63] = v54[73];
        v20[64] = v25;
        v20[65] = v26;
        v20[66] = v27;
        v28 = v54[78];
        v29 = v54[79];
        v30 = v54[80];
        v20[67] = v54[77];
        v20[68] = v28;
        v20[69] = v29;
        v20[70] = v30;
        v31 = v54[82];
        v32 = v54[83];
        v33 = v54[84];
        v20[71] = v54[81];
        v20[72] = v31;
        v20[73] = v32;
        v20[74] = v33;
        v34 = v54[86];
        v20[75] = v54[85];
        v20[76] = v34;
        v20[1] = v52 | 0x22;
      }
      if ( (v13 & 4) != 0 )
      {
        v35 = *(_DWORD *)(v5 + 1320 * v7 + 284);
        v36 = *(_DWORD *)(v5 + 1320 * v7 + 288);
        v37 = (_DWORD *)(v4 + 696 * v51);
        v37[60] = *(_DWORD *)(v5 + 1320 * v7 + 280);
        v37[61] = v35;
        v37[62] = v36;
        v37[1] |= 4u;
      }
      v9 = sub_13267C(v6, v5 + 1320 * v7 + 248);
    }
    sub_134DEC(v9);
    if ( *(_BYTE *)off_134570 )
    {
      v38 = *(unsigned __int8 *)(v4 + 696 * v51 + 192);
      memset(v55, 0, sizeof(v55));
      memset(v56, 0, 12);
      if ( v38 )
      {
        v39 = v55;
        v40 = (unsigned __int8 *)v56;
        v53 = (unsigned __int8)(v38 - 1);
        v41 = (char *)v55 + v53 + 1;
        v42 = 696 * v51 + 192 + v4;
        v43 = (char *)v55;
        v44 = v56;
        do
        {
          while ( 1 )
          {
            v46 = *(_BYTE *)++v42;
            v45 = v46;
            v47 = (unsigned __int8)((v46 & 0x7F) - 2);
            if ( v47 <= 9 && ((1 << v47) & 0x205) != 0 )
              break;
            *v43++ = v45;
            *v44++ = 1;
            if ( v43 == v41 )
              goto LABEL_20;
          }
          *v43++ = v45;
          *v44++ = 0;
        }
        while ( v43 != v41 );
LABEL_20:
        for ( i = (_DWORD *)((char *)v56 + 1); ; i = (_DWORD *)((char *)i + 1) )
        {
          v49 = *v40;
          v40 = (unsigned __int8 *)i;
          if ( v49 )
          {
            *(_BYTE *)(v4 + 696 * v51 + v3 + 193) = *v39;
            v3 = (unsigned __int8)(v3 + 1);
          }
          ++v39;
          if ( i == (_DWORD *)((char *)v56 + v53 + 1) )
            break;
        }
      }
      else
      {
        LOBYTE(v3) = 0;
      }
      *(_BYTE *)(v4 + 696 * v51 + 192) = v3;
    }
    sub_132F20(v6);
    return 0;
  }
}

