// sub_125BB4 @ 0x125bb4, size 162 bytes
unsigned int  sub_125BB4(unsigned int *a1, unsigned int *a2, unsigned int *a3, unsigned int a4)
{
  unsigned int v4; // r5
  unsigned int *v5; // lr
  unsigned int v6; // r4
  unsigned int v7; // r7
  unsigned int v8; // r12
  unsigned int v9; // r5
  unsigned int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r4
  unsigned int v13; // r5
  unsigned int v14; // r1
  unsigned int result; // r0
  unsigned int v16; // r0
  unsigned int v17; // r0

  v4 = *a1 - *a2;
  if ( (v4 & 0x80000000) != 0 )
  {
    v4 = *a2 - *a1;
    v5 = a1;
  }
  else
  {
    v5 = a2;
  }
  if ( a4 < v4 )
  {
    v6 = a4 + *v5;
    do
    {
      v4 -= a4;
      v7 = v5[1] - *v5 + v6;
      v8 = v6;
      v6 += a4;
    }
    while ( a4 < v4 );
    *v5 = v8;
    v5[1] = v7;
  }
  if ( v4 > a4 >> 1 )
  {
    v9 = *v5 + a4;
    v10 = a4 + v5[1];
    *v5 = v9;
    v5[1] = v10;
  }
  v11 = a1[1];
  v12 = a2[1];
  if ( (int)(v11 - v12) < 0 )
  {
    if ( a3 )
    {
      v13 = *a1;
      v14 = *a2;
      a3[1] = v12;
      if ( (int)(v13 - v14) < 0 )
      {
        result = v12 - v13;
        goto LABEL_13;
      }
      result = v12 - v14;
      goto LABEL_18;
    }
    v17 = *a1;
    if ( (int)(v17 - *a2) < 0 )
      return v12 - v17;
    else
      return v12 - *a2;
  }
  else
  {
    if ( a3 )
    {
      v13 = *a1;
      v14 = *a2;
      a3[1] = v11;
      if ( (int)(v13 - v14) < 0 )
      {
        result = v11 - v13;
LABEL_13:
        *a3 = v13;
        return result;
      }
      result = v11 - v14;
LABEL_18:
      *a3 = v14;
      return result;
    }
    v16 = *a1;
    if ( (int)(v16 - *a2) >= 0 )
      return v11 - *a2;
    else
      return v11 - v16;
  }
}

