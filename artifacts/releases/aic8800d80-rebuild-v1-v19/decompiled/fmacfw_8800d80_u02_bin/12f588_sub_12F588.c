// sub_12F588 @ 0x12f588, size 82 bytes
// Doc: sub_122F588 [util]: Check firmware state byte against value 3 and branch
// sub_122F588 [util]: Check firmware state byte against value 3 and branch
void __fastcall sub_12F588(int a1)
{
  int v2; // r0
  int v3; // r5
  _DWORD *v4; // r4

  if ( **(_BYTE **)off_12F5DC == 3 )
  {
    v2 = sub_10CC50();
    v3 = v2;
    if ( v2 )
    {
      *(_DWORD *)(a1 + 24) = 49374;
      sub_143770(v2, a1, 28);
      v4 = off_12F5E0;
      while ( !*(_DWORD *)off_12F5E0 )
        ;
      list_push_tail(*(_DWORD *)off_12F5E4 + 604, (_DWORD *)(v3 - 4));
      *v4 = 1;
      sub_10CCA4();
    }
    else
    {
      msg_parse(dword_12F5E8);
    }
  }
}

