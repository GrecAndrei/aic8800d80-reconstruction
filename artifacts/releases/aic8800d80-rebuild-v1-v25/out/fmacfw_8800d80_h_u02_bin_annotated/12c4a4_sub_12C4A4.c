// fwstruct annotate: 12c4a4_sub_12C4A4.c
// sub_12C4A4 @ 0x12c4a4, size 288 bytes
int __fastcall sub_12C4A4(int a1, int a2, unsigned int a3)
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

  v3 = (__int16 **)off_12C5F0;
  if ( **(__int16 **)off_12C5F0 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_12C5DC )
        sub_12F32C(dword_12C5E4, dword_12C5E0, 148);
    }
    else
    {
      sub_12F32C(dword_12C5E8, dword_12C5E0, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12C5C4 = 1;
  }
  v7 = (int *)off_12C5F4;
  v8 = off_12C5F8;
  v9 = *((_DWORD *)off_12C5F8 + 5);
  ++*(_DWORD *)off_12C5F4;
  if ( v9 )
    v9 = *(unsigned __int16 *)(v9 + 4) == a1 && *(unsigned __int16 *)(v9 + 6) == a2;
  v10 = sub_12C8FC(dword_12C5CC, off_12C5C8, a2 | (a1 << 16));
  if ( !v10 )
  {
    v17 = ((int (__fastcall *)(int))loc_12C9A4)(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      sub_12F32C(dword_12C5EC, dword_12C5E0, 165);
    *(_WORD *)(v10 + 4) = a1;
    *(_WORD *)(v10 + 6) = a2;
  }
  v11 = dword_12C5D4;
  v12 = dword_12C5CC;
  v13 = a3 + *((_DWORD *)off_12C5D0 + 4);
  *(_DWORD *)(v10 + 8) = v13;
  result = sub_12D240(v12, v10, v11);
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = sub_124BFC(dword_12C5D8, *(_DWORD *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(_DWORD *)off_12C5C4, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((_DWORD *)off_12C5D0 + 4)) < 0 )
      return sub_12CFC4(0x10000000);
  }
  else if ( (int)(v13 - *((_DWORD *)off_12C5D0 + 4)) < 0 )
  {
    return sub_12CFC4(0x10000000);
  }
  return result;
}

