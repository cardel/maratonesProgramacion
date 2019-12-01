# -*- coding: utf-8 -*-
from sys import stdin

#https://github.com/morris821028/UVa/blob/master/volume110/11053 - Flavius Josephus Reloaded[v2].cpp
#http://manoharcodes.blogspot.com/2017/09/uva-11053-flavius-josephus-reloaded.html

def main():
	c = stdin.readline().split()

	while int(c[0]) != 0:    
		#Total soldados
		n = int(c[0])
		a = int(c[1])
		b = int(c[2])    
		
		sobrevivientes = n
		
		soldado1 = 0
		soldado2 = 0
		
	
		while(True):
			soldado1 = (a*(soldado1*soldado1%n)%n + b)%n;
			soldado2 = (a*(soldado2*soldado2%n)%n + b)%n;
			soldado2 = (a*(soldado2*soldado2%n)%n + b)%n;			
			
			if(soldado1==soldado2):
				break

		soldado1 = (a*(soldado1*soldado1%n)%n + b)%n;
		sobrevivientes-=1
		
		while(soldado1 != soldado2):
			soldado1 = (a*(soldado1*soldado1%n)%n + b)%n;
			sobrevivientes-=1

		print(sobrevivientes)
		
		c = c = stdin.readline().split()


main()
