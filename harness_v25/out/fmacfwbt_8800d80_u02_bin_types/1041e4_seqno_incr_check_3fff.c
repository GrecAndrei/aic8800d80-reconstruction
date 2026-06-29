// seqno_incr_check_3fff @ 0x1041e4, size 66 bytes
// Doc: seqno_incr_check_3fff [mac]: Increment and bound-check 14-bit sequence number against 0x3fff.
// seqno_incr_check_3fff [mac]: Increment and bound-check 14-bit sequence number against 0x3fff.
int  seqno_incr_check_3fff(int a1, int a2, uint32_t *a3)
{
  int v3; // r3
  int v4; // r4
  int result; // r0

  v3 = (unsigned __int16)*(uint32_t *)off_104228;
  v4 = 0x3FFF;
  if ( v3 == 0x3FFF )
    a3 = (uint32_t *)*a3;
  else
    v4 = v3 + 1;
  if ( v3 != 0x3FFF )
    a3 = (uint32_t *)a3[v4];
  if ( ((unsigned __int8)a3 & 1) != 0 )
  {
    if ( a2 )
      goto LABEL_8;
  }
  else if ( a2 != 1 )
  {
LABEL_8:
    result = v3 + 2 + 2 * a1;
    goto LABEL_9;
  }
  result = v3 + 1 + 2 * a1;
LABEL_9:
  if ( result >= 0x4000 )
    result -= 0x4000;
  return result;
}

