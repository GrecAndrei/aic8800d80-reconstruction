// v23 annotated: rf_chan_setup_init @ 0x110bf8
// Original: 110bf8_rf_chan_setup_init.c
// Primary struct: <unclustered>
//
// rf_chan_setup_init @ 0x110bf8, size 118 bytes
// Doc: rf_chan_setup_init [rf]: Initialize RF channel setup with 4-byte config
// rf_chan_setup_init [rf]: Initialize RF channel setup with 4-byte config
int __fastcall rf_chan_setup_init(char a1, int a2, int a3)
{
  _DWORD *v6; // r0
  _DWORD *v7; // r4
  _DWORD *v8; // r6
  int v9; // r2
  int v10; // r3

  v6 = sub_10FEAC(4);
  if ( !v6 )
    return sub_10DA6C(dword_110C78);
  v7 = v6;
  v8 = (_DWORD *)sub_1101AC();
  if ( v8 )
  {
    *(_BYTE *)v7 = a3;
    *((_BYTE *)v7 + 1) = BYTE1(a3) & 0xF;
    *((_BYTE *)v7 + 2) = a1;
    *((_BYTE *)v7 + 3) = 0;
    sub_1282E8(v7 + 1, a2, a3);
    v9 = v8[2];
    v10 = dword_110C70;
    v8[1] = 0;
    *v8 = v7;
    v8[2] = (unsigned __int16)(a3 + 4) | v10 & v9 | 0x80000000;
    return rf_field_align_n_2a4((int)v8);
  }
  else
  {
    sub_10DA6C(dword_110C74);
    return sub_10FEF8(v7);
  }
}

