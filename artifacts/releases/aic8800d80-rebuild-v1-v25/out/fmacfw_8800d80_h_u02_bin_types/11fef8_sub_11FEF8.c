// sub_11FEF8 @ 0x11fef8, size 326 bytes
uint64_t  sub_11FEF8(unsigned __int8 *a1, char a2)
{
  int v3; // r6
  int v4; // r8
  int v5; // r4
  uint8_t *v6; // r7
  int v7; // r10
  int *v8; // r9
  int *v9; // r0
  int v10; // r2
  int v11; // r3
  uint64_t result; // r0
  uint64_t v13; // r2
  int v14; // r4
  int v15; // r0

  v3 = *a1;
  v4 = a1[41];
  v5 = dword_120048;
  v6 = (uint8_t *)(1320 * v4 + 120 * v3 + dword_120048);
  v7 = 120 * v3 + 1320 * v4;
  v6[578] = a2;
  v6[576] = a1[40];
  v8 = (int *)(v7 + 480 + v5);
  v6[577] = v3;
  v9 = sub_100200(v8, 0, 0x48u);
  switch ( v6[576] )
  {
    case 0:
    case 3:
      *(QWORD *)(1320 * v4 + 120 * v3 + v5 + 552) = sub_14383C(v9) & 0xFFFFFFLL;
      break;
    case 1:
      v15 = 1320 * v4 + 120 * v3 + v5;
      *(uint32_t *)(v15 + 560) = *((uint32_t *)a1 + 6);
      *(uint32_t *)(v15 + 564) = *((uint32_t *)a1 + 7);
      *(uint32_t *)(v15 + 568) = *((uint32_t *)a1 + 8);
      *(uint32_t *)(v15 + 572) = *((uint32_t *)a1 + 9);
      *(QWORD *)(v15 + 552) = 0;
      break;
    case 4:
      *(QWORD *)(1320 * v4 + 120 * v3 + v5 + 552) = *(QWORD *)&dword_120040;
      break;
    case 5:
      sub_143630(v7 + 560 + v5, a1 + 8, 16);
      goto LABEL_3;
    default:
LABEL_3:
      *(QWORD *)(1320 * v4 + 120 * v3 + v5 + 552) = 0;
      break;
  }
  v10 = 1320 * v4 + 120 * v3 + v5;
  v11 = 1320 * v4 + v5;
  if ( *(uint8_t *)(v10 + 576) == 5 )
    *(uint32_t *)(v11 + 1204) = v8;
  else
    *(uint32_t *)(v11 + 1200) = v8;
  *(uint8_t *)(v10 + 579) = 1;
  result = *((QWORD *)a1 + 1);
  v13 = *((QWORD *)a1 + 2);
  v14 = v5 + 1320 * v4 + 120 * v3;
  *(QWORD *)(v14 + 580) = result;
  *(QWORD *)(v14 + 588) = v13;
  *(uint8_t *)(v14 + 596) = a1[4];
  return result;
}

