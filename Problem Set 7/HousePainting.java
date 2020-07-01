import java.io.DataInputStream; 
import java.io.FileInputStream; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
  
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
        
        
        int N = sc.nextInt(); 
        int M = sc.nextInt(); 
        int K = sc.nextInt(); 
        int color[][] = new int[N+7][M+7];
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                color[i][j] = 0;
            }
        }
        int row[][]= new int [N+7][2];
        int col[][]= new int [M+7][2];
        for(int i=0; i<N; i++){
            row[i][0] = 0;
            row[i][1] = 0;
        }
        for(int i=0; i<M; i++){
            col[i][0] = 0;
            col[i][1] = 0;
        }
        for(int k=0; k<K; k++){
        
            int choice  = sc.nextInt(); 
            int block = sc.nextInt(); 
            int A = sc.nextInt(); 
            if(choice==1){
                row[block-1][0]=A;
                row[block-1][1]=k+1;
            }
            else if(choice==2){
                col[block-1][0]=A;
                col[block-1][1]= k+1;
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(col[j][1]>row[i][1]){
                    color[i][j]=col[j][0];
                }
                else if(col[j][1]<row[i][1]){
                    color[i][j]=row[i][0];
                }
                
                System.out.print(color[i][j]+" ");

            }
            System.out.println("");
        }
    } 
} 