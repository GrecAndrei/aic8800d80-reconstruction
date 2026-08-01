// is_hw_feature_6 @ 0x135964, size 20 bytes
// Doc: is_hw_feature_6 [util]: Check timeout/latch: call helper with arg 6, return boolean
// is_hw_feature_6 [util]: Check timeout/latch: call helper with arg 6, return boolean
BOOL is_hw_feature_6()
{
  return rx_rate_field_parse(6u) == 6;
}

