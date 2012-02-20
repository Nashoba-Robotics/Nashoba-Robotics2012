#include "CoprocessorVision.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <resolvLib.h>
#include <arpa/inet.h>
#include <sockLib.h>
#include <inetLib.h>
#include <hostLib.h>
#include <ioLib.h>

#define BUFFERSIZE		1024
#define MY_PORT		    9999

#include <ctype.h>

CoprocessorVision::CoprocessorVision(){}

CoprocessorVision * CoprocessorVision::instance = 0;

CoprocessorVision * CoprocessorVision::getInstance()
{
	return instance;
}

void alltoupper(char* s)
{
	while ( *s != 0 )
		*s++ = toupper(*s);
}

int CoprocessorVision::run()
{
	char buffer[BUFFERSIZE];
	struct sockaddr_in clientaddr;
	struct sockaddr_in addr;
	int sd,  bytes_read;
	int addr_size;

	sd = socket(AF_INET, SOCK_DGRAM, 0);
	if ( sd == ERROR )
	{
		perror("socket");
		return -1;
	}
	addr_size = sizeof (sockaddr_in);
	bzero ((char*) &addr, sizeof (addr));
	bzero ((char*) &clientaddr, sizeof (clientaddr));
	addr.sin_family = AF_INET;
	addr.sin_len = sizeof (struct sockaddr_in);
	addr.sin_port = htons(9999);
	addr.sin_addr.s_addr = htonl (INADDR_ANY);
	if ( bind(sd, (struct sockaddr*)&addr, sizeof(addr)) == ERROR )
	{
		perror("bind");
		return -1;
	}
	do
	{
		bzero(buffer, BUFFERSIZE);
		addr_size = BUFFERSIZE;
		printf("sd = %d, BUFFERSIZE = %d", sd, BUFFERSIZE);
		bytes_read = recvfrom(sd, buffer, BUFFERSIZE, 0, (struct sockaddr*)&clientaddr, &addr_size);
		
		if ( bytes_read > 0 )
		{
			printf("Connect: %s:%d \"%s\"\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), buffer);
			alltoupper(buffer);
			if ( sendto(sd, buffer, bytes_read, 0, (struct sockaddr*)&clientaddr, addr_size) == ERROR )
				perror("reply");
		}
		else
		{	
			printf ("Error: %d \n", errno);
			perror("recvfrom");
			
		}	
	}
	while ( bytes_read > 0 );
	close(sd);
	return 0;
}	
