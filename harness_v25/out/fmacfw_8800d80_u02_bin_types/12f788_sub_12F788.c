// sub_12F788 @ 0x12f788, size 136 bytes
// Doc: sub_122F788 [mac]: Frame/mac build helper pushing large register frame and calling sub
// sub_122F788 [mac]: Frame/mac build helper pushing large register frame and calling sub
uint32_t * sub_12F788(int a1, uint32_t *a2, int a3)
{
  int v5; // r0
  int v6; // r11
  int v7; // r9
  uint32_t *v8; // r4
  int v9; // r5
  int v10; // r6
  uint32_t *v11; // r10

  v5 = sub_1439B8(a1, 46);
  if ( v5 )
    v6 = v5 - a1;
  else
    v6 = sub_143E40(a1);
  if ( a3 )
  {
    v7 = 0;
    v8 = a2;
    v9 = 0;
    do
    {
      while ( 1 )
      {
        v10 = *v8;
        ++v9;
        v11 = v8;
        if ( !sub_143F1C(a1, *v8, v6) )
          break;
        v8 += 4;
        if ( a3 == v9 )
          goto LABEL_9;
      }
      if ( sub_143E40(v10) == v6 )
        return v11;
      a2 = v8;
      ++v7;
      v8 += 4;
    }
    while ( a3 != v9 );
LABEL_9:
    if ( v7 == 1 )
      return a2;
  }
  return nullptr;
}

