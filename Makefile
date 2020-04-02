make:		msttest.cpp mst.cpp disjoint_set.cpp deque.cpp node.cpp msttest.h mst.h disjoint_set.h deque.h node.h
			g++ -std=c++11 -o mstdriver msttest.cpp mst.cpp disjoint_set.cpp deque.cpp node.cpp
run:	
			./mstdriver
clean:
			rm mstdriver 

