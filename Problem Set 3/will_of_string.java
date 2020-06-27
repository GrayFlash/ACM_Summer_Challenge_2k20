import java.io.*;
import java.util.*;
class TestClass {
        public static long subStr(String s, int low, int high, long count){
			while (low >= 0 && high < s.length()&& s.charAt(low) == s.charAt(high)){
				count++;
				low--;
				high++;
			}
			return count;
		}
		public static long palindromes(String s, int n)
		{	
			long count = 0;
			for (int i=0; i<n; i++){
				count +=subStr(s,i,i,0);
				count += subStr(s,i,i+1,0);
			}
			return count;
		}

    public static void main(String[] args ) throws Exception {
        Scanner sc = new Scanner(System.in);
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
   		int T=Integer.parseInt(br.readLine());
   		while(T-->0)
   		{
   			int N=Integer.parseInt(br.readLine());
   		    String s=br.readLine();
   		    long ans = palindromes(s, N);
            System.out.println(ans);
   		    
   		  
   		}   
	  
    }
}