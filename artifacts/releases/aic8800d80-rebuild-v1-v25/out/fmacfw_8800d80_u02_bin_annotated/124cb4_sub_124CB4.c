// fwstruct annotate: 124cb4_sub_124CB4.c
// sub_124CB4 @ 0x124cb4, size 102 bytes
int __fastcall sub_124CB4(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int v6; // r1
  int v7; // r0
  int v8; // [sp+4h] [bp-4h]
  int v9; // [sp+4h] [bp-4h]
  int v10; // [sp+4h] [bp-4h]
  int v11; // [sp+4h] [bp-4h]
  int v12; // [sp+4h] [bp-4h]

  switch ( *(_DWORD *)a2 )
  {
    case 0:
      v8 = a3;
      sub_124988(a2 + 2);
      a3 = v8;
      break;
    case 1:
      v10 = a3;
      sub_124A24((unsigned __int8 *)a2 + 4);
      a3 = v10;
      break;
    case 2:
      v11 = a3;
      sub_124B3C((unsigned __int8 *)a2 + 4);
      a3 = v11;
      break;
    case 3:
      v12 = a3;
      sub_124C14((unsigned __int8 *)a2 + 4, a2);
      a3 = v12;
      break;
    case 6:
      v6 = *((unsigned __int8 *)a2 + 4);
      v7 = dword_124D20;
      v9 = a3;
      *(_BYTE *)off_124D1C = v6;
      msg_parse(v7, v6, a3);
      a3 = v9;
      break;
    default:
      break;
  }
  sub_12CA10(127, a4, a3);
  return 0;
}

