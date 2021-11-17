# Changelog
All notable changes and bug fixing to this project will be documented in this file.

## [0.1.0] - 2021-11-17
### Bug Fixing
In buggy.cxx "word" struct, the member variable "count" is not given initial value, count should set as zero in constructor. \
In buggy.cxx line 40 and 42, s_word is assigned as zero at first element, so we cannot compare it with "end".\
In buggy.cxx line 52, found is changed to true when it found the word in the list, but "found" cannot change to false again.\
In buggy.cxx line 84, s_word would write and read at the same time, if there is no lock to protect it.\
In buggy.cxx line 115, "found" cannot be false anymore.

### Changed 
In new main.cpp, Word is changed from struct to class, and data and count are set as private for protecting.\

Because in buggy.cxx line85 there is a while-loop waiting for another thread to consume is not efficient and waste cpu,
in main.cpp the wordbuffer is added for storing the words in a queue.\
Then, condition variable and mutex are used for checking it's the right time to push a new word or consume a new word from the queue.\

And in main.cpp reader class, there is a map to store words and their count. There are two reasons for using std::map. \
First, when searching the words in buggy.cxx line 47 and line 111 by a for-loop is not efficient because complexity is O(n), and searing in std::map is O(logN). \
Second, it sort alphabetically automatically in std::map, so sorting is not necessary before lookupwords.

In buggy.cxx line 78, std::gets was deprecated in C++11 and removed from C++14. std::getline is used in main.cpp. 

Finally, in buggy.cxx line 21-23, it's not safe and efficient to memory to use static global variables, so in main.cpp there is no static global variables. 
