// sub_13698C @ 0x13698c, size 58 bytes
// Doc: sub_123698C [ipc]: Initialize/register module with id 0x3f and 7 entries
// sub_123698C [ipc]: Initialize/register module with id 0x3f and 7 entries
_DWORD *sub_13698C()
{
  int v0; // r4
  int v1; // r0
  __int16 v2; // r1
  __int16 v3; // r2

  v0 = *(_DWORD *)off_1369C8;
  v1 = sub_12C92C(63, 0, 7, 0xCu);
  v2 = *(_WORD *)(v0 + 36);
  v3 = *(_WORD *)(v0 + 38);
  *(_DWORD *)v1 = *(_DWORD *)(v0 + 32);
  *(_WORD *)(v1 + 4) = v2;
  *(_WORD *)(v1 + 6) = v3;
  *(_BYTE *)(v1 + 8) = *(_BYTE *)(v0 + 50);
  *(_BYTE *)(v1 + 9) = *(_BYTE *)(v0 + 51);
  sdio_buffer_prepare_n_4e8(v1);
  return sub_12CD34(7u, 2);
}

