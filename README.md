# 13.1.1 Task 1
At the very begining, you need to do the following steps in the terminal.

(1) Souce ~/stat-pyenv
(2) cd STOR-601-env
(3) source ./start-environment 
 
## IS_STABLE function 
In the IS_STABLE function, the inputs is two maps representing the preference lists of all the husbands and wives and a another map representing a matching between them. The output is a string ("stable" or "unstable") and a dummy variable (0 or 1).

I created a source file "isstable.cpp" to write my IS_STABLE function and a header file 'isstable.h' for using this function in other files. Then I created the "main1.cpp" file in which I write my main function to test the IS_STABLE function. 

First, you need to compile the file "isstable.cpp" by running the following code in the terminal.

<pre>g++ --std=c++17 -c isstable.cpp</pre>

and then compile the "main1.cpp" by running

<pre>g++ --std=c++17 main1.cpp isstable.o -o main1.out</pre>

You can see the output of the main function by running

<pre>./main1.out</pre>

Then you will get the output.

<pre>Result for matching1: stable
Flag: 0
Result for matching2: unstable
Flag: 1
</pre>

If you want to use IS_STABLE function the files other than "isstable.cpp", you need to include 

<pre>#include "IS_STABLE.h"</pre>

in that file.

## Fundamental algorithm function 


I also write a source file "algorithm.cpp" and a header file "algorithm.h" for the fundamental algorithm function. Besides, I write the main function in file "main2.cpp" to test the function. Again, you need to run the following code to compile them. 

<pre>g++ --std=c++17 -c algorithm.cpp
g++ --std=c++17 main2.cpp algorithm.o -o main2.out
./main2.out</pre>

# 13.1.2 Task 2
I create a function called table_algorithm in the souce file "table_algorithm.cpp". In this function, the inputs are the names of two text files which are the preference lists of all the males and females, and we transfer them to unodered maps and then apply the fundamental algorithm to them. The output is still a stable matching which is an unordered map. Within the table_algorithm function, we also use IS_STABLE function to check if the matching produced by fundamental algorithm is stable. To run this function, you need to run the following code in your terminal:

<pre>g++ --std=c++17 -c table_algorithm.cpp
g++ -O3 --std=c++17 main3.cpp isstable.o algorithm.o table_algorithm.o -o main3.out
./main3.out</pre>

The output is given by

<pre>Result for matching: stable
Flag: 0
Algorithm Result:
a matches with B
b matches with C
c matches with D
d matches with A
</pre>

# 13.1.3 Task 3
In the main function, I run the fundamental algorithm n times. I set set the number of iterations to be $100000$ and then calculate the cumulative time of running fundamental algorithm for preference lists with varing sizes ranging from $2$ to $10$. I calculate the time using time function in the terminal as following.

<pre><font color="#26A269"><b>yangl35@vdi-stori-062</b></font>:<font color="#12488B"><b>~/STOR-601-env</b></font>$ g++ --std=c++17 main4.cpp algorithm.o table_algorithm.o -o main4.out
<font color="#26A269"><b>yangl35@vdi-stori-062</b></font>:<font color="#12488B"><b>~/STOR-601-env</b></font>$ time ./main4.out &quot;table1.txt&quot; &quot;table2.txt&quot; 100000
Algorithm Result:
a matches with B
b matches with C
c matches with D
d matches with A

real	0m2.548s
user	0m2.188s
sys	0m0.312s</pre>

So, the average time of running a single iteration is $2.548\times 10^{-5}$ seconds and that time in python is $4.324\times 10^{-4}$ which is lot more longer than that in c++. 

If we add -O3 to the g++ command, we get the following result.

<pre><font color="#26A269"><b>yangl35@vdi-stori-062</b></font>:<font color="#12488B"><b>~/STOR-601-env</b></font>$ g++ -O3 --std=c++17 main4.cpp algorithm.o table_algorithm.o -o main4.out
<font color="#26A269"><b>yangl35@vdi-stori-062</b></font>:<font color="#12488B"><b>~/STOR-601-env</b></font>$ time ./main4.out &quot;table1.txt&quot; &quot;table2.txt&quot; 100000
Algorithm Result:
a matches with B
b matches with C
c matches with D
d matches with A

real	0m2.385s
user	0m2.012s
sys	0m0.333s</pre>

Therefore, adding -O3 makes it faster to run the code.

# 13.1.5 Task 5




