depths = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 50, 60, 70, 80, 90, 100, 120, 130, 150, 170, 180, 190, 200]
NUMBER_OF_RUNS = 5000000

with open("run_generated1.mac", mode='w') as file:
    file.write(
"""
/control/verbose 1
/tracking/verbose 0
/run/verbose 1
/event/verbose 0


##########################
# Random
#

/random/setDirectoryName .
/random/setSavingFlag 1
#/random/resetEngineFrom currentEvent.rndm1


##########################
# Initialisation procedure
#
#/geometry/textInput/verbose 3
/run/printProgress 1000000

# Задаём частицу и другие параметры
/gps/particle gamma
/gps/direction -1 0 0
/gps/pos/centre 105 0 0 
#/dicom/intersectWithUserVolume 0. 0. 0. 45.*deg 0. 0. TUBE 0. 150. 100.
/run/initialize
#
/control/verbose 2
/run/verbose 2
/event/verbose 0
/tracking/verbose 0
\n\n""")
    
    for depth in depths[:15]:
        file.write(f"/detector/setPos {depth / 10}\n")
        file.write(f"/score/create/cylinderMesh det{depth}\n")
        file.write(f"/score/mesh/cylinderSize 3.1 20 mm\n")
        file.write(f"/score/mesh/translate/xyz {(15 - 0.62 - depth / 10):2f} 0 0 cm\n")
        file.write(f"/score/mesh/nBin 1 1 1\n")
        file.write(f"/score/quantity/energyDeposit eDep\n")
        file.write(f"/score/close\n")
        file.write(f"/run/beamOn {NUMBER_OF_RUNS}\n")
        file.write(f"/score/dumpQuantityToFile det{depth} eDep out{depth}.csv")
        file.write(f"\n\n")


with open("run_generated2.mac", mode='w') as file:
    file.write(
"""
/control/verbose 1
/tracking/verbose 0
/run/verbose 1
/event/verbose 0


##########################
# Random
#

/random/setDirectoryName .
/random/setSavingFlag 1
#/random/resetEngineFrom currentEvent.rndm1


##########################
# Initialisation procedure
#
#/geometry/textInput/verbose 3
/run/printProgress 1000000

# Задаём частицу и другие параметры
/gps/particle gamma
/gps/direction -1 0 0
/gps/pos/centre 105 0 0 
#/dicom/intersectWithUserVolume 0. 0. 0. 45.*deg 0. 0. TUBE 0. 150. 100.
/run/initialize
#
/control/verbose 2
/run/verbose 2
/event/verbose 0
/tracking/verbose 0
\n\n""")
    
    for depth in depths[15:]:
        file.write(f"/detector/setPos {depth / 10}\n")
        file.write(f"/score/create/cylinderMesh det{depth}\n")
        file.write(f"/score/mesh/cylinderSize 3.1 20 mm\n")
        file.write(f"/score/mesh/translate/xyz {(15 - 0.62 - depth / 10):2f} 0 0 cm\n")
        file.write(f"/score/mesh/nBin 1 1 1\n")
        file.write(f"/score/quantity/energyDeposit eDep\n")
        file.write(f"/score/close\n")
        file.write(f"/run/beamOn {NUMBER_OF_RUNS}\n")
        file.write(f"/score/dumpQuantityToFile det{depth} eDep out{depth}.csv")
        file.write(f"\n\n")
