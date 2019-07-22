/* 20182c1p2: Gaussian quadrature, two points */

w(t) := t $

a : 0 $ b : 1 $

p0(t) := 1 $
n0 : integrate(w(t) * p0(t) * p0(t), t, a, b) $

p1(t) := ratsimp(t - integrate(w(t) * t * p0(t), t, a, b) * p0(t) / n0) $
n1 : integrate(w(t) * p1(t) * p1(t), t, a, b) $

p2(t) := ratsimp(t^2 - integrate(w(t) * t^2 * p1(t), t, a, b) * p1(t) / n1
		  - integrate(w(t) * t^2 * p0(t), t, a, b) * p0(t) / n0) $
n2 : integrate(w(t) * p2(t) * p2(t), t, a, b) $

x : map(rhs, solve(p2(t), t)) $

l0(t) := (t - x[1]) / (x[2] - x[1]) $
l1(t) := (t - x[2]) / (x[1] - x[2]) $

A0 : ratsimp(integrate(w(t) * l0(t), t, a, b)) $
A1 : ratsimp(integrate(w(t) * l1(t), t, a, b)) $

print("p2(t) = ", p2(t)) $
print("x = ", x) $
print("A = [", A0, ", ", A1, "]") $


