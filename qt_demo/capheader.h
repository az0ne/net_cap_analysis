#include "pcap.h"
#ifndef PHEADER_H_INCLUDED
#define PHEADER_H_INCLUDED

#define ETHER_ADDR_LEN 6 /* ethernet address */
#define ETHERTYPE_IP 0x0800 /* ip protocal */
#define TCP_PROTOCAL 0x0600 /* tcp protocal */
#define UDP_PROTOCAL 0x1100 /*udp protocal*/
#define ICMP_PROTOCAL 0x0100 /*icmp protocal*/
#define ARP_PROTOCAL 0x0806 /*arp protocal*/

#define BUFFER_MAX_LENGTH 65536 /* buffer max length */
#define true 1  /* define true */
#define false 0 /* define false */

/*
* define struct of ethernet header , ip address , ip header and tcp header
*/
/* ethernet header */
typedef struct ether_header {
	u_char ether_shost[ETHER_ADDR_LEN]; /* source ethernet address, 6 bytes */
	u_char ether_dhost[ETHER_ADDR_LEN]; /* destination ethernet addresss, 6 bytes */
	u_short ether_type;                 /* ethernet type, 2 bytes */
}ether_header;

/* four bytes ip address */
typedef struct ip_address {
	u_char byte1;
	u_char byte2;
	u_char byte3;
	u_char byte4;
}ip_address;

/* ipv4 header */
typedef struct ip_header {
	u_char ver_ihl;         /* version and ip header length */
	u_char tos;             /* type of service */
	u_short  tlen;           /* total length */
	u_short identification; /* identification */
	u_short flags_fo;       // flags and fragment offset
	u_char ttl;             /* time to live */
	u_char proto;           /* protocol */
	u_short crc;            /* header checksum */
	ip_address saddr;       /* source address */
	ip_address daddr;       /* destination address */
	u_int op_pad;           /* option and padding */
}ip_header;

/* tcp header */
typedef struct tcp_header {
	u_short th_sport;         /* source port */
	u_short th_dport;         /* destination port */
	u_int th_seq;             /* sequence number */
	u_int th_ack;             /* acknowledgement number */
	u_short th_len_resv_code; /* datagram length and reserved code */
	u_short th_window;        /* window */
	u_short th_sum;           /* checksum */
	u_short th_urp;           /* urgent pointer */
}tcp_header;

/*udp header*/
typedef struct udp_header {
	u_short uh_sport;			/* source port */
	u_short uh_dport;			/* destination port */
	u_short uh_len;				/*udp length */
	u_short uh_sum;				 /* checksum */
}udp_header;

/*icmp header*/
typedef struct icmp_header{
	u_char icmp_type;			/*icmp type*/
	u_char icmp_code;			/*icmp code*/
	u_short icmp_sum;			/*checksum*/
}icmp_header;

/*arp header*/
typedef struct arp_header{
	u_short hard_type;			/*hardware type*/
	u_short proto_type;			/*protocal type*/
	u_char hard_len;			/*hardware address length*/
	u_char proto_len;			/*protocal address length*/
	u_short op;
	u_char ether_shost[ETHER_ADDR_LEN];	/*source MAC*/
	ip_address saddr;					/*source ip*/
	u_char ether_dhost[ETHER_ADDR_LEN];	/*destination MAC*/
	ip_address daddr;					/*destination ip*/
};

typedef struct image{
	int size = 0;
	int seg = 0;
	bool writing = false;
	u_int ack;
	int imgType=0; //1->jpg , 2->png
	char filename[_MAX_PATH];
};

typedef struct file{
	int seg = 0;
	bool writing = false;
	u_int ack;
	char  fileType[20]; //1->jpg , 2->png
	char filename[_MAX_PATH];
	int allSize = 0;
	int size = 0;
};
#endif // PHEADER_H_INCLUDED