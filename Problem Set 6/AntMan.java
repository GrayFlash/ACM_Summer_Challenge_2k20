import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        int N = Integer.parseInt(br.readLine());
        String s1[] = br.readLine().split(" ");
        String s2[] = br.readLine().split(" ");
        int arr[] = new int[N+7];
        int brr[] = new int[N+7];
        Queue<Integer> q1 = new LinkedList<>(); 
        Queue<Integer> q2 = new LinkedList<>(); 
        for(int i=0; i<N; i++){
            arr[i] = Integer.parseInt(s1[i]);
            brr[i] = Integer.parseInt(s2[i]);
            q1.add(arr[i]);
            q2.add(brr[i]);
        }
        int count  = 0;
        Map< Integer,Integer> mp =  new HashMap< Integer,Integer>(); 
        for(int i=0; i<N; i++){
            int a = q1.peek();
            q1.remove();
            //int b = q2.peek();
            if(mp.containsKey(a)){
                //System.out.println("Map");
                mp.remove(a);
                continue;
            }
            int b = q2.peek();
            while(a!=b){
                mp.put(b,1);
                q2.remove();
                //System.out.println(a+" "+b);
                count++;
                b= q2.peek();
            }
            q2.remove();
        }
        System.out.println(count);

    }
}
