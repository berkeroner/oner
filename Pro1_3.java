
//  Berker ÖNER 150122018

import java.util.Scanner;

public class Pro_150122018 {

	public static void main(String[] args) {

		System.out.println("Welcome to our String Analyzer Program. ");
		
		System.out.println("1. Count number of chars");
		System.out.println("2. Print the words in a sentence");
		System.out.println("3. Delete substring");
		System.out.println("4. Replace substring");
		System.out.println("5. Sort characters");
		System.out.println("6. Hash code of a string");
		
		Scanner input = new Scanner(System.in);
		System.out.println("Please enter your menu choice : ");
		String choice = input.next();
		
		switch (choice) {
		
			case "1":
				Scanner input1 = new Scanner(System.in);
				
				System.out.println("Enter an input string : ");
				String str1 = input1.nextLine();
				
				System.out.println("Enter an input char : ");
				String letter = input1.next();
				
				char ch1 = letter.charAt(0);		
				int number = numOfChars(str1, ch1);
				System.out.println("The number of " + ch1 + " in " + str1 +  " is " + number + ".");
				
				break;
		
			case "2":
				Scanner input2 = new Scanner(System.in);
				System.out.println("Enter an input string : ");
				String str2 = input2.nextLine();
				
				printWords(str2);
				break;
				
			case "3":
				Scanner input3 = new Scanner(System.in);
				System.out.println("Enter an input string : ");
				String str3 = input3.nextLine();
				
				System.out.println("Enter a substring : ");
				String subStr = input3.nextLine();
				
				System.out.println("Enter a type : ");
				int type = input3.nextInt();
				
				String newStr3 = delete(str3, subStr, type);
				
				System.out.println(newStr3);
				break;
				
			case "4":
				Scanner input4 = new Scanner(System.in);
				System.out.println("Enter an input string : ");
				String str4 = input4.nextLine();
				
				System.out.println("Enter the first substring : ");
				String subStr1 = input4.nextLine();
			
				
				System.out.println("Enter the second substring : ");
				String subStr2 = input4.nextLine();
				
				String newStr = replace(str4, subStr1, subStr2);
				
				System.out.println();	
				break;
				
			case "5":
				Scanner input5 = new Scanner(System.in);
				System.out.println("Enter an input string : ");
				String str = input5.nextLine();
				
				System.out.println("Enter a type : ");
				int type5 = input5.nextInt();
				
				String newString = sortChars(str, type5);
				
				System.out.println(newString);
				break;
				
			case "6":
				Scanner input6 = new Scanner(System.in);
				System.out.println("Enter an input string : ");
				String str6 = input6.nextLine();
				
				System.out.println("Enter a value for b : ");
				int b = input6.nextInt();
				
				long result = hashCode(str6, b);
				System.out.println("The hash code for " + str6 + " is " + result + ".");
				
				break;
				
			case "exit":
				System.out.println("Program ends. Bye :)");
				System.exit(0);
			case "quit":
				System.out.println("Program ends. Bye :)");
				System.exit(1);
		}		
	}
	
	public static int numOfChars(String str, char ch) {
		
		int number=0;
		
		for(int a=0 ;a < str.length() ; a++) {
			char b = str.charAt(a);  
			if (b == ch) 
				number++;
		}
		return number;
	}
	
	public static void printWords(String str2) {
		
		System.out.println("The output is : ");
		
		for (int i=0 ; i < str2.length() ; i++) {
			int count=0;
			char ch2 = str2.charAt(i);
			
			if (ch2 == ' ') {
				System.out.println();
			}
			else if (ch2 == ',' ) { 
				System.out.print("");
			}
			else if (ch2 == '!' ) { 
				System.out.print(""); 
			}
			else if (ch2 == '_' ) { 
				System.out.print(""); 
			}
			else if (ch2 == '(' ) { 
				System.out.print(""); 
			}
			else if (ch2 == ')' ) { 
				System.out.print(""); 
			}
			else if (ch2 == '.' ) { 
				System.out.print(""); 
			}
			else if (ch2 == '?' ) { 
				System.out.print(""); 
			}
			else if (ch2 == '-' ) { 
				System.out.println(""); 
			}
			else 
				System.out.print(ch2);
		}	
	}
	
	public static String delete(String str3, String subStr, int type) {
		
		String newStr = "";
		
		int length = subStr.length();
		int index = str3.indexOf(subStr);
		
		while (index != -1) {
			str3 = str3.substring(0, index) + str3.substring(index + length);
		
		if (type == 0) {
			break;
			}
		else if (type == 1) {
			index = str3.indexOf(subStr, index);
			}
		}
		return str3;
	}
	
	public static String replace(String str4, String subStr1, String subStr2) {
		
		char chSubStr1 = subStr1.charAt(0) ;
		char chSubStr2 = subStr2.charAt(0) ;
		
		for(int i=0 ; i<str4.length() ; i++) {
			
			char letter = str4.charAt(i) ;
			
			if (letter == chSubStr1) {
				letter = chSubStr2;
				System.out.print(letter);
			}
			
			else {
				System.out.print(letter);
			}
		}
		return str4;
	}
	
	public static String sortChars(String str, int type5) {
		
		String newStr = "";
		char least = ' ';
		int length = str.length();
		
		if (type5 == 0) {
			
			for(int k=0 ; k<1 ; k++) {
			
			for(char ch=0 ; ch<=127 ; ch++) {
				int res=0;
				for(int i=0 ; i<length ; i++) {
					if(str.charAt(i) == ch) {
						res++;		
					}	
				}
				for(int j=0 ; j<res ; j++) {
					System.out.print(ch);
						}	
					}	
				}			
		}
		else if (type5 == 1) {
			for(int i=0 ; i<str.length(); i++) {
				char ch = str.charAt(i);
			}
			
			for(int i=0 ; i<str.length(); i++) {
				char ch = str.charAt(i);
				if (ch>='a' && ch<='z') {
					System.out.print(ch);
				}
			}
			for(int i=0 ; i<str.length(); i++) {
				char ch = str.charAt(i);
				if (ch>='A' && ch<='Z') {
					System.out.print(ch);
				}
			}
			for(int i=0 ; i<str.length(); i++) {
				char ch = str.charAt(i);
				if (ch>='0' && ch<='9') {
					System.out.print(ch);
				}
			}
			for(int i=0 ; i<str.length(); i++) {
				char ch = str.charAt(i);
				if (ch>='a' && ch<='z') {					
				}
				else if (ch>='A' && ch<='Z') {					
				}
				else if (ch>='0' && ch<='9') {					
				}
				else
					System.out.print(ch);				
				}
			}
		
		else {
			System.out.println("Invalid input");
			System.exit(2);
		}		
		return newStr;		
	}
	public static int hashCode(String str6, int b) {
		
		long result = 0;
		long total = 0;
		int length = str6.length();
		
		for(int i=0, c=1 ; i<length ; i++, c++) {
			char ch = str6.charAt(i);
			result = (long)((int)ch * Math.pow(b, (length-c)));
			
			total += result;
			
			result = 0;
		}		
		return (int)total;
	}
}