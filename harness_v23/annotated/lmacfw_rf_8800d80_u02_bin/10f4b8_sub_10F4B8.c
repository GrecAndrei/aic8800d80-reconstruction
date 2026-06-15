// v23 annotated: sub_10F4B8 @ 0x10f4b8
// Original: 10f4b8_sub_10F4B8.c
// Primary struct: log_state (cluster 19, 4 funcs)
// Fields: enable=0x0, state=0x0, level=0x4, flag=0x7, count=0x8, tick=0xa, buf=0x14, status=0x16a
//
// sub_10F4B8 @ 0x10f4b8, size 70 bytes
void __noreturn sub_10F4B8()
{
  __int64 v0; // r0
  __int64 v1; // kr00_8
  _QWORD *v2; // r3

  v0 = *(_QWORD *)(*(_DWORD *)off_10F500 + 32);
  v1 = *(_QWORD *)(*(_DWORD *)off_10F500 + 24);
  v2 = off_10F504;
  *((_DWORD *)off_10F504 + 4) = *(_DWORD *)(*(_DWORD *)off_10F500 + 44);
  *v2 = v1;
  v2[1] = v0;
  sub_10C2E4();
}

