// mmio_read_field_n_af0 @ 0x114af0, size 350 bytes
// Doc: mmio_read_field_n_af0 [mmio]: Reads MMIO register and extracts shifted field value
// mmio_read_field_n_af0 [mmio]: Reads MMIO register and extracts shifted field value
void mmio_read_field_n_af0()
{
  int v0; // r3
  _DWORD *v1; // r7
  int *v2; // r4
  void (__fastcall **v3)(int, int); // r6
  int v4; // r5
  int v5; // r3
  _DWORD *v6; // r2
  _DWORD *v7; // r1
  int *v8; // r4
  void (__fastcall **v9)(int, int); // r5
  _BYTE *v10; // r2
  _BYTE *v11; // r1
  _BYTE *v12; // r3
  int v13; // r2

  v0 = *(_DWORD *)off_114C50;
  if ( (*(_DWORD *)off_114C50 & 0x10000) != 0 )
  {
    v8 = **(int ***)off_114C70;
    *(_DWORD *)off_114C54 = 0x10000;
    if ( v8 )
    {
      v9 = (void (__fastcall **)(int, int))off_114C74;
      while ( !*((_BYTE *)v8 + 4) )
      {
        if ( *v9 )
          (*v9)(v8[3], v8[2]);
        v8 = (int *)*v8;
        if ( !v8 )
          goto LABEL_35;
      }
      if ( **(__int16 **)off_114C78 < 0 )
        sub_12F694(dword_114C80, dword_114C7C, 209);
    }
    else
    {
LABEL_35:
      if ( !*(_BYTE *)off_114C8C )
        *(_DWORD *)off_114C6C = 0x20000;
    }
  }
  else if ( (v0 & 0x20000) != 0 )
  {
    v1 = off_114C58;
    v2 = *(int **)off_114C58;
    *(_DWORD *)off_114C54 = 0x20000;
    if ( v2 )
    {
      v3 = (void (__fastcall **)(int, int))off_114C5C;
      v4 = dword_114C60;
LABEL_8:
      while ( 2 )
      {
        if ( *((_BYTE *)v2 + 4) )
        {
          if ( **(__int16 **)off_114C78 < 0 )
            sub_12F694(dword_114C80, dword_114C90, 316);
        }
        else
        {
          if ( *v3 )
            (*v3)(v2[3], v2[2]);
          v5 = dword_114C64;
          while ( !*(_BYTE *)(v5 + 16) || v2 != (int *)v5 )
          {
            v5 += 20;
            if ( v5 == v4 )
            {
              v2 = (int *)*v2;
              if ( v2 )
                goto LABEL_8;
              goto LABEL_16;
            }
          }
          *((_BYTE *)v2 + 16) = 0;
          v2 = (int *)*v2;
          if ( v2 )
            continue;
        }
        break;
      }
    }
LABEL_16:
    v6 = off_114C68;
    if ( *(_DWORD *)off_114C68 )
    {
      v7 = off_114C6C;
      *v1 = *(_DWORD *)off_114C68;
      *v6 = 0;
      *v7 = 0x10000;
    }
    else
    {
      v10 = off_114C84;
      *v1 = 0;
      if ( *v10 )
      {
        v11 = off_114C88;
        *v10 = 0;
        if ( *v11 )
          *v11 = 0;
      }
    }
  }
  else if ( (v0 & 0x40000) != 0 )
  {
    *(_DWORD *)off_114C54 = 0x40000;
  }
  else if ( (v0 & 0x80000) != 0 )
  {
    *(_DWORD *)off_114C54 = 0x80000;
  }
  else if ( (v0 & 0x400000) != 0 )
  {
    *(_DWORD *)off_114C54 = 0x400000;
  }
  else
  {
    if ( (v0 & 0x4000000) != 0 )
    {
      *(_DWORD *)off_114C54 = 0x4000000;
      sub_12F2F0(v0 << 12, v0 << 9);
    }
    if ( (v0 & 0x8000000) != 0 )
    {
      v12 = off_114C94;
      v13 = *((unsigned __int8 *)off_114C94 + 15);
      *(_DWORD *)off_114C54 = 0x8000000;
      if ( v13 )
      {
        fw_send_event_n_584();
      }
      else if ( v12[14] == 1 )
      {
        message_dispatch_n270();
      }
    }
  }
}

