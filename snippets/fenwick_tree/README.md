# Fenwick Tree

The Fenwick Tree, AKA the BIT (Binary Indexed Tree) allows us to:

1. Efficiently represent dynamic frequency tables and query on them
2. Solve the Dynamic Range Sum Query problem
3. Represent an ordered statistics tree

## Data Stored

The Fenwick Tree is understood as a tree only visually, however all the data is stored inside an array with indices.

## Range Sum Query Operation

The Fenwick Tree works by each index storing the sum of all the terms after the $\text{index} - \text{LSOne}$ to the $\text{index}$ (LSOne = Least Significant Bit). Then we can get everything before that by running the same process recursively on the $\text{index} - \text{LSOne}$. This will in the end give us the total sum from $0$ to the $\text{index}$. If we want to get the sum starting from another index, we can simply just subtract off the sum before that. In other words, the range sum query between point $i$ and $j$ where $i\le j$ is equal to $rsq(j)-rsq(i-1)$. Note that if you are using the Fenwick Tree as a frequency table, this operation will just give the inclusive frequency count between the two numbers.

## Update Operation

To update a point, we need to update all indices that represent a range that contains the point we are trying to update and increment/decrement it by the change required. We can achieve this by repeatedly adding the least significant bit of the current index and updating that index until our number overflows the size of the array stored. _TODO: Why?_ We can extend this into range based updates by incrementing the starting index by `+change` and the ending index by `-change`.

## RSQ

_TODO: Write about sum queries when using frequency tables_

## Ordered Statistic Tree

_TODO: Write about finding the kth minimum element_

_TODO: Write time complexities_
