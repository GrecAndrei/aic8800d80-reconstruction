// fwstruct annotate: 1425d4_sub_1425D4.c
// sub_1425D4 @ 0x1425d4, size 58 bytes
// Doc: sub_12425DE [unknown]: Helper routine with saved r4/lr; small wrapper
// sub_12425DE [unknown]: Helper routine with saved r4/lr; small wrapper
int __fastcall sub_1425D4(int a1, unsigned int a2)
{
  if ( **(__int16 **)off_142610 < 0 && *(unsigned __int8 *)(a2 + 8) == 255 )
    sub_12F46C(dword_142618, dword_142614, 50);
  if ( (*(_WORD *)(a2 + 2) & 0xFC) == 0xD0 )
    sub_1420D0(a2);
  return 0;
}

