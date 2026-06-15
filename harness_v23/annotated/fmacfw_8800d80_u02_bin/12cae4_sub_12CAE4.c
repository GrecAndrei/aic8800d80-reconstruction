// v23 annotated: sub_12CAE4 @ 0x12cae4
// Original: 12cae4_sub_12CAE4.c
// Primary struct: <unclustered>
//
// sub_12CAE4 @ 0x12cae4, size 200 bytes
int __fastcall sub_12CAE4(int a1)
{
  __int16 **v1; // r7
  unsigned int v2; // r4
  unsigned int v3; // r6
  _DWORD *v4; // r3
  int *v5; // r5
  int v6; // r12
  _DWORD *v7; // r1
  unsigned int v8; // r2
  _DWORD *v9; // r2
  unsigned int v10; // r3
  int result; // r0
  int v12; // r2

  v1 = (__int16 **)off_12CBAC;
  v2 = (a1 + 3) & 0xFFFFFFFC;
  v3 = v2 + 4;
  if ( **(__int16 **)off_12CBAC < 0 && v3 <= 7 )
    sub_12F46C(dword_12CBC4, dword_12CBBC, 132);
  v4 = *((_DWORD **)off_12CBB0 + 7);
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12CBB4 = 1;
  }
  v5 = (int *)off_12CBB8;
  v6 = *(_DWORD *)off_12CBB8 + 1;
  *(_DWORD *)off_12CBB8 = v6;
  if ( v4 )
  {
    v7 = nullptr;
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = v4[1];
        if ( v8 >= v2 + 12 )
          break;
LABEL_8:
        v4 = (_DWORD *)*v4;
        if ( !v4 )
          goto LABEL_12;
      }
      if ( v7 )
      {
        if ( v8 < v7[1] )
          v7 = v4;
        goto LABEL_8;
      }
      v7 = v4;
      v4 = (_DWORD *)*v4;
      if ( !v4 )
      {
LABEL_12:
        if ( **v1 < 0 && !v7 )
          goto LABEL_20;
        v9 = v7;
        goto LABEL_14;
      }
    }
  }
  if ( **v1 >= 0 )
    __und(0xFFu);
LABEL_20:
  sub_12F46C(dword_12CBC0, dword_12CBBC, 160);
  v9 = nullptr;
  v6 = *v5;
  v7 = nullptr;
LABEL_14:
  v10 = v7[1] - v3;
  v7[1] = v10;
  result = (int)v9 + v10 + 4;
  *(_DWORD *)((char *)v9 + v10) = v3;
  if ( v6 )
  {
    v12 = *(_DWORD *)off_12CBB4;
    *v5 = v6 - 1;
    if ( v6 == 1 )
    {
      if ( v12 )
        __enable_irq();
    }
  }
  return result;
}

