// sub_131100 @ 0x131100, size 72 bytes
// Doc: sub_1231100 [ipc]: Forward event/message to handler at 0x12dd08
// sub_1231100 [ipc]: Forward event/message to handler at 0x12dd08
int __fastcall sub_131100(_BYTE *a1, int a2, int a3)
{
  int result; // r0
  int v5; // r3
  __int16 v6; // r3
  __int16 v7; // r2

  result = (int)sub_12DD08(a1, a2);
  if ( result )
  {
    *(_WORD *)a3 = *(unsigned __int8 *)(result + 2) | (*(unsigned __int8 *)(result + 3) << 8);
    *(_BYTE *)(a3 + 2) = *(_BYTE *)(result + 4);
    v5 = a3 + 2;
    do
    {
      *(_BYTE *)(v5 + 1) = *(_BYTE *)(result + v5 + 3 - a3);
      ++v5;
    }
    while ( v5 != a3 + 18 );
    v6 = *(unsigned __int8 *)(result + 21);
    v7 = *(unsigned __int8 *)(result + 22);
    *(_DWORD *)(a3 + 24) = *(unsigned __int16 *)(result + 23);
    *(_WORD *)(a3 + 20) = v6 | (v7 << 8);
    *(_BYTE *)(a3 + 28) = *(_BYTE *)(result + 27);
    return 1;
  }
  return result;
}

