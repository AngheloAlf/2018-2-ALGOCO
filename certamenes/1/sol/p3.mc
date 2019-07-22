/* 20182c1p3: Variant of Hanoi puzzle */

h(z) := rhs(solve(H / z = 3 * H + 2 / (1 - z), H)[1]) $

print("h(z) =", partfrac(h(z), z)) $
