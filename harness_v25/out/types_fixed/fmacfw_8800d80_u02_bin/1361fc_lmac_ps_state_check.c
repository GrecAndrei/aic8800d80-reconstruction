// lmac_ps_state_check @ 0x1361fc, size 52 bytes
// Doc: lmac_ps_state_check [mac]: Check LMAC power-save state via signed halfword
// lmac_ps_state_check [mac]: Check LMAC power-save state via signed halfword
int __fastcall lmac_ps_state_check(int value)
{
  int v2; // r0

  if ( **(__int16 **)off_136230 >= 0 || (value = msg_get_value(7u), value == 3) )
  {
    sub_136820(value);
    return 0;
  }
  else
  {
    v2 = sub_12F46C(dword_136238, dword_136234, 415);
    sub_136820(v2);
    return 0;
  }
}

