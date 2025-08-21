#### <span style="color:rgb(255, 0, 0)">Big Θ(theta) notation</span> 

The Theta Notation encloses the function from above and below. It is basically a mix of the Big O and Big Omega notations. Since <span style="color:rgb(146, 208, 80)">it represents the upper and lower bound of the running time of an algorithm, it is used for analyzing the average-case complexity of an algorithm.</span>

#### <span style="color:rgb(145, 215, 232)">Formal definition</span>

```
Let g and f be non negative functions. The function f is said to be Θ(g), if there are constants c1,c2 > 0 and n0(input) such that 

0 <= c1* g(n) <= f(n) <= c2 * g(n) for all n>= n0

Note that f(n) = Θ(g(n)) -> Θ(g(n)) is a set of functions

```

<span style="color:rgb(255, 192, 0)">This formal definition means that, if f(n) is Big theta of g(n) then, the value f(n) is always between c1 * g(n) and c2 * g(n) for large values of n(n >= n0).</span>

![[Pasted image 20250812130859.png]]

To compute the theta notation, we must follow the next steps:

1. **Break the program into smaller segments**

2. **Find all types of inputs and their number and calculate their number of operations they take to be executed**

3. **Find the sum of all the calculated values and divide the sum by the total number of inputs**

#### <span style="color:rgb(145, 215, 232)">Example</span>

We consider as an example a linear seach of an array to determine if there is a specific key located within it. We search the array linearly and analyze if the element we are in is the one we are looking for.

```cpp
#include <bits/stdc++.h>
using namespace std;
bool linearSearch(int a[],int n, int key){
	for(int i = 0; i < n; i++){ //n
		if(a[i] == key){ //c2
			return true; //c1
			}
	}
	return false; //c3
}

int main()
{
	int arr[] = { 2, 3, 4, 10, 40 }; // c4
	int x = 10; // c5
	int n = sizeof(arr) / sizeof(arr[0]); // c6
	if(linearSearch(arr,n,x)){
		cout << "Element is present in the array"; // c7
	}else{
		cout << "Element is not present in array";

	return 0; // c8
	}
}

--------------------------------------------------------------------------------
f(n) = (c1 + c2) * n + c3 + c4 + c5+ c6 + c7 + c8 = c9 * n + c10 -> O(n)

We now assume that all the cases are identically distributed. We sum all the cases( when the key is found on the positions 0, 1, 2) and then we divide by
n + 1 to compute the average leading to the image shown below.

```

We divide by n + 1 because we have the n cases of the number we are looking for being in one of the keys of the array and an extra case regarding the array being empty.

We need to use the following formula:

![[Pasted image 20250812133027.png]]


**HOW TO OBTAIN THE PREVIOSULY SHOWN**

![[Pasted image 20250812134450.png]]
For our case we can do the previous simplification following the next steps(second inequation is the definition of big theta):


![[Pasted image 20250812134608.png]]

Knowing the previous reasoning we can continue

![[Pasted image 20250812134128.png]]

<span style="color:rgb(0, 176, 240)">Finally, if we remove the simplify -> Θ(n/2 + 1) = Θ(n) After removing constants and non highest terms.</span> 


#### <span style="color:rgb(0, 176, 240)">Example 2</span> 

Prove that 1/2 n² - 3n = Θ(n²)

By using the formal definition, we need to ensure that:

c1n² <= 1/2n² -3n <= c2n² 

<span style="color:rgb(145, 215, 232)">Dividing by n² we obtain:
c1 <= 1/2 - 3/n <= c2</span>

<span style="color:rgb(145, 215, 232)">we can choose c2 >=1/2 for any value of n>= 1 and</span>

<span style="color:rgb(145, 215, 232)">1/2 - 3/7 = 7/14 - 6/14 = 1/14(n = 7) As a result,</span> c1 <= 1/14 for n>= 7

Therefore, we can verify that  1/2 n² - 3n = Θ(n²) as we have found constants c1 and c2 meeting the definition.
![[Pasted image 20250814185452.png]]

Because the function increases we can take a given value of n and obtain its constant c and it is going to be valid for higher n's starting from that one