#ifndef SOLN_FUNC_CC
#define SOLN_FUNC_CC

//
// Jeffrey Blinks
// z1647644
// CSCI 340 - Section 4
// Fall '22
//
// Rotating Corner Spiral
//
// I certify that this is my own work and where appropriate
// an extension of starter code provided to me.
//

/* Rotating Corner Spiral will return a vector
   containing a sequence of elements according
   to the traversal pattern defined below


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

*/

#include <cstdlib>
#include <vector>

typedef long unsigned int lui;

std::vector<int> RotatingCornerSpiral( std::vector<std::vector<int>> &m )
{
    std::vector<int> spiral;
    lui n = m.size();

    // Check for square-ness
    for ( std::vector<std::vector<int>>::iterator it = m.begin(); it != m.end(); ++it )
    {
        if ( it->size() != n ) return spiral;
    }

    // Outlier Case
    if ( n == 1 )
    { // push only element and return
        spiral.push_back( m[0][0] );
        return spiral;
    }

    int counter = n - 1;
    int end_ind = n - 1;

    for ( lui h = 0; h < (n+1)/2 ; h++ )
    { // h will change "layers' of matrix
        for ( int i = 0; i < counter; i++ )
        { // i will rotate spiral within layer h
            // First Corner
            spiral.push_back( m[h][h+i] );

            // Second Corner
            spiral.push_back( m[h+i][end_ind-h] );

            // Third Corner
            spiral.push_back( m[end_ind-h][end_ind-h-i] );

            // Fourth Corner
            spiral.push_back( m[end_ind-h-i][h] );
        }

        if ( counter == 1 )
            break;

        counter -= 2;

        if ( counter == 0 )
        {
            spiral.push_back( m[h+1][h+1] );
            break;
        }
    }
    return spiral;
}

#endif // SOLN_FUNC_CC
