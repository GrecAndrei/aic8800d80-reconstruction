// fwstruct annotate: 117bbc_fw_init_umac_subsystem.c
// fw_init_umac_subsystem @ 0x117bbc, size 246 bytes
// Doc: fw_init_umac_subsystem [util]: Initialize UMAC subsystem with 0x1f000 base
// fw_init_umac_subsystem [util]: Initialize UMAC subsystem with 0x1f000 base
__int64 fw_init_umac_subsystem()
{
  _BYTE *v0; // r8
  int v1; // r10
  char *v2; // r5
  _BYTE *v3; // r4
  char *v4; // r9
  _BYTE *v5; // r7
  int v6; // r6
  int v7; // r11
  int v8; // r9
  int inited; // r0
  int v10; // r0
  int v11; // r0
  __int16 v12; // r7
  char *v13; // r0
  int i; // r6
  int v15; // r2
  __int64 result; // r0
  _DWORD *v17; // r3
  _BYTE v18[44]; // [sp+0h] [bp-2Ch] BYREF

  v0 = off_117CBC;
  v1 = dword_117CC0;
  clear_flags(126976);
  v2 = v0 + 12;
  v3 = v18;
  v0[510] = 1;
  v4 = v0 + 12;
  v5 = v18;
  v6 = 0;
  do
  {
    v7 = (unsigned __int8)v6;
    sub_12D240(v5);
    sub_118940((unsigned __int8)v6++, v1, v5);
    sub_118940(v7, v4, v5);
    v1 += 8;
    v5 += 8;
    v4 += 84;
  }
  while ( v6 != 5 );
  v8 = dword_117CB4;
  inited = fmac_buffer_init_n_setup(5);
  v10 = sub_119E74(inited);
  v11 = subsys_init(v10);
  sub_11BEE0(v11);
  v12 = *((_WORD *)v0 + 254);
  memset_thunk((int *)(v8 - 432), 0, 0x204u);
  *((_WORD *)v0 + 254) = v12;
  do
  {
    sub_12D240(v2);
    *((_DWORD *)v2 - 3) = 0;
    v2[14] = 0;
    v2[68] = 0;
    *((_DWORD *)v2 + 6) = 0;
    *((_DWORD *)v2 + 7) = 0;
    v13 = v2 + 16;
    v2 += 84;
    sub_12D240(v13);
  }
  while ( v2 != (char *)v8 );
  for ( i = 0; i != 5; ++i )
  {
    if ( rf_bus_mark_n100_d2d0(v3) )
    {
      do
        sub_13AF24();
      while ( rf_bus_mark_n100_d2d0(v3) );
      sub_11A7E8((unsigned __int8)i);
    }
    v3 += 8;
  }
  v15 = dword_117CB8;
  result = (unsigned int)(dword_117CB8 + 1152);
  do
  {
    v17 = (_DWORD *)(v15 - 36);
    do
      *v17++ = 0;
    while ( (_DWORD *)v15 != v17 );
    v15 += 36;
  }
  while ( (_DWORD)result != v15 );
  return result;
}

