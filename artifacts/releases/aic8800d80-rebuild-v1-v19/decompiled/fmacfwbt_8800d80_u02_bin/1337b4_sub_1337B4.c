// sub_1337B4 @ 0x1337b4, size 22 bytes
int __fastcall sub_1337B4(int result, int a2, int a3, unsigned __int8 *a4)
{
  unsigned int v4; // r4
  unsigned int v5; // r2
  int v6; // r1
  unsigned int v7; // r2
  __int16 v8; // r1
  int v9; // r1

  if ( (unsigned int)(result - 1) > 2 )
    return result;
  v4 = *a4;
  if ( *a4 )
  {
    if ( v4 == 1 )
    {
      if ( (unsigned __int8)(a2 - 1) > 0xB0u )
        v4 = 0;
      else
        v4 = 5 * a2 + 5000;
      *((_WORD *)a4 + 2) = v4;
      if ( (unsigned __int8)(a3 - 1) <= 0xB0u )
      {
        v5 = 5 * a3 + 5000;
LABEL_15:
        *((_WORD *)a4 + 3) = v5;
        if ( result != 2 )
        {
          if ( result != 3 )
          {
            if ( v5 < v4 )
            {
              v6 = v4 - v5;
              goto LABEL_19;
            }
            v9 = v5;
LABEL_36:
            v6 = v9 - v4;
LABEL_19:
            if ( v6 != 40 )
            {
              if ( v6 > 40 && *((_BYTE *)off_132678 + 373) == 4 )
                goto LABEL_22;
              goto LABEL_27;
            }
            if ( *((unsigned __int8 *)off_132678 + 373) > 2u )
            {
              *((_WORD *)a4 + 2) = v5;
              a4[1] = 3;
              *((_WORD *)a4 + 3) = 0;
              return 3;
            }
LABEL_27:
            a4[1] = 2;
            *((_WORD *)a4 + 3) = 0;
            return result;
          }
          goto LABEL_26;
        }
        goto LABEL_28;
      }
    }
    else
    {
      *((_WORD *)a4 + 2) = 0;
      v4 = 0;
    }
  }
  else
  {
    if ( (unsigned int)(a2 - 1) <= 0xD )
    {
      if ( a2 == 14 )
        v4 = 2484;
      else
        v4 = 5 * a2 + 2407;
    }
    *((_WORD *)a4 + 2) = v4;
    if ( a3 && a3 <= 14 )
    {
      if ( a3 == 14 )
      {
        v9 = 2484;
        *((_WORD *)a4 + 3) = 2484;
        if ( result != 2 )
        {
          if ( result != 3 )
          {
            LOWORD(v5) = 2484;
            goto LABEL_36;
          }
LABEL_26:
          if ( *((_BYTE *)off_132678 + 373) == 4 )
          {
LABEL_22:
            a4[1] = 4;
            return result;
          }
          goto LABEL_27;
        }
        goto LABEL_28;
      }
      v5 = 5 * a3 + 2407;
      goto LABEL_15;
    }
  }
  *((_WORD *)a4 + 3) = 0;
  if ( result != 2 )
  {
    if ( result != 3 )
      goto LABEL_27;
    goto LABEL_26;
  }
LABEL_28:
  if ( *((unsigned __int8 *)off_132678 + 373) <= 2u )
  {
    v7 = *((unsigned __int16 *)a4 + 1);
    a4[1] = 2;
    if ( v7 <= v4 )
      v8 = v4 - 40;
    else
      v8 = v4 + 40;
    *((_WORD *)a4 + 2) = v8;
  }
  else
  {
    a4[1] = 3;
  }
  return result;
}

