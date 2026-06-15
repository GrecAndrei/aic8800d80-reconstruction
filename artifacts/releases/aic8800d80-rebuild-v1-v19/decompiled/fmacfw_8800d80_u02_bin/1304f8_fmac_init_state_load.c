// fmac_init_state_load @ 0x1304f8, size 174 bytes
// Doc: fmac_init_state_load [util]: Loads signed byte state and initializes context
// fmac_init_state_load [util]: Loads signed byte state and initializes context
void fmac_init_state_load()
{
  _BYTE *v0; // r4
  int v1; // r2
  int v2; // r3
  unsigned int v3; // r3
  char v4; // r0
  int v5; // r1
  char v6; // r3
  int v7; // r0
  unsigned __int8 v8; // [sp+3h] [bp-Dh] BYREF
  int v9; // [sp+4h] [bp-Ch] BYREF
  int v10; // [sp+8h] [bp-8h] BYREF
  int v11; // [sp+Ch] [bp-4h] BYREF

  v0 = off_1305A8;
  v1 = *(char *)off_1305A8;
  if ( *(_BYTE *)off_1305A8 )
    return;
  v8 = *(_BYTE *)off_1305A8;
  v2 = *(_DWORD *)off_1305AC;
  v9 = v1;
  if ( (v2 & 0x2000000) != 0 )
  {
    rf_cmd_wait_n_7e(&v8);
    rf_fault_dump_n384(&v9);
    goto LABEL_4;
  }
  v10 = 0;
  v11 = 0;
  if ( !sub_114D34((int)&v10) )
    v8 = v10;
  if ( sub_114D64((int)&v11) )
  {
LABEL_4:
    v3 = v8;
    if ( v8 )
      goto LABEL_5;
    goto LABEL_19;
  }
  v9 = (char)v11;
  v3 = v8;
  if ( v8 )
  {
LABEL_5:
    if ( v3 > 0x1F )
    {
      LOBYTE(v3) = 31;
      v8 = 31;
    }
    goto LABEL_7;
  }
LABEL_19:
  LOBYTE(v3) = 15;
LABEL_7:
  v0[4] = v3;
  v4 = sub_10EF24();
  v5 = v9;
  v0[6] = v4;
  if ( v5 )
  {
    if ( v5 < -7 )
    {
      v6 = -7;
      v9 = -7;
      v5 = -7;
    }
    else if ( v5 > 8 )
    {
      v6 = 8;
      v9 = 8;
      v5 = 8;
    }
    else
    {
      v6 = v5;
    }
    v7 = dword_1305B0;
    v0[2] = v6;
    msg_parse(v7, v5);
  }
  v0[3] = 0x80;
  *v0 = 1;
}

