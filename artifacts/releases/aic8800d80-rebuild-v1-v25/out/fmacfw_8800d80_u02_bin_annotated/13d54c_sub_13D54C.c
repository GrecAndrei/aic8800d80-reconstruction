// fwstruct annotate: 13d54c_sub_13D54C.c
// sub_13D54C @ 0x13d54c, size 322 bytes
int __fastcall sub_13D54C(int a1, unsigned int a2)
{
  int v4; // r5
  __int16 v5; // r0
  int v6; // r2
  char v7; // r7
  unsigned int v8; // r5
  unsigned int v9; // r2
  bool v10; // cc
  int result; // r0
  int v12; // r3
  unsigned __int8 v13; // r5
  unsigned int v14; // r3
  int v15; // r1

  v4 = (a2 >> 11) & 7;
  if ( (a2 & 0x2000) != 0 )
  {
    v5 = random_mix_64(a1);
    v6 = a2 & 0xF;
    switch ( v4 )
    {
      case 4:
        if ( (a2 & 0xF) == 0 )
          goto LABEL_13;
        result = (unsigned __int16)((v6 - 1) | a2 & 0xFFF0);
        if ( *(_BYTE *)(a1 + 181) )
          return result | 0x200;
        return result;
      case 5:
        if ( (a2 & 0xF) == 0 )
          goto LABEL_13;
        v15 = v6 - 1;
        result = a2 & 0xFFF0 | (unsigned __int16)(v6 - 1);
        if ( (a2 & 0x4000) == 0 )
          return result;
        if ( v6 == 3 )
          return result & 0xBFFF;
        goto LABEL_21;
      case 7:
        if ( (a2 & 0xF) != 0 )
        {
          v15 = v6 - 1;
          result = a2 & 0xFFF0 | (unsigned __int16)(v6 - 1);
          if ( (a2 & 0x4000) != 0 )
          {
LABEL_21:
            if ( v15 > *(unsigned __int8 *)(a1 + 195) )
              return result & 0xBFFF;
          }
          return result;
        }
        if ( *(_BYTE *)(a1 + 183) && (a2 & 0x180) == 0 )
          return dword_13D690 & a2 | 1;
        break;
      default:
        return a2;
    }
    return a2;
  }
  if ( ((a2 >> 11) & 6) == 0 )
  {
    v7 = a2;
    v8 = a2 & 0x7F;
    random_mix_64(a1);
    if ( (v7 & 0x7C) != 0 )
    {
      v9 = *(unsigned __int8 *)(a1 + 177);
      if ( v9 < 4 )
        v9 = 4;
    }
    else
    {
      v9 = *(unsigned __int8 *)(a1 + 177);
    }
    while ( 1 )
    {
      v10 = v8 > v9;
      v8 = (unsigned __int8)(v8 - 1);
      if ( !v10 )
        break;
      if ( ((*(unsigned __int16 *)(a1 + 174) >> v8) & 1) != 0 )
      {
        result = a2 & 0xFFFFFF80 | v8;
        if ( !v8 )
          return (unsigned __int16)result | 0x400;
        return result;
      }
    }
    return a2;
  }
  v5 = random_mix_64(a1);
  v12 = a2 & 7;
  while ( 1 )
  {
    v13 = v12 - 1;
    if ( !v12 )
      break;
    v12 = v13;
    if ( ((*(unsigned __int8 *)(((a2 >> 3) & 3) + a1 + 170) >> v13) & 1) != 0 )
    {
      result = a2 & 0xFFFFFFF8 | v13;
      if ( *(_BYTE *)(a1 + 181) )
        return (unsigned __int16)result | 0x200;
      return result;
    }
  }
LABEL_13:
  v14 = *(unsigned __int8 *)(a1 + 178);
  if ( v14 > 3 )
    return a2;
  if ( *(_BYTE *)(a1 + 178) )
    return (unsigned __int16)(v14 | (*(unsigned __int8 *)(a1 + 182) << 10)) | v5 & 0x400;
  else
    return 1024;
}

