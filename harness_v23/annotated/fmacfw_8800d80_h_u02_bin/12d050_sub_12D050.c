// v23 annotated: sub_12D050 @ 0x12d050
// Original: 12d050_sub_12D050.c
// Primary struct: <unclustered>
//
// sub_12D050 @ 0x12d050, size 104 bytes
void sub_12D050()
{
  unsigned int *v0; // r6
  unsigned int v1; // r4
  __int16 **v2; // r8
  int v3; // r5
  void *v4; // r7
  int v5; // r10
  int v6; // r9
  int v7; // r4
  void (__fastcall *v8)(_DWORD); // r3

  v0 = (unsigned int *)off_12D0B8;
  v1 = *(_DWORD *)off_12D0B8;
  if ( *(_DWORD *)off_12D0B8 )
  {
    v2 = (__int16 **)off_12D0C4;
    v3 = dword_12D0BC;
    v4 = off_12D0C0;
    v5 = dword_12D0C8;
    v6 = dword_12D0CC;
    while ( 1 )
    {
      v7 = __clz(v1);
      if ( **v2 < 0 )
      {
        if ( v7 <= 27 )
        {
          v8 = *(void (__fastcall **)(_DWORD))(v3 + 8 * v7);
          if ( v8 )
            goto LABEL_5;
        }
        sub_12F32C(v6, v5, 230);
      }
      v8 = *(void (__fastcall **)(_DWORD))(v3 + 8 * v7);
LABEL_5:
      v8(*(_DWORD *)(v3 + 8 * v7 + 4));
      v1 = *v0;
      if ( *(_BYTE *)(*(_DWORD *)v4 + 3) )
      {
        sub_114578();
        if ( !v1 )
          return;
      }
      else if ( !v1 )
      {
        return;
      }
    }
  }
}

