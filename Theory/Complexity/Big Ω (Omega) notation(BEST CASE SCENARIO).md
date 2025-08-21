#### <span style="color:rgb(255, 0, 0)">Big Ω (Omega) notation</span>

The big-Omega notation is a way to <span style="color:rgb(146, 208, 80)">express the asymptotic lower bound of an algorithm's time complexity</span>, since<span style="color:rgb(146, 208, 80)"> it analyzes the best-case scenario of a given algorithm</span>.

It provides a <span style="color:rgb(146, 208, 80)">lower limit on the time taken by an algorithm in terms of the size of the input.</span> 

It is denoted as **Ω(f(n))** where f(n) is a function that represents the **number of operations(steps) that the algorithm requires to solve a problem of size n.**

<span style="color:rgb(146, 208, 80)">The Big-Omega notation is used when we need to find this lower bound so that we want to express that the algorithm will take AT LEAST that amount of time.</span>

<span style="color:rgb(255, 192, 0)">NOT GENERALLY USEFUL</span>

#### <span style="color:rgb(145, 215, 232)">Formal definition</span>


```Given two functions g(n) and f(n), we say that f(n) = Ω(g(n)) if there exists constants c > 0 and n0 >= 0 such that f(n) >= c*g(n) for all n >=n0.```

<span style="color:rgb(255, 192, 0)">In simpler terms, f(n) is Ω(g(n)) if f(n) will always grow faster than c * g(n) for all n >= n0 where c and n0 are constants.</span>

<span style="color:rgb(0, 176, 240)">Provided with an expression the following steps must be followed:</span>

1. **Break the program into smaller segments**
	* Divide the program into the different parts such that each part has its own runtime complexity
	
2. **Find the complexity of each segment**
	* Find the number of operations performed for each segment(in terms of the input size) assuming the given input in such that the program takes the least amount of time.
	
3. **Add the complexity of all the segments**
	* Add up all the operations and simplify it. Let's consider the result yielded f(n).
	
4. **Remove all the constants**
	* Remove all the constants and choose the term having the least order or any other function which is always less than f(n) where n tends to infinity. Let's say the least order function is g(n), then, Big-Omega(Ω) of f(n) = Ω(g(n))

#### <span style="color:rgb(145, 215, 232)">Example</span>

We are going to consider the following fragment of code which prints all the pairs of elements of the array:

```cpp
using namespace std;

int print(int a[],int n){

	for(int i = 0; i< n; i++){
		for(int j = 0; j < n < j++){
			if(i != j){
				cout<< a[i] << " " << a[j] << "\n";
			}
			}

	}


}

int main(){

	int a[] = { 1, 2, 3 };

	// We compute the number of elements of the array
    int n = sizeof(a) / sizeof(a[0]);
	print(a, n);

	return 0;
}

```

In this example, for an input size of n we would always traverse thorugh the array leading to a time complexity of n².

```cpp
f(n) = n * n *(2) + 1 + 1 + 1 = 2n² + 3 -> O(n²)
```

As the worst case scenario is n² which matches the best case as well, we can take as lower bound  any function below it. As a result , we could say that:

```cpp 
f(n) = Ω(log(n)) or Ω(n) or Ω(1)
```


This notation is typically not used because it is true that it is correct but at the same time it is imprecise as it does not give us a real approximate on how much time the algorithm will actually take.


