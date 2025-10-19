with open('files.txt', 'r') as file:
	lines = file.readlines()

with open('Data.txt', 'w') as out:
	for line in lines: 
		out.write(f':FILE /home/vanya/MODELLING/dcmfiles/Mask/2370004/{line}')
