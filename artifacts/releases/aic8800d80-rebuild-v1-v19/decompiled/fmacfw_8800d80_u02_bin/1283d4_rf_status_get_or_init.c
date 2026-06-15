// rf_status_get_or_init @ 0x1283d4, size 160 bytes
// Doc: rf_status_get_or_init [rf]: Check RF status flag and initialize context
// rf_status_get_or_init [rf]: Check RF status flag and initialize context
int __fastcall rf_status_get_or_init(int result)
{
  int v1; // r7
  int v2; // r5
  _BYTE *v3; // r6
  int v4; // r8
  int v5; // r0
  __int16 v6; // r5
  __int16 v7; // r4
  int v8; // r2

  v1 = *(_DWORD *)(result + 72);
  v2 = result;
  if ( **(__int16 **)off_128474 < 0 && !v1 )
    result = sub_12F46C(dword_128488, dword_128484, 3591);
  v3 = off_128478;
  if ( (*((_BYTE *)off_128478 + 88) & 0x20) == 0 && *((unsigned __int8 *)off_128478 + 90) > 1u )
  {
    v4 = *(unsigned __int8 *)(v2 + 116);
    v5 = sub_12C92C(70, *((_BYTE *)off_128478 + 88) & 0x20, *((_BYTE *)off_128478 + 88) & 0x20, 20);
    *(_BYTE *)v5 = 0;
    *(_BYTE *)(v5 + 1) = *(_BYTE *)(v2 + 107);
    *(_BYTE *)(v5 + 2) = *(_BYTE *)(v1 + 4);
    *(_BYTE *)(v5 + 3) = *(_BYTE *)(v1 + 5);
    v6 = *(_WORD *)(v1 + 8);
    v7 = *(_WORD *)(v1 + 10);
    v8 = dword_12847C;
    *(_WORD *)(v5 + 4) = *(_WORD *)(v1 + 6);
    *(_WORD *)(v5 + 6) = v6;
    *(_WORD *)(v5 + 8) = v7;
    *(_BYTE *)(v5 + 16) = *(_BYTE *)(v1 + 12);
    *(_DWORD *)(v5 + 12) = (unsigned int)(((unsigned int)dword_128480
                                         * (unsigned __int64)(unsigned int)(*(_DWORD *)(v8 + 696 * v4 + 8) - 5000)) >> 32) >> 6;
    result = sdio_buffer_prepare_n_4e8(v5);
    v3[88] |= 0x20u;
  }
  return result;
}

