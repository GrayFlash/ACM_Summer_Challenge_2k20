import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        int T = Integer.parseInt(br.readLine());
        while(T-->0){
            String s[] = br.readLine().split(" ");
            int N = Integer.parseInt(s[0]);
            int M = Integer.parseInt(s[1]);
            int arr[][] = new int[N+7][M+7];
            //long sum[] = new long[N*M + 7];
            long total = 0;
            int max = 0;
            for(int i=0; i<N; i++){
                String s2[] = br.readLine().split(" ");
                for(int j=0; j<M; j++){
                    arr[i][j] = Integer.parseInt(s2[j]);
                }
            }
            int pos=0;
            long sum = 0;
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    int flag=0;
                    for(int k=0; k<3; k++){
                        for(int l=0; l<3; l++){
                            if((i-1+k)<0 || (j-1+l)<0 || (i-1+k)>=N || (j-1+l)>=M ) continue;
                            if(arr[i-1+k][j-1+l] > arr[i][j]){
                                flag = 1;
                            }
                        }
                    }
                    //System.out.println(flag);
                    if(flag==1) continue;
                    sum += arr[i][j];
                }
            }
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    total += arr[i][j];
                    //if(arr[i][j]>max) max = arr[i][j];
                }
            }
            //System.out.println(total);
            System.out.println(sum);

        }
       

    }
}
