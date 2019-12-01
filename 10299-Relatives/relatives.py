# -*- coding: utf-8 -*-
from sys import stdin

#https://algorithmist.com/wiki/UVa_10299
#https://cp-algorithms.com/algebra/phi-function.html
#https://www.geeksforgeeks.org/eulers-totient-function/
#https://www.geeksforgeeks.org/optimized-euler-totient-function-multiple-evaluations/

primos = []

#Función para encontrar todos los números primero desde 1 hasta 100000, se trabaja con la raíz del
#maximo porque al final se descartan los primos más pequeños

def encontrarPrimos():
	
	esPrimo = [0]*100001
	
	for i in range(2,100001):
		if(esPrimo[i]==0):
			
			#Agregamos el factor primo
			primos.append(i)
			
			#Descartamos todos los multiplos del número primo
			
			j = 2
			while(i*j <= 100000):
				esPrimo[i*j] = 1
				j+=1                 
                
def algoritmo_euler(n):
	
	if n == 1:
		return 0
	result = n
	i = 0
	
	while(primos[i]*primos[i] <= n):
		#Eliminar raices n-ésimas
		if(n % primos[i] == 0):
				
			result -= result//primos[i]
			
			#Eliminar todos los multiplos del número primo p[i]
			
			while(n%primos[i]==0):
				n = n//primos[i]
		i += 1
			
	if(n>1):
		result -= result//n
	
	return result
	
def main():
  c = int(stdin.readline())
  encontrarPrimos()
  while c > 0:
    
    print(int(algoritmo_euler(c)))
    c = int(stdin.readline())

main()
