// fwstruct annotate: 125260_sub_125260.c
// sub_125260 @ 0x125260, size 152 bytes
// Doc: sub_1225262_init [unknown]: Saves r4-r6,lr; moves args r0->r4, r1->r6; init stub
// sub_1225262_init [unknown]: Saves r4-r6,lr; moves args r0->r4, r1->r6; init stub
int __fastcall sub_125260(int a1, int a2)
{
  int v4; // r5

  switch ( a2 )
  {
    case 2:
      v4 = dword_1252FC;
      *(_DWORD *)(dword_125300 + 20 * a1 + 4) = 0;
      break;
    case 3:
      v4 = dword_1252FC;
      bt_link_lookup_entry(*(unsigned __int8 *)(dword_1252FC + 1320 * a1 + 1225), dword_12530C + 38 * a1);
      break;
    case 1:
      v4 = dword_1252FC;
      *(_DWORD *)(dword_125300 + 20 * a1 + 4) = dword_125304 + 20 * a1;
      break;
    default:
      v4 = dword_1252FC;
      if ( **(__int16 **)off_1252F8 < 0 )
        sub_12F694(dword_125314, dword_125310, 1214);
      break;
  }
  *(_BYTE *)(a1 + dword_125308 + 20) = 0;
  return sub_12AEBC(*(unsigned __int8 *)(v4 + 1320 * a1 + 1225), a2);
}

