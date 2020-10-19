There are an army of  soldiers coming to attack on your kingdom . Army can be represented as matrix of size  ,
where each cell represents strength of soldier standing on that cell. But you have a special "lightning spell" by using it on a particular soldier ,
that soldier will kill (Strength become 0) all neighbouring soldier  having strength  less than him . 


Consider below example.
<ul>
<img src= "https://he-s3.s3.amazonaws.com/media/uploads/260cc328-ce04-464e-b61b-86bcc2dfd258.png"  width="200px" height="109px" />
</ul>
If you use lightning spell  on soldier having strength 12  then it will become
<ul>
<img src= "https://he-s3.s3.amazonaws.com/media/uploads/aea002ce-37e1-4e63-a09b-bc5b47939368.png"  width="200px" height="109px" />
<img src= "https://he-s3.s3.amazonaws.com/media/uploads/48a18dc2-5f0c-4718-bd41-0029c1ef0925.png"  width="200px" height="109px" />
</ul> 

If you use lightning spell  on soldier having strength 8  then it will become
<ul>
<img src= "https://he-s3.s3.amazonaws.com/media/uploads/79690227-ced0-4ba4-a872-9479c7649885.png"  width="200px" height="109px" />
<img src= "https://he-s3.s3.amazonaws.com/media/uploads/0af5eeba-ffdf-4df2-8faf-c255d23b0633.png"  width="200px" height="109px" />
</ul>
note than 12 is still present because 12>=8

You can use spell as many times you want
By using different sequence of spell , you will get different-different strength of soldiers
Your want to know what will be Minimum Sum of strengths of all soldiers .

#### INPUT:

The first line contains one integer T - the total number of test cases.

The first line of each test case contains two integer M,N -denoting size of army;

Next M lines of each test case contains N integers denoting stregnths of soldiers .

#### OUTPUT:

For each test case print one integer - Minimum Sum of strengths of all soldiers in new line.

<img src= "https://he-s3.s3.amazonaws.com/media/uploads/c043ddc9-04d8-4201-ad7e-15235b2b1894.png"  width="200px" height="109px" />

#### Constraints:

0 <= initial strength of a soldier <= 109

The total area of the matrices in one test does not exceed 106

#### SAMPLE INPUT 

  1       <br />
  3 3     <br />
  7 0 4   <br />
  0 8 3   <br />
  12 6 0  <br />

#### SAMPLE OUTPUT

  12

#### Explanation:

There are sevaral possible outcomes as below:
<ul>
<img src= "https://he-s3.s3.amazonaws.com/media/uploads/8b031dc6-6ed9-4317-aa6c-ced964eb701c.png"  width="200px" height="109px" />
<img src= "https://he-s3.s3.amazonaws.com/media/uploads/c043ddc9-04d8-4201-ad7e-15235b2b1894.png"  width="200px" height="109px" />
<img src= "https://he-s3.s3.amazonaws.com/media/uploads/4147f2d1-b5df-4636-87b8-ad11d85f993d.png"  width="200px" height="109px" />
</ul>

Out of all above you will get minimum sum as 12 for last one.

Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	6 MB
Source Limit:	1024 KB
