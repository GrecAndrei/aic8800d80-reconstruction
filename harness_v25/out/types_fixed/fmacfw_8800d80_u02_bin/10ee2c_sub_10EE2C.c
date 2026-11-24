// sub_10EE2C @ 0x10ee2c, size 70 bytes
// Doc: rf_reg_write_increment [rf]: RF register write core incrementing sequence counter
// rf_reg_write_increment [rf]: RF register write core incrementing sequence counter
int __fastcall sub_10EE2C(int a1, int a2, int a3, int a4)
{
  int *v4; // r5
  _DWORD *v5; // r4
  int result; // r0
  int v7; // r3
  int v8; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10EE74 = 1;
  }
  v4 = (int *)off_10EE78;
  ++*(_DWORD *)off_10EE78;
  if ( a4 )
  {
    v5 = off_10EE7C;
    while ( !*(_DWORD *)off_10EE7C )
      ;
    result = sub_10ED7C();
    *v5 = 1;
  }
  else
  {
    result = sub_10ED7C();
  }
  if ( *v4 )
  {
    v7 = *v4 - 1;
    v8 = *(_DWORD *)off_10EE74;
    *v4 = v7;
    if ( !v7 )
    {
      if ( v8 )
        __enable_irq();
    }
  }
  return result;
}

