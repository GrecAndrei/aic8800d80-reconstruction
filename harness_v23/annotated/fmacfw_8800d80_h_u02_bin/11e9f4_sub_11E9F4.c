// v23 annotated: sub_11E9F4 @ 0x11e9f4
// Original: 11e9f4_sub_11E9F4.c
// Primary struct: <unclustered>
//
// sub_11E9F4 @ 0x11e9f4, size 124 bytes
int __fastcall sub_11E9F4(int result)
{
  int v1; // r4
  __int16 v2; // r2
  int v3; // r1

  v1 = result;
  if ( **(__int16 **)off_11EA70 < 0 && *(_DWORD *)(result + 20) != dword_11EA78 )
    result = sub_12F32C(dword_11EA80, dword_11EA7C, 1811);
  v2 = *(_WORD *)(v1 + 48);
  if ( v2 )
  {
    switch ( *(_DWORD *)(v1 + 84) & 0x7C )
    {
      case 4:
      case 8:
        *(_WORD *)(v1 + 48) = v2 - 8;
        break;
      case 0xC:
        *(_WORD *)(v1 + 48) = v2 - 12;
        break;
      case 0x10:
      case 0x14:
      case 0x18:
      case 0x1C:
        *(_WORD *)(v1 + 48) = v2 - 20;
        break;
      default:
        *(_WORD *)(v1 + 48) = v2 - 4;
        break;
    }
  }
  v3 = dword_11EA74;
  *(_BYTE *)(v1 + 16) = 2;
  *(_BYTE *)(v1 + 156) = 0;
  *(_DWORD *)(v1 + 12) = v1;
  *(_DWORD *)(v1 + 4) = v3;
  return result;
}

