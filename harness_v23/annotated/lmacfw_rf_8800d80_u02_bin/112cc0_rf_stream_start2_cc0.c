// v23 annotated: rf_stream_start2_cc0 @ 0x112cc0
// Original: 112cc0_rf_stream_start2_cc0.c
// Primary struct: <unclustered>
//
// rf_stream_start2_cc0 @ 0x112cc0, size 164 bytes
// Doc: rf_cmd_send_n428 [rf]: Send RF command N428
// rf_cmd_send_n428 [rf]: Send RF command N428
int __fastcall rf_stream_start2_cc0(int a1, unsigned int a2)
{
  _BYTE *v2; // r4
  _BYTE *v3; // r5
  int v4; // r3
  _DWORD *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = off_112D64;
  if ( *(_BYTE *)off_112D64 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = off_112D68;
  if ( *(_BYTE *)off_112D68 )
  {
    sub_10DA6C(dword_112D7C, dword_112D78, *(unsigned __int8 *)off_112D68);
    return -3;
  }
  else
  {
    v4 = *(char *)off_112D6C;
    *(_BYTE *)off_112D68 = 1;
    v5 = off_112D70;
    if ( v4 )
    {
      *((_DWORD *)off_112D70 + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((_DWORD *)off_112D70 + 713) |= 1u;
    }
    v6 = sub_111A24(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      sub_10DA6C(dword_112D80, dword_112D78, v6);
      return -1;
    }
    else
    {
      *(_BYTE *)off_112D74 = 1;
      if ( *v2 )
      {
        rf_bus_setup_n_148(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

