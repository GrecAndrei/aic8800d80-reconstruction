// v23 annotated: sub_13BC64 @ 0x13bc64
// Original: 13bc64_sub_13BC64.c
// Primary struct: <unclustered>
//
// sub_13BC64 @ 0x13bc64, size 96 bytes
int __fastcall sub_13BC64(bool a1, int a2)
{
  unsigned int v2; // r5
  bool *v5; // r4
  int v6; // r1
  int v7; // r3

  v2 = (unsigned __int16)((_WORD)a2 << 8) | 8;
  v5 = (bool *)sub_12C7EC(42, 0, ((_WORD)a2 << 8) | 8, 3u);
  if ( **(__int16 **)off_13BCC4 < 0 && sub_12CD48(v2) != 4 )
    sub_12F32C(dword_13BCD0, dword_13BCCC, 891);
  v6 = dword_13BCC8 + 32 * a2;
  v7 = *(unsigned __int8 *)(v6 + 17);
  v5[1] = a1;
  *v5 = v7 != 1;
  v5[2] = *(_BYTE *)(v6 + 22);
  return sub_12C84C((int)v5);
}

