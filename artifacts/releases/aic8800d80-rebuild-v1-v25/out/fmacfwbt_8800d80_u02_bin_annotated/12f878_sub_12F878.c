// fwstruct annotate: 12f878_sub_12F878.c
// sub_12F878 @ 0x12f878, size 144 bytes
// Doc: sub_122F878 [unknown]: Unknown function in fmacfwbt firmware
// sub_122F878 [unknown]: Unknown function in fmacfwbt firmware
unsigned int __fastcall sub_12F878(unsigned int a1, int a2, int a3)
{
  unsigned int v3; // r7
  int *v4; // r5
  _BYTE *v8; // r9
  int v9; // r3
  int v10; // r8
  unsigned __int8 *v11; // r4
  unsigned __int8 *v12; // r6
  int v13; // t1

  v3 = a2 - 1;
  if ( *(_BYTE *)(a2 - 1) == 9 )
  {
    v4 = (int *)off_12F908;
    if ( a3 < *(_DWORD *)off_12F908 )
    {
      v8 = (_BYTE *)dword_12F910;
      do
      {
        sub_10D60C(v8);
        v9 = *v4 - 1;
        *v4 = v9;
      }
      while ( v9 > a3 );
    }
    if ( v3 > a1 )
    {
      v10 = dword_12F914;
      v11 = (unsigned __int8 *)(a1 - 1);
      v12 = (unsigned __int8 *)(a2 - 2);
      do
      {
        while ( 1 )
        {
          v13 = *++v11;
          if ( v13 == 9 )
            break;
          ++*v4;
          uart_putc(*v11);
          if ( v11 == v12 )
            goto LABEL_10;
        }
        sub_10D60C((_BYTE *)((*v4 & 7) + v10));
        *v4 = (*v4 & 0xFFFFFFF8) + 8;
      }
      while ( v11 != v12 );
    }
  }
  else
  {
    sub_10D60C((_BYTE *)dword_12F910);
    --*(_DWORD *)off_12F908;
  }
LABEL_10:
  --*(_DWORD *)off_12F90C;
  return v3;
}

