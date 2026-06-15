// rf_chan_set_mask @ 0x113694, size 16 bytes
// Doc: rf_chan_set_mask [rf]: Sets a 0x100 channel/mask register for RF configuration
// rf_chan_set_mask [rf]: Sets a 0x100 channel/mask register for RF configuration
int __fastcall rf_chan_set_mask(int a1, int a2)
{
  msg_parse(dword_1136A4, a2);
  return rf_stream_start_once();
}

