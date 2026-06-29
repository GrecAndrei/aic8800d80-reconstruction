// sub_11F28C @ 0x11f28c, size 122 bytes
int  sub_11F28C(int a1, int a2, int a3)
{
  int v3; // r10
  int v4; // r4
  int v8; // r9
  int v9; // r1
  int v10; // r0
  int v12; // [sp+4h] [bp-4h] BYREF

  v3 = *(uint32_t *)(a2 + 572);
  if ( !v3 )
    return 0;
  v4 = 0;
  v8 = a2 + 572;
  do
  {
    v12 = 0;
    if ( !sub_116DBC(a1) )
      break;
    if ( !sub_1369C8(v3) )
      break;
    v10 = sub_136A90(a1, a2, &v12);
    if ( v12 )
      break;
    if ( !v10 )
      v10 = sub_12D190(v8);
    v9 = *(unsigned __int8 *)(v10 + 27);
    *(uint8_t *)(v10 + 97) = 0;
    ++v4;
    sub_117560(v10, v9);
    if ( a3 )
    {
      if ( v4 == a3 )
        break;
    }
    v3 = *(uint32_t *)(a2 + 572);
  }
  while ( v3 );
  return v4;
}

