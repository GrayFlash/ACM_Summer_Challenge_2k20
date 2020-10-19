import java.util.*;
import java.io.*;

class TestClass {

    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        int q = Integer.parseInt(br.readLine());
	        
	        while(q--!=0) {
	        	int n = Integer.parseInt(br.readLine());
	        	String S[] = br.readLine().split(" "); 
	        	
				List<Integer> ll = new LinkedList<Integer>();
	        	int total=0;
	        	for(int i=0 ; i<n ; i++) {
	        		
					ll.add(Integer.parseInt(S[i]));
					total=total+ll.get(i);
				}
	        	if(total%2!=0)
	        	{
	        		System.out.println("1");
	        	}
	        	else
	        	{
	        		System.out.println("-1");
	        	}
	        	
	        }

			
		} 

	} 
