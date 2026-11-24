// sub_11ED58 @ 0x11ed58, size 68 bytes
// Doc: sub_121ED58 [mmio]: MMIO helper reading from 0x403410b0/0x403410b4 peripheral registers
// sub_121ED58 [mmio]: MMIO helper reading from 0x403410b0/0x403410b4 peripheral registers
_QWORD *sub_11ED58()
{
  _QWORD *result; // r0
  __int64 v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(_DWORD *)off_11ED9C;
  v3 = *(_DWORD *)dword_11EDA0;
  v4 = *(_DWORD *)(dword_11EDA0 + 8 + 0xFFFFFFFC);
  v5 = *(_DWORD *)(dword_11EDA0 + 8);
  result = get_cached_1828f8(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (_QWORD *)sub_12F588(&v1);
  return result;
}

