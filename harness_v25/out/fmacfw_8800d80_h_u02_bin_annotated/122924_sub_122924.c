// fwstruct annotate: 122924_sub_122924.c
// sub_122924 @ 0x122924, size 152 bytes
int __fastcall sub_122924(int a1, unsigned __int8 *a2, int a3, int a4)
{
  int v4; // r4
  _BYTE *v7; // r4
  _DWORD *v8; // r6
  _DWORD *v9; // r5
  unsigned int v10; // r3
  _DWORD *v11; // r3
  _DWORD *v13; // r6
  _DWORD *v14; // r5

  v4 = *a2;
  if ( v4 && *((_BYTE *)off_1229BC + 177) )
  {
    v7 = off_1229C0;
    v13 = off_1229C4;
    v14 = off_1229C8;
    *(_BYTE *)off_1229C0 = 1;
    *v13 |= 0x2000000u;
    v14[14] |= 0x10u;
  }
  else
  {
    v7 = off_1229C0;
    v8 = off_1229C4;
    v9 = off_1229C8;
    *(_BYTE *)off_1229C0 = 0;
    *v8 &= ~0x2000000u;
    v9[14] &= ~0x10u;
  }
  *(_DWORD *)off_1229C4 &= ~0x800u;
  v7[2] = 0;
  if ( a2[2] )
    v10 = *(_DWORD *)off_1229CC | 0x80000000;
  else
    v10 = *(_DWORD *)off_1229CC & 0x7FFFFFFF;
  *(_DWORD *)off_1229CC = v10;
  if ( a2[4] )
  {
    v11 = off_1229D4;
    *(_DWORD *)off_1229D0 = *((_DWORD *)a2 + 2);
    *v11 &= 0xFFFFFu;
    *v11 |= *((_DWORD *)a2 + 3) << 20;
  }
  sub_12C8D0(102, a4, a3);
  return 0;
}

