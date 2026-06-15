// sub_123FF0 @ 0x123ff0, size 118 bytes
int __fastcall sub_123FF0(unsigned int a1, int a2, int a3)
{
  int v3; // r4
  unsigned int *v4; // r5
  unsigned int v5; // r2
  int *v6; // r5
  int v7; // r3

  if ( !a1 )
  {
    if ( !a2 )
    {
      v3 = 1024;
      goto LABEL_4;
    }
LABEL_3:
    v3 = a3 << 9;
LABEL_4:
    v4 = (unsigned int *)off_12406C;
    v5 = *(_DWORD *)off_12406C & 0xE3FFFFFF;
    *(_DWORD *)off_124068 = *(_DWORD *)off_124068 & 0xFFFFC180 | a2 & 0xFFFFF9FF | (a1 << 11) | v3;
    *v4 = v5;
LABEL_8:
    ++*(_BYTE *)off_124074;
    return 0;
  }
  if ( a1 <= 4 )
    goto LABEL_3;
  if ( (*(_DWORD *)off_124070 & 1) == 0 )
  {
    v6 = (int *)off_12406C;
    v7 = *(_DWORD *)off_12406C | 0x10000000;
    *(_DWORD *)off_124068 = *(_DWORD *)off_124068 & 0xFFFFC780 | a2 | (a1 << 11);
    *v6 = v7;
    goto LABEL_8;
  }
  msg_parse(dword_124078, a1, a3, *(_DWORD *)off_124070 << 31);
  return 1;
}

