// sub_13B13C @ 0x13b13c, size 62 bytes
_WORD *__fastcall sub_13B13C(int a1, _WORD *a2, int a3)
{
  _WORD *v6; // r1
  int v8; // r0
  char v9; // r3
  int v10; // [sp+4h] [bp-4h] BYREF

  if ( *(_BYTE *)(a1 + 51) )
  {
    v6 = (_WORD *)((char *)a2 + a3 + *(unsigned __int8 *)(a1 + 51));
  }
  else
  {
    v8 = sub_13A5C4(a1, &v10);
    v9 = v10;
    *(_BYTE *)(a1 + 51) = v8;
    v6 = (_WORD *)((char *)a2 + a3 + v8);
    *(_BYTE *)(a1 + 53) = v9;
  }
  *a2 |= 0x4000u;
  return sub_13AA1C(a1, v6, 0);
}

