// sub_13B424 @ 0x13b424, size 142 bytes
int __fastcall sub_13B424(int a1, char *a2, unsigned int a3)
{
  unsigned int v5; // r5
  int v6; // r6
  char v7; // r0
  char v8; // r8
  unsigned __int8 v9; // r7
  char v10; // r6
  _BYTE *v11; // r0

  if ( a2[2] != 2 )
    return 0;
  v5 = a3 >> 8;
  if ( sub_12CD48(a3 & 0xFF00 | 8) == 4 )
  {
    v6 = dword_13B4B4 + 32 * v5;
    if ( *(_BYTE *)(v6 + 17) == 1 )
    {
      v7 = sub_13C2C0(*(_DWORD *)(v6 + 28));
      v8 = *a2;
      v9 = a2[1];
      v10 = 4 - *(_BYTE *)(v6 + 20) + v7;
      v11 = (_BYTE *)sub_12C7EC(5131, 13, 5, 3u);
      v11[2] = v10;
      *v11 = v8;
      v11[1] = v9;
      sub_12C84C((int)v11);
    }
    *(_DWORD *)(696 * (unsigned __int8)*a2 + 12 * (unsigned __int8)a2[1] + dword_13B4B8 + 448) = *((_DWORD *)off_13B4BC
                                                                                                 + 4);
    sub_13BAE8(v5);
  }
  return 0;
}

