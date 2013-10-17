#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#if 0

 struct ucred credentials;
  int ucred_length = sizeof(struct ucred);

   /* fill in the user data structure */
   if(getsockopt(connection_fd, SOL_SOCKET, SO_PEERCRED, &credentials, &ucred_length))
		 {
				   printf("could obtain credentials from unix domain socket");
				     return 1;
					  }

 /* the process ID of the process on the other side of the socket */
 credentials.pid;

  /* the effective UID of the process on the other side of the socket  */
  credentials.uid;

   /* the effective primary GID of the process on the other side of the socket */
   credentials.gid;

    /* To get supplemental groups, we will have to look them up in our account
	 *     database, after a reverse lookup on the UID to get the account name.
	 *         We can take this opportunity to check to see if this is a legit account.
	 *          */
#endif

int main(void)
{
 int socket_fd;
 struct sockaddr_un server_address; 
 struct sockaddr_un client_address; 
 int bytes_received, bytes_sent, address_length;
 int integer_buffer;
 socklen_t address_length = sizeof(struct sockaddr_un);

 if((socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0)
 {
  perror("server: socket");
  return 1;
 }
 
 memset(&server_address, 0, sizeof(server_address));
 server_address.sun_family = AF_UNIX;
 strcpy(server_address.sun_path, "./UDSDGSRV");
 
 unlink("./UDSDGSRV");       
 if(bind(socket_fd, (const struct sockaddr *) &server_address, sizeof(server_address)) < 0)
 {
  close(socket_fd);
  perror("server: bind");
  return 1;
 }

 while(1)
 {
  /* address_length is the length of the client's socket address structure.
     Hear this should always be the same since these socets are of type struct sockaddr_un. 
     However, code that could be used with different types of sockets, ie UDS and UPD should
     take care to hold and pass the correct value back to sendto on reply.  */

  bytes_received = recvfrom(socket_fd, (char *) &integer_buffer, sizeof(int), 0, 
                            (struct sockaddr *) &(client_address),
                            &address_length);

  if(bytes_received != sizeof(int))
  {
   printf("datagram was the wrong size.\n");
  } else {
   integer_buffer += 5;

   bytes_sent = sendto(socket_fd, (char *) &integer_buffer, sizeof(int), 0,
                       (struct sockaddr *) &(client_address), 
                        &address_length);
  }
 }

 unlink("./UDSDGSRV");
 close(socket_fd);

 return 0;
}
