// fwstruct annotate: 11e8e0_sub_11E8E0.c
// sub_11E8E0 @ 0x11e8e0, size 110 bytes
// Doc: sdio_buffer_prepare_n_2ac [mmio]: Prepare SDIO buffer descriptors with DMA settings
// sdio_buffer_prepare_n_2ac [mmio]: Prepare SDIO buffer descriptors with DMA settings
int __fastcall sub_11E8E0(int a1)
{
  int v1; // r5
  __int64 v3; // r0
  __int64 v4; // r0
  __int64 v5; // r0
  __int64 v6; // r0
  unsigned int v7; // r0
  _DWORD v9[32]; // [sp+0h] [bp-104h] BYREF
  _BYTE v10[132]; // [sp+80h] [bp-84h] BYREF

  v1 = dword_11E958;
  sub_1282E8(v9, dword_11E958, 128);
  sub_1282E8(v10, v1 + 128, 128);
  v3 = sub_127570(a1);
  v4 = sub_127620(v3, HIDWORD(v3), dword_11E950, dword_11E954);
  v5 = sub_127620(v4, HIDWORD(v4), 0, dword_11E95C);
  v6 = sub_1272B4(v5, HIDWORD(v5), 0, dword_11E960);
  v7 = sub_127B54(v6, HIDWORD(v6));
  return v7 & 0x7F800000
       | ((((v7 & 0x7FFFFF) * (__int64)(int)v9[(v7 >> 18) & 0x1F]) >> 23) + *(_DWORD *)&v10[4 * ((v7 >> 18) & 0x1F)]);
}

