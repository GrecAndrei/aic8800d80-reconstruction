// v23 annotated: sub_12C80C @ 0x12c80c
// Original: 12c80c_sub_12C80C.c
// Primary struct: <unclustered>
//
// sub_12C80C @ 0x12c80c, size 288 bytes
int __fastcall sub_12C80C(int a1, int a2, unsigned int a3)
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

  v3 = (__int16 **)off_12C958;
  if ( **(__int16 **)off_12C958 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_12C944 )
        sub_12F694(dword_12C94C, dword_12C948, 148);
    }
    else
    {
      sub_12F694(dword_12C950, dword_12C948, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12C92C = 1;
  }
  v7 = (int *)off_12C95C;
  v8 = off_12C960;
  v9 = *((_DWORD *)off_12C960 + 5);
  ++*(_DWORD *)off_12C95C;
  if ( v9 )
    v9 = *(unsigned __int16 *)(v9 + 4) == a1 && *(unsigned __int16 *)(v9 + 6) == a2;
  v10 = sub_12CC64(dword_12C934, dword_12C930, a2 | (a1 << 16));
  if ( !v10 )
  {
    v17 = sub_12CD0C(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      sub_12F694(dword_12C954, dword_12C948, 165);
    *(_WORD *)(v10 + 4) = a1;
    *(_WORD *)(v10 + 6) = a2;
  }
  v11 = dword_12C93C;
  v12 = dword_12C934;
  v13 = a3 + *((_DWORD *)off_12C938 + 4);
  *(_DWORD *)(v10 + 8) = v13;
  result = sub_12D5A8(v12, v10, v11);
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = sub_124F60(dword_12C940, *(_DWORD *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(_DWORD *)off_12C92C, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((_DWORD *)off_12C938 + 4)) < 0 )
      return sub_12D32C(0x10000000);
  }
  else if ( (int)(v13 - *((_DWORD *)off_12C938 + 4)) < 0 )
  {
    return sub_12D32C(0x10000000);
  }
  return result;
}

