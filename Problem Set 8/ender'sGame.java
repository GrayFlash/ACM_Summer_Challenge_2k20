import java.io.DataInputStream; 
import java.io.FileInputStream; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
import java.util.HashMap;
import java.util.Map;
import java.math.BigInteger;
public class Main 
{ 
    static class Reader 
    { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; // line length 
            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    } 
  
    public static void main(String[] args) throws IOException 
    { 
        Reader sc=new Reader(); 
        int T = sc.nextInt(); 
        while(T-->0){
            //HashMap <Integer, Integer> hm = new HashMap <> ();
            int N = sc.nextInt();
            int arr[] = new int[N+7];
            int brr[] = new int[N+7];
            String boxes[] = new String[101];
            for(int i=0; i<101; i++){
                boxes[i] = "";
            }
            for(int i=0; i<N; i++){
                arr[i] = sc.nextInt();
                boxes[arr[i]] = boxes[arr[i]] + " "+ i;
            }
            for(int i=0; i<N; i++){
                brr[i] = sc.nextInt();
            }
            int steps = 1;
            int pos = 0;
            int Flag = 0;
            for(int i=0; i<N; i++){
                int find = brr[i];
                String X_t[] = boxes[find].split(" ");
                int l = X_t.length;
                int search[] = new int[l];
                for(int j=1; j<l; j++){
                    search[j] = Integer.parseInt(X_t[j]);
                    //System.out.print(search[j]+" ");
                }
                //System.out.println();
                if(l<=1){
                    Flag = 1;
                    break;
                }
                if(pos>=search[l-1]){
                    pos = search[1];
                    //System.out.println("Step up"+pos+" "+search[l-1]);
                    steps++;
                    continue;
                }
                for(int j=1; j<l; j++){
                    if(pos<search[j]){
                        pos=search[j];
                        break;
                    }
                }
            }
            if(Flag==1) System.out.println("-10099");
            else System.out.println(steps);
        }
    } 
} 