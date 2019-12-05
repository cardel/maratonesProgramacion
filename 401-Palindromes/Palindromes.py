# -*- coding: utf-8 -*-
from sys import stdin


#Declare a dictionary

reverse = {'A':'A'};

def createHash():
	reverse['E']='3';
	reverse['H']='H';
	reverse['I']='I';			
	reverse['J']='L';
	reverse['L']='J';			
	reverse['M']='M';
	reverse['O']='0';
	reverse['S']='2';
	reverse['T']='T';
	reverse['U']='U';
	reverse['V']='V';
	reverse['W']='W';
	reverse['X']='X';			
	reverse['Y']='Y';
	reverse['Z']='5';
	reverse['1']='1';
	reverse['2']='S';
	reverse['3']='E';			
	reverse['5']='Z';
	reverse['8']='8';

def Palindrome(word):
	
	size = len(word)

	for i in range(0, size//2+1):		
		first = word[i]
		second = word[size-1-i]	

		if(first != second):
			return False;			
	return True;

def MirroredString(word):
	

	size = len(word)

	for i in range(0, size//2+1):		
		first = word[i]
		
		if word[size-1-i] in reverse:		
			second = reverse[word[size-1-i]]
		else:
			return False			

		if second == '0':
			second = 'O'
		
			
		if(first != second):
			return False			
	return True;


def main():
	
	createHash()
	for line in stdin:
		
		#Quitar \n de line
		line = line[:-1]		
		pal = Palindrome(line)
		mirrored = MirroredString(line)
		
		if pal and mirrored:
			print(line+" -- is a mirrored palindrome.\n")
		elif pal:
			print(line+" -- is a regular palindrome.\n")
		elif mirrored:
			print(line+" -- is a mirrored string.\n")
		else:
			print(line+" -- is not a palindrome.\n")
		
main()
