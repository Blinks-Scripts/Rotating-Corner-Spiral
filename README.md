README

Rotating Corner Spiral

Consider a set of values arranged in an NxN square for some N>0.
Our task is to visit each value in the square
exactly once using a prescribed path.

The path begins by first visiting the values in the outermost embedded
square (i.e., top and bottom rows, first and last columns), then proceeding
inward to the next embedded square, and so on until we reach the center.

For each embedded square, start with the upper left corner and proceed
clockwise around the square visiting the four corners in sequence.

Once you reach the fourth corner, “rotate” your path one cell
clockwise and visit the four cells in sequence.

Repeat “rotating” then visiting four cells until you have visited
all the cells in the embedded square.

Continue the sequence by proceeding inward to the upper left corner in
the next embedded square and visit its cells in the same manner. Repeat
until all the embedded squares have been traversed.


The problem is broken down by breaking the matrix into layers or rings
that each can be seen as four vectors. Take a 3x3 matrix:

[1][2][3]
[4][5][6]
[7][8][9]

where [1..4, 6..9] comprise a layer, and [5] comprises a layer.
The former layer can be broken into 4 vectors: {1,2}{3,6}{9,8}{7,4}.
In this case, the variable count would begin at 2, because each vector
has two elements to provide to the traversal.  The code implementation does
not explicitly divide these vectors but simply accomplishes it mathematically.

Each sub-vector will decrease in size by 2 for each layer, until the final
layer in which case count is 0 but we must return the final element still.
This case of the final element is explicitly handled. Otherwise, elements are
traversed in a rotating-spiral fashion by sequentially visiting the first
element of each subvector, then the second of each subvector, etc.. Four separate
blocks act as "iterators" through the sides of the square being rotated, always
providing the current corner of the rotating spiral traversal.

Usage:
Simply provide a ```std::vector<std::vector<int>>``` as an argument

```RotatingCornerSpiral( std::vector<std::vector<int>> matrix ) ```
