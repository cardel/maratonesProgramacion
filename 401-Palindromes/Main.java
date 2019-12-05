import java.util.Scanner; 
import java.util.Hashtable;

public class Main{	
	

	static Hashtable<Character,Character> reverse;
	
	
	public static void createHash(){
	
		reverse = new Hashtable<Character,Character>();
		
		reverse.put('A','A');
		reverse.put('E','3');
		reverse.put('H','H');
		reverse.put('I','I');			
		reverse.put('J','L');
		reverse.put('L','J');			
		reverse.put('M','M');
		reverse.put('O','0');
		reverse.put('S','2');
		reverse.put('T','T');
		reverse.put('U','U');
		reverse.put('V','V');
		reverse.put('W','W');
		reverse.put('X','X');			
		reverse.put('Y','Y');
		reverse.put('Z','5');
		reverse.put('1','1');
		reverse.put('2','S');
		reverse.put('3','E');			
		reverse.put('5','Z');
		reverse.put('8','8');
		
	}
	
	public static boolean Palindrome(String word){
		
		int size = word.length();
		for(int i=0; i<=size/2; i++){			
			char first = word.charAt(i);
			char second = word.charAt(size-1-i);
			
			if(first != second){
				return false;
			}
			
		}
		return true;
	}

	
	public static boolean MirroredString(String word){
		
		int size = word.length();
		for(int i=0; i<=size/2; i++){
			char first = word.charAt(i);
			char second =  word.charAt(size-1-i);		
			if(reverse.get(first)==null || reverse.get(second)==null ){
				return false;
			}
			char mirrored = reverse.get(second);
			if(mirrored == '0'){
				mirrored = 'O';
			}
			
			
			if(first != mirrored){
				return false;
			}
			
		}
		return true;
	}		

		
	public static void main(String args[]){
		
		Scanner in = new Scanner(System.in);
		String linea = "";
		
		createHash();
		
		while(in.hasNext()){		
			
			linea = in.nextLine(); 
			boolean palindrome = Palindrome(linea);
			boolean mirroredString = MirroredString(linea);
			
			
			if(palindrome && mirroredString){
				System.out.println(linea+" -- is a mirrored palindrome.\n");
			}
			else{
				if(palindrome){
					
					System.out.println(linea+" -- is a regular palindrome.\n");
				}
				else{
						if(mirroredString){
							System.out.println(linea+" -- is a mirrored string.\n");
						}
						else{
							System.out.println(linea+" -- is not a palindrome.\n");
						}
					
				}				
				
			}

		}
				
	}
 
 

}
