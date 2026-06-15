// sub_121544 @ 0x121544, size 96 bytes
int __fastcall sub_121544(int a1, int *a2, __int16 a3, __int16 a4)
{
  int v5; // r0
  _DWORD *v6; // r2
  int *v7; // r5
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = sub_11DDF0(1027, a4, a3, 8u);
  v6 = (_DWORD *)*a2;
  v7 = (int *)v5;
  if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
  {
    sub_10F010((int)v6, a2[1], 1);
    v9 = sub_10EFBC(*a2, 1);
    v8 = *a2;
  }
  else
  {
    *v6 = a2[1];
    v8 = *a2;
    v9 = *(_DWORD *)*a2;
  }
  v7[1] = v9;
  v10 = a2[1];
  *v7 = v8;
  sub_11F504(dword_1215A4, v10);
  sub_11DE50((int)v7);
  return 0;
}

