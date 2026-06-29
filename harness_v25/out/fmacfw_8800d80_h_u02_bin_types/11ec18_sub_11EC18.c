// sub_11EC18 @ 0x11ec18, size 68 bytes
QWORD *sub_11EC18()
{
  QWORD *result; // r0
  uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(uint32_t *)off_11EC5C;
  v3 = *(uint32_t *)dword_11EC60;
  v4 = *(uint32_t *)(dword_11EC60 + 8 + 0xFFFFFFFC);
  v5 = *(uint32_t *)(dword_11EC60 + 8);
  result = sub_1018F0(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (QWORD *)sub_12F448(&v1);
  return result;
}

