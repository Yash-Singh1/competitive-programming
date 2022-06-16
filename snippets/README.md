TODO: Move snippets to someplace else to make more accessible

## Personal Choices in Starter Template

These are a few suggestions for starter templates and their explanations.

### `bits/stdc++.h`

I import `bits/stdc++.h` to get access to all libraries straight in the beginning.
Some people worry about this taking up too much space in the compiled output,
however it doesn't take a significant amount and some judges may even run dead
code elimination on the output in the process.

## `using namespace std`

While this is a bad practice in an enterprise environment due to namespace conflict,
it is fine to use in competitive programming as long as you are aware of how you're
naming your variables, because in competitive programming you want to implement your
solution faster.

## `ios_base::sync...`

Read the following links on why this speeds up I/O (Input and Output):

- [StackOverflow Question](https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull)
- [USACO Guide Article](https://usaco.guide/general/fast-io?lang=cpp#iossync_with_stdiofalse)
