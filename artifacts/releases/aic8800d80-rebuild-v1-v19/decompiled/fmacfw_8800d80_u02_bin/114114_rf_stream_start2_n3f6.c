// rf_stream_start2_n3f6 @ 0x114114, size 64 bytes
// Doc: rf_msg_process_body_alt_12a [rf]: Alternate RF message body processor
// rf_msg_process_body_alt_12a [rf]: Alternate RF message body processor
int rf_stream_start2_n3f6()
{
  int v0; // r0
  _DWORD *v1; // r4
  int result; // r0

  v0 = (*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_114154 + 2) + 16))(*((_DWORD *)off_114154 + 1));
  if ( !v0 )
    return sub_10DC24(dword_114160);
  v1 = (_DWORD *)v0;
  result = sub_113350(*(_DWORD *)off_114158 + v0, *(_DWORD *)off_11415C);
  if ( result < 0 )
  {
    log_free_dispatch_2(v1);
    return sub_10DC24(dword_114164);
  }
  return result;
}

