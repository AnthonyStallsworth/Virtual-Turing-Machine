# VirtualTuringMachine
This is a Virtual Turing Machine. My goal is to be able to put in any mathematical
algorithm and let the Turing Machine calculate it! At the current moment it does not
divide. It takes any algorithm, converts it into reverse polish using the Shunting Yard
algorithm, and then runs a virtual turing machine on it that returns the correct answser.

If you decide to print out EVERY state the Turing Machine goes through be careful, the file
that gets created can get quite large, and based on the size of the algorithm, can get gigabytes
large. It will literally print out EVERY state that the turing machine goes through as well as 
the head position.

Just use the bash script I made to test this out yourself by typing:
"./compile_and_run"

Everything else should be simple. I think if you want to change the print state that will
be in the test/test.cpp file. Just change the print boolean to true! : ) Have fun!

And don't divide, or create an algorithm that will end up with a negative number. My machine
does not do negatives (although I think it easily could)
