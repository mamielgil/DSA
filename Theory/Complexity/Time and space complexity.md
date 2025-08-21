
# Different notations

This notations are different ways of expressing the performance in terms of time of an algorithm. By expressing two different algorithms in a given notation we are able to compare their performance and determine which one takes the least amount of time.

These notations allow to understand the scalability of algorithms by helping to predict how these algorithms will perform as the input size grows.

## Best Case, Worst Case and Expected Case

The runtime of the different algorithms can be described in three different ways:

We are going to look at it from the perspective of the quick sort algorithm.

The quick sort algorithm is that sorting algorithm in which we set a pivot and we recursively sort the array by ensuring that all the elements on the left of the pivot are smaller than it and all of the greater ones are on its right.

1.  **Best case**:  if all the elements are equal, then quick sort will, on average, just traverse thorugh the array once. Therefore the time complexity will be O(n).

2. **Worst case:** if the pivot is the biggest element of the array  in each recursive iteration. Then in the array will be reduced just by one element each iteration because the pivot will be at the end, leading to the right side being empty and the left part with all the remaining elements.  This happens for example, when we use quicksort for an sorted array in decreasing order and we choose as pivot the first element.
   This will degenate to O(n²). <span style="color:rgb(145, 215, 232)">This is the one that is typically analyzed as it provides an upper bound, we know that the algorithm cannot be worse than that.</span>

3.  **Expected case**:  this is the average situation which is<span style="color:rgb(145, 215, 232)"> normally coincides with the worst case</span>. It represents on average what will be observed. In the quicksort it is O(nlog(n)).


<span style="color:rgb(255, 192, 0)">The best expected case is not an useful concept</span> because if a specific input is introduced, it would always lead to O(1). Therefore, the ones of interest are <span style="color:rgb(255, 192, 0)">the average and the worst case scenarios, which, in most algorithms, they lead to the same result.
</span>


<span style="color:rgb(255, 0, 0)">FROM THE ONES THAT ARE GOING TO BE MENTIONED THE ONE THAT IS MOSTLY USED IS THE BIG O NOTATION.</span>

[[Calculate Time Complexity]]

[[Calculate Space complexity]]

### ASYMPTOTIC NOTATIONS

**ALL OF THESE NOTATIONS CONSIDER AN INPUT OF SIZE N FOR THEIR ANALYSIS**

[[Big O notation(WORST CASE SCENARIO)]]

[[Big Ω (Omega) notation(BEST CASE SCENARIO)]]

[[Big Θ(theta) notation(AVERAGE CASE SCENARIO)]]



### Mixed properties of asymptotic notations

