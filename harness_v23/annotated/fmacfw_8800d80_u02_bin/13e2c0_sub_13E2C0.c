// v23 annotated: sub_13E2C0 @ 0x13e2c0
// Original: 13e2c0_sub_13E2C0.c
// Primary struct: <unclustered>
//
// sub_13E2C0 @ 0x13e2c0, size 104 bytes
int __fastcall sub_13E2C0(unsigned __int8 *a1)
{
  int result; // r0
  unsigned int v2; // r3
  int v3; // r3

  switch ( a1[169] )
  {
    case 0u:
    case 1u:
      v2 = a1[177];
      if ( !a1[177] )
        goto LABEL_15;
      if ( v2 > 3 )
        result = a1[177];
      else
        result = (unsigned __int16)(v2 | (a1[182] << 10));
      break;
    case 2u:
    case 3u:
      if ( !a1[177] )
        goto LABEL_15;
      result = (unsigned __int16)(a1[169] << 11);
      break;
    case 4u:
      result = 0x2000;
      break;
    case 5u:
      if ( a1[177] )
      {
        v3 = a1[194];
        if ( a1[183] )
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

