#  Building exe.
```
mkdir build
cd build
cmake ..
make
```

# Run the exe.
```
./Read_words
```

# Result is like
i \
love \
self-driving car \
i \
like \
japan \
yaya \
end 

=== Word list: \
[car:1] \
[i:2] \
[japan:1]\
[like:1]\
[love:1]\
[self-driving:1]\
[yaya:1] 

Enter a word for lookup \
i \
SUCCESS: i was present 2 times in the initial word list \
Enter a word for lookup \
japan \
SUCCESS: japan was present 1 times in the initial word list \
Enter a word for lookup \
korea \
korea was NOT found in the initial word list \
Enter a word for lookup \
^Z \
=== Total words found: 2 \
end program 
