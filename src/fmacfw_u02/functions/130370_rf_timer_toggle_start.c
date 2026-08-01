// call_phy_op @ 0x130370, size 4 bytes
// Doc: call_phy_op [rf]: Toggles and starts an RF timer
// call_phy_op [rf]: Toggles and starts an RF timer
// attributes: thunk
int call_phy_op()
{
  return rf_core_reset_alt();
}

