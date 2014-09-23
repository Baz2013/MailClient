# -*- coding:utf-8 -*-
import string

def read_data():
	data_list=[]
	#file = open("example.txt")
	file = open("data1.txt")
	for line in file:
		#print line,
		line=line.strip('\n') #去掉每行后的换行符
		line=string.atoi(line) #字符串转换数字
		data_list.append(line)
	return data_list

list1 = [18,0,4,8,9,16,1,14,7,19,3,5,2,11,6]
def brute_force(lst):
	i=0
	while True:
		if i not in lst:
			return i
		i = i + 1

if __name__ == '__main__':
	list2=read_data()
	#print list2[10]
	num = brute_force(list2)
	print num
