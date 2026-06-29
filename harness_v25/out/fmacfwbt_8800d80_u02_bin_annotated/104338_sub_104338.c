// fwstruct annotate: 104338_sub_104338.c
// sub_104338 @ 0x104338, size 212 bytes
int sub_104338()
{
  int *v0; // r1
  _DWORD *v1; // r3
  int v2; // r0
  int v3; // r5
  _DWORD *v4; // r6
  int *v5; // r4
  int v6; // r1
  int result; // r0
  _DWORD *v8; // r3
  _DWORD *v9; // r1

  v0 = (int *)off_10440C;
  v1 = off_104414;
  v2 = dword_104418;
  v3 = *(_DWORD *)off_104410;
  *(_DWORD *)off_104410 = dword_10441C;
  *v0 = v2;
  v4 = off_104420;
  v5 = (int *)off_104424;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v1 &= 0x3FFFFFFFu;
  *v1 |= 0xC000000u;
  *v1 = ~(~(*v1 >> 12) << 12);
  v0[29] = v0[29] & 0xFFFFFF0F | 0xA0;
  *v1 |= 0x10000000u;
  sub_100644(10);
  *v4 = dword_104428;
  sub_100644(125);
  *v4 = dword_10442C;
  while ( *v5 < 0 )
    sub_100644(1);
  sub_12EEF8(1, dword_104430);
  v6 = dword_104434;
  *(_DWORD *)off_104420 = 0;
  sub_12EEF8(1, v6);
  *(_DWORD *)off_104410 = v3;
  sub_10422C();
  result = sub_12EEF8(1, dword_104438);
  v8 = off_104414;
  v9 = off_10443C;
  *(_DWORD *)off_104414 &= 0xF3FFFFFF;
  *v9 |= 0xF0u;
  *v8 &= ~0x10000000u;
  *v8 &= 0x3FFFFFFFu;
  return result;
}

