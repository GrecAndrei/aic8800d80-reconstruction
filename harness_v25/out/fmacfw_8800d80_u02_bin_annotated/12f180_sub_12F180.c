// fwstruct annotate: 12f180_sub_12F180.c
// sub_12F180 @ 0x12f180, size 468 bytes
// Doc: fmac_init_subsystems [mac]: Initializes FMAC subsystem registers and pointers
// fmac_init_subsystems [mac]: Initializes FMAC subsystem registers and pointers
int sub_12F180()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r10
  _DWORD *v2; // r6
  _DWORD *v3; // r7
  _DWORD *v4; // r8
  _DWORD *v5; // r9
  _DWORD *v6; // r5
  int v7; // r2
  unsigned int v8; // r0
  int v9; // r3
  _DWORD *v10; // r7
  int v11; // r6
  _DWORD *v12; // r5
  int v13; // r4
  bool v15; // nf
  _DWORD **v16; // r3

  v0 = off_12F35C;
  v1 = off_12F3F8;
  v2 = off_12F360;
  v3 = off_12F364;
  v4 = off_12F3FC;
  v5 = off_12F400;
  v6 = off_12F368;
  msg_parse(dword_12F358, *(_DWORD *)off_12F354 & 0xF);
  msg_parse(dword_12F370, *v0, *(_DWORD *)off_12F36C);
  msg_parse(dword_12F374, *v1);
  msg_parse(dword_12F378, *v2);
  msg_parse(dword_12F37C, *v3);
  msg_parse(dword_12F380, *v4);
  msg_parse(dword_12F384, *v5);
  msg_parse(dword_12F388, *v6);
  msg_parse(
    dword_12F39C,
    *(_DWORD *)off_12F38C,
    *(_DWORD *)off_12F390,
    *(_DWORD *)off_12F394,
    *(_DWORD *)off_12F398,
    *(_DWORD *)off_12F404);
  msg_parse(dword_12F3A0, *(_DWORD *)(*v2 + 60));
  msg_parse(dword_12F3A4, *(_DWORD *)(*v3 + 60));
  msg_parse(dword_12F3A8, *(_DWORD *)(*v4 + 60));
  msg_parse(dword_12F3AC, *(_DWORD *)(*v5 + 60));
  msg_parse(dword_12F3B0, *(_DWORD *)(*v6 + 60));
  v7 = *v0 << 6;
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (_DWORD *)*v6;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(_DWORD **)off_12F3F0;
  }
  else if ( (*v0 & 0x20) != 0 )
  {
    v0 = (_DWORD *)*v2;
  }
  else if ( (*v0 & 0x200) != 0 )
  {
    v0 = (_DWORD *)*v3;
  }
  else if ( (*v0 & 0x2000) != 0 )
  {
    v0 = (_DWORD *)*v4;
  }
  else
  {
    v7 = *v0 << 14;
    if ( (*v0 & 0x20000) != 0 )
    {
      v0 = (_DWORD *)*v5;
    }
    else
    {
      v16 = (_DWORD **)(*v0 << 30);
      v15 = (*v0 & 2) != 0;
      if ( (*v0 & 2) != 0 )
        v16 = (_DWORD **)dword_12F3F4;
      else
        v0 = (_DWORD *)*v1;
      if ( v15 )
        v0 = *v16;
    }
  }
  if ( v0 )
  {
    rf_mem_read_eb18((unsigned int)v0, 68, 1, 0);
    rf_mem_read_eb18(v0[9], 52, 1, 0);
    msg_parse(dword_12F3B4, v0[6]);
    v8 = v0[4];
    if ( v8 )
    {
      rf_mem_read_eb18(v8, v0[5] + 1 - v8, 1, 0);
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
    rf_mem_read_eb18(*(_DWORD *)(v9 + 8), *(_DWORD *)(v9 + 12) + 1 - *(_DWORD *)(v9 + 8), 1, 0);
  }
LABEL_6:
  v10 = off_12F3B8;
  v11 = dword_12F3BC;
  v12 = off_12F3C0;
  LOBYTE(v13) = 8;
  do
  {
    msg_parse(v11, *v10, v7);
    msg_parse(dword_12F3C4, *v12);
    v13 = (unsigned __int8)(v13 - 1);
  }
  while ( v13 );
  msg_parse(dword_12F3CC, *(_DWORD *)off_12F3C8);
  msg_parse(dword_12F3D4, *(_DWORD *)off_12F3D0);
  msg_parse(dword_12F3DC, *(_DWORD *)off_12F3D8);
  msg_parse(dword_12F3E4, *(_DWORD *)off_12F3E0);
  return msg_parse(dword_12F3EC, *(_DWORD *)off_12F3E8);
}

