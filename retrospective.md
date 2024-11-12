# Retrospective

## Optimal Number of Threads

### Experiment Setup
- **Array Size**: 1,000,000
- **Thread Counts Tested**: 1 to 32
- **Machine Specifications (Code Space)**:
  - **CPU Model**: AMD EPYC 7763 64-Core Processor
  - **Number of Cores**: 1 core (2 threads per core)
  - **Total Threads**: 2
  - **CPU MHz**: 3243.191
  - **L1d Cache**: 32 KiB
  - **L1i Cache**: 32 KiB
  - **L2 Cache**: 512 KiB
  - **L3 Cache**: 32 MiB
  - **Virtualization**: AMD-V
  - **Hypervisor Vendor**: Microsoft
  - **Operating System**: Linux (x86_64 architecture)

### Results
| Threads | Time (ms)     |
|---------|---------------|
| 1       | 19414.883789  |
| 2       | 8972.501221   |
| 3       | 6529.208984   |
| 4       | 5566.361816   |
| 5       | 4917.838135   |
| 6       | 6096.304932   |
| 7       | 5726.601074   |
| 8       | 5081.868164   |
| 9       | 5145.610107   |
| 10      | 4714.581055   |
| 11      | 5369.845947   |
| 12      | 5414.659912   |
| 13      | 5599.619873   |
| 14      | 5528.804932   |
| 15      | 5225.237793   |
| 16      | 5285.844971   |
| 17      | 4986.399902   |
| 18      | 5052.149170   |
| 19      | 4699.200928   |
| 20      | 4904.113037   |
| 21      | 4916.338867   |
| 22      | 5181.603027   |
| 23      | 5115.265869   |
| 24      | 5384.445068   |
| 25      | 5682.991943   |
| 26      | 5603.526123   |
| 27      | 5256.854980   |
| 28      | 5302.601074   |
| 29      | 5247.021973   |
| 30      | 5141.557129   |
| 31      | 5163.447021   |
| 32      | 5040.930908   |


### Analysis
- **Optimal Number of Threads**: Based on the results, the optimal number of threads for this machine is **10**.
- **Performance Trends**: 
  - Significant speedup is observed as the number of threads increases from 1 to 10.
  - Beyond 10 threads, the performance gains diminish, and the execution time starts to increase due to the overhead of context switching and thread management.
- **Conclusion**: For this specific machine, using 10 threads provides the best balance between parallelism and overhead, resulting in the shortest execution time for sorting the array.
