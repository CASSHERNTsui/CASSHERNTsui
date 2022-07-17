#include<netdb.h>
#include<stdio.h>

void display_protocol(struct protoent *pt)
{
		int i=0;
		if(pt)
		{
				printf("protocol name: %s,",pt->p_name);
				if(pt->p_aliases)
				{
						printf("alias name:");
						while(pt->p_aliases[i])
						{
								printf("%s",pt->p_aliases[i]);
								i++;
						}
				}
				printf(",value:%d\n",pt->p_proto);
		}
}

int main(int argc,char *argv[])
{
		int i=0;
		const char *const protocol_name[]={
			"ip",
			"icmp",
			"igmp",
			"ggp",
			"ipencap",
			"st",
			"tcp",
			"egp",
			"igp",
			"pup",
			"udp",
			"hmp",
			"xns-idp",
			"rdp",
			"iso-tp4",
			"xtp",
			"ddp",
			"idpr-cmtp",
			"ipv6",
			"ipv6-route",
			"ipv6-frag",
			"idrp",
			"rsvp",
			"gre",
			"esp",
			"ah",
			"skip",
			"ipv6-icmp",
			"ipv6-nonxt",
			"ipv6-opts",
			"rspf",
			"vmtp",
			"eigrp",
			"ospf",
			"ax.25",
			"ipip",
			"etherip",
			"enacp",
			"pim",
			"ipcomp",
			"vrrp",
			"l2tp",
			"isis",
			"sctp",
			"fc",
			NULL};


		setprotoent(1);
		while(protocol_name[i] != NULL)
		{
				struct protoent *pt= getprotobyname((const char*)&protocol_name[i][0]);
				if(pt)
				{
						display_protocol(pt);
				
				}
				i++;
		}
		endprotoent();
		return 0;
}
