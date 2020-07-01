import java.io.DataInputStream; 
import java.io.FileInputStream; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
import java.util.Arrays;
import java.util.*;
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
        int n = sc.nextInt();
        int arr[] = new int[n+7];
        int pos=0, pos2=0,pos3=0;
        int threes[] = new int[n+7];
        int twos[] = new int[n+7];
        int rest[] = new int[n+7];
        Map< Integer,Integer> hm =  new HashMap< Integer,Integer>(); 
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
            if(hm.containsKey(arr[i])){
                i--;
                n--;
            }
            else{
                hm.put(arr[i],1);
            }
        }
        for(int i=0; i<n; i++){
            if(arr[i]%3==0){
                threes[pos] = arr[i];
                pos++;
            }
            else if(arr[i]%2==0){
                twos[pos2] = arr[i];
                pos2++;
            }
            else{
                rest[pos3] = arr[i];
                pos3++;
            }
        }
        Arrays.sort(threes,0,pos);
        Arrays.sort(twos,0,pos2);
        Arrays.sort(rest,0,pos3);
        Arrays.sort(arr,0,n);
        int A=0, B=0, T=0;
        for(int i=0; i<pos; i++){
            if(arr[i]==threes[i])T++;
            else if(arr[i]>threes[i])B++;
            else A++;
        }
        for(int i=0; i<pos2; i++){
            if(arr[i+pos]==twos[i])T++;
            else if(arr[i+pos]>twos[i])B++;
            else A++;
        }
        for(int i=0; i<pos3; i++){
            if(arr[i+pos+pos2]==rest[i])T++;
            else if(arr[i+pos+pos2]>rest[i])B++;
            else A++;
        }
       System.out.println(A+" "+B+ " " + T);
    } 
} 