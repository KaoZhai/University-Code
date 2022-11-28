# Data Mining Homework Association 1

## 40847011S 高子翔

### Given the data set shown below:

| Transaction ID |     Items     |
| :------------: | :-----------: |
|      001       | a, b, c, d, e |
|      002       |  a, c, d, e   |
|      003       |  b, c, d, e   |
|      004       |  a, d, e, f   |
|      005       |  a, c, d, e   |

### (1) 

1st Scan

![image-20221121141556320](C:\Users\w96j0\AppData\Roaming\Typora\typora-user-images\image-20221121141556320.png)

2nd Scan

![image-20221121144237314](C:\Users\w96j0\AppData\Roaming\Typora\typora-user-images\image-20221121144237314.png)

3rd Scan

![image-20221121143340947](C:\Users\w96j0\AppData\Roaming\Typora\typora-user-images\image-20221121143340947.png)

4th Scan

![image-20221121143430085](C:\Users\w96j0\AppData\Roaming\Typora\typora-user-images\image-20221121143430085.png)

### (2)

{a, c, d}, {a, c, e}, {a, d, e}, {c, d, e}

![image-20221121155441707](C:\Users\w96j0\AppData\Roaming\Typora\typora-user-images\image-20221121155441707.png)

### (3)

####  maximum frequent itemsets

![image-20221121164619610](C:\Users\w96j0\AppData\Roaming\Typora\typora-user-images\image-20221121164619610.png)

 #### closed frequent itemsets

![image-20221121164438043](C:\Users\w96j0\AppData\Roaming\Typora\typora-user-images\image-20221121164438043.png)

### (4)

![image-20221121171410209](C:\Users\w96j0\AppData\Roaming\Typora\typora-user-images\image-20221121171410209.png)

the strong association rules are:

- A, C $\to$ D
- A, C $\to$ E
- A $\to$ D, E
- A, D $\to$ E
- A, E $\to$ D
- C $\to$ D, E
- C, D $\to$ E
- C, E $\to$ D

