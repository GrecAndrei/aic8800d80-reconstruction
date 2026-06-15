// v23 annotated: sub_1194A8 @ 0x1194a8
// Original: 1194a8_sub_1194A8.c
// Primary struct: <unclustered>
//
// sub_1194A8 @ 0x1194a8, size 514 bytes
unsigned int __fastcall sub_1194A8(int a1, int a2, int a3)
{
  __int16 **v3; // r10
  unsigned int v5; // r3
  int v8; // r4
  unsigned int v9; // r9
  bool v10; // zf
  int v11; // r10
  unsigned int v12; // r8
  int v13; // s16
  int (__fastcall *v14)(int, _DWORD); // r3
  char v15; // r1
  int v16; // r4
  int v17; // r9
  int v18; // r6
  unsigned int *v19; // r11
  int i; // r0
  unsigned int v21; // r0
  unsigned int v22; // r3
  int v23; // r9
  unsigned int v24; // r8
  int v25; // r11
  unsigned int v26; // r1
  int v27; // r0
  _BYTE *v28; // r2
  unsigned int result; // r0
  char v30; // r3
  int v31; // r1
  unsigned int v32; // r2
  int v33; // r0
  int v34; // [sp+8h] [bp-1Ch]
  int v35; // [sp+8h] [bp-1Ch]
  int v36; // [sp+Ch] [bp-18h]
  unsigned int v37; // [sp+10h] [bp-14h] BYREF
  int v38; // [sp+14h] [bp-10h] BYREF
  int (__fastcall *v39)(int, _DWORD); // [sp+18h] [bp-Ch] BYREF
  int (__fastcall *v40[2])(int, int); // [sp+1Ch] [bp-8h] BYREF

  v3 = (__int16 **)off_1196D8;
  v5 = *(_DWORD *)(a1 + 4);
  v36 = *(unsigned __int8 *)(a1 + 12);
  v8 = (v5 >> 7) & 3;
  v9 = (v5 >> 11) & 7;
  if ( **(__int16 **)off_1196D8 < 0 && ((v5 >> 11) & 6) == 0 )
    sub_12F46C(dword_1196C4, dword_1196C0, 397);
  v10 = v9 == 4;
  if ( v9 <= 4 )
  {
    v22 = *(_DWORD *)(a1 + 4);
    v23 = *(unsigned __int8 *)(a1 + 12);
    v24 = v22 & 0x7F;
    v25 = (v22 >> 9) & 1;
    if ( v10 )
    {
      v31 = **v3;
      v32 = v24 >> 4;
      v33 = (v24 >> 4) + 1;
      v12 = v22 & 0xF;
      v38 = v33;
      if ( v31 < 0 )
      {
        if ( v32 <= 3 || (sub_12F46C(dword_1196D4, dword_1196C8, 340), **v3 < 0) )
        {
          if ( v12 > 9 )
            sub_12F46C(dword_1196D0, dword_1196C8, 341);
        }
      }
      v34 = dword_1196AC;
      v37 = *(_DWORD *)(dword_1196AC + 696 * v23 + 16);
    }
    else
    {
      if ( **v3 < 0 && (v22 & 0x60) != 0 )
      {
        v35 = *(_DWORD *)(a1 + 4);
        sub_12F46C(dword_1196CC, dword_1196C8, 349);
        LOBYTE(v22) = v35;
      }
      v34 = dword_1196AC;
      v26 = *(unsigned __int16 *)(dword_1196AC + 696 * v23 + 20);
      v38 = ((v24 >> 3) & 3) + 1;
      v12 = v22 & 7;
      v37 = v26;
    }
    v14 = (int (__fastcall *)(int, _DWORD))dword_1196B0;
    v39 = (int (__fastcall *)(int, _DWORD))dword_1196B0;
    v11 = v25 | (8 * v12);
    v40[0] = (int (__fastcall *)(int, int))dword_1196B4;
    LOBYTE(v12) = 0;
    goto LABEL_14;
  }
  v11 = sub_11C394(a1, v9, &v39, v40, &v37, &v38);
  v12 = (*(unsigned __int8 *)(a1 + 344) >> 5) & 1;
  if ( v9 != 7 )
  {
    v14 = v39;
    v34 = dword_1196AC;
LABEL_14:
    v15 = v8;
    v13 = (unsigned __int8)v8;
    goto LABEL_5;
  }
  v13 = (unsigned __int8)v8;
  v14 = v39;
  v34 = dword_1196AC;
  v15 = 0;
LABEL_5:
  v16 = 0;
  v17 = dword_1196DC;
  *(_BYTE *)(a3 + 34) = v15;
  v18 = a2 + 4;
  *(_BYTE *)(a3 + 35) = 0;
  v19 = (unsigned int *)(a3 + 12);
  for ( i = v14(v11, 0); ; i = v39(v11, (unsigned __int8)v16) )
  {
    v21 = (i * v38 * (unsigned int)*(unsigned __int16 *)(v17 + 2 * v18)) >> v12;
    if ( v21 >= v37 )
      v21 = v37;
    *v19++ = v21;
    if ( *(unsigned __int8 *)(a3 + 34) < ++v16 )
      break;
  }
  v27 = v40[0](v11, v13);
  v28 = off_1196B8;
  result = v27 * v38 * *(unsigned __int8 *)(v34 + 696 * v36 + 28);
  *(_WORD *)(a3 + 28) = result >> v12;
  v30 = v28[381];
  if ( !v30 || *(_BYTE *)off_1196BC )
    v30 = *(_BYTE *)(v34 + 696 * *(unsigned __int8 *)(a1 + 12) + 6 * *(unsigned __int8 *)(a1 + 13) + 354);
  *(_BYTE *)(a3 + 32) = v30;
  return result;
}

