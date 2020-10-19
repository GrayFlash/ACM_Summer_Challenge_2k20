>NOTE: Consider A_i as A subscript i.

Raven gave an array of N integers A = A_0, A_1, A_2, ..., A_{N-1} to mortal for amazing gameplay in PMPL-Finals.

Mortal has a machine that makes an array B which is obtained by concatenating K copies of A. For example, A = 1,5,3,7 and k = 2, B = 1,5,3,7,1,5,3,7

Find the number of ordered pairs in an array B of integers (i , j) (0 <= i < j <= (KxN)-1) such that B_i > B_j modulo 10^9 + 7 .

#### INPUT:

First-line contains N and K.

Second-line contains N space-separated integers A = A_0, A_1, A_2, ..., A_{N-1}.

#### OUTPUT:

Print the answer to the given problem modulo 10^9 + 7.

#### Constraints:

1 <= N <= 2000    <br />
1 <= K <= 10^9    <br />
1 <= A_i <= 2000  <br />



#### SAMPLE INPUT 

2 2<br />
2 1<br />

#### SAMPLE OUTPUT

3

#### Explanxation
In this case, B = 2,1,2,1. We have:
<ul>
  <li> B_0 > B_1    </li>
  <li> B_0 > B_3    </li>
  <li> B_2 > B_3    </li>
</ul>
Thus, the answer is 3.

<br>Time Limit:	1.0 sec(s) for each input file.<br />
Memory Limit:	256 MB<br />
Source Limit:	1024 KB
