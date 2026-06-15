// sub_12F154 @ 0x12f154, size 72 bytes
int __fastcall sub_12F154(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  _DWORD *v6; // r1
  _DWORD *v7; // r4
  int v9; // r0

  v5 = sub_12CB54(1025, a4, a3, 8u);
  v6 = (_DWORD *)*a2;
  v7 = (_DWORD *)v5;
  if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    v9 = sub_10EBDC(*a2, 1);
    v6 = (_DWORD *)*a2;
    v7[1] = v9;
  }
  else
  {
    *(_DWORD *)(v5 + 4) = *v6;
  }
  *v7 = v6;
  sub_12ECB0(dword_12F19C);
  sub_12CBB4((int)v7);
  return 0;
}

