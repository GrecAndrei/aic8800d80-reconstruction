// sub_12C5E4 @ 0x12c5e4, size 288 bytes
int __fastcall sub_12C5E4(int a1, int a2, unsigned int a3)
{
  __int16 **v3; // r11
  int *v7; // r8
  _DWORD *v8; // r10
  int v9; // r6
  int v10; // r4
  int v11; // r2
  int v12; // r0
  unsigned int v13; // r5
  int result; // r0
  int v15; // r3
  int v16; // r2
  int v17; // r0

  v3 = (__int16 **)off_12C730;
  if ( **(__int16 **)off_12C730 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_12C71C )
        sub_12F46C(dword_12C724, dword_12C720, 148);
    }
    else
    {
      sub_12F46C(dword_12C728, dword_12C720, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12C704 = 1;
  }
  v7 = (int *)off_12C734;
  v8 = off_12C738;
  v9 = *((_DWORD *)off_12C738 + 5);
  ++*(_DWORD *)off_12C734;
  if ( v9 )
    v9 = *(unsigned __int16 *)(v9 + 4) == a1 && *(unsigned __int16 *)(v9 + 6) == a2;
  v10 = sub_12CA3C(dword_12C70C, dword_12C708, a2 | (a1 << 16));
  if ( !v10 )
  {
    v17 = sub_12CAE4(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      sub_12F46C(dword_12C72C, dword_12C720, 165);
    *(_WORD *)(v10 + 4) = a1;
    *(_WORD *)(v10 + 6) = a2;
  }
  v11 = dword_12C714;
  v12 = dword_12C70C;
  v13 = a3 + *((_DWORD *)off_12C710 + 4);
  *(_DWORD *)(v10 + 8) = v13;
  result = sub_12D380(v12, v10, v11);
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = sub_124D3C(dword_12C718, *(_DWORD *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(_DWORD *)off_12C704, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((_DWORD *)off_12C710 + 4)) < 0 )
      return sub_12D104(0x10000000);
  }
  else if ( (int)(v13 - *((_DWORD *)off_12C710 + 4)) < 0 )
  {
    return sub_12D104(0x10000000);
  }
  return result;
}

