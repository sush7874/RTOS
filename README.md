# RTOS
This assignment creates a one on one chat and a group chat respectively. 
To run files in One_on_one chat: 
compile: 
gcc -o server server_thread.c 
gcc -o client client_thread.c

run: 
./server 1 <portnum>
./client 2 127.0.0.1 <portno>

to run files in Group Chat: 
compile: 
gcc -o servergr server_group.c
gcc -o clientgr client_group.c

run: 

./server <portnum>
./client 4 127.0.0.1 <portnum> <name> <groupname>
./client 4 127.0.0.1 <portnum> <name2> <groupname>
./client 4 127.0.0.1 <portnum> <name3> <groupname>

we can go on manually creating new clients, but to test performance, it would be better if we create new clients
by automation. this could be achieved by using fork to create new clients and comm within groups. 

Next step would be to add autonomus clients, and checking the performance.
