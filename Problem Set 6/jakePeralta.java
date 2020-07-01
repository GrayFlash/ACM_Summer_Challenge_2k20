import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        String s = br.readLine();
        String P="",ans="";
        int len = s.length();
        int i=0;int j=0;
        int arr[]= new int[26];int brr[]=new int[26];int a=0;int pointer=0;
        for(i=0;i<26;i++){
            arr[i]=0;brr[i]=0;}
        for(i=0;i<len;i++)arr[s.charAt(i)-97]++;
        for(i=0;i<len;i++){
            char c1 =s.charAt(i);
            for(j=0;j<(c1-97);j++)if(arr[j]>0)break;
            if(pointer>0 && P.charAt(pointer-1)<=(j+97)){
                ans=ans+P.charAt(pointer-1);
                pointer--;
                brr[c1-97]--;
                i--;
            }
            else if(j==(c1-97)){
                arr[j]--;
                ans=ans+c1;
            }else{
                P=P+c1;
                pointer++;
                arr[c1-97]--;
                brr[c1-97]++;
            }
            
        }
        for(i=0;i<pointer;i++){
            ans = ans+ P.charAt(pointer-i-1);
        }
            System.out.println(ans);
        }
}
