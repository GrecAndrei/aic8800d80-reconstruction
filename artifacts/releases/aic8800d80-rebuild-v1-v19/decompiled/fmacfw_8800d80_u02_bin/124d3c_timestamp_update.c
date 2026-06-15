// timestamp_update @ 0x124d3c, size 212 bytes
// Doc: timestamp_update [util]: Updates timestamp value with shifted high/low words
// timestamp_update [util]: Updates timestamp value with shifted high/low words
int __fastcall timestamp_update(int a1, int a2)
{
  int *v4; // r7
  _DWORD *v5; // r2
  int *v6; // r6
  int v7; // r2
  int result; // r0
  int v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r2
  _DWORD *v13; // r2
  int v14; // r1

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_124E10 = 1;
  }
  v4 = (int *)off_124E14;
  v5 = off_124E18;
  ++*(_DWORD *)off_124E14;
  if ( a2 - v5[4] < 0 )
  {
    msg_parse(dword_124E24, *(_DWORD *)(a1 + 4), a2);
    if ( **(__int16 **)off_124E28 < 0 )
      sub_12F46C(dword_124E30, dword_124E2C, 131);
  }
  v6 = (int *)off_124E1C;
  if ( a1 == *(_DWORD *)off_124E1C )
  {
    rf_bus_mark_n100_d2d0(off_124E1C);
    v12 = dword_124E20;
    *(_DWORD *)(a1 + 12) = a2;
    result = list_insert_sorted_d380(v6, a1, v12);
    v9 = *v6;
    if ( !*v6 )
    {
      *((_DWORD *)off_124E18 + 2) = 1024;
      goto LABEL_6;
    }
    goto LABEL_14;
  }
  sub_12D2E8(off_124E1C, a1);
  v7 = dword_124E20;
  *(_DWORD *)(a1 + 12) = a2;
  result = list_insert_sorted_d380(v6, a1, v7);
  v9 = *v6;
  if ( a1 == *v6 )
  {
LABEL_14:
    v13 = off_124E18;
    v14 = *(_DWORD *)(v9 + 12);
    result = 0x40000;
    *((_DWORD *)off_124E18 + 2) = 0x40000;
    v13[12] = v14;
    v13[2] = 4;
  }
LABEL_6:
  if ( *v4 && (v10 = *v4 - 1, v11 = *(_DWORD *)off_124E10, (*v4 = v10) == 0) && v11 )
  {
    __enable_irq();
    if ( a2 - *((_DWORD *)off_124E18 + 4) < 0 )
      return irq_nesting_or_d104(0x20000000);
  }
  else if ( a2 - *((_DWORD *)off_124E18 + 4) < 0 )
  {
    return irq_nesting_or_d104(0x20000000);
  }
  return result;
}

