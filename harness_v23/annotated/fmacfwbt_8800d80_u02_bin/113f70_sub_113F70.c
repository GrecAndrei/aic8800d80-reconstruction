// v23 annotated: sub_113F70 @ 0x113f70
// Original: 113f70_sub_113F70.c
// Primary struct: <unclustered>
//
// sub_113F70 @ 0x113f70, size 64 bytes
int sub_113F70()
{
  int v0; // r0
  _DWORD *v1; // r4
  int result; // r0

  v0 = (*(int (__fastcall **)(_DWORD))(*((_DWORD *)off_113FB0 + 2) + 16))(*((_DWORD *)off_113FB0 + 1));
  if ( !v0 )
    return log_printf(dword_113FBC);
  v1 = (_DWORD *)v0;
  result = rf_stream_start_1ac(*(_DWORD *)off_113FB4 + v0, *(_DWORD *)off_113FB8);
  if ( result < 0 )
  {
    log_free_dispatch_2(v1);
    return log_printf(dword_113FC0);
  }
  return result;
}

