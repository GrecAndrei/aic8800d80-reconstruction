// v23 annotated: sub_12EEA0 @ 0x12eea0
// Original: 12eea0_sub_12EEA0.c
// Primary struct: <unclustered>
//
// sub_12EEA0 @ 0x12eea0, size 120 bytes
int __fastcall sub_12EEA0(int a1, int *a2, __int16 a3, __int16 a4)
{
  int *v5; // r0
  int *v6; // r5
  _DWORD *v7; // r0
  int v8; // r3
  int v9; // r0
  int v10; // r2

  v5 = (int *)sub_12C7EC(1027, a4, a3, 8u);
  v6 = v5;
  if ( (unsigned int)**(unsigned __int8 **)off_12EF18 - 1 <= 1 )
  {
    v10 = a2[1];
    *(_QWORD *)v5 = *(_QWORD *)a2;
  }
  else
  {
    v7 = (_DWORD *)*a2;
    if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      sub_10EC98((int)v7, a2[1], 1);
      v9 = sub_10EC44(*a2, 1);
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
  sub_12E948(dword_12EF1C, v10);
  sub_12C84C((int)v6);
  return 0;
}

