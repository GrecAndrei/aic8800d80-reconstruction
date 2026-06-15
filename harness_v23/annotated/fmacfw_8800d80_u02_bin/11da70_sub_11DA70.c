// v23 annotated: sub_11DA70 @ 0x11da70
// Original: 11da70_sub_11DA70.c
// Primary struct: <unclustered>
//
// sub_11DA70 @ 0x11da70, size 356 bytes
int __fastcall sub_11DA70(int inited)
{
  _DWORD *v1; // r7
  _BYTE *v2; // r9
  int v3; // r8
  int v4; // r6
  int i; // r5
  int v6; // r3
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // r4
  int result; // r0
  int v15; // r1
  int v16; // r2
  void (__fastcall *v17)(_DWORD); // r2
  void *v18; // r3
  _DWORD *v19; // r5
  int v20; // [sp+14h] [bp-8h]

  v1 = off_11DBD4;
  v2 = off_11DBF4;
  v3 = dword_11DC00;
  v4 = inited;
  for ( i = 0; ; ++i )
  {
    v13 = mmio_reg_poll_ready(inited);
    *v1 = 0x10000;
    result = clear_flags(0x80000);
    if ( !v13 )
      break;
    if ( !v4 )
    {
      v6 = (unsigned __int8)v2[192];
      if ( v2[192] )
      {
        v6 = *(_DWORD *)off_11DBD8;
        if ( *(_DWORD *)off_11DBD8 > 0x80000u || i > 31 )
          return irq_nesting_or_d104(0x80000);
      }
      else if ( i > 3 )
      {
        return irq_nesting_or_d104(0x80000);
      }
    }
    v7 = sub_12F538(result, v15, v16, v6);
    if ( !v7 || (v7 = sub_13A504(v7, v8, v9, v10)) == 0 )
    {
      v18 = off_11DBEC;
      *((_BYTE *)off_11DBEC + 69) = 1;
      sub_13A504(v7, v8, 1, v18);
      return feature_guard_check(1024, dword_11DBF0);
    }
    v11 = *(_DWORD *)(v13 + 20);
    if ( v11 != v3 )
      msg_parse(dword_11DBE0, v13, v11);
    sub_11EB34(v13);
    inited = fmac_frame_parse_or_rx_handler(v13);
    if ( inited )
    {
      if ( inited != 1 )
        goto LABEL_10;
    }
    else
    {
      inited = sub_139F5C(v13);
      if ( inited )
        goto LABEL_10;
    }
    inited = fmac_obj_init_n_1eaa0(v13);
LABEL_10:
    v12 = **(unsigned __int8 **)off_11DBE4;
    switch ( v12 )
    {
      case 2:
        goto LABEL_22;
      case 4:
        if ( !*(_DWORD *)off_11DBE8 || *(_DWORD *)(*(_DWORD *)off_11DBE8 + 12) != v13 || (*(_BYTE *)(v13 + 16) & 1) == 0 )
        {
LABEL_22:
          inited = mem_buf_alloc_n_c30();
          continue;
        }
        v20 = *(_DWORD *)off_11DBE8;
        rf_bus_mark_n100_d2d0(off_11DBE8);
        v17 = *(void (__fastcall **)(_DWORD))(v20 + 4);
        *(_BYTE *)(v20 + 16) = 0;
        if ( v17 )
          v17(*(_DWORD *)(v20 + 8));
        inited = sub_11E0B4(v13);
        break;
      case 3:
        inited = sub_11D8EC();
        break;
    }
  }
  if ( *((_BYTE *)off_11DBF4 + 192) )
  {
    v19 = off_11DBF8;
    if ( *((_BYTE *)off_11DBF8 + 33) )
    {
      result = sub_11101C(*((_DWORD *)off_11DBF8 + 4), *((_DWORD *)off_11DBF8 + 5), *((_DWORD *)off_11DBF8 + 6));
      v19[5] = 0;
      v19[7] = 0;
      v19[4] = 0;
      v19[6] = 0;
      *((_BYTE *)v19 + 33) = 0;
    }
  }
  *(_DWORD *)off_11DBFC |= 0x10000u;
  return result;
}

