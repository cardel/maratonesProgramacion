# -*- coding: utf-8 -*-
from sys import stdin

#https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
#https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Extended_Euclidean_algorithm
#https://github.com/rezwanh001/UVA-Solutions-in-Python/blob/master/10104 euclid problem.py
def euclides_extendido(a,b):
	x0 = 0
	x1 = 1
	y0 = 1
	y1 = 0  
	
	while b != 0:
		q = a//b
		a,b = b,a%b
		x0,x1 = x1-q*x0,x0
		y0,y1 = y1-q*y0,y0
	
	return x1, y1, a
    
    
def main():
	
	for line in stdin:
		c = line.split()
		a = int(c[0])
		b = int(c[1])
		
		x,y,gcd = euclides_extendido(a,b)
		print(x,y,gcd)

main()
