// fwstruct annotate: 1157b4_system_init_chain.c
// system_init_chain @ 0x1157b4, size 32 bytes
// Doc: system_init_chain [util]: System initialization chain calling subs
// system_init_chain [util]: System initialization chain calling subs
int system_init_chain()
{
  int inited; // r0
  int v1; // r0
  int v2; // r0
  int v3; // r0

  *((_BYTE *)ipc_doorbell_handler_n_1a8 + 1) = 0;
  inited = ipc_init_buf();
  v1 = sub_1321C8(inited);
  v2 = mac_phy_init(v1);
  v3 = sub_12D210(v2);
  return sub_12F508(v3);
}

