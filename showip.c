/*
** showip.c -- show IP addresses for a host given on the command line
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
	struct addrinfo hints, *res, *p;
	int status;
	char ipstr[INET6_ADDRSTRLEN];

  if (argc != 2) {
    fprintf(stderr, "Usage: showip hostname.\n");
    return 1;
  }

  // prepare hints
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  // get addrinfo
  if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0) {
    fprintf(stderr, "getaddrinfo fail: %s\n", gai_strerror(status));
    return 2;
  }

  // print addrinfo
  for (p = res; p != NULL; p = p->ai_next) {
    void *addr;
    if (p->ai_family == AF_INET) {
      struct sockaddr_in *sa = (struct sockaddr_in *)p->ai_addr;
      addr = &(sa->sin_addr);
    }
    else if (p->ai_family == AF_INET6) {
      struct sockaddr_in6 *sa = (struct sockaddr_in6 *)p->ai_addr;
      addr = &(sa->sin6_addr);
    }
    inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
    printf("%s\n", ipstr);
  }

  freeaddrinfo(res);

  return 0;
}
