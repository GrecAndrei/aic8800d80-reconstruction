// sub_13D20C @ 0x13d20c, size 302 bytes
unsigned int __fastcall sub_13D20C(unsigned int result)
{
  unsigned int v1; // r4
  int v2; // r1
  __int16 v3; // r3
  unsigned int v4; // r1
  int i; // r3
  int v6; // r2
  int v7; // r2
  __int16 v8; // r1
  __int16 v9; // r1
  unsigned int v10; // r2
  int v11; // r0
  __int16 v12; // r3

  switch ( *(_BYTE *)(result + 169) )
  {
    case 0:
    case 1:
      v4 = *(unsigned __int16 *)(result + 174);
      LOWORD(result) = (((v4 >> 3) & 1) << (1 - *(_BYTE *)(result + 182)))
                     + ((((v4 >> 1) & 1) + ((v4 >> 2) & 1)) << (1 - *(_BYTE *)(result + 182)))
                     + (v4 & 1);
      for ( i = 4; i != 12; ++i )
      {
        v6 = ((int)v4 >> i) & 1;
        result = (unsigned __int16)(result + v6);
      }
      goto LABEL_5;
    case 2:
    case 3:
      v1 = *(unsigned __int8 *)(result + 170);
      v2 = 8;
      v3 = 0;
      do
      {
        --v2;
        v3 += (v1 & 1)
            * (((*(unsigned __int8 *)(result + 179) + 1) << *(_BYTE *)(result + 181))
             + *(unsigned __int8 *)(result + 180)
             * (unsigned __int16)((*(unsigned __int8 *)(result + 179) + 1) << *(_BYTE *)(result + 181)));
        v1 >>= 1;
      }
      while ( v2 );
      result = (unsigned __int16)(((((*(unsigned __int16 *)(result + 174) >> 2) & 1)
                                  + ((*(unsigned __int16 *)(result + 174) >> 1) & 1)) << (1 - *(_BYTE *)(result + 182)))
                                + (*(_WORD *)(result + 174) & 1)
                                + (((*(unsigned __int16 *)(result + 174) >> 3) & 1) << (1 - *(_BYTE *)(result + 182)))
                                + v3);
      goto LABEL_5;
    case 4:
      v9 = *(unsigned __int8 *)(result + 180);
      v10 = (*(_WORD *)(result + 170) & 3) - 1;
      v11 = (*(unsigned __int8 *)(result + 179) + 1) << *(_BYTE *)(result + 181);
      if ( v10 <= 1 )
        v12 = 9;
      else
        v12 = 8;
      result = (unsigned __int16)((v11 + v9 * v11) * v12);
      goto LABEL_5;
    case 5:
      v7 = *(_WORD *)(result + 170) & 3;
      if ( v7 == 1 )
      {
        v8 = 10;
      }
      else if ( v7 == 2 )
      {
        v8 = 12;
      }
      else
      {
        v8 = 8;
      }
      result = (unsigned __int16)(3
                                * (*(unsigned __int8 *)(result + 180)
                                 + 1
                                 + *(unsigned __int8 *)(result + 179) * (*(unsigned __int8 *)(result + 180) + 1))
                                * v8
                                + (*(_WORD *)(result + 174) & 1));
LABEL_5:
      if ( result >= 0xA )
        result = 10;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

