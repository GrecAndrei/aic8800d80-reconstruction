// sub_12F51C @ 0x12f51c, size 144 bytes
unsigned int  sub_12F51C(unsigned int a1, int a2, int a3)
{
  unsigned int v3; // r7
  int *v4; // r5
  uint8_t *v8; // r9
  int v9; // r3
  int v10; // r8
  unsigned __int8 *v11; // r4
  unsigned __int8 *v12; // r6
  int v13; // t1

  v3 = a2 - 1;
  if ( *(uint8_t *)(a2 - 1) == 9 )
  {
    v4 = (int *)off_12F5AC;
    if ( a3 < *(uint32_t *)off_12F5AC )
    {
      v8 = (uint8_t *)dword_12F5B4;
      do
      {
        sub_10D674(v8);
        v9 = *v4 - 1;
        *v4 = v9;
      }
      while ( v9 > a3 );
    }
    if ( v3 > a1 )
    {
      v10 = dword_12F5B8;
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
          sub_10D65C(*v11);
          if ( v11 == v12 )
            goto LABEL_10;
        }
        sub_10D674((uint8_t *)((*v4 & 7) + v10));
        *v4 = (*v4 & 0xFFFFFFF8) + 8;
      }
      while ( v11 != v12 );
    }
  }
  else
  {
    sub_10D674((uint8_t *)dword_12F5B4);
    --*(uint32_t *)off_12F5AC;
  }
LABEL_10:
  --*(uint32_t *)off_12F5B0;
  return v3;
}

