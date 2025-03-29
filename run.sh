#!/bin/bash

# Compilar la biblioteca
make

# Limpiar archivos objeto
make clean

# Eliminar el ejecutable anterior si existe
rm -rf test

# Compilar el programa con la biblioteca
cc main.c libftprintf.a -o test

# Ejecutar el programa
./test
