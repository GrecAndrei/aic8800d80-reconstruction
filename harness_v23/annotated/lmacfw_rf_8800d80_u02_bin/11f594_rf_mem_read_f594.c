// v23 annotated: rf_mem_read_f594 @ 0x11f594
// Original: 11f594_rf_mem_read_f594.c
// Primary struct: <unclustered>
//
// rf_mem_read_f594 @ 0x11f594, size 404 bytes
// Doc: rf_mem_read_n72 [rf]: Bulk RF memory read across entry table
// rf_mem_read_n72 [rf]: Bulk RF memory read across entry table
unsigned int __fastcall rf_mem_read_f594(unsigned int result, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r9
  unsigned int v6; // r5
  unsigned int v7; // r7
  int v8; // r8
  int v9; // r10
  unsigned __int16 *v10; // r6
  unsigned int v11; // r11
  int v12; // r1
  int v13; // r0
  int v14; // r10
  _BYTE *v15; // r11
  int v16; // r4
  unsigned int v17; // r8
  unsigned int v19; // r8
  int v20; // r0
  int v21; // r10
  unsigned int v22; // r8
  unsigned int cb_efa4; // r6
  unsigned int v24; // [sp+Ch] [bp-10h]
  int v26; // [sp+14h] [bp-8h]

  if ( !a2 )
    return result;
  v4 = a3;
  if ( a3 != 4 && (unsigned int)(a3 - 1) > 1 )
    return result;
  v5 = dword_11F73C;
  v24 = a2 * a3;
  v6 = -a3 & result;
  while ( 1 )
  {
    msg_parse(dword_11F728, v6);
    v7 = v24;
    if ( v24 >= 0x10 )
      v7 = 16;
    if ( ((v6 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      if ( !v24 )
        return (unsigned int)uart_puts((_BYTE *)rf_mem_read_n1a0);
      v21 = dword_11F72C;
      v22 = 0;
      while ( 1 )
      {
        cb_efa4 = rf_reg_read_cb_efa4();
        if ( v4 == 4 )
          break;
        if ( v4 == 2 )
        {
          v22 += 4;
          msg_parse(dword_11F738, (unsigned __int16)cb_efa4, HIWORD(cb_efa4), BYTE2(cb_efa4));
          v6 += 4;
          if ( v7 <= v22 )
          {
rf_mem_read_n166:
            a4 = 0;
            goto rf_mem_read_nfa;
          }
        }
        else
        {
          msg_parse(v5);
rf_mem_read_6b8:
          v22 += 4;
          v6 += 4;
          if ( v7 <= v22 )
            goto rf_mem_read_n166;
        }
      }
      msg_parse(v21, cb_efa4, BYTE1(cb_efa4), BYTE2(cb_efa4));
      goto rf_mem_read_6b8;
    }
    if ( v24 )
      break;
    if ( a4 )
    {
      v10 = (unsigned __int16 *)v6;
      goto rf_mem_read_n90;
    }
rf_mem_read_nfa:
    result = (unsigned int)uart_puts((_BYTE *)rf_mem_read_n1a0);
    v24 -= v7;
    if ( !v24 )
      return result;
  }
  v8 = dword_11F740;
  v9 = dword_11F744;
  v10 = (unsigned __int16 *)v6;
  v11 = 0;
  do
  {
    while ( 1 )
    {
      v13 = v8;
      if ( v4 != 4 )
        break;
      v11 += 4;
      msg_parse(dword_11F72C, *(_DWORD *)v10);
      v10 += 2;
      if ( v7 <= v11 )
        goto rf_mem_read_0;
    }
    if ( v4 == 2 )
      v12 = *v10;
    else
      v12 = *(unsigned __int8 *)v10;
    if ( v4 == 2 )
      v13 = v9;
    v11 += v4;
    msg_parse(v13, v12);
    v10 = (unsigned __int16 *)((char *)v10 + v4);
  }
  while ( v7 > v11 );
rf_mem_read_0:
  if ( !a4 )
    goto LABEL_30;
  if ( v24 > 0xF )
  {
    uart_puts((_BYTE *)dword_11F730);
    goto LABEL_26;
  }
rf_mem_read_n90:
  v14 = v4 - 1;
  v26 = v4;
  v15 = (_BYTE *)rf_mem_read_n1b4;
  v16 = 0;
  v17 = 16 - v7;
  do
  {
    while ( (v14 & v16++) != 0 )
    {
      uart_puts(v15);
      if ( v17 == v16 )
        goto rf_mem_read_ncc;
    }
    uart_putc(32);
    uart_puts(v15);
  }
  while ( v17 != v16 );
rf_mem_read_ncc:
  v4 = v26;
  uart_puts((_BYTE *)dword_11F730);
  if ( v24 )
  {
LABEL_26:
    v19 = 0;
    do
    {
      v20 = *(unsigned __int8 *)(v6 + v19);
      if ( (unsigned int)(v20 - 31) > 0x5F )
        v20 = 46;
      ++v19;
      uart_putc(v20);
    }
    while ( v7 > v19 );
LABEL_30:
    v6 = (unsigned int)v10;
    goto rf_mem_read_nfa;
  }
  return (unsigned int)uart_puts((_BYTE *)rf_mem_read_n1a0);
}

