# Principle of Inclusion and Exclusion

The principle of inclusion and exclusion is a combinatorics principle allowing you to count the number of elements in the union of intersecting sets.

## Applications

This is useful to accomadate for over-counting combinations in combinatorics.

## How it Works

The formula for the Principle of Inclusion-Exclusion from [cpalgo](https://cp-algorithms.com/combinatorics/inclusion-exclusion.html#the-formulation-in-terms-of-sets) is:

$$
\left|\bigcup\limits_{i=1}^nA_i\right|=\sum\limits_{\emptyset \neq J\subseteq{\{1,2,\ldots,n\}}}(-1)^{\left|J\right|-1}\cdot{\left|\bigcap\limits_{j\in J}A_j\right|}
$$

In other words, the number of elements in the union of all the sets is equal to the sum of the intersection odd sized intersections of sets minus the sum of the intersection of even sized sets of sets.
