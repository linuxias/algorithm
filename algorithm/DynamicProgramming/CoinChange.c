/*
 * 	for i = 1 to C[i] = INF
 * 	C[0] = 0
 *
 * 	for j = 1 to n {
 * 		for i = 1 to k {
 * 			if (di <= j and C[j-di] + 1 < C[j])
 * 				C[j] = C[j - di] + 1
 * 		}
 * 	}
 */
