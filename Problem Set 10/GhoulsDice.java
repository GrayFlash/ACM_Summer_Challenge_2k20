import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        int T = Integer.parseInt(br.readLine());
        while(T-->0){
            long N = Long.parseLong(br.readLine());
            if(N<20){
                System.out.println("NO");
            }
            else{
                long a = N-20;
                long start = 21;
                int flag = 0;
                while(start<=26){
                    if(a==0 || a%18==0){
                        flag = 1;
                        break;
                    }
                    a = N-start;
                    start++;
                }
                if(flag==1) System.out.println("YES");
                else System.out.println("NO");
            }
        }

    }
}
