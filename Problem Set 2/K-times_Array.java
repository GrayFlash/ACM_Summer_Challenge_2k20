import java.io.*;
import java.util.*;
import java.math.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        
        String s[] = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int K = Integer.parseInt(s[1]);
        long mod = Long.parseLong("1000000000");
        mod = mod +7;
        int arr[] = new int[N+7];
        int before[] = new int[N+7];
        int after[] = new int[N+7];
        String s1[] = br.readLine().split(" ");
        for(int i=0; i<N; i++){
            arr[i] = Integer.parseInt(s1[i]);
        }
        for(int i=0; i<N; i++){
            int count = 0;
            for(int j=0; j<i; j++){
                if(arr[j]<arr[i]){
                    count++;
                }
            }
            before[i] = count;
            count = 0;
            for(int j=i+1; j<N; j++){
                if(arr[j]<arr[i]){
                    count++;
                }
            }
            after[i] = count;
        }
        BigInteger response = new BigInteger("0");
        for(int i=0; i<N; i++){
            if(K==1){
                response = (response.add(BigInteger.valueOf(after[i]))).mod(BigInteger.valueOf(mod));
            }
            else{
                if(after[i]==0 && before[i]==0) continue;
                long a = ((long)after[i]*K)%mod + ((long)before[i]*(K-1))%mod;
                BigInteger x = ((BigInteger.valueOf(after[i])).multiply(BigInteger.valueOf(K)));
                BigInteger y = ((BigInteger.valueOf(before[i])).multiply(BigInteger.valueOf(K-1)));
                x = x.add(y);
                x = x.mod(BigInteger.valueOf(mod));
                long d = after[i] + before[i];
                BigInteger num = a.divide(BigInteger.valueOf(d));
                num = num.mod(BigInteger.valueOf(mod));
                d = d%mod;
                long temp1 = longValue(a.mod(BigInteger.valueOf(d))); 
                if(temp1>0){
                    num.add(BigInteger.valueOf(1));
                }
                response = (response.add( (num.multiply((a.multiply(2).subtract(d.multipy(num.subtract(BigInteger.valueOf(1))))))).divide(BigInteger.valueOf(2)) )).mod(BigInteger.valueOf(mod));

                System.out.println(a+" "+num+" "+response);
            }
        }
        System.out.println(response.mod(BigInteger.valueOf(mod)));
    }
}
