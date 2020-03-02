# RTOS
This assignment creates a one on one chat and a group chat respectively. <br/>
To run files in One_on_one chat: <br/>
compile: <br />
gcc -o server server_thread.c <br />
gcc -o client client_thread.c <br />

run: <br />
./server 1 portnum <br /> 
./client 2 127.0.0.1 portnum <br />

to run files in Group Chat: <br />
compile: <br />
gcc -o servergr server_group.c <br />
gcc -o clientgr client_group.c <br />

run: <br />

./server portnum <br />
./client 4 127.0.0.1 portnum name groupname <br />
./client 4 127.0.0.1 portnum name2 groupname <br />
./client 4 127.0.0.1 portnum name3 groupname <br />

we can go on manually creating new clients, but to test performance, it would be better if we create new clients <br />
by automation. this could be achieved by using fork to create new clients and comm within groups. <br />

Next step would be to add autonomus clients, and checking the performance.<br />
