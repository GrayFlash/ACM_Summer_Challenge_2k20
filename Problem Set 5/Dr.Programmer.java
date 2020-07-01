import java.io.DataInputStream; 
import java.io.FileInputStream; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
import java.util.Arrays;
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
        int Q = sc.nextInt();
       //String s1[] = br.readLine().split(" ");
        //String s2[] = br.readLine().split(" ");
        long X[] = new long [N+7];
        long Y[] = new long [M+7];
        for(int i=0; i<N; i++){
            X[i] = sc.nextLong();
        }
        for(int i=0; i<M; i++){
            Y[i] = sc.nextLong();
        }
        Arrays.sort(X,0,N);
        Arrays.sort(Y,0,M);
        for(int i=0; i<Q; i++){
            int count = 0;
            //String s3[] = br.readLine().split(" ");
            long Z = sc.nextLong();
            char ch = (char)sc.read();
            
            if(ch=='A'){
                long ar[] = new long[N+7];
                int k = 0;
                long L1 = sc.nextLong();
                long R1 = sc.nextLong();
                if((L1+Y[0])>Z){
                    System.out.println("0");
                    continue;
                }
                //System.out.println(ch+" "+(i+1));
                for(int j=0; j<N; j++){
                    if(X[j]>=L1 && X[j]<=R1){
                        ar[k] = X[j];
                        k++;
                    }
                }
                int prev = 0;
                for(int j=k-1; j>=0; j--){
                    int Alpha = 0;
                    for(int l=prev; l<M; l++){
                        if(((long)Z)>=((long)ar[j] + (long)Y[l]) && l!=M-1){
                             Alpha = (j+1)*(l-prev+1);
                        } 
                        else if(((long)Z)>=((long)ar[j] + (long)Y[l]) && l==M-1){
                            Alpha = (j+1)*(l-prev+1);
                            prev = l+1;
                            count += Alpha;
                            break;
                        }
                        else{
                            prev = l;
                            count += Alpha;
                            break;
                        }
                    }
                }
            }
            else if(ch=='B'){
                long ar[] = new long[N+7];
                //System.out.println(ch+" "+(i+1));
                int k = 0;
                long L2 = sc.nextLong();
                long R2 = sc.nextLong();
                if((L2+X[0])>Z){
                    System.out.println("0");
                    continue;
                }
                
                for(int j=0; j<M; j++){
                    if(Y[j]>=L2 && Y[j]<=R2){
                        ar[k] = Y[j];
                        k++;
                    }
                }
                int prev = 0;
                for(int j=k-1; j>=0; j--){
                    int Alpha = 0;
                    for(int l=prev; l<N; l++){
                        if(((long)Z)>=((long)ar[j]+ (long)X[l]) && l!=N-1) {
                           Alpha = (j+1)*(l-prev+1);
                        }
                        else if(Z>=(ar[j]+X[l]) && l==N-1){
                             Alpha = (j+1)*(l-prev+1);
                             prev = l+1;
                             count += Alpha;
                             break;
                        }
                        else{
                            prev = l;
                            count += Alpha;
                            break;
                        }
                    }
                }
            }
            else if(ch=='C'){
                long L1 = sc.nextLong();
                long R1 = sc.nextLong();
                long L2 = sc.nextLong();
                long R2 = sc.nextLong();
                int k=0, l=0;
                if((L2+L1)>Z){
                    System.out.println("0");
                    continue;
                }
                long ar[] = new long[N+7];
                long brr[] = new long[M+7];
                for(int a=0; a<N; a++){
                    if(X[a]>=L1&&X[a]<=R1){
                        ar[k] = X[a];
                        k++;
                    }
                }
                for(int b=0; b<M; b++){
                    if(Y[b]>=L2&&Y[b]<=R2){
                        brr[l] = Y[b];
                        l++;
                    }
                }
                int prev = 0;
                for(int a=k-1; a>=0; a--){
                    int Alpha = 0;
                    for(int b=prev; b<l; b++){
                        if(Z>=(ar[a]+brr[b]) && b!=(l-1)) {
                            Alpha = (a+1)*(b+1-prev);
                        }
                        else if(b==(l-1) && Z>=(ar[a]+brr[b])){
                            Alpha = (a+1)*(b+1-prev);
                            count += Alpha;
                            //System.out.println(count+" 1 "+a+" "+b+" "+prev);
                            prev = b+1;
                            break;
                        }
                        else{
                            count = count + Alpha;
                            //System.out.println(count+" "+a+" "+b+" "+prev);
                            prev = b;
                            break;
                        }
                        
                    }
                }
            }
            System.out.println(count);
        }
       
    } 
} 