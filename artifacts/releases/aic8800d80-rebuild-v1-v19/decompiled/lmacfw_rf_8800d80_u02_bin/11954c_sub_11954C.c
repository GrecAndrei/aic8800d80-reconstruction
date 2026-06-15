// sub_11954C @ 0x11954c, size 288 bytes
// Doc: sub_121954C [rf]: Issue sub-call with opcode 0x6a via dispatch
// sub_121954C [rf]: Issue sub-call with opcode 0x6a via dispatch
int __fastcall sub_11954C(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r3
  unsigned int v7; // r3
  unsigned int v8; // r0
  __int64 v9; // r0
  int v10; // r3
  int v12; // r1
  int v13; // r5
  int v14; // r0
  __int16 v15; // [sp+2h] [bp-Ah] BYREF
  int v16; // [sp+4h] [bp-8h] BYREF

  v15 = 0;
  v5 = rf_setup_dispatch(106, a4, a3, 16);
  if ( (*(_DWORD *)off_11966C & 0x2000000) != 0 )
  {
    sub_113B88(&v15);
    rf_cmd_query_status((_BYTE *)&v15 + 1);
    msg_parse(dword_119684, (unsigned __int8)v15);
    goto LABEL_16;
  }
  v16 = 0;
  if ( sub_114558((int)&v16) )
  {
LABEL_16:
    v6 = (unsigned __int8)v15;
    goto LABEL_4;
  }
  v6 = (unsigned __int8)v16;
  v15 = v16;
LABEL_4:
  if ( !v6 && *(_BYTE *)(a2 + 20) )
  {
    msg_parse(dword_119694, *(unsigned __int8 *)(a2 + 20));
    LOBYTE(v15) = *(_BYTE *)(a2 + 20);
  }
  v7 = HIBYTE(v15);
  if ( !HIBYTE(v15) )
  {
    if ( *(_BYTE *)(a2 + 21) )
    {
      msg_parse(dword_119690, *(unsigned __int8 *)(a2 + 21));
      v8 = (unsigned __int8)v15;
      v7 = *(unsigned __int8 *)(a2 + 21);
      HIBYTE(v15) = *(_BYTE *)(a2 + 21);
      if ( !(_BYTE)v15 )
        goto LABEL_13;
    }
    else
    {
      v8 = (unsigned __int8)v15;
      if ( !(_BYTE)v15 )
        goto LABEL_14;
    }
LABEL_10:
    if ( v8 > 0x1F )
    {
      v8 = 31;
      LOBYTE(v15) = 31;
    }
    sub_10F170(v8);
    msg_parse(dword_119670, (unsigned __int8)v15);
    v7 = HIBYTE(v15);
LABEL_13:
    if ( !v7 )
      goto LABEL_14;
    goto LABEL_18;
  }
  v8 = (unsigned __int8)v15;
  if ( (_BYTE)v15 )
    goto LABEL_10;
LABEL_18:
  if ( v7 > 0x3F )
  {
    v12 = 63;
    HIBYTE(v15) = 63;
    v13 = 16515072;
  }
  else
  {
    v12 = HIBYTE(v15);
    v13 = (HIBYTE(v15) << 18) & 0xFC0000;
  }
  v14 = dword_11968C;
  *(_DWORD *)off_119688 = *(_DWORD *)off_119688 & 0xFF03FFFF | v13;
  msg_parse(v14, v12);
LABEL_14:
  LODWORD(v9) = *((_DWORD *)off_119674 + 2);
  HIDWORD(v9) = *(_DWORD *)off_119678;
  v10 = dword_119680;
  *(_DWORD *)(v5 + 12) = *(_DWORD *)off_11967C;
  *(_QWORD *)(v5 + 4) = v9;
  *(_DWORD *)v5 = v10;
  sub_11DE50(v5);
  return 0;
}

