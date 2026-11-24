// sub_13F794 @ 0x13f794, size 142 bytes
int __fastcall sub_13F794(int a1)
{
  int v1; // r4
  int v2; // r3
  int result; // r0
  char v4; // r3

  v1 = *(_DWORD *)(dword_13F828 + 696 * a1 + 340);
  if ( **(__int16 **)off_13F824 < 0 && !v1 )
    sub_12F46C(dword_13F830, dword_13F82C, 2194);
  sub_13E328(v1);
  v2 = *(unsigned __int16 *)(v1 + 184);
  *(_WORD *)(v1 + 136) = (v2 - 1) & ~(unsigned __int16)((v2 - 1) >> 31);
  *(_WORD *)(v1 + 138) = (v2 - 2) & ~(unsigned __int16)((v2 - 2) >> 31);
  *(_WORD *)(v1 + 140) = (v2 - 3) & ~(unsigned __int16)((v2 - 3) >> 31);
  *(_DWORD *)(v1 + 148) = 0x10000;
  *(_WORD *)(v1 + 190) = -1;
  *(_WORD *)(v1 + 142) = 0;
  *(_BYTE *)(v1 + 166) = 0;
  result = rx_agg_dequeue_n_handle(v1, 1);
  v4 = *(_BYTE *)(v1 + 184);
  *(_BYTE *)(v1 + 154) = 0;
  *(_BYTE *)(v1 + 164) = v4 - 4;
  *(_WORD *)(v1 + 152) = 5;
  return result;
}

