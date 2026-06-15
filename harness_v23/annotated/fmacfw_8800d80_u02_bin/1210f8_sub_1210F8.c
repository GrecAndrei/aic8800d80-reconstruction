// v23 annotated: sub_1210F8 @ 0x1210f8
// Original: 1210f8_sub_1210F8.c
// Primary struct: <unclustered>
//
// sub_1210F8 @ 0x1210f8, size 520 bytes
// Doc: sub_12210F8 [util]: general utility function with register save
// sub_12210F8 [util]: general utility function with register save
int sub_1210F8()
{
  _DWORD *v0; // r6
  int v1; // r4
  int *v2; // r5
  int v3; // r0
  int v4; // r1
  int v5; // r3
  int v6; // r2
  _DWORD *v7; // r7
  _DWORD *v8; // r8
  _DWORD *v9; // r9
  int v10; // r5
  int v11; // r3
  _DWORD *v12; // r3
  _DWORD *v13; // r2
  unsigned int v14; // r10
  int v15; // r10
  int result; // r0
  _DWORD *v17; // r4
  int v18; // r2
  unsigned int v19; // r3
  bool v20; // zf
  bool v21; // cc
  int v22; // r3
  int v23; // r1
  int v24; // r3
  int v25; // r2
  int v26; // r3
  int v27; // r1
  int v28; // r0
  int **i; // r3
  int v30; // r2
  int v31; // r1
  int v32; // r12
  int v33; // r2

  v0 = off_121300;
  v1 = *((_DWORD *)off_121300 + 2);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_121304 = 1;
  }
  v2 = (int *)off_121308;
  ++*(_DWORD *)off_121308;
  rf_set_bit_flag(4);
  v3 = category_dispatch_5way(4);
  if ( *v2 && (v5 = *v2 - 1, v6 = *(_DWORD *)off_121304, (*v2 = v5) == 0) && v6 )
  {
    __enable_irq();
    if ( !v1 )
      return sub_1258C0(v3);
  }
  else if ( !v1 )
  {
    return sub_1258C0(v3);
  }
  v7 = off_12130C;
  v8 = off_121330;
  v9 = off_121338;
  v10 = 0;
  do
  {
    while ( 1 )
    {
      if ( *(_BYTE *)(v1 + 106) != 2 )
        goto LABEL_7;
      v11 = (unsigned __int8)(*(_BYTE *)(v1 + 225) - 1);
      *(_BYTE *)(v1 + 225) = v11;
      if ( v11 )
        goto LABEL_7;
      v12 = *(_DWORD **)off_121310;
      *(_BYTE *)(v1 + 225) = *(_BYTE *)(v1 + 224);
      if ( !v12 )
        break;
      v13 = (_DWORD *)(v1 + 48);
      while ( v12 != v13 )
      {
        v12 = (_DWORD *)*v12;
        if ( !v12 )
          goto LABEL_15;
      }
      v3 = msg_parse(dword_121324, v4, v13);
LABEL_7:
      v1 = *(_DWORD *)v1;
      if ( !v1 )
        goto LABEL_26;
    }
LABEL_15:
    mmio_read_status_reg(v1);
    v3 = fmac_status_chk_4c8(v1, *(_DWORD *)(v1 + 36) + 3048);
    v4 = *(unsigned __int16 *)(v1 + 222);
    v14 = 32 * *v7;
    if ( v14 <= 0xBE7 )
      v14 += v4 << 10;
    v15 = v14 + v8[4] - 3048;
    if ( *(_DWORD *)(v1 + 72) )
      v3 = fmac_handler_dispatch(v1, *(_DWORD *)(v1 + 36), v15);
    if ( *(_BYTE *)(v1 + 1224) )
    {
      v3 = timestamp_update(v1 + 24, v15);
    }
    else
    {
      if ( *((unsigned __int8 *)off_121314 + 90) > 1u )
      {
        for ( i = *((int ***)off_121314 + 4); i; i = (int **)*i )
        {
          v4 = *((unsigned __int8 *)i + 8);
          if ( v4 == *(unsigned __int8 *)(v1 + 107) )
          {
            v30 = *(unsigned __int16 *)(v1 + 222);
            v31 = *(_DWORD *)(v1 + 36);
            v3 = (int)i[1];
            v32 = v31 + (v30 << 10);
            v33 = v30 << 10;
            if ( v3 == v32 )
            {
              i[1] = (int *)v15;
              v3 = v15;
              v33 = *(unsigned __int16 *)(v1 + 222) << 10;
            }
            v4 = v31 + 2 * v33;
            if ( v4 == v3 )
              i[1] = (int *)(v33 + v15);
          }
        }
      }
      if ( *(_BYTE *)off_121318 && (v0[4] & 0xFFFF00) == 0x10000 && (unsigned __int16)*v9 > 0x14u )
      {
        v18 = v8[4];
        v19 = *(unsigned __int8 *)off_121328;
        v20 = v19 == 2;
        v21 = v19 > 2;
        v22 = (unsigned __int16)*v9;
        if ( v21 )
        {
          v3 = timestamp_update(dword_12132C, v18 + 500 * v22);
        }
        else
        {
          if ( v20 )
            v23 = 250;
          else
            v23 = 200;
          v3 = timestamp_update(dword_12132C, v18 + v23 * v22);
        }
      }
      *(_DWORD *)(v1 + 36) = v15;
    }
    if ( *(_BYTE *)(v1 + 412) == 1 )
      v10 = v1;
    v1 = *(_DWORD *)v1;
  }
  while ( v1 );
LABEL_26:
  result = sub_1258C0(v3);
  if ( *((_BYTE *)off_12131C + 413) )
  {
    if ( v10 )
    {
      v17 = off_121320;
      if ( *((_BYTE *)off_121320 + 15) )
      {
        result = msg_get_value(4);
        if ( result != 1 )
        {
          if ( !*((_BYTE *)v17 + 14)
            || (v24 = (unsigned __int8)(*((_BYTE *)v17 + 14) - 1), *((_BYTE *)v17 + 14) = v24, !v24) )
          {
            v25 = *(unsigned __int16 *)(v10 + 222);
            v26 = v17[4];
            v27 = *((_DWORD *)off_121330 + 4);
            v28 = dword_121334;
            v17[7] = v10;
            *((_BYTE *)v17 + 14) = *((_BYTE *)v17 + 15);
            return timestamp_update(v28, v27 + ((unsigned int)((v25 << 10) - v26) >> 1));
          }
        }
      }
    }
  }
  return result;
}

