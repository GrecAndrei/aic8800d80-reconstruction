// fwstruct annotate: 12f208_sub_12F208.c
// sub_12F208 @ 0x12f208, size 120 bytes
int __fastcall sub_12F208(int a1, int *a2, __int16 a3, __int16 a4)
{
  int *v5; // r0
  int *v6; // r5
  _DWORD *v7; // r0
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = (int *)sub_12CB54(1027, a4, a3, 8u);
  v6 = v5;
  if ( (unsigned int)**(unsigned __int8 **)off_12F280 - 1 <= 1 )
  {
    v10 = a2[1];
    *(_QWORD *)v5 = *(_QWORD *)a2;
  }
  else
  {
    v7 = (_DWORD *)*a2;
    if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      sub_10EC30((int)v7, a2[1], 1);
      v9 = sub_10EBDC(*a2, 1);
      v8 = *a2;
    }
    else
    {
      *v7 = a2[1];
      v8 = *a2;
      v9 = *(_DWORD *)*a2;
    }
    v6[1] = v9;
    v10 = a2[1];
    *v6 = v8;
  }
  sub_12ECB0(dword_12F284, v10);
  sub_12CBB4((int)v6);
  return 0;
}

