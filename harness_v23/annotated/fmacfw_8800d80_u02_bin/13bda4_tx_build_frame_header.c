// v23 annotated: tx_build_frame_header @ 0x13bda4
// Original: 13bda4_tx_build_frame_header.c
// Primary struct: <unclustered>
//
// tx_build_frame_header @ 0x13bda4, size 96 bytes
// Doc: tx_build_frame_header [tx]: Builds transmit frame header with shifted control fields and length
// tx_build_frame_header [tx]: Builds transmit frame header with shifted control fields and length
int __fastcall tx_build_frame_header(bool a1, int a2)
{
  unsigned int v2; // r5
  bool *v5; // r4
  int v6; // r1
  int v7; // r3

  v2 = (unsigned __int16)((_WORD)a2 << 8) | 8;
  v5 = (bool *)sub_12C92C(42, 0, ((_WORD)a2 << 8) | 8, 3u);
  if ( **(__int16 **)off_13BE04 < 0 && msg_get_value(v2) != 4 )
    sub_12F46C(dword_13BE10, dword_13BE0C, 891);
  v6 = dword_13BE08 + 32 * a2;
  v7 = *(unsigned __int8 *)(v6 + 17);
  v5[1] = a1;
  *v5 = v7 != 1;
  v5[2] = *(_BYTE *)(v6 + 22);
  return sdio_buffer_prepare_n_4e8((int)v5);
}

