from __future__ import print_function


def fuerzaBruta(kilos, kilosPorPersona):
    a, b, c = kilosPorPersona
    mejor = 0
    diferencia = float("inf")
    for i in range(0, kilos+1):
        for j in range(0, kilos+1):
            for k in range(0, kilos+1):
                kilosSeparados = i*a + j*b + k*c
                if kilosSeparados <= kilos:
                    cantidad = i+j+k
                    if kilos - kilosSeparados <= diferencia and cantidad >= mejor:
                        mejor = cantidad
                        diferencia = kilos - kilosSeparados
    return mejor


def fuerzaBruta2(kilos, kilosPorPersona):
    a, b, c = kilosPorPersona
    mejor = 0
    if kilos == 0:
        return 0
    a_calc = -float("inf") if kilos < a else 1 + fuerzaBruta2(kilos - a, kilosPorPersona)
    b_calc = -float("inf") if kilos < b else 1 + fuerzaBruta2(kilos - b, kilosPorPersona)
    c_calc = -float("inf") if kilos < c else 1 + fuerzaBruta2(kilos - c, kilosPorPersona)
    return max(a_calc, b_calc, c_calc)

def obtenerAumento(numero, arreglo, i):
    aumento = -float("inf")
    if i - numero >= 0:
        aumento = 1 + arreglo[i-numero]
    return aumento


def algoritmo(kilos, kilosPorPersona):
    a, b, c = kilosPorPersona
    arreglo = [0 for i in range(kilos+1)]
    for i in range(1, kilos+1):
        # print(i)
        a_calc = obtenerAumento(a, arreglo, i)
        b_calc = obtenerAumento(b, arreglo, i)
        c_calc = obtenerAumento(c, arreglo, i)
        # print("\t", a_calc)
        # print("\t", b_calc)
        # print("\t", c_calc)

        arreglo[i] = max(a_calc, b_calc, c_calc)

    # print(arreglo)
    return arreglo[-1]


entrada = input("")
kilos, a, b, c = map(int, entrada.split())
print(kilos, a, b, c)
# print("fuerzaBruta    ", fuerzaBruta(kilos, [a, b, c]))
# print("+o-            ", algoritmo(kilos, [a, b, c]))
print(fuerzaBruta2(kilos, [a, b, c]))
print(algoritmo(kilos, [a, b, c]))

# print(fuerzaBruta(5, [5, 3, 2]))
# print(fuerzaBruta(8, [2, 3, 5]))
# print(fuerzaBruta(7, [5, 5, 2]))
