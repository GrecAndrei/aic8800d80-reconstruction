// fwstruct annotate: 118dec_sub_118DEC.c
// sub_118DEC @ 0x118dec, size 34 bytes
// Doc: sub_1226698 [bt]: FMAC BT helper: dispatch on arg0 with 8-register save
// sub_1226698 [bt]: FMAC BT helper: dispatch on arg0 with 8-register save
unsigned int sub_118DEC()
{
  unsigned int result; // r0
  int v1; // r1
  _DWORD *v2; // r2

  *(_DWORD *)off_118E10 |= 2u;
  result = sub_1174B8(0);
  v1 = dword_118E18;
  v2 = off_118E1C;
  *(_DWORD *)off_118E14 = dword_118E18;
  *v2 |= v1;
  return result;
}

