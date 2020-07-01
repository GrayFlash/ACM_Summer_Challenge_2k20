import java.io.*;
import java.util.*;
class TestClass {
    static int max(int a, int b) 
    { 
        return (a > b) ? a : b; 
    } 
  
    static void knapSack(int W, int wt[], int val[], int n) 
    { 
        int i, w; 
        int min = 10000000;
        int K[][] = new int[n + 1][W + 1]; 
        int flag = 0;
        int max=0;
        for(int k=0; k<n; k++){
            int x = wt[k];
            wt[k] /= 2;
            for (i = 0; i <= n; i++) { 
                for (w = 0; w <= W; w++) { 
                    if (i == 0 || w == 0) 
                        K[i][w] = 0;
                    else if (wt[i - 1] <= w) 
                        K[i][w] = Math.max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
                    else
                        K[i][w] = K[i - 1][w]; 
                } 
            }
            if(K[n][W]>max) max = K[n][W];
            wt[k] = x;
        }
        System.out.println(max);
  
        // int res = K[n][W]; 
        // //System.out.println(res); 
  
        // w = W; 
        // int pos = 0;
        // int max_wt = 0;
        // int min_wt = 0;
        // int backtrack[] = new int[10000000];
        // for (i = n; i>0&&res>0 ; i--) {  
        //     if (res == K[i - 1][w]){
        //         backtrack[pos] = i-1;
        //         pos++;
        //     }
        //     else{ 
        //         if(val[i-1]<min) {
        //             min =val[i-1];
        //             min_wt = wt[i-1];
        //         }
        //         res -= val[i - 1]; 
        //         w-=wt[i-1]; 
        //         if(wt[i-1]>max_wt) max_wt=wt[i-1];
        //     } 
        // } 
        
        // if(res==0 && i>0){
        //     for(int loop=i; loop>0; loop--){
        //         backtrack[pos] = loop-1;
        //         pos++;
        //     }
        // }
        // max_wt++;
        //     int max = 0;
        //     int max_rem = -1;
        //     for(int loop=0; loop<pos; loop++){
        //         if(wt[backtrack[loop]]/2 <= w){
        //             if(max<val[backtrack[loop]]) max = val[backtrack[loop]];
        //         }
        //         else if(wt[backtrack[loop]] <= w+max_wt/2){
        //             if(max<val[backtrack[loop]]) max = val[backtrack[loop]];
        //         }
        //         else if(wt[backtrack[loop]]/2 <= w+min_wt ){
        //             if(max_rem < val[backtrack[loop]] && val[backtrack[loop]]>min){
        //                 max_rem = val[backtrack[loop]];
        //             }
        //         }
        //         else if(wt[backtrack[loop]] <= w+min_wt+max_wt/2 ){
        //             if(max_rem < val[backtrack[loop]] && val[backtrack[loop]]>min){
        //                 max_rem = val[backtrack[loop]];
        //             }
        //         }
        //     }
        //     if(max_rem-min<max)
        //     res += max;
        //     else
        //     res += max_rem-min;
        //     System.out.println(K[n][W]+res);
    } 
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        String s[] = br.readLine().split(" ");
        int N = Integer.parseInt(s[0]);
        int M = Integer.parseInt(s[1]);
        int pos = 0;
        int wt[] = new int[N+1];
        int val[] = new int[N+1];
        for(int i=0; i<N; i++){
            String s1[] = br.readLine().split(" ");
            char ch = s1[1].charAt(0);
            if(ch=='H') continue;
            wt[pos] = Integer.parseInt(s1[2]);
            val[pos] = Integer.parseInt(s1[3]);
            pos++;
        }
        knapSack(M, wt, val, pos);
    }
}