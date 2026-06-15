// sub_1159A4 @ 0x1159a4, size 532 bytes
int __fastcall sub_1159A4(int result)
{
  _BYTE **v1; // r5
  unsigned __int8 **v2; // r6
  int v3; // r3
  int *v4; // r3
  _BYTE *v5; // r4
  int v6; // r3
  int v7; // r1
  void *v8; // r2
  char v9; // r0
  int v10; // r1
  void *v11; // r2
  int v12; // r0

  if ( *(_BYTE *)off_115BB8 && (*((_DWORD *)off_115BBC + 4) & 0xFFFF00) == 0x10000 )
  {
    v6 = *(unsigned __int8 *)off_115BDC;
    *(_BYTE *)off_115BE0 = 0;
    if ( v6 )
      return sub_12EB90(2, dword_115C08);
    if ( !*(_BYTE *)off_115BE4 )
      return sub_12EB90(2, dword_115C0C);
    if ( *(_DWORD *)off_115BE8 && *(_DWORD *)(*(_DWORD *)off_115BE8 + 12) - *((_DWORD *)off_115BEC + 4) - 5000 < 0 )
      return sub_12EB90(2, dword_115C14);
    if ( !*(_BYTE *)off_115BF0
      && !*((_DWORD *)off_115BC8 + 126)
      && ((dword_115BF8 & *(_DWORD *)off_115BF4) == 0 || (unsigned int)(32 * *(_DWORD *)off_115BFC) > 0x1387) )
    {
      ((void (*)(void))sub_12E8D0)();
      while ( 1 )
        ;
    }
    return result;
  }
  if ( *((_BYTE *)off_115BBC + 18) )
  {
    v5 = off_115BD4;
    goto LABEL_23;
  }
  v1 = (_BYTE **)off_115BC0;
  if ( **(_BYTE **)off_115BC0 )
  {
    v2 = (unsigned __int8 **)off_115BC4;
    goto LABEL_6;
  }
  v4 = *((int **)off_115BBC + 2);
  v5 = off_115BD4;
  *(_BYTE *)off_115BD4 = 1;
  if ( !v4 )
  {
LABEL_38:
    v2 = (unsigned __int8 **)off_115BC4;
    if ( **(_BYTE **)off_115BC4 == 3 )
      goto LABEL_8;
    result = sub_12EB90(2, dword_115BD8);
    *v5 = 1;
LABEL_6:
    v3 = **v2;
    if ( v3 == 1 )
    {
      if ( **v1 == 3 )
      {
        v9 = sub_10D1C4();
        v11 = off_115BE0;
        *(_BYTE *)off_115BE0 = v9;
        if ( v9 )
          sub_12E948(dword_115C1C, v10, v11);
        else
          sub_12E948(dword_115C10, v10, v11);
        if ( sub_1111B4() )
          sub_11583C();
        return ((int (*)(void))sub_12E8D0)();
      }
      result = sub_1111B4();
      if ( !result || *(_BYTE *)off_115BF0 )
        return result;
    }
    else if ( v3 == 2 )
    {
      return result;
    }
LABEL_8:
    result = sub_128DDC(result);
    if ( result )
    {
      if ( !*((_DWORD *)off_115BC8 + 126) )
      {
        if ( (*(_DWORD *)off_115BCC >> 25) & 1 | *((unsigned __int8 *)off_115BD0 + 36) )
        {
          if ( !*((_BYTE *)off_115BD0 + 29) )
          {
            result = sub_12BC00();
            if ( result )
            {
              LOBYTE(result) = sub_10D1C4();
              v8 = off_115BE0;
              result = (unsigned __int8)result;
              *(_BYTE *)off_115BE0 = result;
              if ( !(_BYTE)result )
              {
                v12 = sub_12E948(dword_115C18, v7, v8);
                result = sub_12E8D0(v12);
              }
              if ( (unsigned __int8)**v1 <= 1u )
                return (int)sub_11583C();
            }
          }
        }
      }
    }
    return result;
  }
  while ( !*((_BYTE *)v4 + 106) )
  {
    if ( *((_BYTE *)v4 + 108) )
      goto LABEL_20;
LABEL_17:
    v4 = (int *)*v4;
    if ( !v4 )
      goto LABEL_38;
  }
  if ( *((_BYTE *)v4 + 106) != 2 )
    goto LABEL_17;
LABEL_20:
  if ( **(_BYTE **)off_115BC4 != 3 )
    result = sub_12EB90(2, dword_115BD8);
LABEL_23:
  *v5 = 0;
  return result;
}

