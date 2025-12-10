z = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 120, 140, 160, 180, 200]
NUMBER_OF_RUNS = 10000000


with open('run2.mac', 'w') as file:
    file.write("""
# Macro file for example B1
# 
# To be run preferably in batch, without graphics:
# % exampleB1 run2.mac
#
/run/numberOfThreads 10
/run/initialize
/run/printProgress 500000
#/run/setCut 0.1 mm
#
/control/verbose 2
/run/verbose 2

# Форма 
#/gps/pos/type Plane
#/gps/pos/shape Square
#/gps/pos/halfx 5 mm #5 cm
#/gps/pos/halfy 5 mm #5 cm
#/gps/pos/rot1 1 0 0
#/gps/pos/rot2 0 1 0            

# Задаём частицу
/gps/particle gamma
/gps/direction 0 0 -1
/gps/pos/centre 0 0 90 cm
               
# Спектр частицы
/gps/ene/type Arb
/gps/hist/file ./spectre.txt
/gps/hist/inter Lin
            

""")
    for depth in z:
        file.write(f"""
/geom/z {depth}
/run/initialize
/run/beamOn {NUMBER_OF_RUNS}
""")