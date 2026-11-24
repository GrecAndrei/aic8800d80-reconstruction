// sub_1147BC @ 0x1147bc, size 94 bytes
// Doc: sub_12147BC [bt]: BT helper invoked after a sub-routine with result branch
// sub_12147BC [bt]: BT helper invoked after a sub-routine with result branch
int __fastcall sub_1147BC(unsigned __int8 *a1, int a2)
{
  int v4; // r0
  int v5; // r2
  char *v6; // r7
  int v7; // r0

  v4 = sub_114790(a1);
  if ( v4 < 0 )
  {
    sub_12ECB0(dword_114828, *a1, v5);
    return a2;
  }
  else if ( v4 == a2 )
  {
    v6 = (char *)off_11481C;
    if ( *((_DWORD *)off_11481C + 2) )
    {
      v7 = sub_1146D0();
      sub_14380C(v7 + 4, a1, a2);
      list_push_tail(v6 + 16);
      irq_nesting_or(16);
    }
    else
    {
      sub_12ECB0(dword_114824, v4, v5);
    }
    return a2;
  }
  else
  {
    sub_12ECB0(dword_114820, v4, a2);
    return a2;
  }
}

