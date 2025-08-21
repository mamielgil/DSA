## <span style="color:rgb(255, 0, 0)">Big O notation</span>


- <span style="color:rgb(146, 208, 80)">The </span>**<span style="color:rgb(146, 208, 80)">b</span><span style="color:rgb(146, 208, 80)">ig O notation</span>** <span style="color:rgb(146, 208, 80)">describes the asymptotic behaviour, that is, the order of growth of time or space in terms of input size of a function, not its exact value.</span>

-  <span style="color:rgb(146, 208, 80)">It is denoted as O(f(n)) where f(n) is a function that represents the number of operations that an algorithm performs to solve a problem of size n.</span>


This means that for example: printing all the values from an array could be described as O(N²), it could also be described as O(N²), O(N³), O(2^n) or other big O times(bigger than O(n)). All of then would correspond to upper bounds for the algoritm.
<span style="color:rgb(255, 192, 0)"> Nevertheless, we use the lowest upper bound possible so we indicate in the most precise way its actual performance.</span>

	This way,if Mark is x years old and it is assumed that no ones lives past 130 years old, then, we could say: x<= 130. However, it would also be correct to say that x<= 1,000 or x<= 1,000,000.

#### <span style="color:rgb(145, 215, 232)">Formal definition</span>

```Given two functions f(n) and g(n), we say that f(n) is O(g(n)) if there exists constants c > 0 and n1 >= 0 such that f(n) <= c*g(n) for all n >= n1```

<span style="color:rgb(0, 176, 240)">Provided with an expression, the steps that would be followed would be:</span>

1. **Ignore the lower terms and consider only the highest term**
2. **Ignore the constant associated with the highest order term.**

<span style="color:rgb(145, 215, 232)">Examples</span>

f(n) = 3n² + 2n + 1000log(n) + 5000

Following the steps:
1. Highest order term -> 3n²
2.  Ignore the constant -> n²
As a result,  O(n²)

f(n) = 3n³ + 2n² + 5n + 1
Following the steps:
1. Highest order term -> 3n³
2. Ignore the constant -> n³
As a result, O(n³)

### <span style="color:rgb(145, 215, 232)">Properties</span>

##### Reflexivity

For any function f(n):
```f(n) = O(f(n))```

<span style="color:rgb(255, 192, 0)">If f(n) = n² then f(n) = O(n²)</span>

#### Transitivity

Given two function f(n) and g(n):
```If f(n) = O(g(n)) and g(n) = O(h(n)) then f(n) = O(h(n))```

<span style="color:rgb(255, 192, 0)">If f(n) = n², g(n) = n³ and h(n) = n⁴ then f(n) = O(g(n)) and g(n) = O(h(n))
Therefore, by transitivity-> f(n) = O(h(n))</span>

#### Constant factor

```For any constant c > 0 and functions f(n) and g(n), if f(n) = O(g(n)), then cf(n) = O(g(n))```

This means that if the original function was big O "something" then despite being multiplied by a constant it will still be big o that someting.

<span style="color:rgb(255, 192, 0)">
f(n) = n, g(n) = n². Then f(n) = O(g(n)). Therefore, 2f(n) = O(g(n))</span>

#### Sum rule

```If f(n) = O(g(n)) and h(n) = O(k(n)) then f(n) + h(n) = O(max(g(n), k(n)) When combining complexities, only the largest term dominates.```

<span style="color:rgb(255, 192, 0)">f(n) = n², h(n) = n³. Then f(n) + h(n) = O(max(n² , n³)= O(n³)</span>

#### Product rule

```If f(n) = O(g(n)) and h(n) = O(k(n)) then f(n) * h(n) ? O(g(n) * k(n))```

<span style="color:rgb(255, 192, 0)">f(n) = n, g(n) = n², h(n) = n³,, k(n) = n⁴. Then f(n) = O(g(n)) and h(n) = O(k(n)). Therefore, f(n) * h(n) = O(g(n) * k(n)) = O(n⁶)</span>

#### Composition rule

```If f(n) = O(g(n)) and g(n) = O(h(n)), then f(g(n)) = O(h(n))```

<span style="color:rgb(255, 192, 0)">f(n) = n, g(n) = n², h(n) = n³. Then f(n) = O(g(n)) and g(n) = O(h(n)). Therefore, f(g(n)) = O(h(n)) = O(n³)</span>

### <span style="color:rgb(145, 215, 232)">Common big O notations</span>

1. <span style="color:rgb(0, 176, 240)">Linear Time Complexity: Big O(n) </span>
Linear time complexity means that the running time of an algorithm grows linearly with the size of the input.

For example consider an algorithm that looks for a specific element in an array
```cpp
bool findElement(int arr[], int n, int key){

for (int i = 0; i < n; i++){

if(arr[i] == key){ // 1
	return true; // 1
	}
}
return false; // 1
}
---------------------------------------------------------------------------------
f(n) = (1 + 1) * n + 1 = 2n + 1 --> As a result, O(n)
```

2.<span style="color:rgb(0, 176, 240)"> Logarithmic Time Complexity: Big O(log n)</span>
Logarithmic time complexity means that the running time of an algorithm is proportional to the logarithm of the input size.

For example, a binary search algorithm has a logarithmic time complexity

```cpp

int binarySearch(int arr[], int l, int r, int x){

if( r >= l){
	int mid = l +(r - 1) / 2; // 1
	if(arr[mid] == x){ // 1
	return mid; // 1
	}
	if(arr[mid] > x){ // 1
	return binarySearch(arr[],int l ,int mid + 1, int x); // f(n/2)
	}

	return binarySearch(arr[], int mid + 1, int r, int x); //f(n/2)


}
return -1; // 1
}

---------------------------------------------------------------------------------
f(n) = 1 + f(n/2) AHORA SEGUIMOS DESAROLLANDO

f(n) = 1+ 1 + f(n/4)

f(n) = 1 + 1 + 1 + f(n/8)

As a result, we observe that there is a pattern that is followed

f(k) = k + f(n/2^k)
IF WE CONSIDER TO HAVE REACHED THE BASE CASE:
n/ 2^k = 1 meaning that we have found our element

n = 2^k --> k = log2(n) We need to clear for k as it corresponds to the number of times the algorithms executes

```

3. <span style="color:rgb(0, 176, 240)">Quadratic Time Complexity: Big O(n²)</span>
Quadratic time complexity means that the running time of an algorithm is proportional to the square of the input size.

For example, a bubble sort algorithm has a quadratic time complexity:

```cpp
void bubbleSort(int arr[], int n)
{
for(int i = 0; i < n - 1; i++){ // n
	for(int j = 0; j < n - i - 1 ; j++){ // worst case n
		(if(arr[j]) > arr[j + 1]){ // 1
			swap(&arr[j],&arr[j + 1]); // 1 asumming swap is atomic
			}
	}
}

}
---------------------------------------------------------------------------------
f(n) = n * 2n = 2n² --> As a result, O(n²)

```

4. <span style="color:rgb(0, 176, 240)">Cubic time complexity</span>
Cubic time complexity means that the running time of an algogorithm is proportional to the cube of the input size.

For example, a naive square matrix multiplication

```cpp
void(int mat1[][N], mat2[][N], res[][N])
for (int i = 0; i < N; i ++){ // n
	for(int j = 0; j < N; j ++){ // n
		res[i][j] = 0; // 1
	
	for(int k = 0; k < N; k++){ // n
		res[i][j] += mat1[i][k] * mat2[k][j]; // 1
		}
	}
}
---------------------------------------------------------------------------------
f(n) = n * n * n = n³ --> As a result, O(n³)
```

<span style="color:rgb(255, 0, 0)">ALL THE PREVIOUSLY MENTIONED ARE THOSE ONES THAT ARE KNOWN AS POLYNOMIAL TIMES. THEY ARE GENERALLY CONSIDERED EFFICIENTAS THE RUNNING TIME GROWS AT A REASONABLE RATE AS THE INPUT SIZE INCREASES.</span> 

 5. <span style="color:rgb(0, 176, 240)">Expontential Time Complexity: Big O(2^n) Complexity</span> 
 Exponential time complexity means that the running time of an algorithm doubles with each additoin to the input data set. 
 
 For example, the problem of generating all subsets of a set is of exponential time.
 
```cpp
void generate Subsets(int arr[], int n)
{
using namespace std;

for(int i = 0; i < (1 <<n); i++){ // 2^n
	for(int j = 0;j < n; j++){ // n
	if(i & (1 << j)){ // 1
	cout << arr[j] << " "; // 1
	}
}
}
cout << "\n"; // 1

}
---------------------------------------------------------------------------------
f(n) = 2^n* 2n + 1 = 2n * 2^n + 1 -> As a result, following the rules -> O(2^n)
```

6. <span style="color:rgb(0, 176, 240)">Factorial Time Complexity: Big O(n!) Complexity</span>
Factorial time complexity means that the running time of an algorithm grows factorially with the size of the input. This is often seen in algorithms that generate permutations of a set of data.

For example, an algorithm that generates all the permutations of an array:

```cpp
void permute(int* a, int l, int r){

using namespace std;
if( l== r){
for(int i = 0; i <= r; i++){ // r
	cout << a[i] << " "; // 1
}
	cout << endl; // 1
}
else{
	for(int i = l; i<= r; i++){ // r
	swap(a[l],a[i]); // 1
	permute(a,l + 1, r); // 1
	swap(a[l], a[i]); 1 //backtrack
	}

}
}
---------------------------------------------------------------------------------
We really notice that by increasing l by 1 we are increasing l upwards until reaching the same value of n that it is when it stops
f(n) = (2 + f(n - 1) )* r = 2r + r *f(n-1)
f(n) = 2r + r *(r-1) *(2 + f(n-2)) = 2r + r * (r-1)* f(n-2) + r *(r-1)* 2 = 
2r + r(r-1)f(n-2) + 2r² - 2r =
r(r-1) f(n-2) + 2r²

f(n) = r(r-1)(r-2)*(2 + f(n-3)) + 2r² = r(r-1)(r-2)*2 + r(r-1)(r-2)f(n-3) =
2 r² + (r² + r) * (r-2) * 2 + r(r-1)(r-2) f(n-3) = 2r² + (r³ -2r² + r² + 2r) * 2 +  r(r-1)(r-2) f(n-3)
 r(r-1)(r-2) f(n-3) = 2r² + 2r³  -4r² + 2r² + 4r +  r(r-1)(r-2) f(n-3) = 
 2r³ + 4r +  r(r-1)(r-2) f(n-3) --> We observe that the factorial of r is developing which r in this case would be equivalent to saying n.
As a result, O(!n)
```

![[Pasted image 20250811202537.png]]

EXAMPLES

![[Pasted image 20250811202636.png]]