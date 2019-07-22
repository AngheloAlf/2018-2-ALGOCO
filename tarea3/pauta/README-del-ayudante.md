Esta tarea fue revisada de forma automatizada con el programa *BATS* y casos de prueba escritos por el profesor.

* Puede instalar bats en fedora usando `sudo dnf install bats`
* Puede compilar el codigo Pauta corriendo el **Makefile**
  * si necesita instalar *pandoc* puede hacerlo con `sudo dnf install pandoc` en fedora, es solo para compilar el readme del profe, si no lo quiere puede compilar individualmene cada pregunta.

Puede verificar que el codigo pauta pasa todas las pruebas corriendo los tests
```
./test-1
./test-2
./tets-3
./test-4
```

Note que el codigo Pauta no comete ningun fallo

(Los tests esperan que sus ejecutables se llamen `2018t3p<n-pregunta>`)

