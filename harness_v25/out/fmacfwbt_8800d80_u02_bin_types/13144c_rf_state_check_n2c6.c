// rf_state_check_n2c6 @ 0x13144c, size 40 bytes
// Doc: rf_state_check_n2c6 [rf]: Checks RF state and updates control register pair
// rf_state_check_n2c6 [rf]: Checks RF state and updates control register pair
unsigned __int8 * rf_state_check_n2c6(unsigned __int8 *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0
  char v5; // [sp+7h] [bp-1h] BYREF

  result = sub_12E160(a1, a2, &v5);
  if ( result )
    *(uint32_t *)(a3 + 220) = *(uint32_t *)(result + 3);
  else
    *(uint32_t *)(a3 + 220) = 0x80000000;
  return result;
}

