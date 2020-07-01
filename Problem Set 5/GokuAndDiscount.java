import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        int N = Integer.parseInt(br.readLine());
        String s[] = br.readLine().split(" ");
        int ar[] = new int[N+7];
        for(int i=0; i<N; i++){
            ar[i] = Integer.parseInt(s[i]);
        }
        Arrays.sort(ar,0,N);
        long sum = 0, count=0;
        for(int i=0; i<N; i++){
            if(ar[i]>=sum){
                sum += ar[i];
            }
            else count++;
        }
        System.out.println(N-count);
    }
}
