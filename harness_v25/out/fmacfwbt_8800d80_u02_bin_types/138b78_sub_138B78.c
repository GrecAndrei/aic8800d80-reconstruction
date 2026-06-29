// sub_138B78 @ 0x138b78, size 46 bytes
uint32_t ** sub_138B78(uint32_t *a1)
{
  int v1; // r5

  v1 = dword_138BA8;
  sub_138AD4(0, 4, a1[5]);
  list_remove_node_d510(v1, a1);
  list_push_tail(v1 - 8, a1);
  return sub_12F770((uint32_t **)(v1 - 32));
}

