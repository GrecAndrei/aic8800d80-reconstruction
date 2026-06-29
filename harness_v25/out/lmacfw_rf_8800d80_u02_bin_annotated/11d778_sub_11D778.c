// fwstruct annotate: 11d778_sub_11D778.c
// sub_11D778 @ 0x11d778, size 290 bytes
void __fastcall sub_11D778(int a1, int a2)
{
  int v2; // r4
  int *v3; // r0
  int *v4; // r1
  int v5; // r2
  int v6; // r3
  unsigned int *v7; // r1
  int v8; // r0
  int v9; // r0
  int v10; // r0

  v2 = *(_DWORD *)off_11D89C & *(_DWORD *)off_11D8A0;
  *(_DWORD *)((char *)off_11D89C + 0xFFFFFFFC) = v2;
  if ( v2 << 30 )
  {
    v3 = (int *)off_11D8A4;
    v4 = (int *)off_11D8A8;
    v5 = *(_DWORD *)off_11D8A4;
    v6 = *(_DWORD *)off_11D8A8;
    if ( (v2 & 1) != 0 && !*((_BYTE *)off_11D8AC + 36) )
    {
      *(_DWORD *)off_11D8A4 = v5 | 0x5400;
      *v3 = v5 | 0xFC00;
      *v4 = v6 | 0x500000;
      v10 = dword_11D8D0;
      *v4 = v6 | 0xF00000;
      msg_parse(v10, v4);
    }
    else
    {
      v7 = (unsigned int *)off_11D8A8;
      v8 = dword_11D8B0;
      *(_DWORD *)off_11D8A4 = v5 & 0xFFFF57FF;
      *v7 = v6 & 0xFF5FFFFF;
      msg_parse(v8, v7);
    }
  }
  if ( (v2 & 4) != 0 )
  {
    if ( (*(_DWORD *)off_11D8B4 & 1) != 0 )
    {
      *(_DWORD *)off_11D8B8 |= 0x400000u;
      while ( 1 )
        ;
    }
    v9 = dword_11D8CC;
    *(_DWORD *)off_11D8C4 |= 1u;
    msg_parse(v9, a2);
  }
}

