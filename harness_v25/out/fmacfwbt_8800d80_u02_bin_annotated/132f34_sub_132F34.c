// fwstruct annotate: 132f34_sub_132F34.c
// sub_132F34 @ 0x132f34, size 106 bytes
int __fastcall sub_132F34(int result, _BYTE *a2, int a3)
{
  unsigned int v3; // r4
  unsigned int v4; // r2
  int v5; // r1
  unsigned int v6; // r2
  __int16 v7; // r1
  int v8; // r1
  __int16 v9; // r4
  __int16 v10; // r3
  unsigned __int8 *v11; // r3
  int v12; // r2
  int v13; // r1

  v9 = *(_WORD *)(a3 + 166);
  *(_WORD *)(a3 + 168) = v9;
  *(_BYTE *)(a3 + 165) = 0;
  *(_WORD *)(a3 + 170) = 0;
  if ( result )
  {
    if ( !*((_BYTE *)off_132FA0 + 373) )
      return result;
    if ( (*(_BYTE *)(result + 3) & 3) != 0 )
    {
      v10 = -10;
      if ( (*(_BYTE *)(result + 3) & 3) == 1 )
        v10 = 10;
      *(_WORD *)(a3 + 168) = v9 + v10;
      *(_BYTE *)(a3 + 165) = 1;
    }
  }
  if ( a2 )
  {
    if ( *((unsigned __int8 *)off_132FA0 + 373) > 1u )
    {
      result = a2[2] & 3;
      if ( (unsigned int)(result - 1) <= 2 )
      {
        v11 = (unsigned __int8 *)(a3 + 164);
        v12 = (unsigned __int8)a2[4];
        v13 = (unsigned __int8)a2[3];
        v3 = *v11;
        if ( *v11 )
        {
          if ( v3 == 1 )
          {
            if ( (unsigned __int8)(v13 - 1) > 0xB0u )
              v3 = 0;
            else
              v3 = 5 * v13 + 5000;
            *((_WORD *)v11 + 2) = v3;
            if ( (unsigned __int8)(v12 - 1) <= 0xB0u )
            {
              v4 = 5 * v12 + 5000;
LABEL_25:
              *((_WORD *)v11 + 3) = v4;
              if ( result != 2 )
              {
                if ( result != 3 )
                {
                  if ( v4 < v3 )
                  {
                    v5 = v3 - v4;
                    goto LABEL_29;
                  }
                  v8 = v4;
LABEL_46:
                  v5 = v8 - v3;
LABEL_29:
                  if ( v5 != 40 )
                  {
                    if ( v5 > 40 && *((_BYTE *)off_132678 + 373) == 4 )
                      goto LABEL_32;
                    goto LABEL_37;
                  }
                  if ( *((unsigned __int8 *)off_132678 + 373) > 2u )
                  {
                    *((_WORD *)v11 + 2) = v4;
                    v11[1] = 3;
                    *((_WORD *)v11 + 3) = 0;
                    return 3;
                  }
LABEL_37:
                  v11[1] = 2;
                  *((_WORD *)v11 + 3) = 0;
                  return result;
                }
                goto LABEL_36;
              }
              goto LABEL_38;
            }
          }
          else
          {
            *((_WORD *)v11 + 2) = 0;
            v3 = 0;
          }
        }
        else
        {
          if ( (unsigned int)(v13 - 1) <= 0xD )
          {
            if ( v13 == 14 )
              v3 = 2484;
            else
              v3 = 5 * v13 + 2407;
          }
          *((_WORD *)v11 + 2) = v3;
          if ( v12 && v12 <= 14 )
          {
            if ( v12 == 14 )
            {
              v8 = 2484;
              *((_WORD *)v11 + 3) = 2484;
              if ( result != 2 )
              {
                if ( result != 3 )
                {
                  LOWORD(v4) = 2484;
                  goto LABEL_46;
                }
LABEL_36:
                if ( *((_BYTE *)off_132678 + 373) == 4 )
                {
LABEL_32:
                  v11[1] = 4;
                  return result;
                }
                goto LABEL_37;
              }
              goto LABEL_38;
            }
            v4 = 5 * v12 + 2407;
            goto LABEL_25;
          }
        }
        *((_WORD *)v11 + 3) = 0;
        if ( result != 2 )
        {
          if ( result != 3 )
            goto LABEL_37;
          goto LABEL_36;
        }
LABEL_38:
        if ( *((unsigned __int8 *)off_132678 + 373) <= 2u )
        {
          v6 = *((unsigned __int16 *)v11 + 1);
          v11[1] = 2;
          if ( v6 <= v3 )
            v7 = v3 - 40;
          else
            v7 = v3 + 40;
          *((_WORD *)v11 + 2) = v7;
        }
        else
        {
          v11[1] = 3;
        }
      }
    }
  }
  return result;
}

