// v23 annotated: sub_12C7AC @ 0x12c7ac
// Original: 12c7ac_sub_12C7AC.c
// Primary struct: ke_dispatch_ctx (cluster 8, 4 funcs)
// Fields: msg_id=0x4, task_id=0x6, param=0x8, status=0x6d
//
// sub_12C7AC @ 0x12c7ac, size 44 bytes
int __fastcall sub_12C7AC(int result)
{
  int *i; // r3
  int v2; // r2
  int v3; // r3

  v2 = *(char *)(result + 110);
  v3 = (char)(*(_BYTE *)(result + 420) - *(_BYTE *)(result + 464));
  if ( v2 == 127 )
  {
    *(_BYTE *)(result + 109) = 127;
    if ( v3 == 127 )
      return result;
  }
  else if ( v3 >= v2 )
  {
    LOBYTE(v3) = *(_BYTE *)(result + 110);
  }
  *(_BYTE *)(result + 109) = v3;
  for ( i = *(int **)(result + 240); i; i = (int *)*i )
    *((_BYTE *)i + 350) |= 0x10u;
  result = *(_DWORD *)(result + 72);
  if ( result )
    return sub_12876C(result);
  return result;
}

