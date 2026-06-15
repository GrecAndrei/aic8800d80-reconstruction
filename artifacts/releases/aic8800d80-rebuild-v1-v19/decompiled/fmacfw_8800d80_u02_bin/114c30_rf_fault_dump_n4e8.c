// rf_fault_dump_n4e8 @ 0x114c30, size 248 bytes
// Doc: patch_apply_4ca0 [patch]: Apply a 4-byte firmware/code patch to target
// patch_apply_4ca0 [patch]: Apply a 4-byte firmware/code patch to target
int __fastcall rf_fault_dump_n4e8(int a1, int a2, unsigned int a3)
{
  int v6; // r4
  unsigned int v7; // r5
  _DWORD v9[4]; // [sp+0h] [bp-4Ch] BYREF
  _BYTE v10[4]; // [sp+10h] [bp-3Ch] BYREF
  _BYTE v11[12]; // [sp+14h] [bp-38h] BYREF
  _BYTE v12[20]; // [sp+20h] [bp-2Ch] BYREF
  _BYTE v13[8]; // [sp+34h] [bp-18h] BYREF
  _BYTE v14[4]; // [sp+3Ch] [bp-10h] BYREF
  _BYTE v15[4]; // [sp+40h] [bp-Ch] BYREF
  _BYTE v16[8]; // [sp+44h] [bp-8h] BYREF

  if ( !*(_DWORD *)off_114D28 )
    rf_fault_dump_n4b0();
  MEMORY[0x1D8](*(_DWORD *)off_114D2C + 0x2000, 72, v9);
  if ( v9[0] != patch_apply_17c )
    return -1;
  v6 = a1 & v9[1];
  if ( !v6 )
    return 1;
  v7 = v6 & 1;
  if ( (v6 & 1) != 0 )
  {
    sub_143770(a2, v10, 4);
    v7 = 4;
    if ( (v6 & 2) == 0 )
    {
LABEL_7:
      if ( (v6 & 4) == 0 )
        goto patch_apply_n_23a;
      goto LABEL_22;
    }
  }
  else if ( (v6 & 2) == 0 )
  {
    goto LABEL_7;
  }
  sub_143770(a2 + v7, v11, 12);
  v7 += 12;
  if ( (v6 & 4) == 0 )
  {
patch_apply_n_23a:
    if ( (v6 & 8) == 0 )
      goto rf_state_check_n_3a6;
    goto LABEL_20;
  }
LABEL_22:
  sub_143770(a2 + v7, v12, 20);
  v7 += 20;
  if ( (v6 & 8) == 0 )
  {
rf_state_check_n_3a6:
    if ( (v6 & 0x20) == 0 )
      goto patch_apply_n_232;
    goto LABEL_18;
  }
LABEL_20:
  sub_143770(a2 + v7, v13, 4);
  v7 += 4;
  if ( (v6 & 0x20) == 0 )
  {
patch_apply_n_232:
    if ( (v6 & 0x40) == 0 )
      goto patch_apply_n_22e;
    goto LABEL_16;
  }
LABEL_18:
  sub_143770(a2 + v7, v14, 4);
  v7 += 4;
  if ( (v6 & 0x40) == 0 )
  {
patch_apply_n_22e:
    if ( (v6 & 0x80) == 0 )
      goto patch_apply_n_22a;
    goto patch_apply_c90;
  }
LABEL_16:
  sub_143770(a2 + v7, v15, 4);
  v7 += 4;
  if ( (v6 & 0x80) != 0 )
  {
patch_apply_c90:
    sub_143770(a2 + v7, v16, 4);
    v7 += 4;
  }
patch_apply_n_22a:
  if ( a3 < v7 )
    return -2;
  else
    return 0;
}

