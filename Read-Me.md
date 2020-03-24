# Algorithm Catalog / Testing
### Authored by: *Isaac A.B. Yep*

For both development and educational use, these algorithms are organized by purpose into testing environments to demonstrate their utility and compare variations of differing complexities. 

# Languages

Currently, 5 languages are peing supported in the project, each with their own directory:

* #### JSAlgorithms (Java Script)

* #### CAlgorithms (C Language) *The only finished one at the moment*

* #### CppAlgorithms (C++)

* #### JavaAlgorithms (Java)

* #### PythonAlgorithms (Python)


# Testing_Catalog/


### Graph

Algorithms/Solutions Involving graphs, such as path-finding or tree navigation


### Return

For general interesting problems that involving returning some solution, and that offer good examples of dynamic programming and other optimizations to naive solutions.

### Search

For searching for a given target in some data structure:
* #### IntTarget
* #### StrTarget



### Sort

For Sorting an array into ascending order.



# General Style Guide
<blockquote>
	<p>//====================================================</p>
	<p>// PROGRAM TITLE; Course title; Course number</p>
	<p>// Isaac A.B. Yep</p>
	<p>// Due: 1/2/34</p>
	<p>//====================================================</p>

	#pre-processor
	#statements
	#go
	#here

	/*************************************************
		Header for definitions
	*************************************************/
	// each definition gets a short label
	public class Shark {
		public Shark(int n = 0) {
			Teeth = n;
		}
		int Teeth;
		void Bite() {
			Console.Write("Chomp!\n");
		}
	}
	// another short label
	public class BabyShark : Shark {
		public BabyShark(int n = 0) : Shark(n) {
			if (n > 2)
				Teeth = n - 2;
			else
				Teeth = 0;
		}
		void Sing() {
			Console.Write("Bayyybeeee shark! Do do! Do do do do!\n");
		}
	}
</blockquote>



| File | Description |
|--|--|
| TEST.c | program entry |
| tools.c | printing tools |
| Makefile | build/workflow |
| solution.c | various algorithms in seperate files |
| rng.h | random number generator for testing purposes |
| main.h | tool deceleration and pre-processing |

