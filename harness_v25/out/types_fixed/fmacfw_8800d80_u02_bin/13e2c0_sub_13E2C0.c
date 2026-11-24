// sub_13E2C0 @ 0x13e2c0, size 104 bytes
int __fastcall sub_13E2C0(unsigned __int8 *a1)
{
  int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  switch ( *(_DWORD *)(a1 + 0x2a4) )
  {
    case 0u:
    case 1u:
      v2 = *(_DWORD *)(a1 + 0x2c4);
      if ( !*(_DWORD *)(a1 + 0x2c4) )
        goto LABEL_15;
      if ( v2 > 3 )
        result = *(_DWORD *)(a1 + 0x2c4);
      else
        result = (unsigned __int16)(v2 | (*(_DWORD *)(a1 + 0x2d8) << 10));
      break;
    case 2u:
    case 3u:
      if ( !*(_DWORD *)(a1 + 0x2c4) )
        goto LABEL_15;
      result = (unsigned __int16)(*(_DWORD *)(a1 + 0x2a4) << 11);
      break;
    case 4u:
      result = 0x2000;
      break;
    case 5u:
      if ( *(_DWORD *)(a1 + 0x2c4) )
      {
        v3 = *(_DWORD *)(a1 + 0x308);
        if ( *(_DWORD *)(a1 + 0x2dc) )
          result = 14976;
        else
          result = 10752;
        if ( v3 )
          result |= 0x4000u;
      }
      else
      {
LABEL_15:
        result = 1024;
      }
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

