// v23 annotated: check_bit_status @ 0x135b80
// Original: 135b80_check_bit_status.c
// Primary struct: <unclustered>
//
// check_bit_status @ 0x135b80, size 20 bytes
// Doc: check_bit_status [util]: Read register and return bit status via clz
// check_bit_status [util]: Read register and return bit status via clz
BOOL check_bit_status()
{
  return msg_get_value(6u) == 6;
}

