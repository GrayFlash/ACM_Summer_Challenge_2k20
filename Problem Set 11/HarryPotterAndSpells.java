import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        int N = Integer.parseInt(br.readLine());
        String s[] = br.readLine().split(" ");
        long arr[] = new long[N+7];
        int negative = 0;
        int min = 1000000000;
        long sum = 0;
        for(int i=0; i<N; i++){
            arr[i] = Long.parseLong(s[i]);
            if(arr[i]<0) negative++;
            int num = (int)Math.abs(arr[i] + 0);
            if(num<min) min = num;
            sum += num;
        }
        
        if(negative%2==1){
            sum -= 2*min;
        }
        System.out.println(sum);
        
    }
}
