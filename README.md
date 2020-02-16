# EE599HW4Q2
If the output is INT16_MAX, it means the supposed output (value) is not exist.
If it's -1, it then means the the supposed output (index) is not exist.

The tree I created in gtest was like this:

----------------9-----------------
               / \
              8   6
             / \ / \
            7  3 2  5
           / \
          1   4 

When pop, remove the top element and put the last element at the top, and trickle down to keep property.
