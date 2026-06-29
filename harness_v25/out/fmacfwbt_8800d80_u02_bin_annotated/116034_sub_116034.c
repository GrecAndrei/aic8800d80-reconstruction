// fwstruct annotate: 116034_sub_116034.c
// sub_116034 @ 0x116034, size 288 bytes
// Doc: sub_1216034 [util]: Loads pointer from 0x182c60 and reads its first byte
// sub_1216034 [util]: Loads pointer from 0x182c60 and reads its first byte
void sub_116034()
{
  _BYTE **v0; // r4
  int v1; // r3
  _BYTE *v2; // r6
  int *v3; // r3
  unsigned __int8 **v4; // r5
  char v5; // r0
  int v6; // r1
  void *v7; // r2
  char v8; // r0
  int v9; // r1
  void *v10; // r2
  int v11; // r0

  v0 = (_BYTE **)off_116154;
  if ( **(_BYTE **)off_116154 )
  {
    v1 = **(unsigned __int8 **)off_116158;
    if ( v1 != 1 )
      goto LABEL_3;
    goto LABEL_12;
  }
  v2 = off_11616C;
  v3 = *((int **)off_116168 + 2);
  *(_BYTE *)off_11616C = 1;
  if ( !v3 )
  {
LABEL_10:
    v4 = (unsigned __int8 **)off_116158;
    if ( **(_BYTE **)off_116158 == 3 )
      goto LABEL_4;
    feature_guard_sdio(2, dword_116170);
    *v2 = 1;
    v1 = **v4;
    if ( v1 != 1 )
    {
LABEL_3:
      if ( v1 == 2 )
        return;
      goto LABEL_4;
    }
LABEL_12:
    if ( **v0 == 3 )
    {
      v8 = sdio_status_check();
      v10 = off_116178;
      *(_BYTE *)off_116178 = v8;
      if ( v8 )
        sub_12ECB0(dword_116184, v9, v10);
      else
        sub_12ECB0(dword_11617C, v9, v10);
      if ( state_flag_check() )
        rf_msg_process_body_n1cc();
      ((void (*)(void))sdio_wait_busy)();
      return;
    }
    if ( !state_flag_check() || *(_BYTE *)off_116174 )
      return;
LABEL_4:
    if ( queue_check()
      && !*((_DWORD *)off_11615C + 126)
      && (*(_DWORD *)off_116160 >> 25) & 1 | *((unsigned __int8 *)off_116164 + 36)
      && !*((_BYTE *)off_116164 + 29)
      && tx_timeout_check() )
    {
      v5 = sdio_status_check();
      v7 = off_116178;
      *(_BYTE *)off_116178 = v5;
      if ( !v5 )
      {
        v11 = sub_12ECB0(dword_116180, v6, v7);
        sdio_wait_busy(v11);
      }
      if ( (unsigned __int8)**v0 <= 1u )
        rf_msg_process_body_n1cc();
    }
    return;
  }
  while ( !*((_BYTE *)v3 + 106) )
  {
    if ( *((_BYTE *)v3 + 108) )
      goto LABEL_20;
LABEL_17:
    v3 = (int *)*v3;
    if ( !v3 )
      goto LABEL_10;
  }
  if ( *((_BYTE *)v3 + 106) != 2 )
    goto LABEL_17;
LABEL_20:
  if ( **(_BYTE **)off_116158 != 3 )
    feature_guard_sdio(2, dword_116170);
  *v2 = 0;
}

