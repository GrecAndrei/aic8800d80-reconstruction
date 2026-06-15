// sub_136628 @ 0x136628, size 84 bytes
int __fastcall sub_136628(int a1, unsigned __int8 *a2, __int16 a3, __int16 a4)
{
  int v7; // r4

  feature_guard_sdio(256, dword_13667C);
  v7 = dword_136680 + 1320 * *a2;
  if ( *(_BYTE *)(v7 + 106) == 2 && *(_BYTE *)(v7 + 108) )
  {
    if ( msg_get_value(7u) )
    {
      return 2;
    }
    else
    {
      patch_apply_n_2ac(v7);
      return 0;
    }
  }
  else
  {
    message_dispatch_n84(7171, a4, a3);
    return 0;
  }
}

