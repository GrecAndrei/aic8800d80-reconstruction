// safe_snprintf @ 0x12d648
/* luna: Scans a length-delimited 802.11 IE buffer for a vendor-specific (ID 221) element whose payload begins with the supplied byte sequence, returning the e */
volatile uint8_t * safe_snprintf(volatile uint8_t *a1, int a2, volatile uint8_t *a3, int a4, volatile uint16_t *a5) {
  unsigned int scan_end; // r9
  unsigned int buffer_end; // r7
  int v7; // lr
  volatile uint8_t *v8; // r5
  int ie_id; // r4
  int ie_total_len; // r3
  volatile uint8_t *ie_start; // r8
  volatile uint8_t *prefix_cursor; // r4
  volatile uint8_t *v14; // r9
  int v15; // t1

  scan_end = (unsigned int)&a1[a2];
  buffer_end = (unsigned int)&a1[a2];
  if ( a1 >= &a1[a2] )
  {
LABEL_15:
    if ( **(volatile int16_t **)off_12D6E0 < 0 && (volatile uint8_t *)buffer_end != a1 )
      irq_disable_mmio_write(dword_12D6E8, dword_12D6E4, 180);
  }
  else
  {
    v7 = a4 + 2;
    v8 = &a3[a4];
    while ( 1 )
    {
      ie_start = a1;
      if ( scan_end <= (unsigned int)(a1 + 1) )
        break;
      ie_id = *a1;
      ie_total_len = a1[1] + 2;
      a1 += ie_total_len;
      if ( ie_id == 221 )
      {
        if ( scan_end < (unsigned int)a1 )
          return 0;
        *a5 = ie_total_len;
        if ( !ie_start || (unsigned int)&ie_start[v7] > buffer_end )
          return 0;
        prefix_cursor = a3;
        while ( 1 )
        {
          v14 = &ie_start[(uint32_t)prefix_cursor];
          v15 = *prefix_cursor++;
          if ( v15 != v14[2 - (uint32_t)a3] )
            break;
          if ( prefix_cursor == v8 )
            return ie_start;
        }
        a2 = (uint16_t)(a2 - ie_total_len);
        if ( buffer_end <= (unsigned int)a1 )
          goto LABEL_15;
        scan_end = (unsigned int)&a1[a2];
      }
    }
  }
  return 0;
}



// range_overflow_check @ 0x12d6ec
/* luna: Scans an 802.11 IE buffer for an extension IE with the requested extension ID and returns it with its encoded size. */
volatile uint8_t * range_overflow_check(volatile uint8_t *a1, int a2, int a3, volatile uint16_t *a4) {
  unsigned int v4; // r7
  unsigned int v5; // r12
  int v6; // r6
  int v7; // r4
  volatile uint8_t *v8; // r5

  v4 = (unsigned int)&a1[a2];
  v5 = (unsigned int)&a1[a2];
  if ( a1 < &a1[a2] )
  {
    while ( 1 )
    {
      v8 = a1;
      if ( v4 <= (unsigned int)(a1 + 1) )
        break;
      v6 = *a1;
      v7 = a1[1] + 2;
      a1 += v7;
      if ( v6 == 255 )
      {
        if ( v4 < (unsigned int)a1 )
          return 0;
        *a4 = v7;
        if ( !v8 || (unsigned int)(v8 + 3) > v5 )
          return 0;
        if ( v8[2] == a3 )
          return v8;
        a2 = (uint16_t)(a2 - v7);
        if ( v5 <= (unsigned int)a1 )
          goto LABEL_13;
        v4 = (unsigned int)&a1[a2];
      }
    }
  }
  else
  {
LABEL_13:
    if ( **(volatile int16_t **)off_12D750 < 0 && (volatile uint8_t *)v5 != a1 )
      mmio_write_field(dword_12D758, dword_12D754, 127);
  }
  return 0;
}



// check_buf_range_12d75c @ 0x12d75c
/* luna: Scans a bounded sequence of type-length-value records and returns the first type-1 record with a payload length from 1 to 12, storing that length thro */
volatile uint8_t * check_buf_range_12d75c(volatile uint8_t *result, int a2, volatile uint8_t *a3) {
  unsigned int v3; // r1
  int v4; // r4
  volatile uint8_t *v5; // r5

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v4 = (uint8_t)result[1];
    v5 = &result[v4 + 2];
    if ( *result == 1 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return 0;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    if ( (unsigned int)(v4 + 2) <= 0xE && result[1] )
    {
      *a3 = v4;
      return result;
    }
  }
  return 0;
}



// check_buf_range_12d79c @ 0x12d79c
/* luna: Scans a bounded 802.11 information-element list for a nonempty element ID 50, returning its element pointer and writing its payload length or NULL if  */
volatile uint8_t * check_buf_range_12d79c(volatile uint8_t *result, int a2, volatile uint8_t *a3) {
  unsigned int ie_list_end; // r1
  int ie_len; // r4
  volatile uint8_t *next_ie; // r5

  ie_list_end = (unsigned int)&result[a2];
  if ( ie_list_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    ie_len = (uint8_t)result[1];
    next_ie = &result[ie_len + 2];
    if ( *result == 50 )
      break;
    result += ie_len + 2;
    if ( ie_list_end <= (unsigned int)(next_ie + 1) )
      return 0;
  }
  if ( ie_list_end >= (unsigned int)next_ie )
  {
    if ( !result )
      return result;
    if ( result[1] )
    {
      *a3 = ie_len;
      return result;
    }
  }
  return 0;
}



// check_buf_range_12d7d8 @ 0x12d7d8
/* luna: Scans length-prefixed buffer entries to a zero-tag terminator, validates their bounds and the terminator length, stores that length, and returns the t */
volatile uint8_t * check_buf_range_12d7d8(volatile uint8_t *result, int a2, volatile uint8_t *a3) {
  unsigned int v3; // r1
  int v4; // r5
  volatile uint8_t *v5; // r6

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v4 = result[1];
    v5 = &result[v4 + 2];
    if ( !*result )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return 0;
  }
  if ( v3 < (unsigned int)v5 )
    return (volatile uint8_t *)*result;
  if ( !result )
    return result;
  if ( (unsigned int)(v4 + 2) > 0x22 )
    return (volatile uint8_t *)*result;
  *a3 = v4;
  return result;
}



// check_buf_range_12d818 @ 0x12d818
/* luna: Scans a bounded sequence of type-length-value records for tag 7 and returns the matching record only if it is fully in bounds and has a payload of at  */
volatile uint8_t * check_buf_range_12d818(volatile uint8_t *result, int a2, volatile uint8_t *a3) {
  unsigned int v3; // r1
  int v4; // r4
  volatile uint8_t *v5; // r5

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v4 = (uint8_t)result[1];
    v5 = &result[v4 + 2];
    if ( *result == 7 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return 0;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    if ( (unsigned int)(v4 + 2) > 7 )
    {
      *a3 = v4;
      return result;
    }
  }
  return 0;
}



// check_buf_range_12d854 @ 0x12d854
/* luna: Scans 802.11 information elements for an in-bounds RSN element with at least 18 bytes of payload and returns its pointer and length. */
volatile uint8_t * check_buf_range_12d854(volatile uint8_t *result, int a2, volatile uint8_t *a3) {
  unsigned int buffer_end; // r1
  int element_length; // r4
  volatile uint8_t *element_end; // r5

  buffer_end = (unsigned int)&result[a2];
  if ( buffer_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    element_length = (uint8_t)result[1];
    element_end = &result[element_length + 2];
    if ( *result == 48 )
      break;
    result += element_length + 2;
    if ( buffer_end <= (unsigned int)(element_end + 1) )
      return 0;
  }
  if ( buffer_end >= (unsigned int)element_end )
  {
    if ( !result )
      return result;
    if ( (unsigned int)(element_length + 2) > 0x13 )
    {
      *a3 = element_length;
      return result;
    }
  }
  return 0;
}



// log_message_level @ 0x12d890
/* luna: Parses a test parameter, rejects values of 23 or less, and stores the accepted value minus two in the output byte. */
volatile uint8_t * log_message_level(volatile uint8_t *a1, int a2, volatile uint8_t *a3) {
  volatile uint8_t *result; // r0
  uint16_t v5; // [sp+Eh] [bp-2h] BYREF

  result = safe_snprintf(a1, a2, (volatile uint8_t *)dword_12D8B8, 5, &v5);
  if ( result )
  {
    if ( v5 <= 0x17u )
      return 0;
    else
      *a3 = v5 - 2;
  }
  return result;
}



// check_buf_range_12d8bc @ 0x12d8bc
/* luna: Scans a length-prefixed buffer for tag 0x44 and returns its address while storing the payload length only if the complete record is in bounds and its  */
volatile uint8_t * check_buf_range_12d8bc(volatile uint8_t *result, int a2, volatile uint8_t *a3) {
  unsigned int v3; // r1
  int v4; // r4
  volatile uint8_t *v5; // r5

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v4 = (uint8_t)result[1];
    v5 = &result[v4 + 2];
    if ( *result == 68 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return 0;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    if ( (unsigned int)(v4 + 2) > 0x15 )
    {
      *a3 = v4;
      return result;
    }
  }
  return 0;
}



// check_buf_range_12d8f8 @ 0x12d8f8
/* luna: Scans length-prefixed records and returns the first complete record with tag 0x25 and a declared payload length of 3, or NULL. */
volatile uint8_t * check_buf_range_12d8f8(volatile uint8_t *result, int a2) {
  unsigned int v2; // r1
  volatile uint8_t *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v3 = &result[(uint8_t)result[1] + 2];
    if ( *result == 37 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return 0;
  }
  if ( v2 < (unsigned int)v3 )
    return 0;
  if ( result )
  {
    if ( result[1] != 3 )
      return 0;
  }
  return result;
}



// check_buf_range_12d938 @ 0x12d938
/* luna: Scans a bounded sequence of length-prefixed elements for tag 0x3C with a four-byte payload, returning its pointer or NULL if it is absent or truncated */
volatile uint8_t * check_buf_range_12d938(volatile uint8_t *result, int a2) {
  unsigned int buffer_end; // r1
  volatile uint8_t *element_end; // r2

  buffer_end = (unsigned int)&result[a2];
  if ( buffer_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    element_end = &result[(uint8_t)result[1] + 2];
    if ( *result == 60 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( buffer_end <= (unsigned int)(element_end + 1) )
      return 0;
  }
  if ( buffer_end < (unsigned int)element_end )
    return 0;
  if ( result )
  {
    if ( result[1] != 4 )
      return 0;
  }
  return result;
}



// test_arg2_one_12d978 @ 0x12d978
/* luna: Scans a length-prefixed byte sequence for tag 0x3E, returning its record pointer and reporting whether its payload length is one byte. */
volatile uint8_t * test_arg2_one_12d978(volatile uint8_t *result, int a2, volatile int *a3) {
  unsigned int v3; // r1
  volatile uint8_t *v4; // r4

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v4 = &result[(uint8_t)result[1] + 2];
    if ( *result == 62 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( v3 <= (unsigned int)(v4 + 1) )
      return 0;
  }
  if ( v3 < (unsigned int)v4 )
    return 0;
  if ( result )
    *a3 = result[1] == 1;
  return result;
}



// test_arg2_one_12d9bc @ 0x12d9bc
/* luna: Scans for a 0xC4 container and returns its well-formed 0xC2 subelement, setting the output flag when the subelement payload length is 3. */
volatile uint8_t * test_arg2_one_12d9bc(volatile uint8_t *result, int a2, volatile int *a3) {
  unsigned int v3; // r1
  int v4; // r4
  volatile uint8_t *v5; // r3
  unsigned int v6; // r4
  int v7; // r3

  v3 = (unsigned int)&result[a2];
  if ( v3 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v4 = result[1];
    v5 = &result[v4 + 2];
    if ( *result == 196 )
      break;
    result += v4 + 2;
    if ( v3 <= (unsigned int)(v5 + 1) )
      return 0;
  }
  if ( v3 >= (unsigned int)v5 )
  {
    if ( !result )
      return result;
    result += 2;
    v6 = (unsigned int)&result[v4];
    while ( v6 > (unsigned int)(result + 1) )
    {
      v7 = result[1] + 2;
      if ( *result == 194 )
      {
        if ( v6 < (unsigned int)&result[v7] )
          return 0;
        if ( result )
          *a3 = result[1] == 3;
        return result;
      }
      result += v7;
    }
  }
  return 0;
}



// test_arg2_one_12da20 @ 0x12da20
/* luna: Scans a bounded information-element buffer for element ID 3 with a one-byte payload and returns its header or NULL. */
volatile uint8_t * test_arg2_one_12da20(volatile uint8_t *result, int a2) {
  unsigned int buffer_end; // r1
  volatile uint8_t *next_ie; // r2

  buffer_end = (unsigned int)&result[a2];
  if ( buffer_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    next_ie = &result[(uint8_t)result[1] + 2];
    if ( *result == 3 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( buffer_end <= (unsigned int)(next_ie + 1) )
      return 0;
  }
  if ( buffer_end < (unsigned int)next_ie )
    return 0;
  if ( result )
  {
    if ( result[1] != 1 )
      return 0;
  }
  return result;
}



// test_arg2_one_12da60 @ 0x12da60
/* luna: Scans a bounded information-element list and returns the first element with ID 76 and a 16-byte payload, or NULL if none qualifies. */
volatile uint8_t * test_arg2_one_12da60(volatile uint8_t *result, int a2) {
  unsigned int buffer_end; // r1
  volatile uint8_t *next_ie; // r2

  buffer_end = (unsigned int)&result[a2];
  if ( buffer_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    next_ie = &result[(uint8_t)result[1] + 2];
    if ( *result == 76 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( buffer_end <= (unsigned int)(next_ie + 1) )
      return 0;
  }
  if ( buffer_end < (unsigned int)next_ie )
    return 0;
  if ( result )
  {
    if ( result[1] != 16 )
      return 0;
  }
  return result;
}



// test_arg2_one_12daa0 @ 0x12daa0
/* luna: Scans a bounded information-element sequence for element ID 42 and returns it only if its payload length is exactly one byte. */
volatile uint8_t * test_arg2_one_12daa0(volatile uint8_t *result, int a2) {
  unsigned int v2; // r1
  volatile uint8_t *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v3 = &result[(uint8_t)result[1] + 2];
    if ( *result == 42 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return 0;
  }
  if ( v2 < (unsigned int)v3 )
    return 0;
  if ( result )
  {
    if ( result[1] != 1 )
      return 0;
  }
  return result;
}



// test_arg2_one_12dae0 @ 0x12dae0
/* luna: Scans a bounded TLV buffer for type 0xC7 with a one-byte payload and returns its record pointer if found. */
volatile uint8_t * test_arg2_one_12dae0(volatile uint8_t *result, int a2) {
  unsigned int buffer_end; // r1
  volatile uint8_t *tlv_end; // r2

  buffer_end = (unsigned int)&result[a2];
  if ( buffer_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    tlv_end = &result[result[1] + 2];
    if ( *result == 199 )
      break;
    result += result[1] + 2;
    if ( buffer_end <= (unsigned int)(tlv_end + 1) )
      return 0;
  }
  if ( buffer_end < (unsigned int)tlv_end )
    return 0;
  if ( result )
  {
    if ( result[1] != 1 )
      return 0;
  }
  return result;
}



// test_arg2_one_12db20 @ 0x12db20
/* luna: Scans a bounded TLV buffer for tag 0x20 with a one-byte payload and returns its record pointer, or NULL if absent or invalid. */
volatile uint8_t * test_arg2_one_12db20(volatile uint8_t *result, int a2) {
  unsigned int v2; // r1
  volatile uint8_t *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v3 = &result[(uint8_t)result[1] + 2];
    if ( *result == 32 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return 0;
  }
  if ( v2 < (unsigned int)v3 )
    return 0;
  if ( result )
  {
    if ( result[1] != 1 )
      return 0;
  }
  return result;
}



// test_arg2_one_12db60 @ 0x12db60
/* luna: Scans a bounded information-element buffer for element ID 54 with length 3 and returns its address, or NULL if none is found. */
volatile uint8_t * test_arg2_one_12db60(volatile uint8_t *result, int a2) {
  unsigned int buffer_end; // r1
  volatile uint8_t *next_ie; // r2

  buffer_end = (unsigned int)&result[a2];
  if ( buffer_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    next_ie = &result[(uint8_t)result[1] + 2];
    if ( *result == 54 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( buffer_end <= (unsigned int)(next_ie + 1) )
      return 0;
  }
  if ( buffer_end < (unsigned int)next_ie )
    return 0;
  if ( result )
  {
    if ( result[1] != 3 )
      return 0;
  }
  return result;
}



// format_log_message_12dba0 @ 0x12dba0
/* luna: Formats a message into the supplied buffer and returns the formatter result only if its recorded output length is 26. */
volatile uint8_t * format_log_message_12dba0(volatile uint8_t *a1, int a2) {
  volatile uint8_t *result; // r0
  uint16_t v3[3]; // [sp+Eh] [bp-6h] BYREF

  result = safe_snprintf(a1, a2, (volatile uint8_t *)dword_12DBC4, 5, v3);
  if ( result )
  {
    if ( v3[0] != 26 )
      return 0;
  }
  return result;
}



// test_arg2_one_12dbc8 @ 0x12dbc8
/* luna: Scans bounded marker-and-length records and returns the first record marked '-' with a length byte of 26, or NULL if none is found. */
volatile uint8_t * test_arg2_one_12dbc8(volatile uint8_t *result, int a2) {
  unsigned int v2; // r1
  volatile uint8_t *v3; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v3 = &result[(uint8_t)result[1] + 2];
    if ( *result == 45 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( v2 <= (unsigned int)(v3 + 1) )
      return 0;
  }
  if ( v2 < (unsigned int)v3 )
    return 0;
  if ( result )
  {
    if ( result[1] != 26 )
      return 0;
  }
  return result;
}



// test_arg2_one_12dc08 @ 0x12dc08
/* luna: Scans a bounded sequence of two-byte-header elements for ID 0x47 and returns its start only if its encoded length is at least six bytes and fits withi */
volatile uint8_t * test_arg2_one_12dc08(volatile uint8_t *result, int a2) {
  unsigned int v2; // r1
  unsigned int v3; // r3
  volatile uint8_t *v4; // r2

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v3 = (uint8_t)result[1] + 2;
    v4 = &result[v3];
    if ( *result == 71 )
      break;
    result += v3;
    if ( v2 <= (unsigned int)(v4 + 1) )
      return 0;
  }
  if ( v2 < (unsigned int)v4 )
    return 0;
  if ( result )
  {
    if ( v3 < 6 )
      return 0;
  }
  return result;
}



// test_arg2_one_12dc48 @ 0x12dc48
/* luna: Scans length-prefixed records and returns the zero-tagged terminal record only when the supplied offset reaches or passes its end and the record is at */
volatile uint8_t * test_arg2_one_12dc48(volatile uint8_t *result, int a2) {
  unsigned int v2; // r1
  unsigned int v3; // r3
  volatile uint8_t *v4; // r4

  v2 = (unsigned int)&result[a2];
  if ( v2 <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    v3 = result[1] + 2;
    v4 = &result[v3];
    if ( !*result )
      break;
    result += v3;
    if ( v2 <= (unsigned int)(v4 + 1) )
      return 0;
  }
  if ( v2 < (unsigned int)v4 )
    return (volatile uint8_t *)*result;
  if ( result )
  {
    if ( v3 < 6 )
      return 0;
  }
  return result;
}



// test_arg2_one_12dc90 @ 0x12dc90
/* luna: Scans a length-prefixed element list and returns the header of element ID 83 with a two-byte payload, or NULL if it is absent or out of bounds. */
volatile uint8_t * test_arg2_one_12dc90(volatile uint8_t *result, int a2) {
  unsigned int buffer_end; // r1
  volatile uint8_t *element_end; // r2

  buffer_end = (unsigned int)&result[a2];
  if ( buffer_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    element_end = &result[(uint8_t)result[1] + 2];
    if ( *result == 83 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( buffer_end <= (unsigned int)(element_end + 1) )
      return 0;
  }
  if ( buffer_end < (unsigned int)element_end )
    return 0;
  if ( result )
  {
    if ( result[1] != 2 )
      return 0;
  }
  return result;
}



// sub_12DCD0 @ 0x12dcd0
/* luna: Scans a length-prefixed buffer for a tag-0x55 entry and returns its start if its length is nonzero and the entry fits within the buffer. */
volatile uint8_t * sub_12DCD0(volatile uint8_t *result, int a2) {
  volatile uint8_t *v2; // r1
  volatile uint8_t *v3; // r2

  v2 = &result[a2];
  if ( v2 <= result + 1 )
    return nullptr;
  while ( 1 )
  {
    v3 = &result[(uint8_t)result[1] + 2];
    if ( *result == 85 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( v2 <= v3 + 1 )
      return nullptr;
  }
  if ( v2 < v3 )
    return nullptr;
  if ( result )
  {
    if ( !result[1] )
      return nullptr;
  }
  return result;
}


// return_zero_1 @ 0x12dd0c
/* luna: Returns zero unconditionally. */
int return_zero_1() {
  return 0;
}



// test_arg2_one_12dd10 @ 0x12dd10
/* luna: Scans a bounded 802.11 information-element list and returns the VHT Capabilities IE (element ID 191, length 12), or NULL if it is absent or truncated. */
volatile uint8_t * test_arg2_one_12dd10(volatile uint8_t *result, int a2) {
  unsigned int ie_list_end; // r1
  volatile uint8_t *current_ie_end; // r2

  ie_list_end = (unsigned int)&result[a2];
  if ( ie_list_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    current_ie_end = &result[result[1] + 2];
    if ( *result == 191 )
      break;
    result += result[1] + 2;
    if ( ie_list_end <= (unsigned int)(current_ie_end + 1) )
      return 0;
  }
  if ( ie_list_end < (unsigned int)current_ie_end )
    return 0;
  if ( result )
  {
    if ( result[1] != 12 )
      return 0;
  }
  return result;
}



// emit_hash_12dd50 @ 0x12dd50
/* luna: Parses a value from the input, accepts only values from 24 through 57, stores the accepted value minus 3 in the output byte, and returns NULL on parse */
volatile uint8_t * emit_hash_12dd50(volatile uint8_t *a1, int a2, volatile uint8_t *a3) {
  volatile uint8_t *result; // r0
  uint16_t v5; // [sp+6h] [bp-2h] BYREF

  result = range_overflow_check(a1, a2, 35, &v5);
  if ( result )
  {
    if ( (unsigned int)v5 - 24 > 0x21 )
      return 0;
    else
      *a3 = v5 - 3;
  }
  return result;
}



// test_arg2_one_12dd78 @ 0x12dd78
/* luna: Scans a bounded 802.11 information-element list and returns the HT Operation element (ID 61) only if its length is 22 bytes. */
volatile uint8_t * test_arg2_one_12dd78(volatile uint8_t *result, int a2) {
  unsigned int ies_end; // r1
  volatile uint8_t *ie_end; // r2

  ies_end = (unsigned int)&result[a2];
  if ( ies_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    ie_end = &result[(uint8_t)result[1] + 2];
    if ( *result == 61 )
      break;
    result += (uint8_t)result[1] + 2;
    if ( ies_end <= (unsigned int)(ie_end + 1) )
      return 0;
  }
  if ( ies_end < (unsigned int)ie_end )
    return 0;
  if ( result )
  {
    if ( result[1] != 22 )
      return 0;
  }
  return result;
}



// test_arg2_one_12ddb8 @ 0x12ddb8
/* luna: Scans a bounded 802.11 information-element buffer for a VHT Operation IE (element ID 192, length 5) and returns its address, or NULL if none is found  */
volatile uint8_t * test_arg2_one_12ddb8(volatile uint8_t *result, int a2) {
  unsigned int ies_end; // r1
  volatile uint8_t *ie_end; // r2

  ies_end = (unsigned int)&result[a2];
  if ( ies_end <= (unsigned int)(result + 1) )
    return 0;
  while ( 1 )
  {
    ie_end = &result[result[1] + 2];
    if ( *result == 192 )
      break;
    result += result[1] + 2;
    if ( ies_end <= (unsigned int)(ie_end + 1) )
      return 0;
  }
  if ( ies_end < (unsigned int)ie_end )
    return 0;
  if ( result )
  {
    if ( result[1] != 5 )
      return 0;
  }
  return result;
}



// emit_dollar_12ddf8 @ 0x12ddf8
/* luna: Parses a value using the `$`-tagged range check, accepts values from 9 through 18, and stores the value minus 3. */
volatile uint8_t * emit_dollar_12ddf8(volatile uint8_t *a1, int a2, volatile uint8_t *a3) {
  volatile uint8_t *result; // r0
  uint16_t v5; // [sp+6h] [bp-2h] BYREF

  result = range_overflow_check(a1, a2, 36, &v5);
  if ( result )
  {
    if ( (unsigned int)v5 - 9 > 9 )
      return 0;
    else
      *a3 = v5 - 3;
  }
  return result;
}



// emit_ampersand_12de20 @ 0x12de20
/* luna: Returns the input pointer only if range_overflow_check succeeds and its first parsed value is 16. */
volatile uint8_t * emit_ampersand_12de20(volatile uint8_t *a1, int a2) {
  volatile uint8_t *result; // r0
  uint16_t v3[3]; // [sp+6h] [bp-6h] BYREF

  result = range_overflow_check(a1, a2, 38, v3);
  if ( result )
  {
    if ( v3[0] != 16 )
      return 0;
  }
  return result;
}



// emit_percent_12de40 @ 0x12de40
/* luna: Checks the percent token and returns the range-check result only when its decoded kind is 4. */
volatile uint8_t * emit_percent_12de40(volatile uint8_t *a1, int a2) {
  volatile uint8_t *result; // r0
  uint16_t v3[3]; // [sp+6h] [bp-6h] BYREF

  result = range_overflow_check(a1, a2, 37, v3);
  if ( result )
  {
    if ( v3[0] != 4 )
      return 0;
  }
  return result;
}



// rf_get_freq_field @ 0x12de60
/* luna: Extracts a 9-bit frequency field from bytes 4–5 and places it in bits 22–30. */
int rf_get_freq_field(int a1) {
  return ((2 * *(volatile uint8_t *)(a1 + 5)) | (*(volatile uint8_t *)(a1 + 4) >> 7)) << 22;
}



// rf_calc_whitening @ 0x12de70
/* luna: Encodes the low nine bits of the supplied value together with a nibble-derived selector from byte offset 5 into an RF control field. */
int rf_calc_whitening(int a1, int16_t a2) {
  return dword_12DE90
       & ((((32 * (*(volatile uint8_t *)(a1 + 5) ^ (*(volatile uint8_t *)(a1 + 5) >> 4))) & 0x1E0) + (a2 & 0x1FF)) << 22)
       | 0x3F0000;
}



// is_factory_mode_a @ 0x12de94
/* luna: Converts recognized factory-test selector codes to internal IDs and returns 255 for unsupported codes. */
int is_factory_mode_a(volatile char *a1) {
  int result; // r0

  if ( (unsigned int)a1 > dword_12DF34 )
  {
    if ( a1 == (volatile char *)off_12DF38 )
    {
      return 19;
    }
    else if ( a1 <= (volatile char *)off_12DF38 )
    {
      if ( a1 == (volatile char *)off_12DF38 - 1 )
        return 18;
      else
        return 255;
    }
    else if ( a1 == (volatile char *)dword_12DF3C )
    {
      return 2;
    }
    else if ( a1 == (volatile char *)(dword_12DF3C + 1) )
    {
      return 3;
    }
    else
    {
      return 255;
    }
  }
  else if ( (unsigned int)a1 <= dword_12DF34 - 18 )
  {
    return 255;
  }
  else
  {
    switch ( (unsigned int)a1 )
    {
      case 0xFAC01u:
        return 2;
      case 0xFAC02u:
        result = 3;
        break;
      case 0xFAC03u:
        result = 4;
        break;
      case 0xFAC04u:
        result = 5;
        break;
      case 0xFAC05u:
        result = 6;
        break;
      case 0xFAC06u:
        result = 7;
        break;
      case 0xFAC07u:
        result = 8;
        break;
      case 0xFAC08u:
        result = 9;
        break;
      case 0xFAC09u:
        result = 10;
        break;
      case 0xFAC0Bu:
        result = 11;
        break;
      case 0xFAC0Cu:
        result = 12;
        break;
      case 0xFAC0Du:
        result = 13;
        break;
      case 0xFAC0Fu:
        result = 14;
        break;
      case 0xFAC10u:
        result = 15;
        break;
      case 0xFAC11u:
        result = 16;
        break;
      case 0xFAC12u:
        result = 17;
        break;
      default:
        return 255;
    }
  }
  return result;
}



// is_factory_mode_b @ 0x12df40
/* luna: Maps recognized factory-mode-B codes to selector values and returns 255 for unrecognized codes. */
int is_factory_mode_b(unsigned int a1) {
  int result; // r0

  if ( a1 > dword_12DFB8 )
  {
    if ( a1 == dword_12DFBC )
    {
      return 1;
    }
    else if ( a1 == dword_12DFBC + 2 )
    {
      return 2;
    }
    else if ( a1 == dword_12DFBC - 3964929 )
    {
      return 4;
    }
    else
    {
      return 255;
    }
  }
  else if ( a1 <= dword_12DFB8 - 13 )
  {
    return 255;
  }
  else
  {
    switch ( a1 )
    {
      case 0xFAC01u:
        result = 0;
        break;
      case 0xFAC02u:
        return 1;
      case 0xFAC04u:
        return 2;
      case 0xFAC05u:
        result = 3;
        break;
      case 0xFAC06u:
        result = 5;
        break;
      case 0xFAC08u:
        result = 6;
        break;
      case 0xFAC09u:
        result = 7;
        break;
      case 0xFAC0Au:
        result = 8;
        break;
      case 0xFAC0Bu:
        result = 9;
        break;
      case 0xFAC0Cu:
        result = 10;
        break;
      case 0xFAC0Du:
        result = 11;
        break;
      default:
        return 255;
    }
  }
  return result;
}



// is_ptr_nonnull @ 0x12dfc0
/* luna: Maps RSSI values from −110 to 0 dBm onto 0 to 220, saturating values outside that range. */
int is_ptr_nonnull(int a1) {
  if ( a1 >= 0 )
    return 220;
  if ( a1 >= -109 )
    return (uint8_t)(2 * (a1 + 110));
  return 0;
}



// rx_process_packet_2 @ 0x12dfdc
/* luna: Parses a printf-style format string and emits the formatted result through the supplied output path. */
unsigned int rx_process_packet_2(volatile char *a1, int a2, unsigned int a3, volatile uint8_t *a4, volatile unsigned int *a5) {
  int v7; // r2
  volatile uint8_t *v8; // r5
  volatile char *v9; // r7
  unsigned int v10; // r4
  int v11; // r6
  volatile char *v12; // r9
  int v13; // r10
  int v14; // r1
  int v15; // t1
  int v17; // t1
  unsigned int v18; // t1
  int v19; // t1
  unsigned int v20; // r1
  int v21; // r1
  int v22; // t1
  volatile char *v23; // r2
  int v24; // r0
  int v25; // r3
  volatile char *v26; // r0
  unsigned int v27; // r3
  unsigned int v28; // t1
  unsigned int v29; // r10
  volatile uint8_t *v30; // lr
  char v31; // r0
  int v32; // cc
  volatile uint8_t *v33; // r2
  int v34; // r0
  char v35; // r0
  volatile char *v36; // t1
  volatile uint8_t *v37; // t1
  int v38; // r2
  unsigned int v39; // lr
  int v40; // r3
  volatile uint8_t *v41; // r12
  char v42; // r1
  char v43; // r3
  int v44; // r1
  int v45; // r2
  volatile uint8_t *v46; // r10
  volatile char *v47; // r2
  int v48; // zf
  int v49; // t1
  char v50; // r9
  volatile uint8_t *v51; // t1
  unsigned int v52; // lr
  int v53; // r3
  volatile uint8_t *v54; // r12
  char v55; // r2
  volatile uint8_t *v56; // r1
  volatile char *v57; // r3
  int v58; // t1
  char v59; // r2
  unsigned int v60; // r1
  int v61; // r3
  unsigned int v62; // t1
  int v63; // r2
  char v64; // r3
  int v65; // r3
  volatile char *v66; // r1
  int v67; // r0
  int v68; // r12
  int v69; // t1
  int v71; // t1
  unsigned int v72; // r12
  int v73; // r3
  unsigned int v74; // lr
  int v75; // r3
  struct __attribute__((packed)) { int v76; // [sp+0h] [bp-54h]
  int v77; // [sp+4h] [bp-50h]
  unsigned int v78; // [sp+8h] [bp-4Ch]
  int v79; // [sp+Ch] [bp-48h]
  char v80_scratch[68]; // [sp+10h] [bp-44h] BYREF — merged scratch: the original uses
  // sp+0x10..sp+0x53 as ONE raw stack region (digit generation grows backward from
  // sp+0x50, %A/%M grow forward from sp+0x10/0x13); merged into one object so the
  // cross-field pointer arithmetic stays in bounds under any correct compilation.
  // offsets: v80=[0] v81=[1] pad=[2] v82=[3] v83 anchor=[64]
  } _frame;
  v8 = a4 + 1;
  v7 = (uint8_t)*a4;
  _frame.v79 = a2;
  v9 = a1;
  if ( !a1 )
  {
    v10 = (uint8_t)*a4;
    if ( *a4 )
    {
      _frame.v79 = 0;
LABEL_3:
      v10 = 0;
      _frame.v76 = 0;
      _frame.v77 = 0;
      v11 = _frame.v79;
      _frame.v78 = 0;
      v12 = nullptr;
      v13 = 0;
      while ( 2 )
      {
        switch ( v7 )
        {
          case ' ':
          case '+':
          case '-':
            v14 = 5;
            goto LABEL_7;
          case '%':
            v61 = 1;
            goto LABEL_124;
          case '*':
            v61 = 4;
LABEL_124:
            v13 = *(volatile uint8_t *)(dword_12E8B4 + 8 * v13 + v61);
            switch ( v13 )
            {
              case 0:
                goto LABEL_17;
              case 1:
                goto LABEL_11;
              case 2:
LABEL_44:
                if ( **(volatile int16_t **)dword_12E354 < 0 )
                  irq_disable_mmio_write(dword_12E8BC, dword_12E8B8, 283);
                v13 = 2;
                goto LABEL_12;
              case 3:
                goto LABEL_29;
              case 4:
                goto LABEL_16;
              case 5:
                goto LABEL_26;
              case 6:
                goto LABEL_21;
              case 7:
                goto LABEL_9;
              default:
                goto LABEL_161;
            }
          case '.':
            v14 = 2;
            goto LABEL_7;
          case '0':
            v13 = *(volatile uint8_t *)(dword_12E350 + 8 * v13 + 3);
            switch ( v13 )
            {
              case 0:
                goto LABEL_17;
              case 1:
                goto LABEL_11;
              case 2:
LABEL_43:
                _frame.v76 |= 0x40u;
                v13 = 2;
                goto LABEL_12;
              case 3:
LABEL_29:
                if ( v7 != 42 )
                  goto LABEL_30;
                v18 = *a5++;
                _frame.v78 = v18;
                v13 = 3;
                break;
              case 4:
                goto LABEL_16;
              case 5:
                goto LABEL_26;
              case 6:
                goto LABEL_21;
              case 7:
                goto LABEL_9;
              default:
                goto LABEL_161;
            }
            goto LABEL_12;
          case 'A':
          case 'M':
          case 'X':
          case 'a':
          case 'b':
          case 'c':
          case 'd':
          case 'i':
          case 'm':
          case 'p':
          case 's':
          case 'u':
          case 'x':
            v14 = 7;
            goto LABEL_7;
          case 'h':
          case 'l':
            v14 = 6;
            goto LABEL_7;
          default:
            if ( (unsigned int)(v7 - 49) > 8 )
            {
              v14 = 0;
LABEL_7:
              v13 = *(volatile uint8_t *)(dword_12E350 + 8 * v13 + v14);
              switch ( v13 )
              {
                case 0:
                  goto LABEL_17;
                case 1:
                  goto LABEL_11;
                case 2:
                  goto LABEL_10;
                case 3:
                  goto LABEL_29;
                case 4:
                  goto LABEL_16;
                case 5:
                  goto LABEL_26;
                case 6:
                  goto LABEL_21;
                case 7:
                  goto LABEL_9;
                default:
                  goto LABEL_161;
              }
            }
            v13 = *(volatile uint8_t *)(dword_12E350 + 8 * v13 + 4);
            switch ( v13 )
            {
              case 0:
LABEL_17:
                if ( v11 )
                {
                  if ( a3 <= v10 )
                  {
                    *v9++ = v7;
                    --v11;
                  }
                }
                ++v10;
                v13 = 0;
                goto LABEL_12;
              case 1:
LABEL_11:
                _frame.v76 = 0;
                _frame.v78 = 0;
                _frame.v77 = -1;
                v13 = 1;
                goto LABEL_12;
              case 2:
LABEL_10:
                switch ( v7 )
                {
                  case ' ':
                    _frame.v76 |= 0x10u;
                    v13 = 2;
                    break;
                  case '+':
                    _frame.v76 |= 8u;
                    v13 = 2;
                    break;
                  case '-':
                    _frame.v76 |= 0x20u;
                    v13 = 2;
                    break;
                  case '0':
                    goto LABEL_43;
                  default:
                    goto LABEL_44;
                }
                goto LABEL_12;
              case 3:
LABEL_30:
                _frame.v78 = v7 - 48 + 10 * _frame.v78;
                v13 = 3;
                goto LABEL_12;
              case 4:
LABEL_16:
                _frame.v77 = 0;
                v13 = 4;
                goto LABEL_12;
              case 5:
LABEL_26:
                if ( v7 == 42 )
                {
                  v17 = *a5++;
                  _frame.v77 = v17;
                }
                else
                {
                  _frame.v77 = v7 - 48 + 10 * _frame.v77;
                }
                v13 = 5;
                goto LABEL_12;
              case 6:
LABEL_21:
                if ( v7 == 104 )
                {
                  _frame.v76 |= 1u;
                  v13 = 6;
                }
                else if ( v7 == 108 )
                {
                  _frame.v76 |= 2u;
                  v13 = 6;
                }
                else
                {
                  if ( **(volatile int16_t **)dword_12E354 < 0 )
                    irq_disable_mmio_write(dword_12E8BC, dword_12E8B8, 334);
                  v13 = 6;
                }
                goto LABEL_12;
              case 7:
                goto LABEL_9;
              default:
LABEL_161:
                if ( **(volatile int16_t **)dword_12E8C0 < 0 )
                  irq_disable_mmio_write(dword_12E8BC, dword_12E8B8, 594);
                goto LABEL_12;
            }
        }
LABEL_9:
        switch ( v7 )
        {
          case 'A':
          case 'a':
            v37 = (volatile uint8_t *)*a5++;
            v38 = _frame.v78;
            v39 = dword_12E8C8;
            v41 = v37 + 1;
            v40 = *v37;
            if ( _frame.v78 )
            {
              v42 = *(volatile uint8_t *)(dword_12E8C8 + (v40 >> 4));
              v43 = *(volatile uint8_t *)(dword_12E8C8 + (v40 & 0xF));
              _frame.v80_scratch[0] = v42;
              if ( _frame.v78 >= 0x15 )
                v38 = 21;
              v44 = 3 * v38;
              v45 = v38 - 1;
              _frame.v80_scratch[1] = v43;
              v25 = v44 - 1;
              v21 = 1 - v44;
              if ( !v45 )
              {
LABEL_106:
                if ( (_frame.v76 & 0x40) != 0 )
                {
                  _frame.v78 = 0;
                  v23 = (&_frame.v80_scratch[0]);
                  goto LABEL_58;
                }
                _frame.v78 = _frame.v76 & 0x40;
                v23 = (&_frame.v80_scratch[0]);
                if ( (_frame.v76 & 0x20) != 0 )
                  goto LABEL_57;
                if ( v25 )
                  goto LABEL_58;
                goto LABEL_93;
              }
            }
            else
            {
              v63 = v40 >> 4;
              v64 = *(volatile uint8_t *)(dword_12E8C8 + (v40 & 0xF));
              _frame.v80_scratch[0] = *(volatile uint8_t *)(dword_12E8C8 + v63);
              _frame.v80_scratch[1] = v64;
              v21 = -47;
              v25 = 47;
              v45 = 15;
            }
            v46 = &v41[v45];
            v47 = (&_frame.v80_scratch[3]);
            do
            {
              v48 = ((uint8_t)v41 & 3) == 0;
              v49 = *v41++;
              *v47 = *(volatile uint8_t *)(v39 + (v49 >> 4));
              v47[1] = *(volatile uint8_t *)(v39 + (v49 & 0xF));
              if ( v48 )
                v50 = 58;
              else
                v50 = 46;
              *(v47 - 1) = v50;
              v47 += 3;
            }
            while ( v46 != v41 );
            goto LABEL_106;
          case 'M':
          case 'm':
            v51 = (volatile uint8_t *)*a5++;
            v52 = dword_12E8C8;
            v54 = v51 + 6;
            v53 = *v51;
            v55 = *(volatile uint8_t *)(dword_12E8C8 + (v53 >> 4));
            _frame.v80_scratch[1] = *(volatile uint8_t *)(dword_12E8C8 + (v53 & 0xF));
            _frame.v80_scratch[0] = v55;
            v56 = v51 + 1;
            v57 = (&_frame.v80_scratch[0]);
            do
            {
              v58 = *v56++;
              v57[2] = 58;
              v59 = *(volatile uint8_t *)(v52 + (v58 & 0xF));
              v57[3] = *(volatile uint8_t *)(v52 + (v58 >> 4));
              v57[4] = v59;
              v57 += 3;
            }
            while ( v54 != v56 );
            v21 = _frame.v78 - 17;
            v23 = (&_frame.v80_scratch[0]);
            v24 = _frame.v76 & 0x40;
            v25 = 17;
            goto LABEL_55;
          case 'X':
          case 'b':
          case 'd':
          case 'p':
          case 'u':
          case 'x':
            if ( (_frame.v76 & 2) != 0 || (_frame.v76 & 1) == 0 )
            {
              v62 = *a5++;
              v20 = v62;
              switch ( v7 )
              {
                case 'X':
LABEL_152:
                  v74 = dword_12E8C8;
                  v23 = (&_frame.v80_scratch[64]);
                  do
                  {
                    v75 = v20 & 0xF;
                    v20 >>= 4;
                    *--v23 = *(volatile uint8_t *)(v74 + v75);
                    v25 = (uintptr_t)((&_frame.v80_scratch[64])) - (uintptr_t)(v23);
                  }
                  while ( v20 );
                  goto LABEL_139;
                case 'b':
LABEL_149:
                  v23 = (&_frame.v80_scratch[64]);
                  do
                  {
                    *--v23 = (v20 & 1) + 48;
                    v20 >>= 1;
                    v25 = (uintptr_t)((&_frame.v80_scratch[64])) - (uintptr_t)(v23);
                  }
                  while ( v20 );
                  goto LABEL_139;
                case 'd':
                  goto LABEL_76;
                case 'p':
LABEL_145:
                  _frame.v76 |= 0x40u;
                  v24 = 64;
                  _frame.v78 = 8;
                  break;
                case 'u':
                  goto LABEL_78;
                case 'x':
LABEL_155:
                  v24 = _frame.v76 & 0x40;
                  break;
                default:
LABEL_142:
                  v21 = _frame.v78;
                  v24 = _frame.v76 & 0x40;
                  v23 = (&_frame.v80_scratch[64]);
                  v25 = 0;
                  goto LABEL_55;
              }
              v72 = dword_12E8CC;
              v23 = (&_frame.v80_scratch[64]);
              do
              {
                v73 = v20 & 0xF;
                v20 >>= 4;
                *--v23 = *(volatile uint8_t *)(v72 + v73);
                v25 = (uintptr_t)((&_frame.v80_scratch[64])) - (uintptr_t)(v23);
              }
              while ( v20 );
              v21 = _frame.v78 - v25;
              goto LABEL_55;
            }
            if ( v7 != 100 )
            {
              v19 = *a5++;
              v20 = (uint16_t)v19;
              switch ( v7 )
              {
                case 'X':
                  goto LABEL_152;
                case 'b':
                  goto LABEL_149;
                case 'p':
                  goto LABEL_145;
                case 'u':
                  goto LABEL_78;
                case 'x':
                  goto LABEL_155;
                default:
                  goto LABEL_142;
              }
            }
LABEL_143:
            v71 = *a5++;
            v20 = (int16_t)v71;
LABEL_76:
            if ( (v20 & 0x80000000) != 0 )
            {
              v20 = -v20;
              _frame.v76 |= 0x80u;
            }
LABEL_78:
            v29 = dword_12E8C4;
            v25 = 0;
            v30 = (&_frame.v80_scratch[64]);
            do
            {
              v31 = v20 - 10 * ((unsigned int)((v29 * (uint64_t)v20) >> 32) >> 3) + 48;
              v32 = v20 > 9;
              v33 = v30;
              v20 = (unsigned int)((v29 * (uint64_t)v20) >> 32) >> 3;
              *--v30 = v31;
              v34 = v25++;
            }
            while ( v32 );
            if ( (_frame.v76 & 0x80) != 0 )
            {
              v25 = v34 + 2;
              v35 = 45;
            }
            else if ( (_frame.v76 & 8) != 0 )
            {
              v25 = v34 + 2;
              v35 = 43;
            }
            else
            {
              if ( (_frame.v76 & 0x10) == 0 )
              {
                v21 = _frame.v78 - v25;
                v23 = v30;
                v24 = _frame.v76 & 0x40;
                goto LABEL_55;
              }
              v25 = v34 + 2;
              v35 = 32;
            }
            *(v30 - 1) = v35;
            v23 = v33 - 2;
            v21 = _frame.v78 - v25;
            if ( (_frame.v76 & 0x40) == 0 )
              goto LABEL_56;
            goto LABEL_84;
          case 'c':
            v21 = _frame.v78 - 1;
            v22 = *a5++;
            _frame.v80_scratch[0] = v22;
            v23 = (&_frame.v80_scratch[0]);
            v24 = _frame.v76 & 0x40;
            v25 = 1;
            goto LABEL_55;
          case 'i':
            if ( (_frame.v76 & 2) == 0 && (_frame.v76 & 1) != 0 )
              goto LABEL_143;
            v28 = *a5++;
            v20 = v28;
            goto LABEL_76;
          case 's':
            v36 = (volatile char *)*a5++;
            v23 = v36;
            if ( !v36 )
              goto LABEL_95;
            v25 = (uint8_t)*v23;
            if ( !*v23 )
            {
              v24 = _frame.v76 & 0x40;
              v21 = _frame.v78;
              goto LABEL_55;
            }
            if ( !_frame.v77 )
            {
LABEL_95:
              v21 = _frame.v78;
              v24 = _frame.v76 & 0x40;
              v25 = 0;
              goto LABEL_55;
            }
            v65 = _frame.v77;
            v66 = v23;
            v67 = 1 - (uint32_t)v23;
            while ( 2 )
            {
              while ( 1 )
              {
                v68 = (int)&v66[v67];
                if ( v65 > 0 )
                  break;
                v68 = (int)&v66[v67];
                if ( !*++v66 )
                  goto LABEL_138;
              }
              v69 = (uint8_t)*++v66;
              --v65;
              if ( v69 )
              {
                if ( !v65 )
                {
                  _frame.v77 = 0;
                  v25 = v68;
                  v21 = _frame.v78 - v68;
                  v24 = _frame.v76 & 0x40;
                  goto LABEL_55;
                }
                continue;
              }
              break;
            }
LABEL_138:
            _frame.v77 = v65;
            v25 = v68;
LABEL_139:
            v21 = _frame.v78 - v25;
            v24 = _frame.v76 & 0x40;
LABEL_55:
            if ( v24 )
            {
LABEL_84:
              if ( v21 <= 0 )
                goto LABEL_92;
              v10 += v21;
              while ( 1 )
              {
                if ( v11 )
                {
                  if ( a3 <= v10 - v21 )
                  {
                    *v9 = 48;
                    --v11;
                    ++v9;
                  }
                }
                else if ( !--v21 )
                {
                  v21 = 0;
                  goto LABEL_92;
                }
                if ( !--v21 )
                  goto LABEL_121;
              }
            }
LABEL_56:
            if ( (_frame.v76 & 0x20) == 0 )
            {
              if ( v21 > 0 )
              {
                v60 = v21 + v10;
                while ( 1 )
                {
                  if ( v11 )
                  {
                    if ( a3 <= v10 )
                    {
                      *v9 = 32;
                      --v11;
                      ++v9;
                    }
                  }
                  else if ( v60 == ++v10 )
                  {
LABEL_120:
                    v10 = v60;
LABEL_121:
                    v21 = 0;
                    if ( !v25 )
                    {
LABEL_93:
                      v12 = v23;
LABEL_72:
                      v13 = 7;
                      goto LABEL_12;
                    }
LABEL_58:
                    v26 = v23;
                    v12 = &v23[v25];
                    while ( 1 )
                    {
                      if ( v11 )
                      {
                        if ( a3 <= (unsigned int)&v26[v10 - (uint32_t)v23] )
                        {
                          *v9 = *v26;
                          --v11;
                          ++v9;
                        }
                      }
                      else if ( ++v26 == v12 )
                      {
LABEL_64:
                        v27 = v25 + v10;
                        goto LABEL_65;
                      }
                      if ( ++v26 == v12 )
                        goto LABEL_64;
                    }
                  }
                  if ( v60 == ++v10 )
                    goto LABEL_120;
                }
              }
LABEL_92:
              if ( !v25 )
                goto LABEL_93;
              goto LABEL_58;
            }
LABEL_57:
            if ( v25 )
              goto LABEL_58;
            v27 = v10;
            v12 = v23;
LABEL_65:
            if ( v21 > 0 )
            {
              v10 = v21 + v27;
              while ( 1 )
              {
                if ( v11 )
                {
                  if ( a3 <= v27 )
                  {
                    *v9 = 32;
                    --v11;
                    ++v9;
                  }
                }
                else if ( ++v27 == v10 )
                {
                  goto LABEL_72;
                }
                if ( ++v27 == v10 )
                  goto LABEL_72;
              }
            }
            v10 = v27;
            v13 = 7;
LABEL_12:
            v15 = (uint8_t)*v8++;
            v7 = v15;
            if ( !v15 )
              goto LABEL_13;
            continue;
          default:
            v23 = v12;
            goto LABEL_95;
        }
      }
    }
    return v10;
  }
  if ( *a4 )
    goto LABEL_3;
  v11 = a2;
  v10 = 0;
LABEL_13:
  if ( v11 )
  {
    *v9 = 0;
    return v10;
  }
  if ( !_frame.v79 )
    return v10;
  *(v9 - 1) = 0;
  return v10;
}


// mmio_read_bit13 @ 0x12e8d0
/* luna: Busy-waits until bit 18 of a volatile word at a fixed address is set. */
void mmio_read_bit13() {
  while ( (*(volatile uint32_t *)off_12E8E8 & 0x40000) == 0 )
    ;
}



// set_global_field0 @ 0x12e8ec
/* luna: Writes the supplied value to the global 32-bit field and returns it unchanged. */
int set_global_field0(int result) {
  *(volatile uint32_t *)off_12E8F4 = result;
  return result;
}



// set_global_field4 @ 0x12e8f8
/* luna: Stores a value in the 32-bit global field at offset 4 and returns that value. */
int set_global_field4(int result) {
  *((volatile uint32_t *)off_12E900 + 1) = result;
  return result;
}



// get_global_field0 @ 0x12e904
/* luna: Returns the 32-bit value stored at the fixed global field-0 address. */
int get_global_field0() {
  return *(volatile uint32_t *)off_12E90C;
}



// get_global_field4 @ 0x12e910
/* luna: Returns the 32-bit value stored at offset 4 in the global record. */
int get_global_field4() {
  return *((volatile uint32_t *)off_12E918 + 1);
}



// is_id_lt_10 @ 0x12e91c
/* luna: Returns true when the index is below 10, its bit is set in the global bitmap, and the adjacent global value is at least the requested value. */
BOOL is_id_lt_10(unsigned int a1, unsigned int a2) {
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(volatile uint32_t *)off_12E944 >> a1) & 1;
  if ( result )
    return *((volatile uint32_t *)off_12E944 + 1) >= a2;
  return result;
}



// alloc_tx_event @ 0x12e948
/* luna: Checks up to two high-bit tag bytes against the debug filter, then forwards the remaining format string and arguments to the test-print backend. */
int alloc_tx_event(const volatile char *fmt, ...) {
  volatile uint32_t *v1; // r6
  const volatile char *v2; // r4
  volatile int16_t **v3; // r8
  unsigned int v4; // r5
  unsigned int v5; // t1
  char v6; // r2
  const volatile char *varg_r0; // [sp+28h] [bp+20h]
  va_list varg_r1; // [sp+2Ch] [bp+24h] BYREF

  va_start(varg_r1, fmt);
  varg_r0 = fmt;
  v1 = (void *)(uintptr_t)(off_12E9C8);
  if ( *((volatile uint32_t *)off_12E9C8 + 1) )
  {
    v2 = fmt;
    v3 = (volatile int16_t **)off_12E9CC;
    do
    {
      fmt = v2;
      v5 = *(volatile uint8_t *)v2++;
      v4 = v5;
      v6 = v5 + 0x80;
      if ( (v5 & 0x80) == 0 )
        break;
      if ( v4 > 0x89 )
      {
        if ( **v3 < 0 && (uint8_t)(v4 + 102) > 5u )
          fmt = (const volatile char *)irq_disable_mmio_write((int)aDbgSevMinPrefi, (int)aDbgTestPrint, 812);
        if ( v1[1] <= v4 - 154 )
          return (int)fmt;
      }
      else if ( (((unsigned int)~*v1 >> v6) & 1) != 0 )
      {
        return (int)fmt;
      }
      fmt = v2;
    }
    while ( varg_r0 + 2 != v2 );
    return stack_struct_init(fmt, (volatile unsigned int *)(*(void **)&(varg_r1)));
  }
  return (int)fmt;
}


// process_packet_params @ 0x12e9d8
/* luna: Emits a hexadecimal dump of the requested memory range in 16-byte lines, optionally appending a printable-ASCII column. */
int process_packet_params(int result, int a2, int a3, int a4) {
  int v4; // r4
  unsigned int v5; // r5
  unsigned int v6; // r7
  volatile uint16_t *v7; // r6
  unsigned int v8; // r11
  int v9; // r1
  const volatile char *v10; // r0
  int v11; // r10
  int v12; // r4
  unsigned int v13; // r8
  unsigned int v15; // r8
  int v16; // r0
  unsigned int v17; // r8
  unsigned int v18; // r6
  unsigned int v19; // [sp+Ch] [bp-10h]
  int v21; // [sp+14h] [bp-8h]

  if ( !a2 )
    return result;
  v4 = a3;
  if ( a3 != 4 && (unsigned int)(a3 - 1) > 1 )
    return result;
  v19 = a2 * a3;
  v5 = -a3 & result;
  while ( 1 )
  {
    alloc_tx_event("%08x:", v5);
    v6 = v19;
    if ( v19 >= 0x10 )
      v6 = 16;
    if ( ((v5 >> 20) & 0xFFFFFDFF) == 0x500 )
    {
      if ( !v19 )
        return (int)radio_tx_write_string(&aNoTxDscrHdr[16]);
      v17 = 0;
      while ( 1 )
      {
        v18 = call_patch_hook_0();
        if ( v4 == 4 )
          break;
        if ( v4 == 2 )
        {
          v17 += 4;
          alloc_tx_event(" %04X %04X", (uint16_t)v18, HIWORD(v18));
          v5 += 4;
          if ( v6 <= v17 )
          {
LABEL_40:
            a4 = 0;
            goto LABEL_31;
          }
        }
        else
        {
          alloc_tx_event(" %02X %02X %02X %02X", (uint8_t)v18, BYTE1(v18), BYTE2(v18), HIBYTE(v18));
LABEL_36:
          v17 += 4;
          v5 += 4;
          if ( v6 <= v17 )
            goto LABEL_40;
        }
      }
      alloc_tx_event(" %08X", v18);
      goto LABEL_36;
    }
    if ( v19 )
      break;
    if ( a4 )
    {
      v7 = (volatile uint16_t *)v5;
      goto LABEL_20;
    }
LABEL_31:
    result = (int)radio_tx_write_string(&aNoTxDscrHdr[16]);
    v19 -= v6;
    if ( !v19 )
      return result;
  }
  v7 = (volatile uint16_t *)v5;
  v8 = 0;
  do
  {
    while ( 1 )
    {
      v10 = a02x;
      if ( v4 != 4 )
        break;
      v8 += 4;
      alloc_tx_event(" %08X", *(volatile uint32_t *)v7);
      v7 += 2;
      if ( v6 <= v8 )
        goto LABEL_18;
    }
    if ( v4 == 2 )
      v9 = *v7;
    else
      v9 = *(volatile uint8_t *)v7;
    if ( v4 == 2 )
      v10 = a04x;
    v8 += v4;
    alloc_tx_event(v10, v9);
    v7 = (volatile uint16_t *)((volatile char *)v7 + v4);
  }
  while ( v6 > v8 );
LABEL_18:
  if ( !a4 )
    goto LABEL_30;
  if ( v19 > 0xF )
  {
    radio_tx_write_string(asc_14AAE0);
    goto LABEL_26;
  }
LABEL_20:
  v11 = v4 - 1;
  v21 = v4;
  v12 = 0;
  v13 = 16 - v6;
  do
  {
    while ( (v11 & v12++) != 0 )
    {
      radio_tx_write_string(&aUseWfPa5gInput[28]);
      if ( v13 == v12 )
        goto LABEL_25;
    }
    radio_tx_write_byte(32);
    radio_tx_write_string(&aUseWfPa5gInput[28]);
  }
  while ( v13 != v12 );
LABEL_25:
  v4 = v21;
  radio_tx_write_string(asc_14AAE0);
  if ( v19 )
  {
LABEL_26:
    v15 = 0;
    do
    {
      v16 = *(volatile uint8_t *)(v5 + v15);
      if ( (unsigned int)(v16 - 31) > 0x5F )
        v16 = 46;
      ++v15;
      radio_tx_write_byte(v16);
    }
    while ( v6 > v15 );
LABEL_30:
    v5 = (unsigned int)v7;
    goto LABEL_31;
  }
  return (int)radio_tx_write_string(&aNoTxDscrHdr[16]);
}


// check_feature_flag @ 0x12eb90
/* luna: Formats and emits a test message when the supplied flag intersects the enabled-test mask; otherwise returns the flag unchanged. */
int check_feature_flag(int a1, const volatile char *fmt, ...) {
  va_list varg_r2; // [sp+10h] [bp+8h] BYREF

  va_start(varg_r2, fmt);
  if ( ((uint16_t)a1 & **(volatile uint16_t **)off_12EBB4) != 0 )
    return stack_struct_init(fmt, (volatile unsigned int *)(*(void **)&(varg_r2)));
  return a1;
}


