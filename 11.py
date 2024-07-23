
final_row = 1
final_col = 1
final_dia = 1
final_dia2 = 1
if __name__ == "__main__":
	with open("11-data", "r") as f:
		data = []
		for line in f:
			#print(f"{line} : {__i}")
			ln = []
			for char in line:
				if char != '\n':
					ln.append(char)	
			data.append(ln)

		fdata = []
		for line in data:
			fln = []
			_str = ""
			for char in line:
				if char != " ":
					_str += char
				else:
					fln.append(int(_str))	
					_str = ""
			fln.append(int(_str))
			fdata.append(fln)
			print(f"{fln} : {len(fln)}")

		for line in fdata:
			candidate = 1
			for _i in range(len(line)-3):
				for _k in range(4):
					candidate *= line[_i+_k]
				if candidate > final_row:
					final_row = candidate
					print(f"row: {line[_i+_k-3]} * {line[_i+_k-2]} * {line[_i+_k-1]} * {line[_i+_k]} = {final_row}")
				candidate = 1
		
		for char_i in range(len(fdata[0])):
			candidate = 1
			for _i in range(len(fdata)-3):
				for _k in range(4):
					candidate *= fdata[_i+_k][char_i]
				if candidate > final_col:
					final_col = candidate
					print(f"col: {fdata[_i+_k-3][char_i]} * {fdata[_i+_k-2][char_i]} * {fdata[_i+_k-1][char_i]} * {fdata[_i+_k][char_i]} = {final_col}")	
				candidate = 1

		candidate = 1
		candidate2 = 1
		for _j in range(len(fdata)-3):
			for _i in range(len(fdata[0])-3):
				for _k in range(4):
					candidate *= fdata[_j+_k][_i+_k]
					candidate2 *= fdata[_j+_k][_i-_k]
				if candidate > final_dia:
					final_dia = candidate
					print(f"dia: {final_dia}")	
				if candidate2 > final_dia2:
					final_dia2 = candidate2
					print(f"dia2: {final_dia2}")	
				candidate = 1
				candidate2 = 1
						
		print(final_row)
		print(final_col)
		print(final_dia)
		print(final_dia2)
		f.close()
