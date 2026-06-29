// sub_12F040 @ 0x12f040, size 468 bytes
int sub_12F040()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r10
  uint32_t *v2; // r6
  uint32_t *v3; // r7
  uint32_t *v4; // r8
  uint32_t *v5; // r9
  uint32_t *v6; // r5
  int v7; // r2
  unsigned int v8; // r0
  int v9; // r3
  uint32_t *v10; // r7
  int v11; // r6
  uint32_t *v12; // r5
  int v13; // r4
  bool v15; // nf
  uint32_t **v16; // r3

  v0 = off_12F21C;
  v1 = off_12F2B8;
  v2 = off_12F220;
  v3 = off_12F224;
  v4 = off_12F2BC;
  v5 = off_12F2C0;
  v6 = off_12F228;
  sub_12E948(dword_12F218, *(uint32_t *)off_12F214 & 0xF);
  sub_12E948(dword_12F230, *v0, *(uint32_t *)off_12F22C);
  sub_12E948(dword_12F234, *v1);
  sub_12E948(dword_12F238, *v2);
  sub_12E948(dword_12F23C, *v3);
  sub_12E948(dword_12F240, *v4);
  sub_12E948(dword_12F244, *v5);
  sub_12E948(dword_12F248, *v6);
  sub_12E948(
    dword_12F25C,
    *(uint32_t *)off_12F24C,
    *(uint32_t *)off_12F250,
    *(uint32_t *)off_12F254,
    *(uint32_t *)off_12F258,
    *(uint32_t *)off_12F2C4);
  sub_12E948(dword_12F260, *(uint32_t *)(*v2 + 60));
  sub_12E948(dword_12F264, *(uint32_t *)(*v3 + 60));
  sub_12E948(dword_12F268, *(uint32_t *)(*v4 + 60));
  sub_12E948(dword_12F26C, *(uint32_t *)(*v5 + 60));
  sub_12E948(dword_12F270, *(uint32_t *)(*v6 + 60));
  v7 = *v0 << 6;
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (uint32_t *)*v6;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(uint32_t **)off_12F2B0;
  }
  else if ( (*v0 & 0x20) != 0 )
  {
    v0 = (uint32_t *)*v2;
  }
  else if ( (*v0 & 0x200) != 0 )
  {
    v0 = (uint32_t *)*v3;
  }
  else if ( (*v0 & 0x2000) != 0 )
  {
    v0 = (uint32_t *)*v4;
  }
  else
  {
    v7 = *v0 << 14;
    if ( (*v0 & 0x20000) != 0 )
    {
      v0 = (uint32_t *)*v5;
    }
    else
    {
      v16 = (uint32_t **)(*v0 << 30);
      v15 = (*v0 & 2) != 0;
      if ( (*v0 & 2) != 0 )
        v16 = (uint32_t **)dword_12F2B4;
      else
        v0 = (uint32_t *)*v1;
      if ( v15 )
        v0 = *v16;
    }
  }
  if ( v0 )
  {
    sub_12E9D8((unsigned int)v0, 68, 1, 0);
    sub_12E9D8(v0[9], 52, 1, 0);
    sub_12E948(dword_12F274, v0[6]);
    v8 = v0[4];
    if ( v8 )
    {
      sub_12E9D8(v8, v0[5] + 1 - v8, 1, 0);
      v9 = v0[3];
      if ( !v9 )
        goto LABEL_6;
    }
    else
    {
      v9 = v0[3];
      if ( !v9 )
        goto LABEL_6;
    }
    sub_12E9D8(*(uint32_t *)(v9 + 8), *(uint32_t *)(v9 + 12) + 1 - *(uint32_t *)(v9 + 8), 1, 0);
  }
LABEL_6:
  v10 = off_12F278;
  v11 = dword_12F27C;
  v12 = off_12F280;
  LOBYTE(v13) = 8;
  do
  {
    sub_12E948(v11, *v10, v7);
    sub_12E948(dword_12F284, *v12);
    v13 = (unsigned __int8)(v13 - 1);
  }
  while ( v13 );
  sub_12E948(dword_12F28C, *(uint32_t *)off_12F288);
  sub_12E948(dword_12F294, *(uint32_t *)off_12F290);
  sub_12E948(dword_12F29C, *(uint32_t *)off_12F298);
  sub_12E948(dword_12F2A4, *(uint32_t *)off_12F2A0);
  return sub_12E948(dword_12F2AC, *(uint32_t *)off_12F2A8);
}

