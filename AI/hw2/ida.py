import time

num_map = []
ans_map = [[1, 2, 2, 3], [1, 2, 2, 3], [4, 5, 5, 6], [4, 0, 0, 6], [7, 8, 9, 10]]
ans_coor = [[0, 0], [0, 1], [0, 3], [2, 0], [2, 1], [2, 3], [4, 0], [4, 1], [4, 2], [4, 3]]
# decide max depth for IDA
max_limit = 12

height = 0
width = 0

# count the H() of the num_map
def getH(num_map):
	num_apper = [False]*10
	cnt = 0
	for y in range(height):
		for x in range(width):
			num = num_map[y][x]
			if num != 0:
				if num_apper[num - 1] == False:
					num_apper[num - 1] = True
					coor = ans_coor[num - 1]
					cnt += abs(y - coor[0]) + abs(x - coor[1])
	return cnt


# check if the move is valid
def checkMove(num_map, num, dir):	
	for y in range(height):
		for x in range(width):
			if dir == 'R':
				if num_map[y][x] == num and x == width - 1:
					return False
				if num_map[y][x] == num and (num_map[y][x + 1] != num and num_map[y][x + 1] != 0):
					return False
			elif dir == 'L':
				if num_map[y][x] == num and x == 0:
					return False
				if num_map[y][x] == num and (num_map[y][x - 1] != num and num_map[y][x - 1] != 0):
					return False
			elif dir == 'U':
				if num_map[y][x] == num and y == 0:
					return False
				if num_map[y][x] == num and (num_map[y - 1][x] != num and num_map[y - 1][x] != 0):
					return False
			elif dir == 'D': 
				if num_map[y][x] == num and y == height - 1:
					return False
				if num_map[y][x] == num and (num_map[y + 1][x] != num and num_map[y + 1][x] != 0):
					return False
	return True

# move the number to the direction
def move(num_map, num, dir):
	ret_map = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
	for y in range(height):
		for x in range(width):
			if num_map[y][x] != num and num_map[y][x] != 0:
				ret_map[y][x] = num_map[y][x]
			elif num_map[y][x] == num:
				if dir == 'L':
					ret_map[y][x - 1] = num
				elif dir == 'R':
					ret_map[y][x + 1] = num
				elif dir == 'U':
					ret_map[y - 1][x] = num
				elif dir == 'D':
					ret_map[y + 1][x] = num
	return ret_map

def DFS(num_map, flimit, sol, g, next_f):
	h = getH(num_map)
	F = g + h
	if num_map == ans_map:
		return sol, min(next_f, F)
	if F > flimit:
		return [], min(next_f, F)

	possible_move = []
	# find all possible moves in number 1-10
	for num in range(1, 11):
		if checkMove(num_map, num, 'R'):
			possible_move.append([str(num),'R'])
		if checkMove(num_map, num, 'L'):
			possible_move.append([str(num),'L'])
		if checkMove(num_map, num, 'U'):
			possible_move.append([str(num),'U'])
		if checkMove(num_map, num, 'D'):
			possible_move.append([str(num),'D'])
	# check every possible move can lead to final answer or not
	for act in possible_move:
		next_num_map = move(num_map, int(act[0]), act[1])
		ret_sol, ret_F = DFS(next_num_map, flimit, sol + [act], g + 1, next_f)
		if ret_F <= flimit:
			return ret_sol, min(ret_F, next_f)
		

	return sol, min(F, next_f)


def IDA(num_map):
	flimit = getH(num_map)
	while True:
		now_time = time.time()
		if now_time - start > 200.0:
			return []
		sol, new_flimit = DFS(num_map, flimit, [], 0, max_limit)
		if len(sol) != 0 and new_flimit == flimit:
			return sol
		flimit = min(new_flimit, max_limit)
		if flimit >= max_limit:
			return []

# reading input
print('\nPlease enter your input file name(ex. input.txt): ', end='')
input_path = input()

start = time.time()
with open(input_path, 'r') as f:
	tmp = f.read()
	input_list = tmp.split('\n')
	for i in range(len(input_list)):
		if i == 0:
			height = int(input_list[0][0:2])
			width = int(input_list[0][2:4])
		else:
			l = []
			for j in range(0, len(input_list[i]), 2):
				num = int(input_list[i][j:j + 2])
				l.append(num)
			num_map.append(l)

now_time = time.time()

print('complete reading input, use time: ' + str(now_time - start) + ' seconds')

print('\nstarting ida, static ans: ')
for i in ans_map:
	for j in i:
		print(j, end = ' ')
	print()
print()

sol = IDA(num_map)
print('finish IDA\n')
end = time.time()

with open('output.txt', 'w') as f:
	f.write('Total run time = ' + str(end - start) + ' seconds.\n')
	print('Total run time = ' + str(end - start) + ' seconds.')

	if len(sol) == 0:
		f.write('Can\'t find optimal solution in 200 seconds\n')
		print('Can\'t find optimal solution in 200 seconds\n')
	else:
		f.write('An optimal solution has ' + str(len(sol)) + ' moves:\n')
		print('An optimal solution has ' + str(len(sol)) + ' moves:')
		for i in sol:
			f.write(str(i[0])+i[1]+' ')
			print(str(i[0])+i[1]+' ', end = '')
		print()