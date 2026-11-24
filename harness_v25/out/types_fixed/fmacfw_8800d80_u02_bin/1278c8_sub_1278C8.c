// sub_1278C8 @ 0x1278c8, size 38 bytes
// Doc: sub_12278C8 [unknown]: helper that reallocates/restructures a context object
// sub_12278C8 [unknown]: helper that reallocates/restructures a context object
int __fastcall sub_1278C8(int a1)
{
  int v2; // r0
  int result; // r0

  v2 = sub_121984(*(_DWORD *)(a1 + 88));
  *(_DWORD *)(a1 + 88) = v2;
  result = sub_12AAD4(a1, v2);
  *(_BYTE *)(a1 + 85) = *(_BYTE *)(a1 + 85) & 0x9F | 0x20;
  return result;
}

