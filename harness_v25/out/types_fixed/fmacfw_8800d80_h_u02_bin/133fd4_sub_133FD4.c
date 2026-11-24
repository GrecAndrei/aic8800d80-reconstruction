// sub_133FD4 @ 0x133fd4, size 570 bytes
int __fastcall sub_133FD4(int a1, unsigned __int8 *a2)
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
  _DWORD *(_DWORD *)(v55 + 0xc); // [sp+10h] [bp-1Ch] BYREF
  _DWORD *(_DWORD *)(v56 + 0x10); // [sp+1Ch] [bp-10h] BYREF

  if ( **(__int16 **)off_134210 < 0 && sub_12CD48(6u) != 3 )
    sub_12F32C(dword_13421C, dword_134218, 481);
  v3 = *a2;
  if ( *a2 )
  {
    sub_134CC4(1);
    return 0;
  }
  else
  {
    v4 = dword_134220;
    v5 = dword_134224;
    v51 = *(_DWORD *)(a2 + 0x4);
    v6 = dword_134220 + 696 * v51;
    v7 = *(unsigned __int8 *)(v6 + 34);
    v8 = (_DWORD *)(dword_134224 + 1320 * v7);
    v9 = *(_DWORD *)(v8 + 0x1a8);
    v10 = *(_DWORD *)(v8 + 0x1ac);
    v11 = *(_DWORD *)(v8 + 0x1b0);
    v12 = *(_DWORD *)(v8 + 0x1b4);
    *(_DWORD *)(v6 + 192) = v9;
    *(_DWORD *)(v6 + 196) = v10;
    *(_DWORD *)(v6 + 200) = v11;
    v13 = *(_DWORD *)(v8 + 0x1d8);
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
      v16 = *(_DWORD *)(v14 + 0xf8);
      v17 = *(_DWORD *)(v14 + 0xfc);
      v18 = *(_DWORD *)(v14 + 0x100);
      v19 = *(_DWORD *)(v14 + 0x104);
      v15 += 4;
      v20 = (_DWORD *)(v4 + 696 * v51);
      *(_DWORD *)(v20 + 0xd0) = v16;
      *(_DWORD *)(v20 + 0xd4) = v17;
      *(_DWORD *)(v20 + 0xd8) = v18;
      *(_DWORD *)(v20 + 0xdc) = v19;
      v21 = *v15;
      v22 = *(_DWORD *)(v15 + 0x4);
      v23 = *(_DWORD *)(v15 + 0x8);
      v24 = *(_DWORD *)(v15 + 0xc);
      v52 = *(_DWORD *)(v20 + 0x4);
      *(_DWORD *)(v20 + 0x4) = v52 | 2;
      *(_DWORD *)(v20 + 0xe0) = v21;
      *(_DWORD *)(v20 + 0xe4) = v22;
      *(_DWORD *)(v20 + 0xe8) = v23;
      *(_DWORD *)(v20 + 0xec) = v24;
      if ( (v13 & 8) != 0 )
      {
        v25 = *(_DWORD *)(v54 + 0x128);
        v26 = *(_DWORD *)(v54 + 0x12c);
        v27 = *(_DWORD *)(v54 + 0x130);
        *(_DWORD *)(v20 + 0xfc) = *(_DWORD *)(v54 + 0x124);
        *(_DWORD *)(v20 + 0x100) = v25;
        *(_DWORD *)(v20 + 0x104) = v26;
        *(_DWORD *)(v20 + 0x108) = v27;
        v28 = *(_DWORD *)(v54 + 0x138);
        v29 = *(_DWORD *)(v54 + 0x13c);
        v30 = *(_DWORD *)(v54 + 0x140);
        *(_DWORD *)(v20 + 0x10c) = *(_DWORD *)(v54 + 0x134);
        *(_DWORD *)(v20 + 0x110) = v28;
        *(_DWORD *)(v20 + 0x114) = v29;
        *(_DWORD *)(v20 + 0x118) = v30;
        v31 = *(_DWORD *)(v54 + 0x148);
        v32 = *(_DWORD *)(v54 + 0x14c);
        v33 = *(_DWORD *)(v54 + 0x150);
        *(_DWORD *)(v20 + 0x11c) = *(_DWORD *)(v54 + 0x144);
        *(_DWORD *)(v20 + 0x120) = v31;
        *(_DWORD *)(v20 + 0x124) = v32;
        *(_DWORD *)(v20 + 0x128) = v33;
        v34 = *(_DWORD *)(v54 + 0x158);
        *(_DWORD *)(v20 + 0x12c) = *(_DWORD *)(v54 + 0x154);
        *(_DWORD *)(v20 + 0x130) = v34;
        *(_DWORD *)(v20 + 0x4) = v52 | 0x22;
      }
      if ( (v13 & 4) != 0 )
      {
        v35 = *(_DWORD *)(v5 + 1320 * v7 + 284);
        v36 = *(_DWORD *)(v5 + 1320 * v7 + 288);
        v37 = (_DWORD *)(v4 + 696 * v51);
        *(_DWORD *)(v37 + 0xf0) = *(_DWORD *)(v5 + 1320 * v7 + 280);
        *(_DWORD *)(v37 + 0xf4) = v35;
        *(_DWORD *)(v37 + 0xf8) = v36;
        *(_DWORD *)(v37 + 0x4) |= 4u;
      }
      v9 = sub_132320(v6, v5 + 1320 * v7 + 248);
    }
    sub_134A90(v9);
    if ( *(_BYTE *)off_134214 )
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
    sub_132BC4(v6);
    return 0;
  }
}

