import java.io.*;
import java.util.*;
class TestClass {
    public static int max(int x, int y) 
    { 
        return (x>y)?x:y;
    } 
  
    public static int minCost(int arr[][], int N, int M) 
    { 
        int maximum = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j]>0){
                    if(i==0){
                        if(j==0){
                            continue;
                        }
                        else{
                            arr[i][j] += arr[i][j-1];
                        }
                    }
                    else{
                        if(j==0){
                            arr[i][j] += arr[i-1][j];
                        }
                        else{
                            arr[i][j] += max(arr[i-1][j], arr[i][j-1]);
                        }
                    }
                }
                else continue;
                maximum = max(maximum, arr[i][j]);
            }
        }
        
        
        return maximum; 
    } 
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        
        String s[] = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int M = Integer.parseInt(s[1]);
        int arr[][] = new int[N+1][M+1];
        for(int i=0; i<N; i++){
            String s1[] = br.readLine().split(" ");
            for(int j=0; j<M; j++){
                int x = Integer.parseInt(s1[j]);
                arr[i][j] = (x==1)? 0: 1;
            }
        }
        int max = minCost(arr, N, M);
        System.out.println(max);
    }
}
