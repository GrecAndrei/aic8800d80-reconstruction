// v23 annotated: sub_11DAFC @ 0x11dafc
// Original: 11dafc_sub_11DAFC.c
// Primary struct: <unclustered>
//
// sub_11DAFC @ 0x11dafc, size 288 bytes
int __fastcall sub_11DAFC(int a1, int a2, unsigned int a3)
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

  v3 = (__int16 **)off_11DC48;
  if ( **(__int16 **)off_11DC48 < 0 )
  {
    if ( a3 )
    {
      if ( a3 > dword_11DC34 )
        sub_1219C4(dword_11DC3C, dword_11DC38, 148);
    }
    else
    {
      sub_1219C4(dword_11DC40, dword_11DC38, 147);
    }
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11DC1C = 1;
  }
  v7 = (int *)off_11DC4C;
  v8 = off_11DC50;
  v9 = *((_DWORD *)off_11DC50 + 5);
  ++*(_DWORD *)off_11DC4C;
  if ( v9 )
    v9 = *(unsigned __int16 *)(v9 + 4) == a1 && *(unsigned __int16 *)(v9 + 6) == a2;
  v10 = sub_11DEEC(dword_11DC24, dword_11DC20, a2 | (a1 << 16));
  if ( !v10 )
  {
    v17 = sub_11DF94(12);
    v10 = v17;
    if ( **v3 < 0 && !v17 )
      sub_1219C4(dword_11DC44, dword_11DC38, 165);
    *(_WORD *)(v10 + 4) = a1;
    *(_WORD *)(v10 + 6) = a2;
  }
  v11 = dword_11DC2C;
  v12 = dword_11DC24;
  v13 = a3 + *((_DWORD *)off_11DC28 + 4);
  *(_DWORD *)(v10 + 8) = v13;
  result = sub_11E840(v12, v10, v11);
  if ( v9 )
  {
    v10 = v8[5];
    if ( !v10 )
      goto LABEL_10;
LABEL_15:
    result = sub_11AB18(dword_11DC30, *(_DWORD *)(v10 + 8));
    goto LABEL_10;
  }
  if ( v8[5] == v10 )
    goto LABEL_15;
LABEL_10:
  if ( *v7 && (v15 = *v7 - 1, v16 = *(_DWORD *)off_11DC1C, (*v7 = v15) == 0) && v16 )
  {
    __enable_irq();
    if ( (int)(v13 - *((_DWORD *)off_11DC28 + 4)) < 0 )
      return sub_11E5E0(0x10000000);
  }
  else if ( (int)(v13 - *((_DWORD *)off_11DC28 + 4)) < 0 )
  {
    return sub_11E5E0(0x10000000);
  }
  return result;
}

