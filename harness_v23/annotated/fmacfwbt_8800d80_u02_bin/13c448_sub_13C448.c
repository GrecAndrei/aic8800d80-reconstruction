// v23 annotated: sub_13C448 @ 0x13c448
// Original: 13c448_sub_13C448.c
// Primary struct: <unclustered>
//
// sub_13C448 @ 0x13c448, size 72 bytes
int __fastcall sub_13C448(int a1)
{
  int v1; // r5
  int result; // r0
  __int16 v4; // r2
  int v5; // r3
  bool v6; // zf

  v1 = *(_DWORD *)(a1 + 28);
  memset_thunk((int *)(v1 + 6), 0, 0x100u);
  result = 348;
  v4 = *(_WORD *)(dword_13C490 + 2 * (*(unsigned __int8 *)(a1 + 22) + 348 * *(unsigned __int8 *)(a1 + 16)) + 316);
  *(_BYTE *)(v1 + 262) = 0;
  v5 = *(unsigned __int8 *)(a1 + 20);
  *(_WORD *)(v1 + 4) = v4;
  v6 = ((v5 - 1) & v5) == 0;
  *(_BYTE *)(v1 + 263) = v5;
  if ( ((v5 - 1) & v5) != 0 )
    v5 = dword_13C494;
  else
    *(_BYTE *)(v1 + 264) = v5 - 1;
  if ( v6 )
    v5 = dword_13C498;
  *(_DWORD *)v1 = v5;
  return result;
}

