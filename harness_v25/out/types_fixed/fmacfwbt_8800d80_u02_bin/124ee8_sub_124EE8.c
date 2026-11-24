// sub_124EE8 @ 0x124ee8, size 96 bytes
int __fastcall sub_124EE8(int a1, unsigned __int16 *a2, int a3, void *a4)
{
  int v4; // r4
  void *v6; // r1
  int v8; // [sp+0h] [bp-8h]
  int v9; // [sp+0h] [bp-8h]
  int v10; // [sp+0h] [bp-8h]
  int v11; // [sp+0h] [bp-8h]

  v4 = *(_DWORD *)a2;
  v6 = a4;
  switch ( v4 )
  {
    case 0:
      v8 = a3;
      sub_124BBC(a2 + 2);
      a3 = v8;
      v6 = a4;
      break;
    case 1:
      v10 = a3;
      sub_124C58((unsigned __int8 *)a2 + 4);
      a3 = v10;
      v6 = a4;
      break;
    case 2:
      v11 = a3;
      sub_124D70((unsigned __int8 *)a2 + 4);
      a3 = v11;
      v6 = a4;
      break;
    case 3:
      v9 = a3;
      sub_124E48((unsigned __int8 *)a2 + 4, a4);
      a3 = v9;
      v6 = a4;
      break;
    default:
      break;
  }
  sub_12CC38(127, v6, a3, a4);
  return 0;
}

