# Changelog
All notable changes and bug fixing to this project will be documented in this file.

## [0.1.0] - 2021-11-17
### Bug Fixing
In "word" struct, the member variable "count" is not given initial value, count should set as zero in constructor. \
In line 40 and 42, s_word is assigned as zero at first element, so we cannot compare it with "end".\
In line 52, found is changed to true when it found the word in the list, but "found" cannot change to false again.\
In line 84, s_word would write and read at the same time, if there is no lock to protect it.\
In line 115, "found" cannot be false anymore.

### Changed 
In new main.cpp, Word is changed from struct to class, and data and count are set as private for protecting.\

Because in line85 there is a while loop waiting for another thread to consume is not efficient and waste cpu, \
the wordbuffer is added for storing the words in a queue.\
Then, condition variable and mutex are used for checking it's the right time to push a new word or consume a new word from the queue.\
