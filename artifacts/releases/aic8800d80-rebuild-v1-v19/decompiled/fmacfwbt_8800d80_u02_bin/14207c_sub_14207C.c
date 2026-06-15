// sub_14207C @ 0x14207c, size 80 bytes
// Doc: sub_124207C [util]: Generic helper, indexed buffer init (size 0x2b8)
// sub_124207C [util]: Generic helper, indexed buffer init (size 0x2b8)
int __fastcall sub_14207C(int a1, int a2, char a3)
{
  int result; // r0
  unsigned __int16 v5; // r3
  int v6; // r0
  int v7; // r1
  __int64 v8; // r2
  int v9; // [sp+Ch] [bp-4h] BYREF

  result = msg_handler_1241c0c((int)&v9, dword_1420D0 + 1320 * a1, dword_1420CC + 696 * a2, 7, 0);
  if ( result )
  {
    v5 = result + 1;
    *(_BYTE *)(*(_DWORD *)(v9 + 72) + result + 108) = a3;
    v6 = v9;
    v7 = *(_DWORD *)(v9 + 76);
    LODWORD(v8) = *(_DWORD *)(v7 + 28) - 1 + v5;
    HIDWORD(v8) = v5 + 4;
    *(_QWORD *)(v7 + 32) = v8;
    return sub_1190B4(v6, 3);
  }
  return result;
}

