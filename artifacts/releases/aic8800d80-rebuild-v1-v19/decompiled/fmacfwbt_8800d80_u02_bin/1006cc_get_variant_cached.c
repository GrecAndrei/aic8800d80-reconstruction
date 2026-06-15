// get_variant_cached @ 0x1006cc, size 6 bytes
// Doc: get_variant_cached [util]: Returns cached chip variant byte from global table
// get_variant_cached [util]: Returns cached chip variant byte from global table
int get_variant_cached()
{
  return *((unsigned __int8 *)off_1006D4 + 1);
}

