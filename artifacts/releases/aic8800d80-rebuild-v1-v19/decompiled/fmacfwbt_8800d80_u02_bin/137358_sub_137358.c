// sub_137358 @ 0x137358, size 628 bytes
_BYTE *__fastcall sub_137358(_BYTE *result, int a2, char a3, int a4)
{
  unsigned __int8 *v5; // r6
  _BYTE *v7; // r0
  _BYTE *v8; // r4
  int v9; // r6
  int v10; // r8
  int v11; // r6
  unsigned int *i; // r4
  unsigned int *v13; // r4
  int v14; // r7
  int v15; // t1
  int v16; // r6
  int v17; // r2
  unsigned int *v18; // r3
  int v19; // r2
  unsigned __int8 *v20; // r0
  unsigned __int8 *v21; // r4
  int v22; // r6
  unsigned int v23; // r0
  int v24; // r8
  int v25; // r6
  unsigned int *j; // r4
  unsigned int *v27; // r7
  int v28; // r8
  unsigned int v29; // r4
  int v30; // r7
  int v31; // r4
  unsigned int *v32; // r6
  unsigned int *v33; // r6
  int v34; // r8
  int v35; // t1
  int v36; // r4
  unsigned __int8 v37; // [sp+7h] [bp-1h] BYREF

  *(_DWORD *)(a4 + 48) = 0;
  *(_DWORD *)(a4 + 52) = 0;
  if ( (a3 & 0x10) == 0 )
  {
    *(_DWORD *)(a4 + 48) = 1;
    return result;
  }
  v5 = result;
  v7 = sub_12DBBC(result, a2, &v37);
  v8 = v7;
  if ( v7 )
  {
    v9 = v37;
    result = (_BYTE *)sub_12E2A8(bswap32(*((_DWORD *)v7 + 1)));
    if ( result )
    {
      result = (_BYTE *)((1 << (char)result) | *(unsigned __int16 *)(a4 + 52));
      *(_WORD *)(a4 + 52) = (_WORD)result;
    }
    v10 = *((unsigned __int16 *)v8 + 4);
    v11 = v9 - 8;
    for ( i = (unsigned int *)(v8 + 10); v10 && v11 > 3; --v10 )
    {
      result = (_BYTE *)sub_12E2A8(bswap32(*i));
      v11 -= 4;
      ++i;
      if ( result )
      {
        result = (_BYTE *)((1 << (char)result) | *(unsigned __int16 *)(a4 + 54));
        *(_WORD *)(a4 + 54) = (_WORD)result;
      }
    }
    if ( v11 > 1 )
    {
      v15 = *(unsigned __int16 *)i;
      v13 = (unsigned int *)((char *)i + 2);
      v14 = v15;
      v16 = v11 - 2;
      if ( v15 && v16 > 3 )
      {
        while ( 1 )
        {
          result = (_BYTE *)sub_12E1FC(bswap32(*v13));
          v16 -= 4;
          ++v13;
          if ( result )
          {
            result = (_BYTE *)((1 << (char)result) | *(_DWORD *)(a4 + 48));
            *(_DWORD *)(a4 + 48) = result;
          }
          if ( !--v14 )
            break;
          if ( v16 <= 3 )
          {
            if ( v16 <= 1 || (*(_WORD *)v13 & 0xC0) == 0 )
              return result;
            goto LABEL_69;
          }
        }
      }
      if ( v16 > 1 )
      {
        v17 = v16 - 2;
        v18 = (unsigned int *)((char *)v13 + 2);
        if ( v16 - 2 > 1 )
        {
          v19 = *(unsigned __int16 *)v18;
          v18 = &v13[4 * v19 + 1];
          v17 = v16 - 4 - 16 * v19;
        }
        if ( (*(_WORD *)v13 & 0xC0) != 0 )
        {
          if ( v17 <= 3 )
          {
LABEL_69:
            *(_WORD *)(a4 + 52) |= 0x20u;
            return result;
          }
          result = (_BYTE *)sub_12E2A8(bswap32(*v18));
          if ( result )
LABEL_28:
            *(_WORD *)(a4 + 52) |= 1 << (char)result;
        }
      }
    }
  }
  else
  {
    v20 = sub_12DBF8(v5, a2, &v37);
    v21 = v20;
    if ( v20 )
    {
      v22 = v37;
      v23 = bswap32(*((_DWORD *)v20 + 2));
      *(_DWORD *)(a4 + 48) = 2;
      result = (_BYTE *)sub_12E2A8(v23);
      if ( result )
      {
        result = (_BYTE *)((1 << (char)result) | *(unsigned __int16 *)(a4 + 52));
        *(_WORD *)(a4 + 52) = (_WORD)result;
      }
      v24 = *((unsigned __int16 *)v21 + 6);
      v25 = v22 - 12;
      for ( j = (unsigned int *)(v21 + 14); v24 && v25 > 3; --v24 )
      {
        result = (_BYTE *)sub_12E2A8(bswap32(*j));
        v25 -= 4;
        ++j;
        if ( result )
        {
          result = (_BYTE *)((1 << (char)result) | *(unsigned __int16 *)(a4 + 54));
          *(_WORD *)(a4 + 54) = (_WORD)result;
        }
      }
      if ( v25 > 1 )
      {
        v27 = (unsigned int *)((char *)j + 2);
        v28 = *(unsigned __int16 *)j;
        if ( *(_WORD *)j )
        {
          if ( v25 > 5 )
          {
            v29 = (unsigned int)j + ((v25 - 6) & 0xFFFFFFFC) + 6;
            do
            {
              result = (_BYTE *)sub_12E1FC(bswap32(*v27++));
              if ( result )
              {
                result = (_BYTE *)((1 << (char)result) | *(_DWORD *)(a4 + 48));
                *(_DWORD *)(a4 + 48) = result;
              }
              --v28;
            }
            while ( v28 && v27 != (unsigned int *)v29 );
          }
        }
      }
    }
    else
    {
      result = sub_12DC24(v5, a2, &v37);
      if ( !result )
      {
        *(_DWORD *)(a4 + 48) = 2;
        *(_WORD *)(a4 + 52) = 1;
        return result;
      }
      v30 = *((unsigned __int16 *)result + 2);
      v31 = v37 - 4;
      v32 = (unsigned int *)(result + 6);
      if ( *((_WORD *)result + 2) && v31 > 3 )
      {
        do
        {
          result = (_BYTE *)sub_12E1FC(bswap32(*v32));
          v31 -= 4;
          ++v32;
          if ( result )
          {
            result = (_BYTE *)((1 << (char)result) | *(_DWORD *)(a4 + 48));
            *(_DWORD *)(a4 + 48) = result;
          }
          --v30;
        }
        while ( v30 && v31 > 3 );
      }
      if ( v31 > 1 )
      {
        v35 = *(unsigned __int16 *)v32;
        v33 = (unsigned int *)((char *)v32 + 2);
        v34 = v35;
        v36 = v31 - 2;
        if ( v35 )
        {
          if ( v36 <= 3 )
            return result;
          while ( 1 )
          {
            result = (_BYTE *)sub_12E2A8(bswap32(*v33));
            v36 -= 4;
            ++v33;
            if ( result )
            {
              result = (_BYTE *)((1 << (char)result) | *(unsigned __int16 *)(a4 + 54));
              *(_WORD *)(a4 + 54) = (_WORD)result;
            }
            if ( !--v34 )
              break;
            if ( v36 <= 3 )
              return result;
          }
        }
        if ( v36 > 3 )
        {
          result = (_BYTE *)sub_12E2A8(bswap32(*v33));
          if ( result )
            goto LABEL_28;
        }
      }
    }
  }
  return result;
}

