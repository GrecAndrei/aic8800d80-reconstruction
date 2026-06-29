// sub_11C88C @ 0x11c88c, size 138 bytes
int sub_11C88C()
{
  int v0; // r0
  uint8_t *v1; // r4
  int v2; // r0
  unsigned int v3; // r2
  unsigned int v4; // r3
  int v5; // r1

  if ( sub_11E34C(2) != 3 )
  {
    v0 = sub_11E34C(2);
    sub_11F504(dword_11C918, v0);
  }
  if ( **(__int16 **)off_11C91C < 0 && sub_11E34C(2) != 3 )
    sub_1219C4(dword_11C928, dword_11C924, 201);
  v1 = off_11C920;
  v2 = *(uint32_t *)off_11C920;
  v3 = *(unsigned __int8 *)(*(uint32_t *)off_11C920 + 367);
  v4 = (unsigned __int8)(*((uint8_t *)off_11C920 + 10) + 1);
  *((uint8_t *)off_11C920 + 10) = v4;
  if ( v3 <= v4 || v1[11] )
  {
    sub_11DEE8(v2 - 12);
    v5 = *((unsigned __int16 *)v1 + 4);
    if ( v1[11] )
    {
      sub_11CD0C(0, v5);
      v1[11] = 0;
    }
    else
    {
      sub_11DED8(2050, v5, 2);
    }
    sub_11E1E4(2);
    return 0;
  }
  else
  {
    sub_11CAC8();
    return 0;
  }
}

