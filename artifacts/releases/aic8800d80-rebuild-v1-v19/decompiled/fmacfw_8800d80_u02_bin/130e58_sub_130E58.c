// sub_130E58 @ 0x130e58, size 202 bytes
_BYTE *__fastcall sub_130E58(_BYTE *a1, int a2, int a3)
{
  _BYTE *result; // r0
  int v5; // r5
  int v6; // r3
  char v7; // r6
  int v8; // r2
  int v9; // r3
  int v10; // r1
  bool v11; // zf
  _BYTE v12[5]; // [sp+7h] [bp-5h] BYREF

  result = sub_12D958(a1, a2, v12);
  if ( result )
  {
    v5 = *(unsigned __int8 *)(a3 + 164);
    if ( *(_BYTE *)(a3 + 164) )
    {
      if ( v5 == 1 && (unsigned __int16)(*(_WORD *)(a3 + 166) - 5005) <= 0x370u )
      {
        v5 = (unsigned __int8)((unsigned int)(((unsigned int)dword_130F24
                                             * (unsigned __int64)((unsigned int)*(unsigned __int16 *)(a3 + 166) - 5000)) >> 32) >> 2);
        v7 = 4;
      }
      else
      {
        v5 = 0;
        v7 = 4;
      }
    }
    else
    {
      v6 = *(unsigned __int16 *)(a3 + 166);
      if ( (unsigned int)(v6 - 2412) > 0x48 )
      {
        v7 = 1;
      }
      else
      {
        v5 = v6 == 2484
           ? 14
           : (unsigned __int8)((unsigned int)(((unsigned int)dword_130F24 * (unsigned __int64)(unsigned int)(v6 - 2407)) >> 32) >> 2);
        v7 = 1;
      }
    }
    v12[0] += 2;
    if ( v12[0] > 7u )
    {
      v8 = 5;
      do
      {
        v9 = (unsigned __int8)result[v8];
        if ( result[v8 + 1] )
        {
          if ( v9 == v5 )
          {
LABEL_7:
            *(_BYTE *)(a3 + 172) = result[v8 + 2];
            return result;
          }
          v10 = 0;
          while ( 1 )
          {
            v11 = v10 == (unsigned __int8)(result[v8 + 1] - 1);
            v9 = (unsigned __int8)(v9 + v7);
            ++v10;
            if ( v11 )
              break;
            if ( v9 == v5 )
              goto LABEL_7;
          }
        }
        v8 = (unsigned __int8)(v8 + 3);
      }
      while ( v12[0] > v8 + 2 );
    }
  }
  return result;
}

