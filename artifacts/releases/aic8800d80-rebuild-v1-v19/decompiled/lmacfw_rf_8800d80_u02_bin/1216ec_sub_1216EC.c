// sub_1216EC @ 0x1216ec, size 448 bytes
int sub_1216EC()
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

  v0 = off_1218B4;
  v1 = off_121950;
  v2 = off_1218B8;
  v3 = off_1218BC;
  v4 = off_121954;
  v5 = off_121958;
  v6 = off_1218C0;
  msg_parse(dword_1218B0, *(_DWORD *)off_1218AC & 0xF);
  msg_parse(dword_1218C8, *v0, *(_DWORD *)off_1218C4);
  msg_parse(dword_1218CC, *v1);
  msg_parse(dword_1218D0, *v2);
  msg_parse(dword_1218D4, *v3);
  msg_parse(dword_1218D8, *v4);
  msg_parse(dword_1218DC, *v5);
  msg_parse(dword_1218E0, *v6);
  msg_parse(
    dword_1218F4,
    *(_DWORD *)off_1218E4,
    *(_DWORD *)off_1218E8,
    *(_DWORD *)off_1218EC,
    *(_DWORD *)off_1218F0,
    *(_DWORD *)off_12195C);
  msg_parse(dword_1218F8, *(_DWORD *)(*v2 + 60));
  msg_parse(dword_1218FC, *(_DWORD *)(*v3 + 60));
  msg_parse(dword_121900, *(_DWORD *)(*v4 + 60));
  msg_parse(dword_121904, *(_DWORD *)(*v5 + 60));
  msg_parse(dword_121908, *(_DWORD *)(*v6 + 60));
  v7 = *v0 << 6;
  if ( (*v0 & 0x2000000) != 0 )
  {
    v0 = (_DWORD *)*v6;
  }
  else if ( (*v0 & 0x200000) != 0 )
  {
    v0 = *(_DWORD **)off_121948;
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
        v16 = (_DWORD **)dword_12194C;
      else
        v0 = (_DWORD *)*v1;
      if ( v15 )
        v0 = *v16;
    }
  }
  if ( v0 )
  {
    rf_mem_read_f594((unsigned int)v0, 68, 1, 0);
    rf_mem_read_f594(v0[9], 52, 1, 0);
    msg_parse(dword_12190C, v0[6]);
    v8 = v0[4];
    if ( v8 )
    {
      rf_mem_read_f594(v8, v0[5] + 1 - v8, 1, 0);
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
    rf_mem_read_f594(*(_DWORD *)(v9 + 8), *(_DWORD *)(v9 + 12) + 1 - *(_DWORD *)(v9 + 8), 1, 0);
  }
LABEL_6:
  v10 = off_121910;
  v11 = dword_121914;
  v12 = off_121918;
  LOBYTE(v13) = 8;
  do
  {
    msg_parse(v11, *v10, v7);
    msg_parse(dword_12191C, *v12);
    v13 = (unsigned __int8)(v13 - 1);
  }
  while ( v13 );
  msg_parse(dword_121924, *(_DWORD *)off_121920);
  msg_parse(dword_12192C, *(_DWORD *)off_121928);
  msg_parse(dword_121934, *(_DWORD *)off_121930);
  msg_parse(dword_12193C, *(_DWORD *)off_121938);
  return msg_parse(dword_121944, *(_DWORD *)off_121940);
}

