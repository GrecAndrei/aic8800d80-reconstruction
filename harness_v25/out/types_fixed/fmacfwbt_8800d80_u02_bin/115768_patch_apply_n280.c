// patch_apply_n280 @ 0x115768, size 464 bytes
// Doc: patch_apply_n292 [patch]: Apply patch entries from a descriptor table
// patch_apply_n292 [patch]: Apply patch entries from a descriptor table
int patch_apply_n280()
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

  v0 = patch_apply_n450_5938;
  v1 = dword_11593C;
  v2 = (int *)patch_apply_n450_5938;
  for ( i = 0; i != 13; ++i )
  {
    v4 = i;
    v5 = *v2++;
    log_printf(v1, v4, v5);
  }
  v6 = off_115940;
  log_printf(patch_apply_n45c, *(_DWORD *)(v0 + 0x34), *(_DWORD *)(v0 + 0x38), *(_DWORD *)(v0 + 0x3c), *(_DWORD *)(v0 + 0x40), *(_DWORD *)(v0 + 0x44), *(_DWORD *)(v0 + 0x48));
  log_printf(patch_apply_n460, *v6, *(_DWORD *)(v6 + 0x4), *(_DWORD *)(v6 + 0x8), *(_DWORD *)(v6 + 0xc));
  log_printf(dword_11594C, *(_DWORD *)(v6 + 0x24), *(_DWORD *)(v6 + 0x28), *(_DWORD *)(v6 + 0x2c), *(_DWORD *)(v6 + 0x30), *(_DWORD *)(v6 + 0x3c));
  v7 = *(_DWORD *)(v6 + 0x28);
  if ( (_BYTE)v7 )
  {
    log_printf(
      patch_apply_n490,
      (unsigned __int8)*(_DWORD *)(v6 + 0x28),
      v7 & 1,
      (v7 >> 1) & 1,
      (v7 >> 3) & 1,
      (v7 >> 4) & 1,
      (v7 >> 5) & 1,
      (v7 >> 7) & 1);
    if ( (v7 & 0x80) != 0 )
      log_printf(patch_write_table_entry, *(_DWORD *)(v6 + 0x34));
  }
  if ( (v7 & 0xFF00) != 0 )
  {
    log_printf(
      dword_115970,
      BYTE1(v7),
      (v7 >> 8) & 1,
      (v7 >> 9) & 1,
      (v7 >> 10) & 1,
      (v7 >> 11) & 1,
      (v7 >> 12) & 1,
      (v7 >> 13) & 1,
      (v7 >> 15) & 1);
    if ( (v7 & 0x8000) != 0 )
      log_printf(dword_115974, *((_DWORD *)off_115940 + 14));
  }
  if ( HIWORD(v7) )
    log_printf(
      patch_apply_n484_596c,
      HIWORD(v7),
      HIWORD(v7) & 1,
      (v7 >> 17) & 1,
      (v7 >> 18) & 1,
      (v7 >> 19) & 1,
      HIBYTE(v7) & 1,
      (v7 >> 25) & 1);
  if ( (*(_DWORD *)(v0 + 0x4c) & 8) == 0 )
  {
    log_printf(patch_apply_n47c);
    goto patch_apply_n308;
  }
  log_printf(patch_apply_n468);
  if ( (*(_DWORD *)(v0 + 0x50) & 1) == 0 )
  {
patch_apply_n308:
    log_printf(patch_apply_n46c);
    goto patch_apply_n30e;
  }
  log_printf(patch_apply_n480_5968);
patch_apply_n30e:
  v8 = *(_DWORD *)(v0 + 0x4c);
  v9 = v8 << 29;
  if ( (v8 & 4) != 0 )
    log_printf(dword_115958, v9);
  else
    log_printf(patch_apply_n474_595c, v9);
  v10 = *(_DWORD *)(v0 + 0x50);
  CPSR = __get_CPSR();
  v12 = __get_CPSR();
  v26 = __get_CPSR();
  result = log_printf(patch_apply_n478, v10, CPSR, v12, v26);
  v14 = *(_DWORD *)(v0 + 0x48);
  if ( v14 )
  {
    v21 = patch_apply_n49c;
    v22 = dword_115988;
    v23 = v14 & 0xFFFFFFF0;
    log_printf(dword_11598C);
    v24 = v23 + 256;
    do
    {
      if ( !(v23 << 28) )
        log_printf(v21, v23);
      v25 = *(_DWORD *)v23;
      v23 += 4;
      result = log_printf(v22, v25);
    }
    while ( v24 != v23 );
  }
  v15 = *(_DWORD *)(v0 + 0x44);
  if ( v15 )
  {
    v16 = patch_apply_n49c;
    v17 = dword_115988;
    v18 = v15 & 0xFFFFFFF0;
    log_printf(dword_115980);
    v19 = v18 + 256;
    do
    {
      if ( !(v18 << 28) )
        log_printf(v16, v18);
      v20 = *(_DWORD *)v18;
      v18 += 4;
      result = log_printf(v17, v20);
    }
    while ( v19 != v18 );
  }
  return result;
}

