// v23 annotated: msg_get_value @ 0x12d0b0
// Original: 12d0b0_msg_get_value.c
// Primary struct: <unclustered>
//
// msg_get_value @ 0x12d0b0, size 130 bytes
// Doc: msg_get_value [ipc]: Extracts a 16-bit value from a message indexed by id and sub-id
// msg_get_value [ipc]: Extracts a 16-bit value from a message indexed by id and sub-id
int __fastcall msg_get_value(unsigned int a1)
{
  __int16 **v1; // r5
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r5
  int v5; // r4
  int v7; // r3

  v1 = (__int16 **)off_12D134;
  v2 = a1 >> 8;
  v3 = (unsigned __int8)a1;
  if ( **(__int16 **)off_12D134 >= 0 )
    goto LABEL_2;
  if ( (unsigned __int8)a1 > 0xDu )
  {
    sub_12F694(dword_12D144, dword_12D13C, 210);
    if ( **v1 >= 0 )
    {
LABEL_2:
      v4 = dword_12D138;
      v5 = 16 * v3;
      return *(unsigned __int16 *)(*(_DWORD *)(v4 + v5 + 8) + 2 * v2);
    }
    if ( v3 != 14 )
      sub_12F694(dword_12D14C, dword_12D148, 183);
  }
  else if ( (unsigned __int8)a1 != 13 )
  {
    goto LABEL_6;
  }
  sub_12F694(dword_12D150, dword_12D13C, 211);
  if ( **v1 >= 0 )
    goto LABEL_2;
LABEL_6:
  v4 = dword_12D138;
  v7 = dword_12D138 + 16 * v3;
  v5 = 16 * v3;
  if ( *(unsigned __int16 *)(v7 + 14) > v2 )
    return *(unsigned __int16 *)(*(_DWORD *)(v4 + v5 + 8) + 2 * v2);
  sub_12F694(dword_12D140, dword_12D13C, 212);
  return *(unsigned __int16 *)(*(_DWORD *)(v4 + v5 + 8) + 2 * v2);
}

