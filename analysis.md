# Analysis

## Introduction
This document provides an analysis of the performance of the multithreaded merge sort algorithm implemented in the project. The goal is to understand the speedup achieved by using multiple threads and identify any potential bottlenecks.

## Methodology
The merge sort algorithm was tested with varying numbers of threads on an array of size 1,000,000. The execution time was recorded for each configuration, and the results were plotted to visualize the performance.

## Results
![Performance Plot](student_plot.png)

### Observations
The data collected from the experiments is as follows:

```plaintext
#Threads Time(ms)
19160.581787 1
8956.305908 2
6474.456055 3
5598.696045 4
5150.025879 5
5691.001953 6
5534.199951 7
5272.353027 8
5031.361084 9
4825.821045 10
4907.714844 11
5579.303955 12
5399.893066 13
5246.491943 14
5227.580811 15
4897.104004 16
5298.266846 17
5069.509033 18
4856.468994 19
4771.955078 20
4825.355957 21
4860.826904 22
5195.927002 23
5288.239990 24
5242.637939 25
5202.286133 26
5251.197021 27
5313.036865 28
5137.589111 29
5108.037109 30
5247.186035 31
```

## Discussion

#### Were you able to generate something close to what the example showed? Why or why not?

Yes, the generated plot closely resembles the example provided. The performance improvement with increasing thread count is evident, but it also shows diminishing returns beyond a certain point. This behavior is expected due to the overhead associated with thread management and context switching.

#### Did you see a slowdown at some point? Why or why not?

Yes, a slowdown is observed beyond a certain number of threads. This slowdown occurs because the overhead of managing additional threads and the increased contention for shared resources outweighs the benefits of parallelism. As the number of threads increases, the time spent on synchronization and context switching increases, leading to reduced performance gains.

#### Did your program run faster and faster when you added more threads? Why or why not?

Initially, the program ran faster with the addition of more threads, as the workload was effectively distributed across multiple cores. However, beyond a certain number of threads, the performance gains diminished and eventually led to a slowdown. This behavior is due to the overhead of thread management and the limited number of physical cores available on the machine. Once the number of threads exceeds the number of available cores, the system spends more time context switching between threads, reducing overall efficiency.

####  What was the optimum number of threads for your machine?

The optimum number of threads for the machine appears to be around 10 threads, as indicated by the lowest execution time of approximately 4825.821045 milliseconds. Beyond this point, the performance gains are minimal, and the execution time starts to increase slightly.

#### What was the slowest number of threads for your machine?

The slowest execution time was observed with a first thread, taking approximately 19160.581787 milliseconds. This is expected, as a single-threaded implementation does not benefit from parallelism and must process the entire array sequentially.

### Conclusions

- **Multithreading significantly improves the performance** of the merge sort algorithm for large arrays, up to a certain point.
- **Diminishing returns** are observed beyond the optimum number of threads due to the overhead of thread management and context switching.
- The **optimum number of threads** for the machine used in this experiment is around 10 threads.
- **Further optimizations** could focus on reducing thread management overhead and improving load balancing to achieve better performance with higher thread counts.
