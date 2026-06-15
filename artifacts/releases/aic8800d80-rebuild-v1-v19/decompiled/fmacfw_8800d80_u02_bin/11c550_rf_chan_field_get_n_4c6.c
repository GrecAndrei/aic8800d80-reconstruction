// rf_chan_field_get_n_4c6 @ 0x11c550, size 46 bytes
// Doc: rf_chan_field_get_n_4c6 [rf]: Reads channel field at offset 0x4c6 from RF table entry
// rf_chan_field_get_n_4c6 [rf]: Reads channel field at offset 0x4c6 from RF table entry
unsigned int *__fastcall rf_chan_field_get_n_4c6(unsigned int *result)
{
  int v1; // r2

  v1 = *(unsigned __int16 *)(dword_11C580 + 1320 * *((unsigned __int8 *)result + 28) + 1222);
  if ( v1 != 1023 && *((_BYTE *)off_11C584 + 361) != 2 )
    return queue_process((unsigned int *)(result[17] + 4), *(_DWORD *)(result[17] + 40), v1);
  return result;
}

