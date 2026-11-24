// sub_102908 @ 0x102908, size 52 bytes
int __fastcall sub_102908(unsigned __int8 *a1, int a2)
{
  int result; // r0
  int v4; // r1
  int v5; // r3

  if ( a2 )
    return msg_parse(dword_102940, dword_102944, a2);
  sub_101E18(*a1, *((unsigned __int16 *)a1 + 1), *((unsigned __int16 *)a1 + 2), *(_DWORD *)(a1 + 0x4));
  result = *(_DWORD *)a1;
  v4 = *((_DWORD *)a1 + 1);
  v5 = dword_10293C;
  *(_DWORD *)dword_10293C = *(_DWORD *)a1;
  *(_DWORD *)(v5 + 4) = v4;
  *(_WORD *)(v5 + 8) = *((_WORD *)a1 + 4);
  return result;
}
