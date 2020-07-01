import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        long mod = 1000000007;
        int T = Integer.parseInt(br.readLine());
        while(T-->0){
            int N = Integer.parseInt(br.readLine());
            if(N<10){
                System.out.println("-1");
                continue;
            }
            if(N==10){
                System.out.println("1");
                continue;
            }
            int alpha[] = new int[101];
            int X = N/10;
            int rem = N%10;
            long product = 1;
            for(int i=0; i<10-rem; i++){
                product = ((long)(product%mod)*(X%mod))%mod;
            }
            for(int i=0; i<rem; i++){
                product = ((long)(product%mod)*((X+1)%mod))%mod;
            }
            System.out.println(product%mod);
        }

    }
}
