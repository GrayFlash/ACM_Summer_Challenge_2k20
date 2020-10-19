Monica entered a cleanliness competition. The competition lasts for n minutes. She can clean Ai items during the i-th minute.</br>
Monica is really good at cleaning, though it is so hard to stay awake for all the time of competition. You are given an array S of Monica's behaviour. If Monica is asleep during the i-th minute of the competition then  Si  will be equal to 0, otherwise, it will be equal to 1. When Monica is awake she cleans all the objects she can clean during i-th minute— Ai. Otherwise, she cleans nothing during that minute.</br>
You know some secret technique to keep Monica awake for k minutes straight. However, you can use it only once. You can start using it at the beginning of any minute between 1 and n - k + 1. If you use it on some minute i then Monica will be awake during minutes j such that <img src="https://espresso.codeforces.com/15d5dec74ccf16318a73dd7d12aa4c54762f9044.png"/> and will clean all the objects she can clean during each minute of the time interval.</br>
Your task is to calculate the maximum number of objects Monica will be able to clean if you use your technique only once to wake her up.

#### Input

The first line of the input contains two integer numbers n and k (1 ≤ k ≤ n ≤ 105) — the duration of the competition in minutes and the number of minutes you can keep Monica awake.</br>
The second line of the input contains n integer numbers A1, A2, ... An (1 ≤ Ai ≤ 104) — the number of objects she can clean during the i-th minute.</br>
The third line of the input contains n integer numbers S1, S2, ... Sn (0 ≤ Si ≤ 1) — the type of Monica's behaviour at the i-th minute of the lecture.

#### Output

Print only one integer — the maximum number of objects Monica will be able to clean if you use your technique only once to wake her up.

#### SAMPLE INPUT 
6 3          </br>
1 3 5 2 5 4  </br>
1 1 0 1 0 0  </br>
#### SAMPLE OUTPUT 
16

Time Limit:	1.0 sec(s) for each input file. </br>
Memory Limit:	256 MB  </br>
Source Limit:	1024 KB  </br>
