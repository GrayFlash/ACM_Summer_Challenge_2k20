import java.util.*;

class TestClass 
{
    public static void main(String[] args ) throws Exception 
{
       
	   Scanner sc=new Scanner(System.in);
	   int t = sc.nextInt();
	   for(int o=0;o<t;o++)                            
{
	   long n = sc.nextLong();
	   int m = sc.nextInt();
	   long sum=0;
	   int binary[] = new int[64];
	   for(int i=0;i<m;i++)                            
{
	   long temp = sc.nextLong();
	   sum=sum+temp;
	   binary[(int) (Math.log(temp)/Math.log(2))]++;
}
	   
	   String s = Long.toBinaryString(n);
	   char ch[] = new char[64];
	   int len = s.length();
	   for(int i=0;i<len;i++)                          
{
	   ch[len-i-1] = s.charAt(i);
}
	   for(int i=len;i<64;i++)
	   ch[i]='0';
	   
	   int ans=0;
	   if(sum<n)
	   ans = -1;
	   else
	   first: for(int i=0;i<64;i++)                     
{
	   if(ch[i]=='1')
{
	   if(binary[i]>=1)
{
	   binary[i]--;
	   continue first;
}
	   for(int j=0;j<i;j++)
{
	   binary[j+1] += binary[j]/2;
	   binary[j]%=2;
}
	   if(binary[i]>=1)
{
	   binary[i]--;
	   continue first;
}
	   int last = i;
	   for(int j=i+1;j<64;j++)
{
	   if(binary[j]>=1)
{
	   last = j;
	   break;
}
}
	   if(last==i)
{
	   ans = -1;
	   break first;
}
	   binary[last]--;
	   for(int j=i;j<last;j++)
	   binary[j]++;
	   ans+=last-i;
}
}
	   System.out.println(ans);
}

}
}