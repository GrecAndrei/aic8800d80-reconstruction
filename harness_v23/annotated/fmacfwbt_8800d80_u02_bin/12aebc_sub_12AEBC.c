// v23 annotated: sub_12AEBC @ 0x12aebc
// Original: 12aebc_sub_12AEBC.c
// Primary struct: <unclustered>
//
// sub_12AEBC @ 0x12aebc, size 94 bytes
int __fastcall sub_12AEBC(int result, int a2)
{
  switch ( a2 )
  {
    case 2:
      result = dword_12AF20 + 140 * result;
      *(_BYTE *)(result + 132) = 0;
      break;
    case 3:
      result = dword_12AF20 + 140 * result;
      if ( !*(_BYTE *)(result + 132) )
        return (int)sub_125EFC(*(unsigned __int8 *)(result + 113), 1);
      break;
    case 1:
      result = dword_12AF20 + 140 * result;
      *(_BYTE *)(result + 132) = 1;
      break;
    default:
      if ( **(__int16 **)off_12AF1C < 0 )
        return sub_12F694(dword_12AF28, dword_12AF24, 1898);
      break;
  }
  return result;
}

