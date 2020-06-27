import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        int t = Integer.parseInt(br.readLine());
        while(t-->0){
            char c1;
            String s = br.readLine();
            int len = s.length();
            String s2="";
            int pos = 0;
            int i =0;
            String arr[] = new String[len+7];
            do{
                c1 = s.charAt(i);
                i++;
            }while(i<len && c1!='/');
            //System.out.println(i);
            int prev= 1;
            int ignore = 0;
            for(int j=i; j<len; j++){
                 c1 = s.charAt(j);
                if(prev==1 && ignore==0){
                    if(c1=='/'){
                        if(j!=(len-1)){
                            char c2 = s.charAt(j+1);
                            if(c2=='/'){
                                ignore = 1;
                                prev = 0;
                                s2="";
                                j++;
                            }
                        }
                        if(s2.length()==0){
                            ignore=1;
                            prev=0;
                        }
                        
                        else{
                            //System.out.println("test");
                            arr[pos] = s2;
                            s2="";
                            pos++;
                        }
                    }
                    else{
                        s2 = s2+c1;
                    }
                }
                else if(c1=='/'){
                    if(ignore==1){
                        ignore = 0;
                        prev= 1;
                    }
                    else if(s2.length()!=0){
                        //System.out.println("test2");
                        arr[pos] = s2;
                        s2 = "";
                        pos++;
                    }
                }
                    
            }
            System.out.println(pos);
            for(int j=0; j<pos; j++){
                System.out.println(arr[j]);
            }

        }

    }
}
