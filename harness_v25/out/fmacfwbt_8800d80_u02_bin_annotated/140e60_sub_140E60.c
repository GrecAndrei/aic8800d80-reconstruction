// fwstruct annotate: 140e60_sub_140E60.c
// sub_140E60 @ 0x140e60, size 52 bytes
int __fastcall sub_140E60(char a1, char a2, char a3, int a4, char a5)
{
  int v5; // r4
  __int16 v6; // r6
  int result; // r0
  _BYTE v8[140]; // [sp+0h] [bp-8Ch] BYREF

  v5 = dword_140E94;
  v8[2] = a5;
  v6 = *(_WORD *)(dword_140E94 + 6488);
  *(_BYTE *)(dword_140E94 + 6488) = a2;
  *(_BYTE *)(v5 + 6489) = a1;
  v8[0] = a3;
  result = sub_140B80((int)v8, a4);
  *(_WORD *)(v5 + 6488) = v6;
  return result;
}

