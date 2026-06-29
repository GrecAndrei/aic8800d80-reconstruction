// fwstruct annotate: 12f65c_sub_12F65C.c
// sub_12F65C @ 0x12f65c, size 144 bytes
unsigned int __fastcall sub_12F65C(unsigned int a1, int a2, int a3)
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
    v4 = (int *)off_12F6EC;
    if ( a3 < *(_DWORD *)off_12F6EC )
    {
      v8 = (_BYTE *)dword_12F6F4;
      do
      {
        uart_puts(v8);
        v9 = *v4 - 1;
        *v4 = v9;
      }
      while ( v9 > a3 );
    }
    if ( v3 > a1 )
    {
      v10 = dword_12F6F8;
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
        uart_puts((_BYTE *)((*v4 & 7) + v10));
        *v4 = (*v4 & 0xFFFFFFF8) + 8;
      }
      while ( v11 != v12 );
    }
  }
  else
  {
    uart_puts((_BYTE *)dword_12F6F4);
    --*(_DWORD *)off_12F6EC;
  }
LABEL_10:
  --*(_DWORD *)off_12F6F0;
  return v3;
}

