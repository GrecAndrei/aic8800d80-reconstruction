package structs

// isArgReg returns true if the base is an argument register or argument
// pseudo-variable. In Hex-Rays output:
//   r0-r3: ARM argument registers (r0 is also the return register)
//   a1-a4: pseudo-args (r0-r3 mapped to a1-a4 in some contexts)
//   v1-v8: pseudo-args/locals (v1, v2 are usually the first 2 args)
//
// We accept v1-v8 because Hex-Rays renames the first few arg registers to
// v1, v2, ... when the function has any locals.
func isArgReg(b string) bool {
	if len(b) < 2 || b[0] != 'v' {
		switch b {
		case "r0", "r1", "r2", "r3",
			"a1", "a2", "a3", "a4":
			return true
		}
		return false
	}
	// v1, v2, ... v8
	if len(b) >= 2 && b[0] == 'v' {
		for i := 1; i < len(b); i++ {
			if b[i] < '0' || b[i] > '9' {
				return false
			}
		}
		// parse number
		n := 0
		for i := 1; i < len(b); i++ {
			n = n*10 + int(b[i]-'0')
		}
		return n >= 1 && n <= 8
	}
	return false
}

// argOrder returns the argument position (0-7) of an arg register.
// Lower numbers are earlier in the call (i.e. higher priority for "primary").
func argOrder(b string) int {
	switch b {
	case "r0", "a1", "v1":
		return 0
	case "r1", "a2", "v2":
		return 1
	case "r2", "a3", "v3":
		return 2
	case "r3", "a4", "v4":
		return 3
	case "v5":
		return 4
	case "v6":
		return 5
	case "v7":
		return 6
	case "v8":
		return 7
	}
	return 99
}
