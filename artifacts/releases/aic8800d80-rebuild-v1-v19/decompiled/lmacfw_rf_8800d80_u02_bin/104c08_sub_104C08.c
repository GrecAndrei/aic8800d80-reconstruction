// sub_104C08 @ 0x104c08, size 168 bytes
int __fastcall sub_104C08(float a1, int a2, int a3)
{
  float v6; // r0
  __int64 v7; // r0
  __int64 v8; // r0
  __int16 v9; // r0
  __int64 v10; // kr00_8
  __int64 v12; // kr08_8

  v6 = sub_11E8E0(a1 / 20.0);
  v7 = sub_127570((float)a2 * v6);
  v8 = sub_127194(v7, HIDWORD(v7));
  v9 = sub_127B54(v8, HIDWORD(v8));
  if ( v9 <= 232 )
  {
    if ( v9 > 31 )
    {
      *(_BYTE *)(a3 + 104) = v9;
    }
    else
    {
      v12 = *(_QWORD *)(a3 + 112);
      *(_BYTE *)(a3 + 104) = 32;
      if ( SHIDWORD(v12) < (int)v12 )
        sub_11F504(dword_104CB8, HIDWORD(v12));
    }
  }
  else
  {
    v10 = *(_QWORD *)(a3 + 112);
    *(_BYTE *)(a3 + 104) = -24;
    if ( SHIDWORD(v10) < (int)v10 )
      sub_11F504(dword_104CBC, HIDWORD(v10));
  }
  return sub_11F74C(1, dword_104CB4, (int)(float)(a1 * flt_104CB0), a2);
}

