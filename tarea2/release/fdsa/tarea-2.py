import numpy as np
from scipy import interpolate
import matplotlib.pyplot as plt

def g(x):
    return x*np.cos(8*x) + x* np.sin(8*x)

def my_vandermonde(f, A):
    matrix = []
    for j in np.arange(len(A)):
        aux = []
        for i in np.arange(len(A)):
            elevated = np.power(A[j], i)
            aux.append(elevated)
        matrix.append(np.array(aux))
    matrix = np.array(matrix)
    y_list = np.array([f(x) for x in A])
    coef = np.linalg.solve(matrix, y_list)
    def thing_to_be_called(x):
        return sum([coef[i] * np.power(x, i) for i in range(len(coef))]) 
    return thing_to_be_called

def my_lagrange(f, A):
    y_list = [f(x) for x in A]
    range_y_list = range(len(y_list))
    def thing_to_be_called(x):
        total = 0
        for k in range_y_list:
            multiplicatoria = 1
            for j in range_y_list:
                if(j != k):
                    multiplicatoria *= np.true_divide(x - A[j], A[k] - A[j])
            total += y_list[k]*multiplicatoria
        return total
    return thing_to_be_called


def my_divided_differences(f, A):
    aux = [f(x) for x in A]
    len_ = len(A)
    for j in range(1, len_):
        for i in range(len_-1, j-1, -1):
            aux[i] = np.true_divide(aux[i]-aux[i-1], A[i]-A[i-j], dtype=np.float64)

    def thing_to_be_called(xx):
        result = aux[0]
        olds = []
        for i in range(1, len(aux)):
            substraction = (xx - A[i-1])
            actualMultiplication = aux[i]*substraction
            for j in olds:
                actualMultiplication *= j
            result += actualMultiplication
            olds.append(substraction)
        return result

    return thing_to_be_called

def my_interp1d(f, A):
    return interpolate.interp1d(np.array(A), np.array([f(x) for x in A]))



def my_range(start, end, howMany):
    return np.linspace(start, end, howMany)

def my_chebyshev(start, end, howMany):
    lista = []
    a_0 = (end + start)/2
    b_0 = (end - start)/2
    for i in range(1, howMany+1):
        x = a_0 + b_0 * np.cos( ((2*i - 1) * np.pi) / (2*howMany))
        lista.append(x)
    return np.array(lista)


def plotError(function, data, title):
    print("Calculando", title)
    real10 = function(data)

    print("\tInterpolando vandermonde")
    vander = my_vandermonde(function, data)
    print("\tPloteando vandermonde")
    plt.plot(data, abs(real10 - vander(data)), "r", label="Vandermonde")
    print("")

    print("\tInterpolando lagrange")
    lagran = my_lagrange(function, data)
    print("\tPloteando lagrange")
    plt.plot(data, abs(real10 - lagran(data)), "g", label="Lagrange")
    print("")

    print("\tInterpolando divided differences")
    divide = my_divided_differences(function, data)
    print("\tPloteando divided differences")
    plt.plot(data, abs(real10 - divide(data)), "b", label="Divided differences")
    print("")

    print("\tInterpolando interp1d")
    interp = my_interp1d(function, data)
    print("\tPloteando interp1d")
    plt.plot(data, abs(real10 - interp(data)), "y", label="interp1d")
    print("")

    plt.legend()
    plt.title(title)
    plt.xlabel("Dominio de la funcion")
    plt.ylabel("Error con respecto a la funcion real")
    plt.show()


def plotReal(function, data, title):
    print("Calculando", title)

    print("\tInterpolando vandermonde")
    vander = my_vandermonde(function, data)
    print("\tPloteando vandermonde")
    plt.plot(data, vander(data), "r", label="Vandermonde")
    print("")

    print("\tInterpolando lagrange")
    lagran = my_lagrange(function, data)
    print("\tPloteando lagrange")
    plt.plot(data, lagran(data), "g", label="Lagrange")
    print("")

    print("\tInterpolando divided differences")
    divide = my_divided_differences(function, data)
    print("\tPloteando divided differences")
    plt.plot(data, divide(data), "b", label="Divided differences")
    print("")

    print("\tInterpolando interp1d")
    interp = my_interp1d(function, data)
    print("\tPloteando interp1d")
    plt.plot(data, interp(data), "y", label="interp1d")
    print("")

    print("\tPloteando real")
    plt.plot(data, function(data), "black", label="real")
    print("")

    plt.legend()
    plt.title(title)
    plt.xlabel("Dominio de la funcion")
    plt.ylabel("Error con respecto a la funcion real")
    plt.show()

START = 0
END = 20

if __name__ == "__main__":
    my_vandermonde(g, [1, 2, 3, 4])
    x10 = my_range(START, END, 10)
    x150 = my_range(START, END, 150)
    x300 = my_range(START, END, 300)

    cheb10 = my_chebyshev(START, END, 10)
    cheb150 = my_chebyshev(START, END, 150)
    cheb300 = my_chebyshev(START, END, 300)

    # Error plotting
    plotError(g, x10, "Error con 10 puntos equiespaciados")
    plotError(g, x150, "Error con 150 puntos equiespaciados")
    plotError(g, x300, "Error con 300 puntos equiespaciados")

    # Chevishev error plotting
    plotError(g, cheb10, "Error con 10 puntos de chevishev")
    plotError(g, cheb150, "Error con 150 puntos de chevishev")
    plotError(g, cheb300, "Error con 300 puntos de chevishev")
    