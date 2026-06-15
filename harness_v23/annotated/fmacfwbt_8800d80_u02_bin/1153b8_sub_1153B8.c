// v23 annotated: sub_1153B8 @ 0x1153b8
// Original: 1153b8_sub_1153B8.c
// Primary struct: <unclustered>
//
// sub_1153B8 @ 0x1153b8, size 228 bytes
// Doc: patch_apply_n_e4_5404 [patch]: Compute patch offset by shifting index left by 7
// patch_apply_n_e4_5404 [patch]: Compute patch offset by shifting index left by 7
int __fastcall sub_1153B8(int a1, int a2, unsigned int a3)
{
  unsigned int v6; // r4
  int v8; // [sp+0h] [bp-144h] BYREF
  int v9; // [sp+4h] [bp-140h]
  _BYTE v10[272]; // [sp+14h] [bp-130h] BYREF
  _BYTE v11[4]; // [sp+124h] [bp-20h] BYREF
  _BYTE v12[8]; // [sp+128h] [bp-1Ch] BYREF
  _BYTE v13[4]; // [sp+130h] [bp-14h] BYREF
  _BYTE v14[2]; // [sp+134h] [bp-10h] BYREF
  _BYTE v15[14]; // [sp+136h] [bp-Eh] BYREF

  if ( !*(_DWORD *)patch_apply_n_4c_549c )
    patch_apply_n_2b4();
  MEMORY[0x1D8](*(_DWORD *)off_1154A0 + 4096, 320, &v8);
  if ( v8 != patch_apply_n_44_4a4 )
    return -1;
  if ( (v9 & a1) == 0 )
    return 1;
  v6 = (unsigned __int8)v9 & (unsigned __int8)a1 & 2;
  if ( ((unsigned __int8)v9 & (unsigned __int8)a1 & 2) != 0 )
  {
    sub_14380C(a2, v10, 6);
    v6 = 6;
    if ( (a1 & 0x100000) == 0 )
    {
patch_apply_n_f0:
      if ( (a1 & 0x200000) == 0 )
        goto patch_apply_n_ec_53fc;
      goto rf_cmd_build_44e;
    }
  }
  else if ( (a1 & 0x100000) == 0 )
  {
    goto patch_apply_n_f0;
  }
  sub_14380C(a2 + v6, v11, 2);
  v6 += 2;
  if ( (a1 & 0x200000) == 0 )
  {
patch_apply_n_ec_53fc:
    if ( (a1 & 0x400000) == 0 )
      goto patch_apply_400;
    goto LABEL_17;
  }
rf_cmd_build_44e:
  sub_14380C(a2 + v6, v12, 8);
  v6 += 8;
  if ( (a1 & 0x400000) == 0 )
  {
patch_apply_400:
    if ( (a1 & 0x800000) == 0 )
      goto patch_apply_n_e4_5404;
    goto LABEL_15;
  }
LABEL_17:
  sub_14380C(a2 + v6, v13, 4);
  v6 += 4;
  if ( (a1 & 0x800000) == 0 )
  {
patch_apply_n_e4_5404:
    if ( (a1 & 0x1000000) == 0 )
      goto patch_apply_range;
    goto LABEL_14;
  }
LABEL_15:
  sub_14380C(a2 + v6, v14, 2);
  v6 += 2;
  if ( (a1 & 0x1000000) != 0 )
  {
LABEL_14:
    sub_14380C(a2 + v6, v15, 10);
    v6 += 10;
  }
patch_apply_range:
  if ( a3 < v6 )
    return -2;
  else
    return 0;
}

