/* Exercise 4-14: Define a macro swap(t, x, y) that interchanges two arguments
 * of type t. (Block structure will help) */

#define swap(t, x, y)                                                          \
	do {                                                                   \
		t _swapper_var;                                                \
		_swapper_var = x;                                              \
		x = y;                                                         \
		y = _swapper_var;                                              \
	} while (0)
