// fwstruct annotate: 1290c4_bt_msg_post_n2cc.c
// bt_msg_post_n2cc @ 0x1290c4, size 72 bytes
// Doc: bt_msg_post_n2cc [bt]: BT mailbox message post via shared data structure at 0x190d1c
// bt_msg_post_n2cc [bt]: BT mailbox message post via shared data structure at 0x190d1c
void bt_msg_post_n2cc()
{
  _BYTE *v0; // r5
  unsigned int *v1; // r1
  int v2; // r2
  int v3; // r4
  void *v4; // r6
  int v5; // r0

  v0 = off_12910C;
  if ( !*((_BYTE *)off_12910C + 28) )
  {
    v1 = (unsigned int *)off_129110;
    v2 = *(_DWORD *)off_129110;
    v3 = *((_DWORD *)off_129114 + 2);
    *((_BYTE *)off_12910C + 8) = 0;
    *v1 = v2 & 0xFFFFFFFB;
    if ( v3 )
    {
      v4 = off_129118;
      do
      {
        if ( !*(_BYTE *)(v3 + 106) )
        {
          if ( *(_BYTE *)(v3 + 108) )
          {
            v5 = *(unsigned __int8 *)(v3 + 116);
            if ( v5 != 255 && !fmacfwbt_phy_chan_init(v5, (int)v4, v3) )
              ++v0[8];
          }
        }
        v3 = *(_DWORD *)v3;
      }
      while ( v3 );
    }
  }
}

