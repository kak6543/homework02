Question 5:
If a robot finishes its tasks and is assigned a new task immediately, the main issue would be that the robot could interfere with another robot that is still doing its tasks, leading to problems like deadlock. If a robot interferes with another robots task the program could potentially fail and effectively stall all progress. The standard fix to this problem would be to program in a halt for a robot that prevents it from starting a new task until the other robots finish their current tasks.

Question 6:
For the ATC condition, an issue while developing the program could be race conditions. When two aircraft try to go into the traffic pattern and land at the same time the traffic count will not be synced properly and will cause the program to sort of freeze up. The solution would be to add more mutual exclusions to the traffic pattern which will ensure that only one aircraft can access the shared traffic pattern state at a time.    
