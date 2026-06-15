// sub_121F1C @ 0x121f1c, size 168 bytes
int __fastcall sub_121F1C(int a1, int a2)
{
  int v3; // r3
  int v4; // r2
  _WORD *v5; // r3
  int result; // r0
  _DWORD *v7; // r3
  int v8; // r1
  _BYTE *v9; // r3
  char *v10; // r0

  if ( (a2 & 0x800000) != 0 )
  {
    v7 = off_121FD8;
    *(_BYTE *)(a1 + 128) = 0;
    v8 = v7[4];
    v9 = off_121FD0;
    v10 = (char *)off_121FD0 + 12;
    *((_WORD *)off_121FD0 + 14) = 1793;
    v9[36] = 0;
    *((_DWORD *)v9 + 5) = a1;
    result = sub_124BFC(v10, v8 + 10000);
    *(_BYTE *)(a1 + 115) = 0;
  }
  else
  {
    v3 = (unsigned __int8)(*(_BYTE *)(a1 + 115) + 1);
    v4 = *(_DWORD *)off_121FC4;
    *(_BYTE *)(a1 + 115) = v3;
    if ( *(unsigned __int8 *)(v4 + 1) == v3 )
    {
      *(_BYTE *)(a1 + 115) = 0;
      sub_12EB90(1024, dword_121FE0);
      return sub_121ED4(a1);
    }
    else if ( *(_BYTE *)(a1 + 108) )
    {
      return sub_12B170(*(unsigned __int8 *)(a1 + 107), off_121FDC, a1);
    }
    else
    {
      if ( *((_BYTE *)off_121FC8 + 2) )
        *(_DWORD *)off_121FCC &= ~0x80000000;
      v5 = off_121FD0;
      if ( *((_BYTE *)off_121FD0 + 8) )
        --*((_BYTE *)off_121FD0 + 8);
      v5[14] = 1;
      result = sub_124CF4(dword_121FD4);
      *(_DWORD *)(a1 + 4) &= ~0x200u;
    }
  }
  return result;
}

