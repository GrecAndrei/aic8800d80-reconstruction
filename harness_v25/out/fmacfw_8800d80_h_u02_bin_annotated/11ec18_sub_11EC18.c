// fwstruct annotate: 11ec18_sub_11EC18.c
// sub_11EC18 @ 0x11ec18, size 68 bytes
_QWORD *sub_11EC18()
{
  _QWORD *result; // r0
  __int64 v1; // [sp+4h] [bp-20h] BYREF
  int v2; // [sp+Ch] [bp-18h]
  int v3; // [sp+10h] [bp-14h]
  int v4; // [sp+14h] [bp-10h]
  int v5; // [sp+18h] [bp-Ch]

  v2 = *(_DWORD *)off_11EC5C;
  v3 = *(_DWORD *)dword_11EC60;
  v4 = *(_DWORD *)(dword_11EC60 + 8 + 0xFFFFFFFC);
  v5 = *(_DWORD *)(dword_11EC60 + 8);
  result = sub_1018F0(&v1, 0);
  if ( (v2 & 0xF) == 2 )
    return (_QWORD *)sub_12F448(&v1);
  return result;
}

