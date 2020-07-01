import java.io.*;
import java.util.*;
class TestClass {
    public static void main(String args[] ) throws Exception {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        // Write your code here
        int T = Integer.parseInt(br.readLine());
        while(T-->0){
            String s = br.readLine();
            int l = s.length();
            int prev = 0;
            Stack <Character> stack = new Stack<Character>();
            stack.add(' ');
            int flag = 1;
            for(int i=0; i<l; i++){
                char c1 = s.charAt(i);
                char c2 = stack.peek();
                if(c1=='{'){
                    stack.push(c1);
                }
                else if(c1=='1'){
                    if(c2!='{'){
                        flag = 0;
                        break;
                    }
                    stack.push(c1);
                }
                else{
                    if(c2!='1'){
                        flag = 0;
                        break;
                    }
                    stack.pop();
                    c2 = stack.peek();
                    if(c2!='{'){
                        flag = 0;
                        break;
                    }
                    stack.pop();
                }
            }
            if(flag==0|| stack.peek()!=' ')System.out.println("No");
            else System.out.println("Yes");
        }
    }
}
