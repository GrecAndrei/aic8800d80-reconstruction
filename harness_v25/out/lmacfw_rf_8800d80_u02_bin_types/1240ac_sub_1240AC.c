// sub_1240AC @ 0x1240ac, size 130 bytes
int  sub_1240AC(int a1)
{
  unsigned int *v1; // r1
  unsigned int *v2; // r4
  unsigned int v3; // r3
  unsigned int v4; // r2
  int v5; // r0
  int result; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r0

  v1 = (unsigned int *)off_124130;
  v2 = (unsigned int *)off_124134;
  v3 = *(uint32_t *)off_124130 & 0xFFFCFFFF;
  v4 = *(uint32_t *)off_124134 & 0xFFFFF9FF;
  *(uint32_t *)off_124134 = v4;
  *v1 = v3;
  switch ( a1 )
  {
    case 0:
      sub_11F504(dword_12413C);
      result = 0;
      break;
    case 1:
      v7 = dword_124140;
      *v1 = v3 | 0x10000;
      sub_11F504(v7);
      result = 0;
      break;
    case 2:
      v8 = dword_124144;
      *v1 = v3 | 0x10000;
      *v2 = v4 | 0x200;
      sub_11F504(v8);
      result = 0;
      break;
    case 3:
      v9 = dword_124148;
      *v1 = v3 | 0x20000;
      sub_11F504(v9);
      result = 0;
      break;
    case 4:
      v5 = dword_124138;
      *v1 = v3 | 0x20000;
      *v2 = v4 | 0x400;
      sub_11F504(v5);
      goto LABEL_3;
    default:
      sub_11F504(dword_12414C);
LABEL_3:
      result = 0;
      break;
  }
  return result;
}

