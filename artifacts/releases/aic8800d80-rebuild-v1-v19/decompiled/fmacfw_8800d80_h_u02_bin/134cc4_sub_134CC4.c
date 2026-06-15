// sub_134CC4 @ 0x134cc4, size 166 bytes
// positive sp value has been detected, the output may be wrong!
void __fastcall sub_134CC4(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13)
{
  _DWORD *v14; // r5
  int v15; // r11
  int v16; // r7
  int v17; // r4
  int v18; // r9
  int v19; // r10
  int v20; // r12
  _BYTE *v21; // r0
  unsigned int *v22; // r1
  unsigned int v23; // r2
  int *v24; // r3
  char *v25; // r1
  int *v26; // r3
  int v27; // r3
  int v28; // r2
  char v29; // lr
  __int16 v30; // r0
  int v31; // lr
  int v32; // r2
  int v33; // lr
  unsigned int v34; // r0
  unsigned int v35; // r3
  unsigned int v36; // r3
  int v37; // r2
  int v38; // r3
  int v39; // r3
  int v40; // r3
  void *v41; // r1
  unsigned __int16 *v42; // r3
  int v43; // r3
  unsigned int v44; // r0
  _DWORD *v45; // r3
  _DWORD *v46; // r2
  int *v47; // r1
  int v48; // r0
  int v49; // [sp-8h] [bp-1Ch]
  void *v50; // [sp-8h] [bp-1Ch]

  v14 = off_134F44;
  v15 = dword_134F8C;
  v16 = *(unsigned __int8 *)(*((_DWORD *)off_134F44 + 4) + 61);
  v17 = *((_DWORD *)off_134F44 + 5);
  v49 = *((_DWORD *)off_134F44 + 4);
  v18 = dword_134F8C + 1320 * v16;
  v19 = *(unsigned __int8 *)(v18 + 116);
  sub_12E948(dword_134F48);
  v20 = v14[4];
  if ( !v20 )
LABEL_11:
    __asm { POP.W           {R4-R11,PC} }
  v21 = off_134F4C;
  v22 = (unsigned int *)off_134F50;
  *(_BYTE *)(v17 + 9) = *(_BYTE *)(v49 + 61);
  v23 = *v22 & 0xFFFFFFEF;
  v24 = *((int **)off_134F54 + 2);
  *(_WORD *)v17 = a1;
  *v22 = v23;
  v25 = nullptr;
  v21[13] = 0;
  if ( v24 )
  {
    do
    {
      if ( !*((_BYTE *)v24 + 106) && *((_BYTE *)v24 + 108) )
        ++v25;
      v24 = (int *)*v24;
    }
    while ( v24 );
    if ( a1 )
      goto LABEL_8;
  }
  else
  {
    v25 = nullptr;
    if ( a1 )
    {
LABEL_8:
      v26 = (int *)off_134F58;
      *(_BYTE *)(v17 + 8) = (*(_DWORD *)(v20 + 48) & 0x60) != 0;
      if ( *v26 < 0 && !v25 )
      {
        v46 = off_134F84;
        v21[2] = 0;
        v47 = (int *)off_134F74;
        v48 = dword_134F88;
        *v46 |= 0x80000000;
        *v47 = v48;
      }
      sub_12CBF4(6u, 10);
      v14[2] = v18;
      *v14 = v17 - 12;
      sub_1346C0(v18);
LABEL_10:
      sub_12EB90(256, dword_134F5C, *(unsigned __int8 *)(v17 + 9), a1, *(unsigned __int16 *)(v17 + 820));
      sub_12C8F8(v14[4] - 12);
      v14[4] = 0;
      *((_BYTE *)v14 + 33) = 0;
      goto LABEL_11;
    }
  }
  v27 = v15 + 1320 * v16;
  v28 = dword_134F60;
  v29 = *(_BYTE *)(v27 + 116);
  *(_DWORD *)(v17 + 2) = *(_DWORD *)(v27 + 368);
  v30 = *(_WORD *)(v27 + 372);
  *(_BYTE *)(v17 + 10) = v29;
  v31 = *(_DWORD *)(v27 + 72);
  *(_WORD *)(v17 + 6) = v30;
  *(_BYTE *)(v17 + 11) = *(_BYTE *)(v31 + 24);
  v32 = *(unsigned __int8 *)(v28 + 696 * v19 + 309);
  *(_BYTE *)(v17 + 826) = v32;
  *(_BYTE *)(v17 + 822) = *(_BYTE *)(v27 + 412);
  v33 = *(unsigned __int8 *)(v27 + 413);
  v34 = *(unsigned __int16 *)(v27 + 414);
  *(_WORD *)(v17 + 824) = v34;
  if ( v33 == v32 )
  {
    *(_DWORD *)(v17 + 828) = *(unsigned __int16 *)(v27 + 416);
  }
  else if ( v32 )
  {
    v35 = *(unsigned __int16 *)(v27 + 416);
    if ( v34 >= v35 )
      v36 = v35 + 20;
    else
      v36 = v35 - 20;
    *(_DWORD *)(v17 + 828) = v36;
  }
  else
  {
    *(_DWORD *)(v17 + 828) = v34;
  }
  v37 = v15 + 1320 * v16;
  v38 = *(_DWORD *)(v37 + 472);
  *(_DWORD *)(v17 + 832) = *(unsigned __int16 *)(v37 + 418);
  v39 = v38 & 1;
  *(_BYTE *)(v17 + 12) = v39;
  if ( v39 )
    LOBYTE(v39) = *(_BYTE *)(v37 + 457);
  *(_BYTE *)(v17 + 13) = v39;
  v40 = v15 + 1320 * v16;
  *(_BYTE *)(v17 + 8) = (*(_DWORD *)(v20 + 48) & 0x60) != 0;
  if ( *(_BYTE *)(v40 + 1224) )
  {
    *(_DWORD *)off_134F64 = *(unsigned __int16 *)(v40 + 100) | (*(unsigned __int16 *)(v40 + 102) << 16);
    *(_DWORD *)off_134F68 = *(unsigned __int16 *)(v40 + 104);
    *(_DWORD *)off_134F6C = *(unsigned __int16 *)(v40 + 64) | (*(unsigned __int16 *)(v40 + 66) << 16);
    *(_DWORD *)off_134F70 = *(unsigned __int16 *)(v40 + 68);
  }
  v50 = v25;
  sub_12C84C(v17);
  v41 = v50;
  *(_DWORD *)off_134F74 = dword_134F78;
  if ( v50 == (void *)1 )
  {
    v42 = (unsigned __int16 *)(v15 + 1320 * v16);
    v41 = off_134F64;
    *(_DWORD *)off_134F64 = v42[50] | (v42[51] << 16);
    *(_DWORD *)off_134F68 = v42[52];
  }
  if ( *(_BYTE *)(v15 + 1320 * v16 + 413) == 2 )
    sub_12063C((int *)v18, 0, 1);
  v43 = v15 + 1320 * v16;
  v44 = *(unsigned __int16 *)(v43 + 416);
  if ( v44 <= 0x1387 )
    sub_10D0BC(v44 | (*(unsigned __int8 *)(v43 + 413) << 16) | 0x80000000, (int)v41, 4999);
  v45 = off_134F7C;
  *(_BYTE *)(v15 + 1320 * v16 + 149) = 1;
  sub_124BFC(1320 * v16 + 152 + v15, dword_134F80 + v45[4]);
  sub_12CBF4(6u, 0);
  goto LABEL_10;
}

