// fwstruct annotate: 119264_sdio_buf_align_lshift.c
// sdio_buf_align_lshift @ 0x119264, size 278 bytes
// Doc: sdio_buf_align_lshift [ipc]: Computes SDIO buffer field offsets via left-shifts for alignment
// sdio_buf_align_lshift [ipc]: Computes SDIO buffer field offsets via left-shifts for alignment
int __fastcall sdio_buf_align_lshift(int a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r3
  int v7; // r3
  BOOL v8; // r0
  int v9; // r8
  int v10; // r0
  int v11; // r2
  int v12; // r6
  int v13; // r5
  _WORD *v14; // r2
  __int16 v15; // r3
  __int16 v16; // r1
  int v17; // r0

  v3 = *(unsigned __int8 *)(a1 + 106);
  if ( v3 != 2 )
  {
    msg_parse(dword_119390, v3, a3);
    return 1;
  }
  v4 = *(_DWORD *)(a1 + 72);
  if ( v4 )
  {
    v7 = *(unsigned __int8 *)(v4 + 4);
    if ( **(__int16 **)off_11937C >= 0 || v7 != 2 )
    {
      v8 = (v7 | *(unsigned __int8 *)(a1 + 1224)) != 0;
      goto LABEL_5;
    }
  }
  else if ( **(__int16 **)off_11937C >= 0 )
  {
    goto LABEL_9;
  }
  sub_12F46C(dword_11938C, dword_119388, 520);
LABEL_9:
  v8 = 1;
LABEL_5:
  v9 = dword_119398;
  v10 = sub_118C44(v8, *(unsigned __int16 *)(dword_119398 + 2 * *(unsigned __int8 *)(a1 + 107)));
  v12 = v10;
  if ( v10 )
  {
    sub_12C4E8(a1, v10);
    v13 = *(_DWORD *)(v12 + 72);
    *(_BYTE *)(v13 + 108) = 80;
    *(_BYTE *)(v13 + 109) = 0;
    *(_BYTE *)(v13 + 110) = 0;
    *(_BYTE *)(v13 + 111) = 0;
    sub_143770(v13 + 112, a2, 6);
    v14 = off_119380;
    v15 = *((_WORD *)off_119380 + 254);
    v16 = *(_WORD *)(a1 + 104);
    *(_DWORD *)(v13 + 118) = *(_DWORD *)(a1 + 100);
    ++v15;
    v17 = *(_DWORD *)(a1 + 100);
    *(_WORD *)(v13 + 122) = v16;
    *(_DWORD *)(v13 + 124) = v17;
    *(_WORD *)(v13 + 128) = v16;
    v14[254] = v15;
    *(_WORD *)(v13 + 130) = 16 * v15;
    sub_143770(
      v13 + 132,
      dword_119384 + (*(unsigned __int8 *)(a1 + 107) << 9),
      *(unsigned __int16 *)(v9 + 2 * *(unsigned __int8 *)(a1 + 107)) - 24);
    *(_DWORD *)(v12 + 88) = 0;
    *(_DWORD *)(v12 + 92) = 0;
    *(_BYTE *)(v12 + 28) = *(_BYTE *)(a1 + 107);
    *(_BYTE *)(v12 + 29) = -1;
    rf_param_get_status(v12, 5);
    return 0;
  }
  else
  {
    msg_parse(dword_119394, *(unsigned __int16 *)(v9 + 2 * *(unsigned __int8 *)(a1 + 107)), v11);
    return 1;
  }
}

