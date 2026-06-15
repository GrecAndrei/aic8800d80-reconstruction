// v23 annotated: sub_117A7C @ 0x117a7c
// Original: 117a7c_sub_117A7C.c
// Primary struct: <unclustered>
//
// sub_117A7C @ 0x117a7c, size 68 bytes
// Doc: sub_1217A7C [unknown]: Unknown firmware helper at 0x1217a7c
// sub_1217A7C [unknown]: Unknown firmware helper at 0x1217a7c
_QWORD *sub_117A7C()
{
  _QWORD *result; // r0
  __int64 v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(_DWORD *)off_117AC0;
  v3 = *(_DWORD *)dword_117AC4;
  v4 = *(_DWORD *)(dword_117AC4 + 8 + 0xFFFFFFFC);
  v5 = *(_DWORD *)(dword_117AC4 + 8);
  result = get_cached_1828f8(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (_QWORD *)rf_cmd_dispatch_a84(&v1);
  return result;
}

