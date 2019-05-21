# GameOfLife

David Hernandez
Email: herna363@mail.chapman.edu
https://www.linkedin.com/in/david-hernandez7/

Link to the Code Requirements:
https://drive.google.com/file/d/1I4Me-Ff94EsNiX3HTIQhRj9tE-wUmpqV/view?usp=sharing

Steps to run code:
make
./a.out

Follow the prompts to simulate the Game. If you are prompted to provide a file,
I have included two different files to run the simulation. One is a simple
glider ("glider.txt") that will continuously run in doughnut mode. The other
one is a glider gunner ("gg.txt") that will go back and forth through the
simulation.

Things I learned from this project:
- This assignment really honed in my ability to master maps, arrays and file i/o.
- There is a bigger performance increase in changing the architecture of the program. Before This submission, I created the exact same program but with two arrays. The primary array would loop through the array and hit every single coordinate then check the 9 neighbors surrounding that coordinate and apply the appropriate rules. With this approach, I only focus on the coordinates that have alive nodes and add 1 to their surrounding neighbors. With this implementation, there aren't any dead ends (e.g. if the first submission checked a coordinate and there weren't any neighbors causing wasted time).
- Git Hub never forgets. I should of never committed compiled code because it doubles the size of the GitHub file. Code that is uploaded to GitHub should only contain the source code.
