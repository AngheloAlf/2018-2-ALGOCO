/* 20182c2ip2 */

g(z) := rhs(solve((g - a0 - a1*z)/z^2 = (g - a0)/z + g + c/(1 - z), g)[1]);

factor(g(z));

partfrac(g(z), z);
