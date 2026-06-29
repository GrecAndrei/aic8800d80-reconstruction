// sub_117A7C @ 0x117a7c, size 68 bytes
// Doc: sub_1217A7C [unknown]: Unknown firmware helper at 0x1217a7c
// sub_1217A7C [unknown]: Unknown firmware helper at 0x1217a7c
QWORD *sub_117A7C()
{
  QWORD *result; // r0
  uint64_t v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(uint32_t *)off_117AC0;
  v3 = *(uint32_t *)dword_117AC4;
  v4 = *(uint32_t *)(dword_117AC4 + 8 + 0xFFFFFFFC);
  v5 = *(uint32_t *)(dword_117AC4 + 8);
  result = get_cached_1828f8(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (QWORD *)rf_cmd_dispatch_a84(&v1);
  return result;
}

