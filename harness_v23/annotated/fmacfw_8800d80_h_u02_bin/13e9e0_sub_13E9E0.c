// v23 annotated: sub_13E9E0 @ 0x13e9e0
// Original: 13e9e0_sub_13E9E0.c
// Primary struct: <unclustered>
//
// sub_13E9E0 @ 0x13e9e0, size 312 bytes
unsigned int __fastcall sub_13E9E0(int a1)
{
  unsigned int v1; // r3
  int v2; // r1
  int v3; // r4
  int v4; // r2
  unsigned int result; // r0
  unsigned int v6; // r0
  int v7; // r3
  unsigned int v8; // r0

  v1 = *(unsigned __int16 *)(a1 + 6);
  v2 = (v1 >> 11) & 7;
  if ( (v1 & 0x2000) != 0 )
  {
    v3 = v1 & 0xF;
    switch ( v2 )
    {
      case 5:
        v6 = *(_DWORD *)(dword_13EB24 + 4 * (6 * (v1 & 0xF) + 3 * ((v1 >> 8) & 1) + ((v1 >> 9) & 3))) >> ((v1 & 0x80) != 0);
        v7 = (v1 >> 4) & 7;
        return v6 / (v7 + 1);
      case 6:
        v8 = *(_BYTE *)(a1 + 8) & 7;
        if ( v8 > 2 )
          result = (*(_DWORD *)(dword_13EB24
                              + 4
                              * (6 * (v1 & 0xF) + ((v8 - 3) & 0xFE) + ((unsigned __int8)(v8 - 3) >> 1) + ((v1 >> 9) & 3))) >> ((v8 - 3) & 1))
                 / (((v1 >> 4) & 7) + 1);
        else
          result = *(_DWORD *)(*(_DWORD *)(dword_13EB20 + 4 * v8) + 4 * (3 * (v1 & 0xF) + ((v1 >> 9) & 3)))
                 / (((v1 >> 4) & 7) + 1);
        break;
      case 7:
        if ( ((v1 >> 7) & 3) == 1 )
          result = *(_DWORD *)(dword_13EB2C + 4 * ((v1 >> 9) & 3)) / (((v1 >> 4) & 7) + 1);
        else
          result = *(_DWORD *)(dword_13EB24 + 4 * (6 * (v1 & 0xF) + ((v1 >> 9) & 3))) / (((v1 >> 4) & 7) + 1);
        break;
      default:
        goto LABEL_7;
    }
  }
  else if ( ((v1 >> 11) & 6) != 0 )
  {
    v3 = v1 & 7;
LABEL_7:
    v6 = *(_DWORD *)(dword_13EB1C + 4 * ((v1 >> 9) & 1 | (2 * ((v1 >> 7) & 3)) | (8 * v3)));
    if ( v2 == 4 )
      v7 = (v1 >> 4) & 7;
    else
      v7 = (v1 >> 3) & 3;
    return v6 / (v7 + 1);
  }
  else
  {
    v4 = v1 & 0x7F;
    if ( (v1 & 0x7C) != 0 )
      return *(_DWORD *)(dword_13EB28 + 4 * (v4 - 4));
    else
      return *(_DWORD *)(dword_13EB18 + 4 * ((v1 >> 10) & 1 | (2 * v4)));
  }
  return result;
}

