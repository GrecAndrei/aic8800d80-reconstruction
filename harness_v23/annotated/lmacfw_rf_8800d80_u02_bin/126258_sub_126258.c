// v23 annotated: sub_126258 @ 0x126258
// Original: 126258_sub_126258.c
// Primary struct: <unclustered>
//
// sub_126258 @ 0x126258, size 148 bytes
int __fastcall sub_126258(int a1, int a2, char a3)
{
  _BYTE *v3; // r5
  _BYTE *v5; // r3
  _BYTE *v6; // r0
  _BYTE *v7; // r1
  _BYTE *v8; // r2
  _DWORD *v9; // r3
  int *v10; // r0
  _DWORD *v11; // r0
  _BYTE *v12; // r1
  _BYTE *v13; // r2
  int v14; // r0

  v3 = off_1262EC;
  if ( *(_BYTE *)off_1262EC )
    msg_parse(dword_126328);
  v5 = off_1262F4;
  v6 = off_1262F8;
  v7 = off_1262FC;
  v8 = off_126300;
  *(_DWORD *)off_1262F0 = -1;
  *v5 = 0;
  v9 = off_126304;
  *v6 = 0;
  *v7 = 0;
  *v8 = a3;
  v10 = (int *)dword_126308;
  *v9 |= 0x100u;
  *v9 |= 0x200u;
  *v9 |= 0x400u;
  sub_100200(v10, 0, 8u);
  msg_parse(dword_12630C);
  v11 = off_126314;
  v12 = off_126318;
  v13 = off_12631C;
  *(_WORD *)off_126310 = 0;
  *v11 = 0;
  *v12 = 1;
  *v13 = 1;
  sub_10F170(16);
  v14 = dword_126324;
  *(_DWORD *)off_126320 = *(_DWORD *)off_126320 & 0xFF03FFFF | 0x800000;
  *v3 = 5;
  msg_parse(v14);
  return irq_nesting_or(0x2000);
}

