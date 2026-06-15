// v23 annotated: sub_13373C @ 0x13373c
// Original: 13373c_sub_13373C.c
// Primary struct: <unclustered>
//
// sub_13373C @ 0x13373c, size 98 bytes
int __fastcall sub_13373C(int a1, int a2)
{
  int v2; // r3

  v2 = *(_WORD *)(a2 + 2) & 0xFC;
  switch ( v2 )
  {
    case 176:
      if ( sub_12CD48(6u) == 5 )
        sub_1358C0(a2);
      break;
    case 16:
    case 48:
      if ( sub_12CD48(6u) == 8 )
        sub_135458(a2);
      break;
    case 192:
    case 160:
      return sub_135528(a2);
    default:
      if ( v2 == 208 && *(_BYTE *)(a2 + 12) == 8 )
        sub_1355C8(a2);
      break;
  }
  return 0;
}

