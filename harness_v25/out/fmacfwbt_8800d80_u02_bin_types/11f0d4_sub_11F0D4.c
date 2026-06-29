// sub_11F0D4 @ 0x11f0d4, size 68 bytes
QWORD *sub_11F0D4()
{
  QWORD *result; // r0
  uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(uint32_t *)off_11F118;
  v3 = *(uint32_t *)dword_11F11C;
  v4 = *(uint32_t *)(dword_11F11C + 8 + 0xFFFFFFFC);
  v5 = *(uint32_t *)(dword_11F11C + 8);
  result = sub_101818(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (QWORD *)sub_12F7A4(&v1);
  return result;
}

