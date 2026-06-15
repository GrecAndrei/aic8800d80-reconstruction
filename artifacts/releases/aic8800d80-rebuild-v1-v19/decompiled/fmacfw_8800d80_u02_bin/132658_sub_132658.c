// sub_132658 @ 0x132658, size 156 bytes
int __fastcall sub_132658(int result, _DWORD *a2, int a3, _WORD *a4, int *a5, int *a6, char *a7)
{
  unsigned int v7; // r4
  int v8; // r12
  int v9; // r4
  char v10; // r12
  int v11; // r1
  int v12; // r3

  *a4 = 0;
  *a5 = 0;
  *a6 = 0;
  if ( result )
  {
    v7 = *(unsigned __int8 *)(result + 2);
    v8 = (v7 >> 2) & 7;
    v9 = v7 & 3;
    if ( v8 > 2 )
      v10 = 1 << (v8 - 3);
    else
      v10 = 1;
    result = (unsigned __int16)((1 << (v9 + 13)) - 1);
    *a7 = v10;
    *a4 = result;
    if ( a2 )
    {
      v11 = (*a2 >> 23) & 7;
      v12 = (1 << (v11 + 13)) - 1;
      *a5 = v12;
      if ( a3 )
      {
        if ( v11 == 7 )
          *a6 = (1 << (((*(_BYTE *)(a3 + 3) >> 3) & 3) + 20)) - 1;
        else
          *a6 = v12;
      }
    }
    else if ( a3 )
    {
      if ( v9 == 3 )
        *a6 = (1 << (((*(_BYTE *)(a3 + 3) >> 3) & 3) + 16)) - 1;
      else
        *a6 = (unsigned __int16)result;
    }
  }
  return result;
}

