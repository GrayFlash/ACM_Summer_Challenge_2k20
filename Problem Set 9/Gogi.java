import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        int T = Integer.parseInt(br.readLine());
        //int T = sc.nextInt(); 
        while(T-->0){
            int N = Integer.parseInt(br.readLine());
            String arr[] = new String[N+7];
            for(int i=0; i<N; i++){
                arr[i] = br.readLine();
            }
            int ans = 0;
            int occur[][] = new int[N+7][26];
            for(int i=0; i<N; i++){
                String s = arr[i];
                int l1 = s.length();
                for(int j=0; j<l1; j++){
                    char c1 = s.charAt(j);
                    occur[i][c1-97]++;
                }
            }
            for(int i=0; i<N; i++){
                int l1 = arr[i].length();
                String s1 = arr[i];
                for(int j=i+1; j<N; j++){
                    String s2 = arr[j];
                    int k = 0;
                    int l2 = s2.length();
                    for(k=0; k<26; k++){
                        if(occur[i][k]>=1 && occur[j][k]>=1) break;
                    }
                    if(k==26){
                        int temp = l1*l2;
                        if(temp>ans) ans = temp;
                    }
                }
            }
            System.out.println(ans);
        }

    }
}
