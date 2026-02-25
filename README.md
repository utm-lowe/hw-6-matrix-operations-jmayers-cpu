[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=22862426)
# CSCI-222-MatrixOperations
In this assignment, we will be exploring the wonderful world of linear algebra!
Linear algebra is the backbone of serious physics simulations and also computer
graphics, and so programming matrices is definitely somethign you may find 
yourself doing someday.

A matrix is essentially a two-dimensional array. We specify matrices in row-major
order, meaning that if we say that `M`is an `m x n` matrix, then `M` has 
`m` rows and `n` columns. For example, suppose we make a 3x2 matrix:

```
1 2 
3 4
5 6
```

We index these the same way would index an array. In fact, in programming the
term "array" is really a borrowed word from linear algebra! A Matrix is  a 2d
array of numbers. So m(0,0) is 1 and m(2,0) is 5 (following the conventional
mathematics definition.)

Now, we could simply implement matrices as two dimensionally arrays, however
we would lose some of their power if we do this! The reason is that their 
convenience really lies in their ability to represent large number of 
operations as simple linear equations. For instance, in physics we could
represent a position in space as a a column vector and velocity as a column
vector:

```
X = x
    y

V = vx
    vy
```

Now we can describe the motion of that object as:
```
X' = X + V*t
```
Where 't' is a scalar value for "time." So in order to better capture 
these sorts of calculations, we need to implement a matrix object with 
overloaded operators to match. That is your task in this lab!

# Matrix Implementation
Your first task is to implement the matrix class and operators as described
in `matrix.h`. I want you to try your hand at doing a bit of research as you
do this. So first, go to the font of wisdom (aka wikipedia) and use its article
on [Matrix (mathematics)](https://en.wikipedia.org/wiki/Matrix_(mathematics))

Now, take a look at what you are being asked to implement in `matrix.h`. There
are a few things to watch out for here. First, make sure you understand how
this matrix will be used. Have a look at `matrixTest.cpp` along with `matrix.h`
to get an idea of the expected syntax/behavior. Now, look over the following
notes:
* The matrix class has two versions of `at`, that will both do the same thing.
  The distinction is that one is const the other allows elements to be modified.
* The matrix should be dynamically allocated by the constructor.
* The destructor should deallocate the dynamically allocated array.
* The "copy constructor" should copy the dimensions of the rhs matrix, dynamically
  allocate its own array, and then copy all the elements over.
* Look up "constructor dispatching" if you want to find a nice short cut for 
  writing the copy constructor.
* The assignment operator is a member of the matrix class. This is a requirement
  for assignment operators. The left hand side of the operation is your 
  current object, and the right hand side is the object being copied.
* The assignment operator should copy all of the elements out of the rhs's
  array. It should NOT copy the pointers! 
* The assignment operator should return a reference to the left hand object.
  this can be accomplished by doing `return *this;` 
* In the copy constructor and in the assignment operator, you will have access
  to the private members of rhs. 

## Implementing Matrix Operators
 Your matrix operators should be implemented according to the math described
in the linked article. For now, we can assume that all dimensions will work out.
That is to say, no error checking will be done in this class. Later on, we'll 
circle back around and correct that!

Another thing to pay attention to is that everything will be in the `matrix.cpp`
file, but not everything is a member object! Be sure you get your scope resolution
operations right.

In regards to the insertion operator for the matrix, this should be done
using iomanip with a standard column width of `10`. Your output must match
the column spec exactly!

## Testing the Matrix
Once you have implemented the Matrix class and operations, you should be able
to build and run matrixTest:

```
make matrixTest
./matrixTest
```

A sample run of `matrixTest` is shown below:
```
$ ./matrixTest 
Enter a 3x3 matrix (A)
1 2 3
4 5 6
7 8 9
Enter a 3x3 matrix (B)
10 11 12
13 14 15
16 17 18
Matrix A
         1          2          3 
         4          5          6 
         7          8          9 

Matrix B
        10         11         12 
        13         14         15 
        16         17         18 

A + B
        11         13         15 
        17         19         21 
        23         25         27 

A - B
        -9         -9         -9 
        -9         -9         -9 
        -9         -9         -9 

A * B
        84         90         96 
       201        216        231 
       318        342        366 

2*A
         2          4          6 
         8         10         12 
        14         16         18 

A*2
         2          4          6 
         8         10         12 
        14         16         18 

```

Note how the output lines up. Make sure your program matches this output
exactly before you proceed!

# Trajectory Simulation
Remember when I said that matrices were used in physics? Well guess what you
get to do now! A little does of kinematics. If we have column vectors of
position (X), velocity (V), and acceleration (A), then we can express the
motion of these objects at discrte time intervals dt using the linear 
equations:

```
X = X + V*dt
V = V + A*dt
```

Look in the `trajectory.cpp` file and read the main file. There is a section
in here that you need to modify. See if you can relate the code that is currently
there to the equations listed above. Once you can, add the features that 
are called for in the comment. (You can search for the phrase "TODO" to see
what you need to do in this file.) Really, you'll just be writing a couple
lines of code plus a little if statement. 

This program does a nice little plot showing the position of the object a 0.1
second intervals. Here are  few sample runs:

```
$ make trajectory
$ ./trajectory
Position is in meters and velocity is in meters per second.
Initial x position: 0
Initial y position: 0
Inital x velocity: 10
Inital y velocity: 20
Simulation Duration (seconds): 10
                   *****                                                                            
                ***     ***                                                                         
              **           *                                                                        
             *              **                                                                      
            *                 *                                                                     
           *                   *                                                                    
          *                     *                                                                   
         *                       *                                                                  
        *                                                                                           
                                  *                                                                 
       *                           *                                                                
      *                             *                                                               
     *                                                                                              
                                     *                                                              
    *                                 *                                                             
                                                                                                    
   *                                   *                                                            
                                                                                                    
  *                                     *                                                           
 *                                                                                                  
                                         *                                                          
                                          *                                                         
$ ./trajectory
Position is in meters and velocity is in meters per second.
Initial x position: 0
Initial y position: 15
Inital x velocity: 5
Inital y velocity: 0
Simulation Duration (seconds): 10
*                                                                                                   
 **                                                                                                 
   *                                                                                                
   **                                                                                               
    *                                                                                               
     *                                                                                              
     *                                                                                              
      *                                                                                             
      *                                                                                             
       *                                                                                            
                                                                                                    
       *                                                                                            
        *                                                                                           
                                                                                                    
        *                                                                                           
         *                                                                                          
$ ./trajectory
Position is in meters and velocity is in meters per second.
Initial x position: 0
Initial y position: 0
Inital x velocity: 10
Inital y velocity: 5
Simulation Duration (seconds): 10
   ******                                                                                           
 **      ****                                                                                       
```

# Affine Transformations
For our final matrix operation, we will be performing affine transformations.
These are the heart of all computer graphics, in fact a GPU is essentially
a hardwrae coputer that specializes in matrix multiplication. So projections
and movement of objects in games in simulation depend upon matrix operations,
especially multiplication! 

So then, what is an affine transformation? An affine transformation is a 
transformation which preserves co-linearity of points. That is, points that
are on a line remain on the same lines after transformation and parallel lines
are preserved, but angles may change. We are going to implement the following
transformations:
* Translation - Movement through space.
* Rotation - Rotation about the origin.
* Scaling - Making objects bigger
We are going to do this in a two dimensional space. For more information 
on the mathematics of this, we can turn to the repository of all human 
knowledge: [Transformation Matrix](https://en.wikipedia.org/wiki/Transformation_matrix) and
[Affine Transformations](https://en.wikipedia.org/wiki/Affine_transformation),
however the gist of this operation is that we are going to produce a transformation
matrix T, from which we will modify our points:
```
X = XT
```
The shape of all the matrices that makes these happen are defined in the comments
in `affine.cpp`. So even if you don't read everything, the hints in that file
can help you. Also note that this forms a single transformation matrix from 
multiple operations. It does this by multiplying the matrices. For instance,
if we want to Scale and then Rotate, the matrix will be `T=R*T`. Note the order
of the multiplications!

So now, have at it! Open up the `affine.cpp` file and try to fill in all the
"TODO" sections. Here are a few sample runs of this program:
```
$ make affine
$ ./affine
(T)ranslate, (R)otate, (S)cale, or (D)one? R
Enter the angle of rotation (degrees): 90
(T)ranslate, (R)otate, (S)cale, or (D)one? D
Transformation Matrix: 
6.12323e-17         -1          0 
         1 6.12323e-17          0 
         0          0          1 


Enter x and y: 0 1
Transformed Point: (-1, 6.12323e-17)
Enter x and y: 1 0
Transformed Point: (6.12323e-17, 1)
Enter x and y: -1 0
Transformed Point: (-6.12323e-17, -1)
Enter x and y: 0 -1
Transformed Point: (1, -6.12323e-17)
Enter x and y: ^C

$ ./affine
(T)ranslate, (R)otate, (S)cale, or (D)one? S
Enter the x and y scaling factors: 2 3
(T)ranslate, (R)otate, (S)cale, or (D)one? D
Transformation Matrix: 
         2          0          0 
         0          3          0 
         0          0          1 


Enter x and y: 1 3
Transformed Point: (2, 9)
Enter x and y: 4 5
Transformed Point: (8, 15)
Enter x and y: ^C

$ ./affine
(T)ranslate, (R)otate, (S)cale, or (D)one? T
Enter the x and y translation: 1 1
(T)ranslate, (R)otate, (S)cale, or (D)one? R
Enter the angle of rotation (degrees): 45
(T)ranslate, (R)otate, (S)cale, or (D)one? S
Enter the x and y scaling factors: 2 3
(T)ranslate, (R)otate, (S)cale, or (D)one? D
Transformation Matrix: 
   1.41421   -1.41421 2.22045e-16 
   2.12132    2.12132    4.24264 
         0          0          1 


Enter x and y: 1 1
Transformed Point: (4.44089e-16, 8.48528)
Enter x and y: 2 3
Transformed Point: (-1.41421, 14.8492)
Enter x and y: 4 0
Transformed Point: (5.65685, 12.7279)
Enter x and y: ^C
```

Note that this program runs until the output is terminated, or until you
press Ctrl-C which is what those `^C` in the run indicate.

# Submission
Once you have all three sample programs working, commit and push your program.
Make sure it passes all of the github tests. Once you pass the automated test,
and submit your URL on canvas, you're all done!
