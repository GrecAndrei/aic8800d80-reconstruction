// fwstruct annotate: 12c0a0_sub_12C0A0.c
// sub_12C0A0 @ 0x12c0a0, size 290 bytes
void __fastcall sub_12C0A0(int a1, int a2)
{
  int v2; // r4
  int *v3; // r0
  int *v4; // r1
  int v5; // r2
  int v6; // r3
  unsigned int *v7; // r1
  int v8; // r0
  unsigned int v9; // r2
  void *v10; // r2
  int v11; // r0
  int v12; // r6
  int v13; // r2
  int v14; // r0

  v2 = *(_DWORD *)off_12C1C4 & *(_DWORD *)off_12C1C8;
  *(_DWORD *)((char *)off_12C1C4 + 0xFFFFFFFC) = v2;
  if ( v2 << 30 )
  {
    v3 = (int *)off_12C1CC;
    v4 = (int *)off_12C1D0;
    v5 = *(_DWORD *)off_12C1CC;
    v6 = *(_DWORD *)off_12C1D0;
    if ( (v2 & 1) != 0 && !*((_BYTE *)off_12C1D4 + 36) )
    {
      v12 = v5 | 0x5400;
      v13 = v5 | 0xFC00;
      *(_DWORD *)off_12C1CC = v12;
      *v3 = v13;
      *v4 = v6 | 0x500000;
      v14 = dword_12C1F8;
      *v4 = v6 | 0xF00000;
      sub_12E948(v14, v4, v13);
    }
    else
    {
      v7 = (unsigned int *)off_12C1D0;
      v8 = dword_12C1D8;
      v9 = v5 & 0xFFFF57FF;
      *(_DWORD *)off_12C1CC = v9;
      *v7 = v6 & 0xFF5FFFFF;
      sub_12E948(v8, v7, v9);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(_DWORD *)off_12C1DC & 1) != 0 )
    {
      *(_DWORD *)off_12C1E0 |= 0x400000u;
      while ( 1 )
        ;
    }
    v10 = off_12C1EC;
    v11 = dword_12C1F4;
    *(_DWORD *)off_12C1EC |= 1u;
    sub_12E948(v11, a2, v10);
  }
}

