# Trabajo Práctico Número II

## Uso del repositorio

Este repositorio utiliza [pre-commit](https://pre-commit.com) para validaciones de formato. Para trabajar con el mismo usted debería tener instalado:

1. pre-commit (https://pre-commit.com/#install)

Después de clonar el repositorio usted debería ejecutar el siguiente comando:

```
pre-commit install
```

Para generar la documentación del proyecto se utiliza el siguiente comando:

```
make doc

```

Para `compilar` el proyecto se utiliza el siguiente comando:

```
make all
```

## Tests implementados 

- Después de la inicialización todos los LEDs deben quedar apagados.
- Se puede prender un LED individual.
- Se puede apagar un LED individual.
- Se pueden prender y apagar múltiples LED’s.
- Se pueden prender todos los LEDs de una vez.
- Se pueden apagar todos los LEDs de una vez.
- Se puede consultar el estado de un LED

## License

This work is distributed under the terms of the [MIT](https://spdx.org/licenses/MIT.html) license.
