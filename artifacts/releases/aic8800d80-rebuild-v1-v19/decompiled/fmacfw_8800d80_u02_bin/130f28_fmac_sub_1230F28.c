// fmac_sub_1230F28 @ 0x130f28, size 40 bytes
// Doc: fmac_sub_1230F28 [unknown]: Thin wrapper calling sub_0x12dca0 with r4=arg2
// fmac_sub_1230F28 [unknown]: Thin wrapper calling sub_0x12dca0 with r4=arg2
unsigned __int8 *__fastcall fmac_sub_1230F28(_BYTE *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0

  result = sub_12DCA0(a1, a2);
  if ( result )
  {
    *(_WORD *)(a3 + 228) = result[2] | (result[3] << 8);
    *(_BYTE *)(a3 + 230) = result[4];
  }
  else
  {
    *(_BYTE *)(a3 + 230) = 0;
    *(_WORD *)(a3 + 228) = 0;
  }
  return result;
}

