// sub_135CCC @ 0x135ccc, size 76 bytes
_BYTE *__fastcall sub_135CCC(_BYTE *a1, int a2)
{
  _BYTE *result; // r0
  int v3; // r2
  unsigned int v4; // r3
  _BYTE *v5; // r0
  int v6; // r1
  unsigned int v7; // r3
  _BYTE *v8; // r0
  char *(_DWORD *)(v9 + 0x14); // [sp+7h] [bp-5h] BYREF

  result = sub_12DBBC(a1, a2, v9);
  if ( result )
  {
    if ( (unsigned __int8)*(_DWORD *)(v9 + 0x0) <= 0x1Du )
      return nullptr;
    v3 = (unsigned __int16)(4 * *((_WORD *)result + 4));
    v4 = (unsigned __int8)(*(_DWORD *)(v9 + 0x0) - 10 - 4 * *(_DWORD *)(result + 0x20));
    if ( v4 <= 0x15 )
      return nullptr;
    v5 = result + 10;
    v6 = (unsigned __int16)(4 * *(_WORD *)&v5[v3]);
    v7 = (unsigned __int8)(v4 - 2 - 4 * v5[v3]);
    v8 = &v5[v3];
    if ( v7 <= 0x13 )
      return nullptr;
    else
      return (_BYTE *)*(unsigned __int16 *)&v8[v6 + 4];
  }
  return result;
}

