#include<netdb.h>
#include<string.h>
#include<stdio.h>
#include<arpa/inet.h>
int main(int argc,char *argv[])
{
		char host[]="www.sina.com.cn";
		struct hostent *ht=NULL;
		char str[32];
		ht=gethostbyname(host);
		if(ht)
		{
				int i=0;
				printf("get the host: %s addr \n",host);
				printf("name : %s\n",ht->h_name);
				
				printf("type : %s \n",ht->h_addrtype==AF_INET?"AF_INET":"AF_INET6");
				printf("length : %d \n",ht->h_length);

				for(i=0;;i++)
				{
						if(ht->h_addr_list[i] != NULL)
						{
								printf("IP:%s\n",inet_ntop(ht->h_addrtype,ht->h_addr_list[i],str,32));
						}
						else
						{
								break;
						}
				}

				for(i=0;;i++)
				{
						if(ht->h_aliases[i] != NULL)
						{
								printf("alias %d:%s \n",i,ht->h_aliases[i]);
						}
						else
						{
								break;
						}
				}
		}
		return 0;
}





