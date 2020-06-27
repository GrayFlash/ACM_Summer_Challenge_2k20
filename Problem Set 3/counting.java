import java.io.*;
import java.util.*;
class TestClass {
    public static long calc(int pos, int n){
        long ans = (long)(n-pos)*(pos+1);
        return ans;
    }
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        int t = Integer.parseInt(br.readLine());
        while(t-->0){
            int n = Integer.parseInt(br.readLine());
            String s = br.readLine();
            s = s.toLowerCase();
            long sum = 0;
            for(int i=0; i<n; i++){
                char ch = s.charAt(i);
                if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
                    long ti = calc(i,n);
                    sum = (long)sum + (long)ti;
                }
            }
            String res = Long.toUnsignedString(sum);
            System.out.println(res);
        }

    }
}
