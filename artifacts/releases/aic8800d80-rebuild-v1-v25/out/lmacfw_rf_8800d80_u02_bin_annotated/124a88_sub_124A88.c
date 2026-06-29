// fwstruct annotate: 124a88_sub_124A88.c
// sub_124A88 @ 0x124a88, size 110 bytes
// Doc: sub_1224A88 [unknown]: Unknown helper, dispatches on 2-way state
// sub_1224A88 [unknown]: Unknown helper, dispatches on 2-way state
int __fastcall sub_124A88(int a1, unsigned __int8 **a2)
{
  int *v3; // r6
  unsigned int v4; // r5
  int v5; // r3
  unsigned __int8 *v6; // r0
  int v7; // r4
  int v8; // r0
  int v9; // r2
  int result; // r0
  int v11; // [sp+4h] [bp-4h]

  if ( a1 <= 2 )
  {
    msg_parse(dword_124B00);
    return -1;
  }
  else
  {
    v3 = (int *)off_124AF8;
    v4 = parse_int(a2[1], nullptr, 0xAu);
    v5 = parse_int(a2[2], nullptr, 0xAu);
    v6 = a2[3];
    v7 = v5;
    v8 = parse_int(v6, nullptr, 0xAu);
    v9 = v8;
    if ( *v3 )
    {
      v11 = v8;
      rf_level_apply_n_4ec(0);
      v9 = v11;
    }
    sub_123FF0(v4, v7, v9);
    msg_parse(dword_124AFC);
    result = *v3;
    if ( *v3 )
    {
      rf_level_apply_n_4ec(result);
      return 0;
    }
  }
  return result;
}

