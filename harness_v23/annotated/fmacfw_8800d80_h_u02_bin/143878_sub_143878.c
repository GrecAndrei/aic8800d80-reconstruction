// v23 annotated: sub_143878 @ 0x143878
// Original: 143878_sub_143878.c
// Primary struct: <unclustered>
//
// sub_143878 @ 0x143878, size 206 bytes
unsigned __int8 *__fastcall sub_143878(unsigned __int8 *result, unsigned __int8 a2)
{
  unsigned __int8 *v2; // r3
  int v3; // r6
  int v4; // t1
  int v5; // r3
  int v6; // t1
  int v7; // r2
  int v8; // t1
  int v9; // t1

  v2 = result;
  if ( a2 )
  {
    if ( (_DWORD)result << 30 )
    {
      while ( 1 )
      {
        result = v2;
        v8 = *v2++;
        v7 = v8;
        if ( !v8 )
          return nullptr;
        if ( v7 == a2 )
          return result;
        result = v2;
        if ( !((_DWORD)v2 << 30) )
          goto LABEL_3;
      }
    }
    else
    {
LABEL_3:
      v3 = a2 | (a2 << 8) | ((a2 | (a2 << 8)) << 16);
      if ( ((((v3 ^ *(_DWORD *)result) - 16843009) & ~(v3 ^ *(_DWORD *)result)
           | (*(_DWORD *)result - 16843009) & ~*(_DWORD *)result)
          & 0x80808080) == 0 )
      {
        do
        {
          v4 = *((_DWORD *)result + 1);
          result += 4;
        }
        while ( (((v4 - 16843009) & ~v4 | ((v4 ^ v3) - 16843009) & ~(v4 ^ v3)) & 0x80808080) == 0 );
      }
      v5 = *result;
      if ( *result )
      {
        while ( a2 != v5 )
        {
          v6 = *++result;
          v5 = v6;
          if ( !v6 )
            return (unsigned __int8 *)v5;
        }
      }
      else
      {
        return (unsigned __int8 *)v5;
      }
    }
  }
  else if ( (_DWORD)result << 30 )
  {
    while ( 1 )
    {
      result = v2++;
      if ( !*result )
        break;
      result = v2;
      if ( !((_DWORD)v2 << 30) )
        goto LABEL_18;
    }
  }
  else
  {
LABEL_18:
    if ( ((*(_DWORD *)result - 16843009) & ~*(_DWORD *)result & 0x80808080) == 0 )
    {
      do
      {
        v9 = *((_DWORD *)result + 1);
        result += 4;
      }
      while ( ((v9 - 16843009) & ~v9 & 0x80808080) == 0 );
    }
    if ( *result )
    {
      while ( *++result )
        ;
    }
  }
  return result;
}

