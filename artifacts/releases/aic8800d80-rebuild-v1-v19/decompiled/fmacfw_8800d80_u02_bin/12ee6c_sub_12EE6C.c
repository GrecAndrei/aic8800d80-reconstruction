// sub_12EE6C @ 0x12ee6c, size 178 bytes
int __fastcall sub_12EE6C(int a1, int *a2, __int16 a3, __int16 a4)
{
  _QWORD *v5; // r0
  int v6; // r5
  _DWORD *v7; // r0
  __int64 v8; // r2
  int v9; // r0

  v5 = (_QWORD *)sub_12C92C(1042, a4, a3, 8u);
  v6 = (int)v5;
  if ( (unsigned int)**(unsigned __int8 **)off_12EF20 - 1 <= 1 )
  {
    LODWORD(v8) = *a2;
    if ( *a2 == dword_12EF28 || (_DWORD)v8 == dword_12EF28 - 36184 )
    {
      *(_DWORD *)v8 ^= (a2[2] ^ *(_DWORD *)v8) & a2[1];
      HIDWORD(v8) = a2[2];
      LODWORD(v8) = *a2;
      v9 = HIDWORD(v8);
      *(_QWORD *)v6 = v8;
    }
    else
    {
      HIDWORD(v8) = a2[2];
      *v5 = v8;
      v9 = HIDWORD(v8);
    }
  }
  else
  {
    v7 = (_DWORD *)*a2;
    if ( (((unsigned int)*a2 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      sub_10EE2C((int)v7, a2[2], a2[1], 1);
      v9 = sub_10ED84(*a2, 1);
      LODWORD(v8) = *a2;
    }
    else
    {
      *v7 ^= (a2[2] ^ *v7) & a2[1];
      LODWORD(v8) = *a2;
      v9 = *(_DWORD *)*a2;
    }
    *(_DWORD *)(v6 + 4) = v9;
    HIDWORD(v8) = a2[2];
    *(_DWORD *)v6 = v8;
  }
  sub_12EA88(dword_12EF24, a2[1], HIDWORD(v8), HIDWORD(v8), (_DWORD)v8, v9, v9);
  sub_12C98C(v6);
  return 0;
}

