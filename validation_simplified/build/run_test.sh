#!/bin/bash

set -e
echo "---0. Делаем make"
make -j12

echo "---1. Генерируем run2.mac ---"
python3 ../generate_macros.py

echo "---2. Запускаем расчет через run2.mac---"
./exampleB1 run2.mac

echo "---Завершение работы---"
