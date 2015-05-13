#include <iostream>
#include <cstring> 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <pcap.h>
#include "capheader.h"

int _main2()
{
	pcap_if_t* alldevs; // list of all devices
	pcap_if_t* d; // device you chose

	pcap_t* adhandle;

	char errbuf[PCAP_ERRBUF_SIZE]; //error buffer
	int i = 0;
	int inum;

	struct pcap_pkthdr *pheader; /* pcap header */
	const u_char * pkt_data; /* pcap data */
	int res;

	/* pcap_findalldevs_ex got something wrong */
	if (pcap_findalldevs_ex(PCAP_SRC_IF_STRING, NULL /* auth is not needed*/, &alldevs, errbuf) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs_ex: %s\n", errbuf);
		exit(1);
	}

	/* print the list of all devices */
	for (d = alldevs; d != NULL; d = d->next)
	{
		printf("%d. %s", ++i, d->name); // print device name , which starts with "rpcap://"
		if (d->description)
			printf(" (%s)\n", d->description); // print device description
		else
			printf(" (No description available)\n");
	}

	/* no interface found */
	if (i == 0)
	{
		printf("\nNo interface found! Make sure Winpcap is installed.\n");
		return -1;
	}

	printf("Enter the interface number (1-%d):", i);
	scanf_s("%d", &inum);

	if (inum < 1 || inum > i)
	{
		printf("\nInterface number out of range.\n");
		pcap_freealldevs(alldevs);
		return -1;
	}

	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++); /* jump to the selected interface */

	/* open the selected interface*/
	if ((adhandle = pcap_open(d->name, /* the interface name */
		65536, /* length of packet that has to be retained */
		PCAP_OPENFLAG_PROMISCUOUS, /* promiscuous mode */
		1000, /* read time out */
		NULL, /* auth */
		errbuf /* error buffer */
		)) == NULL)
	{
		fprintf(stderr, "\nUnable to open the adapter. %s is not supported by Winpcap\n",
			d->description);
		return -1;
	}

	printf("\nListening on %s...\n", d->description);

	pcap_freealldevs(alldevs); // release device list

	FILE *fp_arp, *fp_ip, *fp_icmp, *fp_tcp, *fp_udp, *fp_http;
	fp_arp = fopen("C:\\Users\\ckv1\\Documents\\Visual Studio 2013\\Projects\\demo1\\data\\arp.txt", "w");
	fp_ip = fopen("C:\\Users\\ckv1\\Documents\\Visual Studio 2013\\Projects\\demo1\\data\\ip.txt", "w");
	fp_icmp = fopen("C:\\Users\\ckv1\\Documents\\Visual Studio 2013\\Projects\\demo1\\data\\icmp.txt", "w");
	fp_tcp = fopen("C:\\Users\\ckv1\\Documents\\Visual Studio 2013\\Projects\\demo1\\data\\tcp.txt", "w");
	fp_udp = fopen("C:\\Users\\ckv1\\Documents\\Visual Studio 2013\\Projects\\demo1\\data\\udp.txt", "w");
	fp_http = fopen("C:\\Users\\ckv1\\Documents\\Visual Studio 2013\\Projects\\demo1\\data\\http.txt", "w");

	while ((res = pcap_next_ex(adhandle, &pheader, &pkt_data)) >= 0) {

		if (res == 0)
			continue; /* read time out*/

		ether_header * eheader = (ether_header*)pkt_data; /* transform packet data to ethernet header [14 bytes]*/

		/*write arp header into file*/
		if (eheader->ether_type == htons(ARP_PROTOCAL)){		/*过滤出arp报文*/
			arp_header * ah = (arp_header*)(pkt_data + 14);
			fprintf(fp_arp, "%d %d %d %d %d ", ntohs(ah->hard_type), ntohs(ah->proto_type), ah->hard_len, ah->proto_len, ntohs(ah->op));
			fprintf(fp_arp, "%x:%x:%x:%x:%x:%x %d.%d.%d.%d ", ah->ether_shost[0], ah->ether_shost[1], ah->ether_shost[2], ah->ether_shost[3], ah->ether_shost[4], ah->ether_shost[5],
				ah->saddr.byte1, ah->saddr.byte2, ah->saddr.byte3, ah->saddr.byte4);
			fprintf(fp_arp, "%x:%x:%x:%x:%x:%x %d.%d.%d.%d", ah->ether_dhost[0], ah->ether_dhost[1], ah->ether_dhost[2], ah->ether_dhost[3], ah->ether_dhost[4], ah->ether_dhost[5],
				ah->daddr.byte1, ah->daddr.byte2, ah->daddr.byte3, ah->daddr.byte4);
			fprintf(fp_arp, "\n");
		}
		/*write arp header over*/

		if (eheader->ether_type == htons(ETHERTYPE_IP)) { /* ip packet only */
			ip_header * ih = (ip_header*)(pkt_data + 14); /* get ip header */

			//转换必须注意，除u_char之外的需要使用转换函数ntohs,ntohl ->network to host short/long
			/*write ip header into file*/
			fprintf(fp_ip, "%d.%d.%d.%d ", ih->saddr.byte1, ih->saddr.byte2, ih->saddr.byte3, ih->saddr.byte4);
			fprintf(fp_ip, "%d.%d.%d.%d ", ih->daddr.byte1, ih->daddr.byte2, ih->daddr.byte3, ih->daddr.byte4);
			fprintf(fp_ip, "%d ", ih->tos);
			fprintf(fp_ip, "%d ", ntohs(ih->tlen));
			fprintf(fp_ip, "%d ", ntohs(ih->identification));
			fprintf(fp_ip, "%d ", ih->ttl);
			fprintf(fp_ip, "%d", ih->proto);
			fprintf(fp_ip, "\n");
			/*write ip header over*/

			/*write tcp header into file*/
			if (ih->proto == htons(TCP_PROTOCAL)) { /* 过滤出tcp报文 */
				tcp_header * th = (tcp_header*)(pkt_data + 14 + 20);
				fprintf(fp_tcp, "%d.%d.%d.%d:%d ", ih->saddr.byte1, ih->saddr.byte2, ih->saddr.byte3, ih->saddr.byte4, ntohs(th->th_sport));
				fprintf(fp_tcp, "%d.%d.%d.%d:%d ", ih->daddr.byte1, ih->daddr.byte2, ih->daddr.byte3, ih->daddr.byte4, ntohs(th->th_dport));
				fprintf(fp_tcp, "%lu ", ntohl(th->th_seq));
				fprintf(fp_tcp, "%lu ", ntohl(th->th_ack));
				fprintf(fp_tcp, "%d", ntohs(th->th_urp));
				fprintf(fp_tcp, "\n");

				/*write http request header into file*/
				if (ntohs(th->th_sport) == 80 || ntohs(th->th_dport) == 80){ /*过滤出http报文*/
					int http_len = ntohs(ih->tlen) - 20 - 20; /* http部分的文本长度，减去ip和tcp头部长度 */
					char* http_pkt_data = (char*)(pkt_data + 14 + 20 + 20);//数据包的应用层data
					int find_http = false;
					int n = 0;
					for (; n < http_len; n++){
						if (!find_http && ((n + 3 < http_len && strncmp(http_pkt_data + n, "GET", strlen("GET")) == 0)
							|| (n + 4 < http_len && strncmp(http_pkt_data + n, "POST", strlen("POST")) == 0))){
							find_http = true; break;
						}
						if (n > 4) break;
					}
					if (find_http){
						int blank = 0;
						int temp = 0;
						for (; temp < http_len - 2; temp++){ //http request line
							if (blank == 0 && strncmp(http_pkt_data + temp, " ", strlen(" ")) == 0){ //first blank, next is url
								blank++;
								fprintf(fp_http, " ");
								continue;
							}
							if (blank == 1 && strncmp(http_pkt_data + temp, " ", strlen(" ")) == 0){ //second blacnk, next is release
								blank++;
								fprintf(fp_http, " ");
								continue;
							}
							if ((int)(http_pkt_data[temp]) == 13 && (int)(http_pkt_data[temp + 1]) == 10){ //first CRLF
								temp = temp + 2;
								fprintf(fp_http, " ");
								break;
							}
							fprintf(fp_http, "%c", http_pkt_data[temp]);
						}
						fprintf(fp_http, "%d.%d.%d.%d:%d ", ih->saddr.byte1, ih->saddr.byte2, ih->saddr.byte3, ih->saddr.byte4, ntohs(th->th_sport));
						fprintf(fp_http, "%d.%d.%d.%d:%d ", ih->daddr.byte1, ih->daddr.byte2, ih->daddr.byte3, ih->daddr.byte4, ntohs(th->th_dport));
						for (; temp < http_len - 4; temp++){
							if ((int)(http_pkt_data[temp]) == 13 && (int)(http_pkt_data[temp + 1]) == 10 &&
								(int)(http_pkt_data[temp + 2]) == 13 && (int)(http_pkt_data[temp + 3]) == 10){ // http request form
								temp = temp + 4;
								break;
							}
						}
						for (; temp < http_len; temp++){
							fprintf(fp_http, "%c", http_pkt_data[temp]);
						}
					}
				}
				/*write http header over*/
			}
			/*write tcp header over*/

			/*write udp header into file*/
			if (ih->proto == htons(UDP_PROTOCAL)){ /*过滤出udp报文*/
				udp_header * uh = (udp_header*)(pkt_data + 14 + 20);
				fprintf(fp_udp, "%d.%d.%d.%d:%d ", ih->saddr.byte1, ih->saddr.byte2, ih->saddr.byte3, ih->saddr.byte4, ntohs(uh->uh_sport));
				fprintf(fp_udp, "%d.%d.%d.%d:%d ", ih->daddr.byte1, ih->daddr.byte2, ih->daddr.byte3, ih->daddr.byte4, ntohs(uh->uh_dport));
				fprintf(fp_udp, "%d", ntohs(uh->uh_len));
				fprintf(fp_udp, "\n");
			}
			/*write tcp header over*/

			/*write icmp header into file*/
			if (ih->proto == htons(ICMP_PROTOCAL)){ /*过滤出icmp报文*/
				icmp_header * icmp_h = (icmp_header*)(pkt_data + 14 + 20);
				fprintf(fp_icmp, "%d.%d.%d.%d ", ih->saddr.byte1, ih->saddr.byte2, ih->saddr.byte3, ih->saddr.byte4);
				fprintf(fp_icmp, "%d.%d.%d.%d ", ih->daddr.byte1, ih->daddr.byte2, ih->daddr.byte3, ih->daddr.byte4);
				fprintf(fp_icmp, "%d ", icmp_h->icmp_type);
				fprintf(fp_icmp, "%d", icmp_h->icmp_code);
				fprintf(fp_icmp, "\n");
			}

		}
	}

	fclose(fp_arp);
	fclose(fp_ip);
	fclose(fp_tcp);
	fclose(fp_udp);
	fclose(fp_icmp);
	fclose(fp_http);
	return 0;
}