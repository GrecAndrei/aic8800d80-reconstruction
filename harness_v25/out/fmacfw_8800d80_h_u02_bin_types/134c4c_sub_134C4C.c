// sub_134C4C @ 0x134c4c, size 86 bytes
int  sub_134C4C(int a1, int a2, int a3)
{
  uint32_t *v3; // r5

  v3 = off_134CA4;
  *((uint8_t *)off_134CA4 + 4) = a3;
  v3[2] = a1;
  *((uint16_t *)v3 + 6) = a2;
  sub_12CBF4(6u, 10);
  sub_12EB90(
    256,
    dword_134CAC,
    *(unsigned __int8 *)(a1 + 107),
    a2,
    *(unsigned __int16 *)(dword_134CA8 + 696 * *(unsigned __int8 *)(a1 + 116) + 50),
    a3);
  if ( *((uint8_t *)v3 + 4) )
    return sub_134950();
  else
    return sub_1347D4();
}

