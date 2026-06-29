// sub_114BF8 @ 0x114bf8, size 42 bytes
void sub_114BF8()
{
  int *v0; // r4

  v0 = (int *)off_114C24;
  if ( !*(uint32_t *)off_114C24 )
    *v0 = sub_114BB8();
  if ( !*(uint32_t *)off_114C28 )
    *(uint32_t *)off_114C28 = *v0 + 67092480;
  *(uint32_t *)off_114C2C = 1;
}

