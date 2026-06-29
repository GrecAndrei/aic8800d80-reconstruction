// fwstruct annotate: 11512c_sub_11512C.c
// sub_11512C @ 0x11512c, size 464 bytes
// Doc: patch_apply_n384 [patch]: Decodes patch bitfield bits and dispatches patch install with config
// patch_apply_n384 [patch]: Decodes patch bitfield bits and dispatches patch install with config
int sub_11512C()
{
  _DWORD *v0; // r7
  int v1; // r6
  int *v2; // r5
  int i; // r4
  int v4; // r1
  int v5; // t1
  _DWORD *v6; // r5
  unsigned int v7; // r4
  int v8; // r3
  int v9; // r1
  int v10; // r1
  unsigned int CPSR; // r2
  unsigned int v12; // r3
  int result; // r0
  int v14; // r4
  int v15; // r4
  int v16; // r7
  int v17; // r6
  unsigned int v18; // r4
  unsigned int v19; // r5
  int v20; // t1
  int v21; // r8
  int v22; // r6
  unsigned int v23; // r4
  unsigned int v24; // r5
  int v25; // t1
  unsigned int v26; // [sp+0h] [bp-18h]

  v0 = patch_apply_n450;
  v1 = patch_apply_n454;
  v2 = (int *)patch_apply_n450;
  for ( i = 0; i != 13; ++i )
  {
    v4 = i;
    v5 = *v2++;
    sub_10DC24(v1, v4, v5);
  }
  v6 = off_115304;
  sub_10DC24(dword_115308, v0[13], v0[14], v0[15], v0[16], v0[17], v0[18]);
  sub_10DC24(dword_11530C, *v6, v6[1], v6[2], v6[3]);
  sub_10DC24(patch_apply_n464, v6[9], v6[10], v6[11], v6[12], v6[15]);
  v7 = v6[10];
  if ( (_BYTE)v7 )
  {
    sub_10DC24(
      patch_apply_n490,
      (unsigned __int8)v6[10],
      v7 & 1,
      (v7 >> 1) & 1,
      (v7 >> 3) & 1,
      (v7 >> 4) & 1,
      (v7 >> 5) & 1,
      (v7 >> 7) & 1);
    if ( (v7 & 0x80) != 0 )
      sub_10DC24(patch_apply_n494, v6[13]);
  }
  if ( (v7 & 0xFF00) != 0 )
  {
    sub_10DC24(
      patch_apply_n488,
      BYTE1(v7),
      (v7 >> 8) & 1,
      (v7 >> 9) & 1,
      (v7 >> 10) & 1,
      (v7 >> 11) & 1,
      (v7 >> 12) & 1,
      (v7 >> 13) & 1,
      (v7 >> 15) & 1);
    if ( (v7 & 0x8000) != 0 )
      sub_10DC24(patch_apply_n48c, *((_DWORD *)off_115304 + 14));
  }
  if ( HIWORD(v7) )
    sub_10DC24(
      patch_apply_n484,
      HIWORD(v7),
      HIWORD(v7) & 1,
      (v7 >> 17) & 1,
      (v7 >> 18) & 1,
      (v7 >> 19) & 1,
      HIBYTE(v7) & 1,
      (v7 >> 25) & 1);
  if ( (v0[19] & 8) == 0 )
  {
    sub_10DC24(dword_115328);
    goto LABEL_9;
  }
  sub_10DC24(dword_115314);
  if ( (v0[20] & 1) == 0 )
  {
LABEL_9:
    sub_10DC24(dword_115318);
    goto LABEL_10;
  }
  sub_10DC24(patch_apply_n480);
LABEL_10:
  v8 = v0[19];
  v9 = v8 << 29;
  if ( (v8 & 4) != 0 )
    sub_10DC24(dword_11531C, v9);
  else
    sub_10DC24(patch_apply_n474, v9);
  v10 = v0[20];
  CPSR = __get_CPSR();
  v12 = __get_CPSR();
  v26 = __get_CPSR();
  result = sub_10DC24(patch_apply_n478, v10, CPSR, v12, v26);
  v14 = v0[18];
  if ( v14 )
  {
    v21 = patch_apply_n49c;
    v22 = dword_11534C;
    v23 = v14 & 0xFFFFFFF0;
    sub_10DC24(patch_apply_n4a4);
    v24 = v23 + 256;
    do
    {
      if ( !(v23 << 28) )
        sub_10DC24(v21, v23);
      v25 = *(_DWORD *)v23;
      v23 += 4;
      result = sub_10DC24(v22, v25);
    }
    while ( v24 != v23 );
  }
  v15 = v0[17];
  if ( v15 )
  {
    v16 = patch_apply_n49c;
    v17 = dword_11534C;
    v18 = v15 & 0xFFFFFFF0;
    sub_10DC24(patch_apply_n498);
    v19 = v18 + 256;
    do
    {
      if ( !(v18 << 28) )
        sub_10DC24(v16, v18);
      v20 = *(_DWORD *)v18;
      v18 += 4;
      result = sub_10DC24(v17, v20);
    }
    while ( v19 != v18 );
  }
  return result;
}

