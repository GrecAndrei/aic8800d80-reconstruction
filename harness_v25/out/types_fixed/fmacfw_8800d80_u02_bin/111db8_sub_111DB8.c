// sub_111DB8 @ 0x111db8, size 262 bytes
int __fastcall sub_111DB8(_DWORD *a1, int a2)
{
  _BYTE *v4; // r6
  _DWORD *v5; // r7
  void *v6; // r0
  int v7; // r2
  int v8; // r1
  _DWORD *v9; // r4
  int v10; // r1
  void (__fastcall *v11)(int); // r2
  int v12; // r1
  _DWORD *v13; // r3
  _BYTE *v15; // r7
  int v16; // r0
  int v17; // r1
  _DWORD *v18; // r3

  sub_12EA88(dword_111EC0, 0, a2);
  if ( !a1 )
    return 1;
  if ( !*a1 || !*(_DWORD *)(a1 + 0x4) || !*(_DWORD *)(a1 + 0x8) || !*(_DWORD *)(a1 + 0x14) )
    return 2;
  v4 = off_111EC4;
  if ( *(_BYTE *)off_111EC4 )
    return 3;
  v5 = off_111EC8;
  v6 = off_111ECC;
  *(_BYTE *)off_111EC4 = 1;
  sub_143770(v6, a1, 80);
  v8 = *(_DWORD *)(v5 + 0x184);
  if ( v8 )
  {
    sub_12EA88(dword_111EF8, v8, v7);
    sub_100644(*(_DWORD *)(v5 + 0x184));
  }
  v9 = off_111ED0;
  if ( (*((_DWORD *)off_111ED0 + 512) & 0x7F0) != 0 )
  {
    v15 = off_111EE8;
    *((_DWORD *)off_111EE8 + 1) = 0;
    *((_DWORD *)v15 + 2) = 0;
    *v15 = 0;
    *v4 = 4;
    v16 = sub_111884();
    v17 = *(_DWORD *)off_111EEC;
    v18 = *(_DWORD **)off_111EF0;
    *v18 = dword_111EF4;
    *(_DWORD *)(v18 + 0x4) = v17;
    *(_DWORD *)(v9 + 0xb14) = v18;
    *(_DWORD *)(v9 + 0xb08) = *(_DWORD *)(v9 + 0xb08);
    v11 = *((void (__fastcall **)(int))off_111ECC + 19);
    v10 = 1;
    *(_DWORD *)(v9 + 0xb00) |= 0x84000000;
    *v15 = 1;
    if ( v11 )
      v11(v16);
  }
  else
  {
    if ( (*((_DWORD *)off_111ED0 + 2) & 1) != 0 )
    {
      *((_DWORD *)off_111ED0 + 2) &= ~1u;
      *(_DWORD *)(v9 + 0x804) |= 2u;
    }
    sub_1119FC();
  }
  sub_12EA88(dword_111ED4, v10, v11);
  v12 = dword_111EDC;
  v13 = off_111EE0;
  *(_DWORD *)(*((_DWORD *)off_111ED8 + 2) + 320) = dword_111EDC;
  *(_DWORD *)(v13 + 0x8) = 1;
  if ( a2 == 1 )
  {
    while ( *v4 != 4 )
      ;
  }
  sub_12EA88(dword_111EE4, v12, 1);
  return 0;
}

