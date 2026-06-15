// v23 annotated: sub_116680 @ 0x116680
// Original: 116680_sub_116680.c
// Primary struct: <unclustered>
//
// sub_116680 @ 0x116680, size 48 bytes
int __fastcall sub_116680(_BYTE *a1, char a2)
{
  int v2; // r6
  int v4; // r5

  v2 = dword_1166B0;
  v4 = 696 * (unsigned __int8)a1[29];
  a1[27] = a2;
  a1[97] = 1;
  list_push_tail(v4 + 572 + v2);
  return sub_136B68(a1, v2 + v4);
}

