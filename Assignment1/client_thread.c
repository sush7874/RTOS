#include<stdio.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include <unistd.h>
#include <pthread.h>
struct sockaddr_in serv; // socket variable
int fd; // file descripter
int conn; // connection descripter
char message[100] = "";
void* send_func(void* n){
  int sd = *(int*)n;
  char msg[1024] = {0};
  fgets(msg,1024,stdin);
  send(sd,msg, strlen(msg),0);
  return 0;
}

void* recv_func(void* n){
  int rsd = *(int*)n;
  char rply[1024];
  read(rsd,rply,sizeof(rply));
  printf("%s\n",rply );
  return 0;
}
//main function.
int main(int argc, char const *argv[]) {
  char buffer[1024] = {0};
  int valread;
  pthread_t thread;
  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
  //fd = socket(AF_INET, SOCK_STREAM, 0);
  serv.sin_family = AF_INET;
  int port_no = atoi(argv[3]);
  printf("%d\n",port_no );
  serv.sin_port = htons(port_no);
  printf("%s\n",argv[2] );
  if(inet_pton(AF_INET, argv[2], &serv.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}
  //inet_pton(AF_INET, argv[2], &serv.sin_addr); //binding client to local host
  //connect(fd, (struct sockaddr *)&serv, sizeof(serv));
  if (connect(fd, (struct sockaddr *)&serv, sizeof(serv)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
  while(1) {

    pthread_create(&thread,NULL,send_func,(void*) &fd);
    pthread_create(&thread,NULL,recv_func,(void*) &fd);

  }

  return 0;
}
